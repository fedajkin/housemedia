<?php

/**
 * @file
 *   Form with Settings
 *
 * @version
 *
 * @developers
 *   Rafal Wieczorek <kenorb@gmail.com>
 */


/**
 * Menu callback for the settings form.
 */
function drupal_tweaks_general_settings_form() {
  module_load_include('inc', 'drupal_tweaks'); // load additional functions from included file
  drupal_tweaks_include_shared_code();

  $form['drupal_tweaks']['drupal_tweaks_give_advice'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show tips on Drupal warnings.'),
    '#description' => t('Analyse Drupal warning messages and give advice about some solutions if available.'),
    '#default_value' => variable_get('drupal_tweaks_give_advice', TRUE),
  );
  $form['drupal_tweaks']['drupal_tweaks_settings_stats_activated'] = array(
    '#type' => 'checkbox',
    '#title' => t('Send anonymous statistics about module usage through Google Analytics.'),
    '#description' => t('It will help to improve functionality of this module even better.'),
    '#default_value' => variable_get('drupal_tweaks_settings_stats_activated', FALSE),
  );

  return system_settings_form($form); 
}

