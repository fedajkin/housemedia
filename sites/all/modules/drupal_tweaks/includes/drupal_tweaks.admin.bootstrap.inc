<?php

/**
 * @file
 *   Bootstrap settings file
 *
 * @version
 *
 * @developers:
 *    Rafal Wieczorek <kenorb@gmail.com>
 */

/**
 * Menu callback for the settings form.
 */
function drupal_tweaks_bootstrap_form() {
  module_load_include('inc', 'drupal_tweaks'); // load additional functions from included file
  drupal_tweaks_include_shared_code();

  $form['drupal_tweaks_bootstrap'] = array(
    '#type' => 'fieldset',
    '#title' => t('Bootstrap PHP code'),
    '#description' => t('Bootstrap operations'),
  ); 

  $form['drupal_tweaks_bootstrap']['drupal_tweaks_bootstrap_code_activated'] = array(
    '#type' => 'checkbox',
    '#title' => t('Activate bootstrap code.'),
    '#description' => t('Select if you want to activate below bootstrap code.'),
    '#default_value' => variable_get('drupal_tweaks_bootstrap_code_activated', FALSE),
  );

  $form['drupal_tweaks_bootstrap']['drupal_tweaks_bootstrap_code'] = array(
    '#type' => 'textarea',
    '#title' => t('You can type here some PHP code which will be executed during Drupal bootstrap.'),
    '#cols' => 60,
    '#rows' => 5,
    '#default_value' => variable_get('drupal_tweaks_bootstrap_code', ''),
    '#description' => t('Enter PHP code which will be executed on Drupal bootstrap.'), // Variables which are not supported: $db_url, $db_prefix, $base_url
    '#wysiwyg' => FALSE,
  );

  if (!variable_get('drupal_tweaks_bootstrap_code_activated', FALSE)) {
    drupal_set_message(t('Please enable bootstrap code to apply it on your website.'), 'warning');
  }

  $form['#validate'] = array('drupal_tweaks_bootstrap_form_validate');

  return system_settings_form($form); 
}

/**
 * Form API callback to validate the settings form.
 */
function drupal_tweaks_bootstrap_form_validate($form, &$form_state) {
  $values = &$form_state['values'];

  $code = $values['drupal_tweaks_bootstrap_code'];
  if (@!eval('return true;' . $code)) {
    form_set_error('drupal_tweaks_bootstrap_code', t('PHP syntax error! Validate your syntax!')); // show syntax error
  }
} 

