<?php
// $Id: groupadmin.config.inc.php,v 1.1.2.4 2010/03/15 18:08:30 netgenius Exp $

/********************************************************
Original development by: netgenius.co.uk
Commercial support is available from www.netgenius.co.uk
Contact: drupal(a)netgenius.co.uk
*********************************************************/

/**
 * Get a config. value.
 */
function _groupadmin_settings($key, $return_key = FALSE) {
  static $config;
  static $fields;

  $config_name = 'groupadmin';
  if(!$config) {
    $config = variable_get($config_name, array());
  }

  $fields = _groupadmin_settings_fields();
  $field = $fields[$key];
  $value = isset($config[$key])? $config[$key] : $field[1];
  $options = $field[2];

  return (is_array($options) && !$return_key)? $options[$value] : $value;
}

/**
 * Get fields array for config values.
 */
function _groupadmin_settings_fields($context = FALSE) {
  static $fields;
  if ($fields)  return $fields;

  // Get possible access types.
  $roles = array_merge(array('nobody'), _groupadmin_user_has_role());

  // Array of variables of name => array: description, [default value], [required/options], [menu_rebuild_needed].
  // For fieldset: name => array: description, [collapsed], [collapsible].
  $links = array(
    // Display of admin links.
    'f_links' => array('What links should be shown where?', TRUE, TRUE),
    'x_show_on_node_page' => array('Show GroupAdmin <em>Members</em> link on node page.', TRUE, FALSE, TRUE),
    'x_show_on_members_page' => array('Show GroupAdmin <em>Members</em> link on standard <em>members</em> page.', TRUE, FALSE, TRUE),
    'x_use_standard_path' => array('Expose GroupAdmin at /og/users/[gid]. You may also need to ' .
        l('disable og_members', 'admin/build/views/disable/og_members') . ' View.', FALSE, FALSE, TRUE),
    'x_remove_standard_link' => array('Remove the standard <em>Add Members</em> link.', TRUE, FALSE, TRUE),
  );

  $options = array(
    // GroupAdmin display appearance/behaviour.
    'f_options' => array('Options for appearance and behaviour.', TRUE, TRUE),
    'n_help_node' => array('Node (nid) for help section. If not specified, help section will not be displayed.'),
    'n_member_help_node' => array('Node (nid) for help for members.  If not specified, main help node will be used.'),
    'n_admin_help_node' => array('Node (nid) for help for admins. If not specified, member help node will be used.'),
    'x_help_collapsed' => array('If set, help section initially appears collapsed.', TRUE),
    'n_pagelen' => array('Page length for user list.', 10, TRUE),
    'x_reset_on_add' => array('Clear the search criteria after adding a new member.', FALSE),
  );

  $access = array(
    // Access control.
    'f_access_control' => array('This section allows you to define access controls.  '
                              . 'Note: <em>manager</em> and <em>admin</em> here refer to Group roles and '
                              . '<em>visitor</em> means anyone who has access to view the Group node.', TRUE, TRUE),
    'l_basic_access' => array('Who is allowed basic access to <em>GroupAdmin</em>?', 4, $roles, TRUE),
    'l_show_admins' => array('Who is allowed to view/search group administrators?', 4, $roles, TRUE),
    'l_show_members' => array('Who is allowed to view/search group members?', 3, $roles, TRUE),
    'l_show_non-members' => array('Who is allowed to view/search non-members?', 2, $roles),
    'l_show_email' => array('Who is allowed to view/search email addresses?', 0, $roles),
    'l_show_real_names' => array('Who is allowed to view/search real names?', 0, $roles),
    'x_more_permissions' => array('Activate role-based permissions in conjunction with the above.', FALSE, FALSE, TRUE),
  );

  /*
  $advanced = array(
    // Advanced.
    'f_advanced' => array('<strong>NOT YET FULLY FUNCTIONAL!</strong> This section allows you to define a more flexible configuration for GroupAdmin, depending on group-type and/or individual group.'
                        . '<ul><li>Using configuration per group-type, the main configuration values will be used as defaults.</li>'
                        . '<li>Using configuration per group, the group-type and then main configuration values will be used as defaults.</li></ul>', TRUE, TRUE),
    'x_configuration_per_group_type' => array('Provide a separate configuration for each type of group, accessible via content-type edit pages. '
                        . 'Access requires <em>administer content types</em> permission.', FALSE, FALSE, TRUE),
    'x_configuration_per_group' => array('Provide a separate configuration for each individual group.', FALSE, FALSE, TRUE),
  );

  if ($context) {
    unset($access['l_basic_access']);
    unset($access['x_more_permissions']);
    $fields = array_merge($options, $access);
  }
  else {
    $fields = array_merge($links, $options, $access, $advanced);
  }
  */
  $fields = array_merge($links, $options, $access);
  // Add configuration arrays from other modules.
  $fields = array_merge($fields, _groupadmin_get_modules('config_fields'));

  return $fields;
}

/**
 * Build the config form from $fields array.
 */
function _groupadmin_settings_form_build($fields) {
  // Build the form...

  // Define skeletons for form elements.
  // Note: we use single character key, but longer keys should work too.
  $elements = array(
    'n' => array('#type'=>'textfield', '#size'=>4, '#element_validate' => array('groupadmin_validate_posint')),
    't' => array('#type'=>'textfield', '#size'=>30, '#maxlen'=>30),
    'r' => array('#type'=>'radios'),
    'l' => array('#type'=>'select'),
    'x' => array('#type'=>'checkbox'),
    's' => array('#type'=>'submit'),
    'f' => array('#type'=>'fieldset'),
  );

  // Maps - these define how elements in the $fields array relate to FAPI attributes.
  $maps = array(
    'default' => array('#description', '#default_value', '#required'),
    'select'  => array('#description', '#default_value', '#options'),
    'radio'   => array('#description', '#default_value', '#options'),
    'fieldset'=> array('#description', '#collapsed', '#collapsible'),
    'submit'=> array('#default_value'), // Not complete!
  );

  // Loop through all fields, construct form elements and add them to the form...
  foreach($fields as $key => $field) {

    // Split fieldname into components: $element['#type'] and $element['#title'].
    $element = array_combine(array('#type', '#title'), explode('_', $key, 2));
    // Captialise title and replace underscores with spaces.
    $element['#title'] = ucfirst(str_replace('_', ' ', $element['#title']));
    // Copy default structure for this type (updates #type to FAPI #type).
    $element = array_merge($element, $elements[$element['#type']]);
    $type = $element['#type'];

    // Copy values from $field to $element using the relevant $map.
    $map = $maps[$type]? $maps[$type] : $maps['default'];
    foreach($map as $n => $attribute)  $element[$attribute] = &$field[$n];

    // If processing a fieldset, position it at top level.
    if ($type == 'fieldset') {
      $form[$section_name = $key] = $element;
    }
    // Otherwise create element inside current fieldset.
    else {
      $form[$section_name][$key] = $element;
    }
  }
  //drupal_set_message(print_r($form, 1));
  return $form;
}

/**
 * Build and return the complete config form.
 */
function _groupadmin_settings_form($form_state, $context = '', $id = '') {
  //drupal_set_message(sprintf('Settings form: [%s][%s][%s]', $form_state, $context, $id));
  //drupal_set_message(sprintf('Form state: %s', print_r($form_state, 1)));

  // Get fields (with default values) for form.
  $fields = _groupadmin_settings_fields($context .= $id);

  // Get additional fields from optional module.
  $groupadmin_cp = is_callable('_groupadmin_cp_settings_fields');
  if ($groupadmin_cp) {
    $fields = _groupadmin_cp_settings_fields($fields);
  }

  // Replace default values with current values from config.
  $config = variable_get('groupadmin', array());

  if ($context) {
    foreach($config as $key => $value) {
      if (isset($fields[$key])) {
        $context_value =& $config[$context][$id][$key];
        $fields[$key][1] = isset($context_value)? $context_value : $config[$key];
      }
    }
  }
  else {
    foreach($config as $key => $value) {
      if (isset($fields[$key])) {
        $fields[$key][1] = $config[$key];
      }
    }
  }

  // Build the basic form.
  $form = _groupadmin_settings_form_build($fields);

  // Add validatation function(s) from other modules.
  $form['#validate'] = _groupadmin_get_modules('config_validate');
  $form['#validate'][] = '_groupadmin_settings_form_validate';
  // Add buttons (etc.) using system_settings_form().
  $form = system_settings_form($form);


  // We want to use *our* submit function, so remove the one put there by system_settings_from().
  unset($form['#submit']);

  return $form;
}

/**
 * Validatation.
 */
function _groupadmin_settings_form_validate($form, &$form_state) {
  $values = $form_state['values'];

  // Security check - Ensure that text entries do not contain invalid strings.
  foreach($values as $key=>$value) {
if (substr($key, 0, 2) == 't_') drupal_set_message('checking ' . $key);
    // If it's a text-entry field and value does not match escaped value, report an error.
    if (substr($key, 0, 2) == 't_' && $value != db_escape_string($value)) {
      $tvars = array('%key' => $key, '%value' => $value);
      $reason = t('Entry for %key: %value contains invalid characters.', $tvars);
      form_set_error($key, $reason);
    }
  }
  //if (form_get_errors())  return;

  // Check that nodes actually exist.
  foreach($values as $key => $value) {
    if (substr($key, -5) == '_node' && $value && !node_load($value)) {
      form_set_error($key, t('Node @nid does not exist.', array('@nid' => $value)));
    }
  }
}

/**
 * Submit function for settings form.
 * Pack values into an array, process update and rebuild menu if needed.
 */
function _groupadmin_settings_form_submit($form, &$form_state) {
  //drupal_set_message(print_r($form_state, 1), 'error');
  //drupal_set_message(print_r($form, 1), 'warning');
  //drupal_set_message(print_r($form['f_access_control'], 1), 'warning');

  // Reference form_state['values'] for use later.
  $values =& $form_state['values'];

  // Get current config (used to test if menu rebuild is needed.)
  $old_config = variable_get('groupadmin', array());

  // We could skip these steps if "Reset to defaults" was selected, but we do them anyway.
  if (TRUE) {
    // Get config $fields.
    $fields = _groupadmin_settings_fields();

    // Copy relevant $values into $new_state.
    $new_state['values']['op'] = $values['op'];
    $new_state['values']['groupadmin'] = array_intersect_key($values, $fields);
  }

  // Process via systems_settings_form_submit() so that Drupal standard messages are displayed.
  // @todo: Consider if really worth using system_settings_form.
  system_settings_form_submit($form, $new_state);

  // Reload new config from newly saved version ("Reset to defaults" may have been used.)
  $new_config = variable_get('groupadmin', array());

  // Check if menu needs to be rebuilt...
  $changes = array_diff_assoc($new_config, $old_config);
  foreach ($changes as $key => $value) {
    if ($fields[$key][3]) {
      menu_rebuild();
      drupal_set_message('The menu has been rebuilt.');
      break;
    }
  }
}

/**
 * Test if form field is an integer >= 0.
 * A value such as '1.0' is deliberately disallowed, even though mathematically valid.
 * If #required, also check that value is non-zero.
 */
function groupadmin_validate_posint($element, &$form_state, $form) {
  //drupal_set_message(print_r($elements, 1));
  $value = $element['#value'];

  if ($value !== '') {
    $name = array('!name' => sprintf('<em>%s</em>', $element['#title']));
    if (!is_numeric($value)) {
      $msg = t('!name value should be numeric.', $name);
    }
    elseif ($value == 0 && $element['#required']) {
      $msg = t('!name value should be greater than zero.', $name);
    }
    elseif (strval($value) !== strval(intval($value))) {
      $msg = t('!name value should be a whole number.', $name);
    }
    elseif ($value < 0) {
      $msg = t('!name value should not be negative.', $name);
    }

    if ($msg)  form_error($element, $msg);
  }
}
