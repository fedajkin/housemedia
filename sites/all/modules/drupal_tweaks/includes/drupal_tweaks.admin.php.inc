<?php

/**
 * @file
 *   Form with PHP Settings
 *
 * @version
 *
 * @developers
 *   Rafal Wieczorek <kenorb@gmail.com>
 */


/**
 * Menu callback for the settings form.
 */
function drupal_tweaks_php_settings_form() {
  module_load_include('inc', 'drupal_tweaks'); // load additional functions from included file
  drupal_tweaks_include_shared_code();

  $php_conf = drupal_tweaks_get_php_configuration(); // get actual settings
  if ((bool)$php_conf['memory_limit']['php'] !== (bool)$php_conf['memory_limit']['conf']) {
      drupal_set_message(t("Actual %variable is differ than it was set, probably you do not have proper privileges.", array('%variable' => 'memory_limit')),'error');
  }
  if ((int)$php_conf['max_execution_time']['php'] !== (int)$php_conf['max_execution_time']['conf']) {
      drupal_set_message(t("Actual %variable is differ than it was set, probably you do not have proper privileges.", array('%variable' => 'max_execution_time')),'error');
  }

  $form['php'] = array(
      '#type' => 'fieldset',
      '#title' => t('PHP settings'),
      '#description' => t('You may check your actual PHP configuration on <a href="!url">Status Report page</a> or on <a href="!url_php">PHP Info page</a>.', array('!url' => url('admin/reports/status'), '!url_php' => url('admin/reports/status/php'))),
      '#collapsible' => TRUE,
  ); 
  $form['php']['drupal_tweaks_php_activated'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable PHP tweaks.'),
    '#description' => t('Select if you want to enable above changes.'),
    '#default_value' => variable_get('drupal_tweaks_php_activated', FALSE),
  );
  $form['php']['drupal_tweaks_override_lesser'] = array(
    '#type' => 'checkbox',
    '#title' => t('Allow to override current settings with lesser values.'),
    '#description' => t('Select if you want to override current settings with lesser values. Activate only if you are know what you are doing.'),
    '#default_value' => variable_get('drupal_tweaks_override_lesser', FALSE),
  );
  $form['php']['drupal_tweaks_php_memory_limit'] = array(
      '#type' => 'textfield',
      '#title' => t('Default PHP memory limit (memory_limit)'),
      '#default_value' => $php_conf['memory_limit']['php'],
      '#size' => 20,
      '#maxlength' => 20,
      '#description' => t('Maximum memory limit. Some hosting providers could not allow you to change that. Examples: 20M, 128M'),
      '#suffix' => t('Current !name is: !size', array('!name' => 'memory_limit', '!size' => $php_conf['memory_limit']['php'])) . ' '
                 . t('Config !name is: !size', array('!name' => 'memory_limit', '!size' => $php_conf['memory_limit']['org'])),
  ); 
  $form['php']['drupal_tweaks_php_max_execution_time'] = array(
      '#type' => 'textfield',
      '#title' => t('Default maximum execution time for php scripts (max_execution_time)'),
      '#default_value' => $php_conf['max_execution_time']['php'],
      '#size' => 10,
      '#maxlength' => 8,
      '#description' => t('For how long PHP script should be executed, before it will be terminated. You can not change this setting with ini_set() when running in safe mode.'),
      '#field_suffix' => t('sec'),
      '#suffix' => t('Current !name is: !size', array('!name' => 'max_execution_time', '!size' => $php_conf['max_execution_time']['php'])) . ' '
                 . t('Config !name is: !size', array('!name' => 'max_execution_time', '!size' => $php_conf['max_execution_time']['org'])),
  ); 

  if (!variable_get('drupal_tweaks_php_activated', FALSE)) {
    drupal_set_message(t('Please enable PHP tweaks to activate following settings.'), 'warning');
  }

  $form['#validate'] = array('drupal_tweaks_php_settings_form_validate');

  return system_settings_form($form); 
}
 
/**
 * Form API callback to validate the upload settings form.
 */
function drupal_tweaks_php_settings_form_validate($form, &$form_state) {
  module_load_include('inc', 'drupal_tweaks');
  $php_conf = drupal_tweaks_get_php_configuration(TRUE); // get db configuration

  // get actual variables from configuration
  $max_execution_time = $php_conf['max_execution_time']['conf'] = $form_state['values']['drupal_tweaks_php_max_execution_time'];
  $memory_limit = $php_conf['memory_limit']['conf'] = $form_state['values']['drupal_tweaks_php_memory_limit'];

  // validate PHP memory_limit
  if (!is_numeric(parse_size($memory_limit)) && parse_size($memory_limit) <= 0) {
      form_set_error('drupal_tweaks_php_memory_limit', t('The PHP memory_limit limit must be a number and greater than 0 (current limit is: %size).', array('%size' => $php_conf['memory_limit']['php'])));
  } else if (parse_size($memory_limit) < parse_size(DRUPAL_MINIMUM_PHP_MEMORY_LIMIT)) {
      form_set_error('drupal_tweaks_php_memory_limit', t('To prevent breaking your website, it is strictly recommended that PHP memory_limit should be greater than %min_memory_limit (current limit is: %size).', array('%size' => $php_conf['memory_limit']['php'], '%min_memory_limit' => DRUPAL_MINIMUM_PHP_MEMORY_LIMIT)));
  } else if (!variable_get('drupal_tweaks_override_lesser', FALSE) && (int)$memory_limit < $php_conf['memory_limit']['org']) {
      form_set_error('drupal_tweaks_php_memory_limit', t('Can\'t override %name variable with lesser value of %user_size (config value: %size).', array('%size' => $php_conf['memory_limit']['org'], '%user_size' => $memory_limit, '%name' => 'memory_limit')));
  }

  // validate PHP max_execution_time
  if (!is_numeric($max_execution_time) || ($max_execution_time <= 0)) {
      form_set_error('drupal_tweaks_php_max_execution_time', t('The max_execution_time must be a number and greater than 0 (current timeout is: %size).', array('%size' => $php_conf['max_execution_time']['php'])));
  } else if ((int)$max_execution_time < (int)DRUPAL_MINIMUM_MAX_EXECUTION_TIME) {
      form_set_error('drupal_tweaks_php_max_execution_time', t('To prevent breaking your website, it is strictly recommended that PHP max_execution_time should be greater than %min_max_execution_time (current limit is: %size).', array('%size' => $php_conf['max_execution_time']['php'], '%min_max_execution_time' => DRUPAL_MINIMUM_PHP_MEMORY_LIMIT)));
  } else if (!variable_get('drupal_tweaks_override_lesser', FALSE) && (int)$max_execution_time < $php_conf['max_execution_time']['org']) {
      form_set_error('drupal_tweaks_php_max_execution_time', t('Can\'t override %name variable with lesser value of %user_size (config value: %size).', array('%size' => $php_conf['max_execution_time']['org'], '%user_size' => $max_execution_time, '%name' => 'max_execution_time')));
  }
  if (!form_get_errors()) {
    /* validate PHP */
    foreach ($php_conf as $var_name => $var_values) {
        // update php settings if necessary
        if ($var_values['conf'] <> $var_values['php']) {
            if (!ini_set($var_name, parse_size($var_values['conf']))) {
              form_set_error('drupal_tweaks_php_' . $var_name, t('Cannot set variable `%variable` to `%value` in your PHP configuration!', array('%variable' => $var_name, '%value' => $var_values['conf'])). t('<br>') . t('Probably you do not have proper privileges.'), 'error');
              variable_set('drupal_tweaks_php_' . $var_name, $var_values['php']); // reverting changes in settings (to prevent showing error message)
            }
        }
    }
  }
}

