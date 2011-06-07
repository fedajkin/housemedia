<?php
// $Id: common.inc,v 1.1.2.8 2009/08/05 19:09:11 markuspetrux Exp $

/**
 * @file
 * Common functions for the CCK Private Fields module.
 */

/**
 * Set the privacy option for the given field.
 */
function cck_private_fields_set_content_field_privacy($field_name, $content_field_privacy) {
  if ($content_field_privacy !== FALSE) {
    // If privacy is enabled, then create the variable.
    variable_set('cck_private_fields_'. $field_name, $content_field_privacy);
  }
  elseif (variable_get('cck_private_fields_'. $field_name, FALSE) !== FALSE) {
    // If privacy is disabled, then remove the variable to reduce the size
    // of the {variable} table. Note this is perfectly fine because default
    // variable value is disabled.
    variable_del('cck_private_fields_'. $field_name);

    // Delete privacy data related to the field instance being disabled.
    db_query("DELETE FROM {cck_private_fields} WHERE field_name = '%s'", $field_name);
  }
}

/**
 * Get the privacy option for the given field.
 */
function cck_private_fields_get_content_field_privacy($field_name) {
  return variable_get('cck_private_fields_'. $field_name, FALSE);
}

/**
 * Get the list of private fields for the given content type.
 */
function cck_private_fields_get_content_private_fields($type_name, $reset = FALSE) {
  static $private_fields;
  if (!isset($private_fields) || $reset) {
    $private_fields = array();
  }
  if (!isset($private_fields[$type_name])) {
    $private_fields[$type_name] = array();
    // Scan the list of fields defined in the given content type.
    $result = db_query("SELECT nfi.field_name, nfi.label
      FROM {". content_instance_tablename() ."} nfi
        INNER JOIN {". content_field_tablename() ."} nf ON nfi.field_name = nf.field_name
      WHERE nfi.type_name = '%s' AND nf.active = 1 AND nf.locked = 0", $type_name);
    while ($instance = db_fetch_object($result)) {
      $content_field_privacy = cck_private_fields_get_content_field_privacy($instance->field_name);
      if ($content_field_privacy !== FALSE) {
        $private_fields[$type_name][$instance->field_name] = $content_field_privacy;
      }
    }
  }
  return $private_fields[$type_name];
}

/**
 * Get the list of all fields with privacy options enabled.
 */
function cck_private_fields_get_private_fields($reset = FALSE) {
  static $private_fields;
  if (!isset($private_fields) || $reset) {
    $private_fields = array();
  }
  $result = db_query("SELECT name FROM {variable} WHERE name LIKE 'cck\_private\_fields\_field\_%%'");
  while ($row = db_fetch_object($result)) {
    $field_name = preg_replace('`^cck_private_fields_(.*)$`', '\1', $row->name);
    $private_fields[$field_name] = cck_private_fields_get_content_field_privacy($field_name);
  }
  return $private_fields;
}

/**
 * Get the usage count for the given field.
 */
function cck_private_fields_get_field_usage_count($field_name) {
  return (int)db_result(db_query("SELECT COUNT(*) FROM {cck_private_fields} WHERE field_name = '%s'", $field_name));
}

/**
 * Get the privacy status for the given field in the given node revision.
 */
function cck_private_fields_get_field_privacy_status($vid, $field_name) {
  $field_privacy_status = db_result(db_query("SELECT privacy_status FROM {cck_private_fields} WHERE vid = %d AND field_name = '%s'", $vid, $field_name));
  return is_numeric($field_privacy_status) ? (int)$field_privacy_status : (int)cck_private_fields_get_content_field_privacy($field_name);
}

/**
 * Get the privacy status for the given node revision.
 */
function cck_private_fields_get_node_privacy_status($vid) {
  $fields = array();
  $result = db_query("SELECT field_name, privacy_status FROM {cck_private_fields} WHERE vid = %d", $vid);
  while ($data = db_fetch_object($result)) {
    $fields[$data->field_name] = (int)$data->privacy_status;
  }
  return $fields;
}

/**
 * Build the permission name for the given operation against a particular field.
 *
 * @param $op
 *   The operation related to the permission ('view' or 'edit').
 * @param $field_name
 *   The field name related to the permission.
 *
 * @return
 *   Boolean TRUE if the current user has the requested permission.
 *
 * @see cck_private_fields_perm()
 * @see user_access()
 */
function cck_private_fields_build_permission_name($op, $field_name) {
  return ($op == 'view' ? 'view private data for field' : 'edit privacy options for field') .' '. $field_name;
}

/**
 * Get the name of the module that provides private access control.
 *
 * @see cck_private_fields_notify()
 */
function cck_private_fields_get_private_field_access_module() {
  return variable_get('cck_private_fields_view_access_module', NULL);
}

/**
 * Invoke privacy access module to check for view access to the given field
 * for the given module.
 *
 * @param $field
 *   The field which is about to be checked.
 * @param $node
 *   The node where this field is located.
 * @param $account
 *   The account to check.
 *
 * @return
 *   Boolean TRUE if the specified account is allowed to view the field.
 */
function cck_private_fields_invoke_view_access($field, $node, $account) {
  // Check if privacy access module is enabled and exists.
  $module = cck_private_fields_get_private_field_access_module();
  if (empty($module) || !module_exists($module)) {
    return FALSE;
  }

  // Check if privacy access hook is implemented.
  $function = $module .'_cck_private_fields_view_access';
  if (!function_exists($function)) {
    return FALSE;
  }

  return (boolean)$function($field, $node, $account);
}
