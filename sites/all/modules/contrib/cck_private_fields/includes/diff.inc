<?php
// $Id: diff.inc,v 1.1.2.4 2009/11/02 07:01:04 markuspetrux Exp $

/**
 * @file
 * Integration of CCK Private Fields with diff module.
 */

/**
 * Implementation of hook_diff().
 */
function cck_private_fields_diff(&$old_node, &$new_node) {
  $result = array();

  // Prevent against invalid 'nodes' built by broken 3rd party code.
  if (isset($new_node->type)) {
    module_load_include('inc', 'cck_private_fields', 'includes/common');

    // Get privacy status for both node revisions.
    $old_node_privacy_status = cck_private_fields_get_node_privacy_status($old_node->vid);
    $new_node_privacy_status = cck_private_fields_get_node_privacy_status($new_node->vid);

    // Check for values that exist in old node only, or both.
    foreach ($old_node_privacy_status as $field_name => $privacy_status) {
      $new_value = isset($new_node_privacy_status[$field_name]) ? $new_node_privacy_status[$field_name] : '';
      _cck_private_fields_build_diff_entry($result, $field_name, $old_node, $privacy_status, $new_value);
    }

    // Check for values that exist in new node only.
    foreach ($new_node_privacy_status as $field_name => $privacy_status) {
      if (!isset($old_node_privacy_status[$field_name])) {
        _cck_private_fields_build_diff_entry($result, $field_name, $new_node, '', $privacy_status);
      }
    }
  }

  return $result;
}

/**
 * Helper function to format the result of changes in field privacy status.
 */
function _cck_private_fields_build_diff_entry(&$result, $field_name, $node, $old_value, $new_value) {
  $privacy_status_options = array(
    CCK_FIELDS_PRIVACY_STATUS_PUBLIC => t('Public'),
    CCK_FIELDS_PRIVACY_STATUS_HIDDEN => t('Hidden'),
    CCK_FIELDS_PRIVACY_STATUS_PRIVATE => t('Private'),
  );

  // Obtain information about this particular field.
  $field = content_fields($field_name, $node->type);

  // Check permission to view this field.
  if (!content_access('view', $field, NULL, $node)) {
    return;
  }

  $old_diff = $new_diff = array();
  if (isset($privacy_status_options[$old_value])) {
    $old_diff[] = $privacy_status_options[$old_value];
  }
  if (isset($privacy_status_options[$new_value])) {
    $new_diff[] = $privacy_status_options[$new_value];
  }

  $result[$field_name .'_privacy_status'] = array(
    '#name' => t('Privacy status for field @field', array('@field' => $field['widget']['label'])),
    '#old' => $old_diff,
    '#new' => $new_diff,
    '#weight' => $field['widget']['weight'] + 0.01,
    '#format' => array(
      'show_header' => FALSE,
    )
  );
}
