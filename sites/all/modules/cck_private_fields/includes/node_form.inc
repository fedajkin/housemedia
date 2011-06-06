<?php
// $Id: node_form.inc,v 1.1.2.8 2009/11/02 07:01:04 markuspetrux Exp $

/**
 * @file
 * User side interface for the CCK Private Fields module.
 */

/**
 * Alter the node edit form.
 *
 * Scan the node form to add field privacy options to fields with this
 * option enabled.
 *
 * @param $form
 *   The form being processed.
 * @param $private_fields
 *   The list of private fields for the node type in the form.
 *
 * @see cck_private_fields_form_alter()
 */
function _cck_private_fields_node_form_alter(&$form, &$form_state, $private_fields) {
  static $js_settings_processed;

  // Configure privacy options for fields in this node form.
  $privacy_status_options = array(
    CCK_FIELDS_PRIVACY_STATUS_PUBLIC => array(
      'name' => t('Public'),
      'class' => 'cck-private-field-status-icon-public',
      'label' => t('Public - visible to everyone.'),
    ),
    CCK_FIELDS_PRIVACY_STATUS_HIDDEN => array(
      'name' => t('Hidden'),
      'class' => 'cck-private-field-status-icon-hidden',
      'label' => t('Hidden - visible to you, hidden from everyone else.'),
    ),
  );

  // Enable 'Private' option, only if supported.
  if (cck_private_fields_get_private_field_access_module()) {
    $privacy_status_options[CCK_FIELDS_PRIVACY_STATUS_PRIVATE] = array(
      'name' => t('Private'),
      'class' => 'cck-private-field-status-icon-private',
      'label' => t('Private - visible to you and your friends.'),
    );
  }

  // Make sure Drupal settings are not sent more than once per page.
  if (!isset($js_settings_processed)) {
    $js_settings = array(
      'privacyStatusOptions' => $privacy_status_options,
      'privacyStatusForm' => drupal_get_form('cck_private_field_privacy_settings_dialog', $privacy_status_options),
      'privateFields' => array(),
    );
  }

  // Grab information about the fields we are interested in.
  $type_name = $form['type']['#value'];
  $content_type = content_types($type_name);
  $groups = (module_exists('fieldgroup') ? fieldgroup_groups($type_name) : array());
  foreach ($content_type['fields'] as $field_name => $field) {
    if (isset($private_fields[$field_name])) {
      // See if this field is located on a field group.
      $group_type = 'none';
      $group_table_id = '';
      $multiple_columns = FALSE;
      foreach ($groups as $group_name => $group) {
        if (isset($group['fields'][$field_name])) {
          $group_type = $group['group_type'];
          $group_table_id = $group_name .'_values';
          if ($group['group_type'] == 'multigroup' && isset($group['settings']['multigroup']['multiple-columns'])) {
            $multiple_columns = (boolean)$group['settings']['multigroup']['multiple-columns'];
          }
          break;
        }
      }

      // See if the current user is allowed to edit privacy settings for this field.
      $edit_privacy_access = user_access(cck_private_fields_build_permission_name('edit', $field_name));

      $private_fields[$field_name] = array(
        'field' => $field,
        'edit_privacy_access' => $edit_privacy_access,
        'group_type' => $group_type,
        'group_table_id' => $group_table_id,
        'multiple_columns' => $multiple_columns,
      );

      // Prepare field information for sending to client-side behavior?
      if ($edit_privacy_access && !isset($js_settings_processed)) {
        $js_settings['privateFields'][$field_name] = array(
          'label' => check_plain($field['widget']['label']),
          'group_type' => $group_type,
          'group_table_id' => $group_table_id,
          'multiple_columns' => $multiple_columns,
        );
      }
    }
  }

  // Prepare the form for private fields handling.
  $form['#cck_private_fields'] = $private_fields;
  $form['cck_private_fields'] = array(
    '#tree' => TRUE,
    '#weight' => 100,
  );

  // Scan the form recursively to find fields with privacy options enabled.
  _cck_private_fields_node_form_recursive($form, $form, $form_state);

  // Send our javascript and stylesheets to the page.
  $module_path = drupal_get_path('module', 'cck_private_fields');
  drupal_add_css($module_path .'/css/privacy_status_dialog.css');
  drupal_add_js($module_path .'/js/privacy_status_dialog.js');
  jquery_ui_add(array('ui.dialog', 'ui.draggable'));

  // Make sure Drupal settings are not sent more than once per page.
  if (!isset($js_settings_processed)) {
    drupal_add_js(array('CCKPrivateFields' => $js_settings), 'setting');
    $js_settings_processed = TRUE;
  }
}

/**
 * Scan the form recursively to find fields with privacy options enabled.
 *
 * Move privacy status for fields to the top level of the $form_state['values']
 * structure (defined as hidden form elements that are manipulated client-side;
 * requires javascript to be enabled).
 * This is used by node_form_submit_build_node() and node_submit() to build a
 * node object suitable for node_save().
 *
 * @see node_form_submit_build_node()
 * @see node_submit()
 * @see node_save()
 * @see cck_private_fields_nodeapi()
 */
function _cck_private_fields_node_form_recursive(&$form, &$elements, &$form_state) {
  foreach (element_children($elements) as $field_name) {
    if (isset($elements[$field_name]) && $elements[$field_name]) {

      // See if this is one of those fields where privacy options are enabled.
      if (isset($form['#cck_private_fields'][$field_name])) {

        // Ignore hidden elements.
        if (isset($elements[$field_name]['#type']) && $elements[$field_name]['#type'] == 'hidden') {
          continue;
        }

        // Load information about the field.
        $field = $form['#cck_private_fields'][$field_name]['field'];

        // Get the privacy status for this field from $form_state if it is
        // a form preview.
        if (isset($form_state['values']['cck_private_fields']) && isset($form_state['values']['cck_private_fields'][$field_name])) {
          $field_privacy_status = $form_state['values']['cck_private_fields'][$field_name];
        }
        // If this is a node edit form, get the privacy status from database.
        elseif (isset($form['vid']['#value'])) {
          $field_privacy_status = cck_private_fields_get_field_privacy_status($form['vid']['#value'], $field_name);
        }
        // Otherwise, when creating a node, get the default privacy status
        // defined for this field.
        else {
          $field_privacy_status = cck_private_fields_get_content_field_privacy($field_name);
        }

        // Allow access to change the privacy options for this field only to
        // users with appropriate permissions.
        if (!$form['#cck_private_fields'][$field_name]['edit_privacy_access']) {
          // This user is not allowed, but we still need field privacy settings
          // in the form, so that this data is available to node_submit().
          $form['cck_private_fields'][$field_name] = array(
            '#type' => 'value',
            '#value' => $field_privacy_status,
          );
        }
        else {
          // Send the privacy status for this field as a hidden form element.
          $form['cck_private_fields'][$field_name] = array(
            '#type' => 'hidden',
            '#default_value' => $field_privacy_status,
          );

          // Render the privacy status icon.
          // Note however that fields in multigroups configured to use
          // multiple columns table are targeted client-side.
          if ($form['#cck_private_fields'][$field_name]['group_type'] != 'multigroup' || !$form['#cck_private_fields'][$field_name]['multiple_columns']) {
            $old_prefix = (isset($elements[$field_name]['#prefix']) ? $elements[$field_name]['#prefix'] : '');
            $old_suffix = (isset($elements[$field_name]['#suffix']) ? $elements[$field_name]['#suffix'] : '');

            $wrapper_class = 'cck-private-field-wrapper cck-private-field-wrapper-';
            $wrapper_class .= (isset($elements[$field_name]['#theme']) && $elements[$field_name]['#theme'] == 'content_multiple_values' ? 'multiple' : 'single');
            $wrapper_class .= ' cck-private-field-name-'. $field_name .' clear-block';

            $new_prefix = '<div class="'. $wrapper_class .'"><div class="cck-private-field-status-icon"></div>';
            $new_suffix = '</div>';

            if ($field['multiple'] > 1) {
              $new_prefix .= '<div>';
              $new_suffix .= '</div>';
            }

            $elements[$field_name]['#prefix'] = $new_prefix . $old_prefix;
            $elements[$field_name]['#suffix'] = $old_suffix . $new_suffix;
          }
        }
      }
      else {
        // Recurse through all children elements.
        _cck_private_fields_node_form_recursive($form, $elements[$field_name], $form_state);
      }
    }
  }
}

/**
 * Field privacy settings form.
 *
 * This form is processed client-side.
 */
function cck_private_field_privacy_settings_dialog(&$form_state, $privacy_status_options) {
  $form = array(
    '#method' => 'get',
  );
  $options = array();
  foreach ($privacy_status_options as $status => $info) {
    $options[$status] = $info['label'];
  }
  $form['cck-private-fields-dialog-status-options'] = array(
    '#type' => 'radios',
    '#title' => t('Privacy options for @field'),
    '#options' => $options,
    '#default_value' => CCK_FIELDS_PRIVACY_STATUS_PUBLIC,
    '#description' => t('Use these options to select who is allowed to view the @field field.'),
    '#weight' => 0,
  );
  $form['cck-private-fields-dialog-status-buttons'] = array(
    '#prefix' => '<div class="container-inline">',
    '#suffix' => '</div>',
    '#weight' => 10,
  );
  $form['cck-private-fields-dialog-status-buttons']['cck-private-fields-dialog-status-button-ok'] = array(
    '#type' => 'button',
    '#value' => t('Ok'),
    '#weight' => 0,
  );
  $form['cck-private-fields-dialog-status-buttons']['cck-private-fields-dialog-status-button-cancel'] = array(
    '#type' => 'button',
    '#value' => t('Cancel'),
    '#weight' => 10,
  );
  return $form;
}
