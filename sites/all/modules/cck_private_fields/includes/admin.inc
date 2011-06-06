<?php
// $Id: admin.inc,v 1.1.2.6 2009/08/05 18:23:41 markuspetrux Exp $

/**
 * @file
 * Administrative interface for the CCK Private Fields module.
 */

/**
 * Alter the CCK Field settings form.
 */
function _cck_private_fields_content_field_edit_form_alter(&$form) {
  $field_name = $form['#field']['field_name'];
  $content_field_privacy = cck_private_fields_get_content_field_privacy($field_name);

  $privacy_status_options = array(
    '' => t('Disabled'),
    CCK_FIELDS_PRIVACY_STATUS_PUBLIC => t('Enabled and %status by default', array('%status' => t('Public'))),
    CCK_FIELDS_PRIVACY_STATUS_HIDDEN => t('Enabled and %status by default', array('%status' => t('Hidden'))),
  );
  if (cck_private_fields_get_private_field_access_module()) {
    $privacy_status_options[CCK_FIELDS_PRIVACY_STATUS_PRIVATE] = t('Enabled and %status by default', array('%status' => t('Private')));
  }

  $form['field']['cck_private_fields'] = array(
    '#type' => 'fieldset',
    '#title' => t('CCK Privacy options'),
    '#weight' => 50,
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#description' => t('Allow users with %permission permission select privacy options for this field.', array(
      '%permission' => cck_private_fields_build_permission_name('edit', $field_name),
    )),
  );
  $form['field']['cck_private_fields']['content_privacy_status'] = array(
    '#type' => 'radios',
    '#title' => t('Privacy settings for this field'),
    '#options' => $privacy_status_options,
    '#default_value' => (isset($privacy_status_options[$content_field_privacy]) ? $content_field_privacy : ''),
  );

  if ($content_field_privacy !== FALSE) {
    if (($field_usage_count = cck_private_fields_get_field_usage_count($field_name)) > 0) {
      $form['field']['cck_private_fields']['field_usage_count_warning'] = array(
        '#type' => 'markup',
        '#value' => '<div class="warning">'. t('Warning: If this option is disabled existing privacy data related to this field will be deleted. Records affected: @count', array('@count' => $field_usage_count)) .'</div>',
      );
    }
  }

  $form['#submit'][] = '_cck_private_fields_content_field_edit_form_submit';
}

/**
 * Submit function for Private Fields extra config.
 */
function _cck_private_fields_content_field_edit_form_submit($form, &$form_state) {
  // Set the privacy option for the given field.
  $content_field_privacy = (is_numeric($form_state['values']['content_privacy_status']) ? $form_state['values']['content_privacy_status'] : FALSE);
  cck_private_fields_set_content_field_privacy($form_state['values']['field_name'], $content_field_privacy);
}

/**
 * Modules notify CCK Private Fields module when enabled, disabled, etc.
 *
 * @param $op
 *   The module operation: install, uninstall, enable, disable.
 * @param $module
 *   The name of the affected module.
 *
 * @see cck_private_fields_get_private_field_access_module()
 */
function _cck_private_fields_notify($op, $module) {
  switch ($op) {
    case 'enable':
      if (!module_exists($module)) {
        return FALSE;
      }

      // Save the name of the module that provides view access control
      // for Private status.
      variable_set('cck_private_fields_view_access_module', $module);
      return TRUE;

    case 'disable':
      variable_del('cck_private_fields_view_access_module');

      // This will force Drupal core invoke hook_requirements('install')
      // whenever the module is enabled again.
      drupal_set_installed_schema_version($module, SCHEMA_UNINSTALLED);
      return TRUE;

    case 'install':
    case 'uninstall':
      // Nothing really special to do here.
      return TRUE;
  }
  return FALSE;
}

/**
 * Modules that provide field access control for Private status should
 * invoke this function from its own hook_requirements('install')
 * implementation.
 */
function _cck_private_fields_check_install_requirements($module) {
  $requirements = array();
  $t = get_t();

  $field_access_module = cck_private_fields_get_private_field_access_module();
  if (!empty($field_access_module) && $field_access_module != $module) {
    $requirements[$module] = array(
      'title' => $t('CCK Private Fields'),
      'severity' => REQUIREMENT_ERROR,
      'description' => $t('%cck-private-fields is not compatible with more than one field access control provider. Please, uninstall %field-access-module if you want to enable %module.', array(
        '%cck-private-fields' => $t('CCK Private Fields'),
        '%field-access-module' => $field_access_module,
        '%module' => $module,
      )),
    );
  }
  return $requirements;
}
