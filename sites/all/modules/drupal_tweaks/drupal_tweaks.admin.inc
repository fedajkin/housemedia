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
  if (module_exists('filter')) {
    $module_name = 'Filter';
    $form['drupal_tweaks_filter'] = array(
      '#type' => 'fieldset',
      '#title' => t('%module tweaks', array('%module' => $module_name)),
      '#description' => t('Tweaks for %module module.', array('%module' => $module_name)),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
    );
    $form['drupal_tweaks_filter']['drupal_tweaks_filter_tweak'] = array(
      '#type' => 'checkbox',
      '#title' => t('Enable tweaks for %module module.', array('%module' => $module_name)),
      '#description' => t('If selected, you will see which filter belongs to which module (Link: <a target=_blank href="!url">Filter list</a> and choose configure)', array('!url' => url('admin/settings/filters'))),
      '#default_value' => variable_get('drupal_tweaks_filter_tweak', TRUE),
    );
  }
  if (module_exists('views')) {
    $module_name = 'Views';
    $form['drupal_tweaks_views'] = array(
      '#type' => 'fieldset',
      '#title' => t('%module tweaks', array('%module' => $module_name)),
      '#description' => t('Tweaks for %module module.', array('%module' => $module_name)),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
    );
    $form['drupal_tweaks_views']['drupal_tweaks_views_tweak'] = array(
      '#type' => 'checkbox',
      '#title' => t('Enable tweaks for %module module.', array('%module' => $module_name)),
      '#description' => t('If selected, you will see which View belongs to which module (Link: <a target=_blank href="!url">Views list</a>)', array('!url' => url('admin/build/views'))),
      '#default_value' => variable_get('drupal_tweaks_views_tweak', TRUE),
    );
  }

  return system_settings_form($form); 
}

