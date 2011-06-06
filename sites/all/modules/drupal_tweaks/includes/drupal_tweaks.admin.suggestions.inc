<?php

/**
 * @file
 *   Form with Report Settings
 *
 * @version
 *
 * @developers
 *   Rafal Wieczorek <kenorb@gmail.com>
 */

/**
 * Menu callback for the error reporting form
 */
function drupal_tweaks_report_form() {
  module_load_include('inc', 'drupal_tweaks'); // load additional functions from included file
  drupal_tweaks_include_shared_code();

  $no_problems = TRUE;
  /* CHECK FOR MENU_ROUTER TABLE IF NEEDS TO BE REBUILD */
  $no_problems = $no_problems && drupal_tweaks_op_cache_messages(); // Defined in drupal_tweaks.inc

  /* FIXME: Checking new updates */
  /*
  require_once './includes/install.inc';
  $modules = drupal_get_installed_schema_version(NULL, FALSE, TRUE);
  foreach ($modules as $module => $schema_version) {
    if ($updates = drupal_get_schema_versions($module)) {
      foreach (array_keys($updates) as $update) {
        if ($update > $schema_version) {
          $no_problems = $no_problems && drupal_set_message(t('New updates available for %module module.', array('%module' => $module)));
          break;
        }
      }
    }
  }
   */

  /* CHECK FOR DUPLICATED AND MISSING MODULES */
  $issues = drupal_tweaks_report_module_issues();
  $no_problems = $no_problems && empty($issues);

  /* CHECK PHP MEMORY */
  if (!drupal_tweaks_report_check_memory()) {
    $no_problems = !drupal_set_message(t('You should consider to increase your PHP memory limit to prevent crashes of your websites. Limit: %limit; Current usage: %current', array('%limit' => ini_get("memory_limit"), '%current' =>  round(memory_get_usage()/1024/1024).'M')), 'warning');
  }


  if ($no_problems) {
    drupal_set_message(t('No issues detected.'));
  }
  return $form;
}

