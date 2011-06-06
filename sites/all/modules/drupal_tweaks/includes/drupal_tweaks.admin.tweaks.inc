<?php

/**
 * @file
 *   Settings Page for module tweaks
 *
 * @version
 *
 * @developers
 *   Rafal Wieczorek <kenorb@gmail.com>
 */


/**
 * Menu callback for the settings form.
 */
function drupal_tweaks_general_tweaks_form() {
  module_load_include('inc', 'drupal_tweaks'); // load additional functions from included file
  drupal_tweaks_include_shared_code();

  $form['drupal_tweaks_dev'] = array(
    '#type' => 'fieldset',
    '#title' => t('Development tweaks'),
    '#description' => t('Tweaks which help you to diagnose common problems with your website.'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['drupal_tweaks_dev']['drupal_tweaks_backtrace_php_show'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show backtrace on PHP errors.'),
    '#description' => t('Show backtrace under Drupal error messages. It will help you to diagnose what\'s the reason of the error.'),
    '#default_value' => variable_get('drupal_tweaks_backtrace_php_show', FALSE),
  );

  $form['drupal_tweaks_dev']['drupal_tweaks_backtrace_php_log'] = array(
    '#type' => 'checkbox',
    '#title' => t('Log backtrace on PHP errors.'),
    '#description' => t('Log backtrace on Drupal error messages. (<a href="!url">Recent log entries</a>)', array('!url' => url('admin/reports/dblog'))),
    '#default_value' => variable_get('drupal_tweaks_backtrace_php_log', TRUE),
  );

  $form['drupal_tweaks_dev']['drupal_tweaks_backtrace_error_pages_show'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show backtrace on Drupal error pages.'),
    '#description' => t('Show backtrace under on Drupal error pages (like Permission Denied or Page Not Found page). It will help you to diagnose what\'s the reason of the error.'),
    '#default_value' => variable_get('drupal_tweaks_backtrace_error_pages_show', FALSE),
  );

  $form['drupal_tweaks_dev']['drupal_tweaks_backtrace_error_pages_log'] = array(
    '#type' => 'checkbox',
    '#title' => t('Log backtrace on Drupal error pages.'),
    '#description' => t('Log backtrace on Drupal error pages (like Permission Denied or Page Not Found page). (<a href="!url">Recent log entries</a>)', array('!url' => url('admin/reports/dblog'))),
    '#default_value' => variable_get('drupal_tweaks_backtrace_error_pages_log', FALSE),
  );

  $form['drupal_tweaks_dev']['drupal_tweaks_msgs'] = array(
    '#type' => 'fieldset',
    '#title' => t('Debug Drupal messages'),
    '#description' => t('Note that those options are probably useless, all backtraces pointing to the same place, where message is rendered.'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  foreach (array('error', 'warning', 'status') as $msg_type) {
    $form['drupal_tweaks_dev']['drupal_tweaks_msgs']['drupal_tweaks_backtrace_on_msg_' . $msg_type] = array(
      '#type' => 'checkbox',
      '#title' => t('Show backtrace on every Drupal %type message.', array('%type' => t($msg_type))),
      '#description' => t('Show backtrace above every Drupal %type messages (BEWARE of performance slowdown! - use only for debugging purposes). If disabled, make sure that <i>Message tweaks</i> option is enabled.', array('%type' => t($msg_type))),
      '#default_value' => variable_get('drupal_tweaks_backtrace_on_msg_' . $msg_type, FALSE),
      '#disabled' => !variable_get('drupal_tweaks_msg2log_activated', FALSE),
    );

    $form['drupal_tweaks_dev']['drupal_tweaks_msgs']['drupal_tweaks_backtrace_log_on_msg_' . $msg_type] = array(
      '#type' => 'checkbox',
      '#title' => t('Log backtrace on every Drupal %type message.', array('%type' => t($msg_type))),
      '#description' => t('Log backtrace on Drupal %type messages. If disabled, make sure that <i>Message tweaks</i> option is enabled. (<a href="!url">Recent log entries</a>)', array('!url' => url('admin/reports/dblog'), '%type' => $msg_type)),
      '#default_value' => variable_get('drupal_tweaks_backtrace_log_on_msg_' . $msg_type, FALSE),
      '#disabled' => !variable_get('drupal_tweaks_msg2log_activated', FALSE),
    );
  }

/* TODO: Finish drupal_tweaks_show_backtrace()
  $form['drupal_tweaks_dev']['drupal_tweaks_backtrace_any_pages_show'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show backtrace on every Drupal message.'),
    '#description' => t('Show backtrace above every Drupal message (BEWARE of performance slowdown! - use only for debugging purposes).'),
    '#default_value' => variable_get('drupal_tweaks_backtrace_any_pages_show', FALSE),
  );

  $form['drupal_tweaks_dev']['drupal_tweaks_backtrace_any_pages_log'] = array(
    '#type' => 'checkbox',
    '#title' => t('Log backtrace on every Drupal message.'),
    '#description' => t('Log backtrace on every Drupal message (BEWARE of performance slowdown! - use only for debugging purposes). (Link: <a href="!url">Recent log entries</a>)', array('!url' => url('admin/reports/dblog'))),
    '#default_value' => variable_get('drupal_tweaks_backtrace_any_pages_log', FALSE),
  );
*/

  $form['drupal_tweaks_dev']['drupal_tweaks_backtrace_adv'] = array(
    '#type' => 'fieldset',
    '#title' => t('Advanced development settings'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['drupal_tweaks_dev']['drupal_tweaks_backtrace_adv']['drupal_tweaks_backtrace_log_arg_max_length'] = array(
    '#type' => 'textfield',
    '#title' => t('Maximum length of function arguments in backtrace'),
    '#description' => t('If you want to debug website and check which arguments has been passed into function, try to increase it. Set 0 for unlimited length.'),
    '#default_value' => variable_get('drupal_tweaks_backtrace_log_arg_max_length', 100),
    '#disabled' => !(variable_get('drupal_tweaks_backtrace_php_show', TRUE) || variable_get('drupal_tweaks_backtrace_error_pages_show', FALSE)),
    '#size' => 5,
  );

  $form['drupal_tweaks_dev']['drupal_tweaks_backtrace_adv']['drupal_tweaks_backtrace_log_arg_max_length_log'] = array(
    '#type' => 'textfield',
    '#title' => t('Maximum length of function arguments in backtrace log'),
    '#description' => t('Set 0 for unlimited length.'),
    '#default_value' => variable_get('drupal_tweaks_backtrace_log_arg_max_length_log', 0),
    '#disabled' => !(variable_get('drupal_tweaks_backtrace_php_log', TRUE) || variable_get('drupal_tweaks_backtrace_error_pages_log', FALSE)),
    '#size' => 5,
  );

  $form['drupal_tweaks_modules'] = array(
    '#type' => 'fieldset',
    '#title' => t('Module tweaks'),
    '#description' => t('Tweaks for modules.'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  /*
  $module_name = 'filter';
  $form['drupal_tweaks_modules']['drupal_tweaks_' . strtolower($module_name)] = array(
    '#type' => 'fieldset',
    '#title' => t('%module tweaks', array('%module' => $module_name)),
    '#description' => t('Tweaks for %module module.', array('%module' => $module_name)),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#disabled' => !module_exists($module_name),
  );
  $form['drupal_tweaks_modules']['drupal_tweaks_filter']['drupal_tweaks_filter_tweak'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable tweaks for %module module.', array('%module' => $module_name)),
    '#description' => t('If selected, you will see which filter belongs to which module (Link: <a target=_blank href="!url">Filter list</a> and choose configure)', array('!url' => url('admin/settings/filters'))),
    '#default_value' => variable_get('drupal_tweaks_filter_tweak', module_exists('filter')),
    '#disabled' => !module_exists('filter'),
  );

  $module_name = 'views';
  $module_desc = t('If selected, you will see which View belongs to which module (Link: <a target=_blank href="!url">Views list</a>)', array('!url' => url('admin/build/views')));
  $form['drupal_tweaks_modules']['drupal_tweaks_' . strtolower($module_name)] = array(
    '#type' => 'fieldset',
    '#title' => t('%module tweaks', array('%module' => $module_name)),
    '#description' => t('Tweaks for %module module.', array('%module' => $module_name)),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#disabled' => !module_exists($module_name),
  );
  $form['drupal_tweaks_modules']['drupal_tweaks_' . strtolower($module_name)]['drupal_tweaks_' . strtolower($module_name) . '_tweak'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable tweaks for %module module.', array('%module' => $module_name)),
    '#description' => $module_desc,
    '#default_value' => variable_get('drupal_tweaks_' . strtolower($module_name) . '_tweak', module_exists($module_nam)),
    '#disabled' => !module_exists($module_name),
  );
*/

  foreach (array(
    'filter' => 'admin/settings/filters', 
    'block' => 'admin/build/block', 
    'views' => 'admin/build/views',
      ) as $module_name => $module_path) {
    $module_desc = t('If selected, you will see which %module belongs to which module (List: <a target=_blank href="!url">%module list</a>)', array('%module' => $module_name, '!url' => url($module_path)));
    $form['drupal_tweaks_modules']['drupal_tweaks_' . $module_name] = array(
      '#type' => 'fieldset',
      '#title' => t('%module tweaks', array('%module' => ucfirst($module_name))),
      '#description' => t('Tweaks for %module module.', array('%module' => ucfirst($module_name))),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
      '#disabled' => !module_exists($module_name),
    );
    $form['drupal_tweaks_modules']['drupal_tweaks_' . strtolower($module_name)]['drupal_tweaks_' . $module_name . '_tweak'] = array(
      '#type' => 'checkbox',
      '#title' => t('Enable tweaks for %module module.', array('%module' => ucfirst($module_name))),
      '#description' => $module_desc,
      '#default_value' => variable_get('drupal_tweaks_' . $module_name . '_tweak', module_exists($module_name)),
      '#disabled' => !module_exists($module_name),
    );
  }

  return system_settings_form($form); 
}

