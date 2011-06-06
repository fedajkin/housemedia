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
 * Menu callback for the settings operation form
 */
function drupal_tweaks_op_form() {
  module_load_include('inc', 'drupal_tweaks'); // load additional functions from included file
  drupal_tweaks_include_shared_code();

  $form['drupal_tweaks'] = array(
    '#type' => 'fieldset',
    '#title' => t('All rebuild and flush operations in one place'),
    '#collapsible' => TRUE,
  ); 

  $form['drupal_tweaks']['all_cache'] = array(
    '#type' => 'fieldset',
    '#title' => t('All Caches'),
    '#description' => t('Clear all caches and rebuild the permissions.'),
    '#collapsible' => TRUE,
  ); 
  $form['drupal_tweaks']['all_cache']['clear_cache'] = array(
    '#type' => 'submit',
    '#value' => t('Clear cached data and rebuild the permissions'),
    '#submit' => array('drupal_tweaks_clear_all_caches'),
  );

  $form['drupal_tweaks']['cache'] = array(
    '#type' => 'fieldset',
    '#title' => t('Cache'),
    '#description' => t('Caching data improves performance, but may cause problems while troubleshooting new modules, themes, or translations, if outdated information has been cached. To refresh all cached data on your site, click the button below. <em>Warning: high-traffic sites will experience performance slowdowns while cached data is rebuilt.</em>'),
    '#collapsible' => TRUE,
  ); 
  $form['drupal_tweaks']['cache']['clear_cache'] = array(
    '#type' => 'submit',
    '#value' => t('Clear cached data'),
    '#submit' => array('drupal_tweaks_clear_cache_submit'),
    '#suffix' => print_r(drupal_tweaks_db_tables('cache%%', 'SELECT COUNT(*) FROM {}'),true), /* FIXME: any better format? */
  );

  if (module_exists('views')) {
    $form['drupal_tweaks']['cache_views'] = array(
      '#type' => 'fieldset',
      '#title' => t('Views Cache'),
      '#description' => t('Views caches data about tables, modules and views available. By checking this box, Views caches will be rebuild.'),
      '#collapsible' => TRUE,
    ); 
    $form['drupal_tweaks']['cache_views']['clear_cache'] = array(
      '#type' => 'submit',
      '#value' => t('Clear Views data'),
      '#submit' => array('drupal_tweaks_clear_views_cache_submit'),
      '#suffix' => print_r(drupal_tweaks_db_tables('cache_views%%', 'SELECT COUNT(*) FROM {}'),true), /* FIXME: any better format? */
    );
  }

  $form['drupal_tweaks']['perm'] = array(
    '#type' => 'fieldset',
    '#title' => t('Permissions'),
    '#description' => t('If the site is experiencing problems with permissions to content, you may have to rebuild the permissions cache. Possible causes for permission problems are disabling modules or configuration changes to permissions. Rebuilding will remove all privileges to posts, and replace them with permissions based on the current modules and settings.'),
    '#collapsible' => TRUE,
  ); 

  $form['drupal_tweaks']['perm']['perm_rebuild'] = array(
    '#type' => 'submit',
    '#value' => t('Rebuild permissions'),
    '#submit' => array('drupal_tweaks_rebuild_perm_confirm_submit'),
    '#suffix' => print_r(drupal_tweaks_get_perm_details(), true), /* FIXME: any better format? */
  ); 

  $form['drupal_tweaks']['cron'] = array(
    '#type' => 'fieldset',
    '#title' => t('Cron'),
    '#description' => t('Cron operations'),
    '#collapsible' => TRUE,
  ); 

  $cron_semaphore = variable_get('cron_semaphore', FALSE);
  $form['drupal_tweaks']['cron']['release_semaphore'] = array(
    '#type' => 'submit',
    '#value' => t('Release cron semaphore'),
    '#description' => t('Use this option if you experiencing problems with cron.'),
    '#submit' => array('drupal_tweaks_release_cron_semaphore_submit'),
    '#suffix' =>  $cron_semaphore ? sprintf(t('Cron run on %s'), date('r', $cron_semaphore)) : t('No problems detected with cron semaphore.'),
    '#disabled' => !$cron_semaphore,
  );

  drupal_tweaks_op_cache_messages(); // Defined in drupal_tweaks.inc

  return system_settings_form($form); 
}

/**
 * Menu callback: confirm rebuilding of permissions.
 */
function drupal_tweaks_rebuild_perm_confirm() {
  return confirm_form(array(), t('Are you sure you want to rebuild the permissions on site content?'),
          'admin/drupal_tweaks/op', t('This action rebuilds all permissions on site content, and may be a lengthy process. This action cannot be undone.'), t('Rebuild permissions'), t('Cancel'));
}

/**
 * Handler for wipe confirmation
 */
function drupal_tweaks_rebuild_perm_confirm_submit($form, &$form_state) {
  node_access_rebuild(TRUE); // rebuild node permissions
  drupal_set_message(t('Content permissions have been rebuilt.'));
  $form_state['redirect'] = 'admin/drupal_tweaks/op';
}

/**
 * Submit callback; clear system caches.
 *
 * @ingroup forms
 */
function drupal_tweaks_clear_cache_submit($form, &$form_state = array()) {
  drupal_flush_all_caches();
  drupal_set_message(t('Caches has been cleared.'));
  $form_state['redirect'] = 'admin/drupal_tweaks/op';
  drupal_goto($form_state['redirect']);
}

/**
 * Submit callback; clear Views caches.
 *
 * @ingroup forms
 */
function drupal_tweaks_clear_views_cache_submit($form, &$form_state = array()) {
  views_invalidate_cache();
  drupal_set_message(t('Views caches has been cleared.'));
  $form_state['redirect'] = 'admin/drupal_tweaks/op';
  drupal_goto($form_state['redirect']);
}

/**
 * Submit callback; clear system caches.
 *
 * @ingroup forms
 */
function drupal_tweaks_release_cron_semaphore_submit($form, &$form_state = array()) {
  variable_del('cron_semaphore');
  drupal_set_message(t('Cron semaphore cleared.'));
  $form_state['redirect'] = 'admin/drupal_tweaks/op';
  drupal_goto($form_state['redirect']);
}

/**
 * Submit callback; clear system caches.
 *
 * @ingroup forms
 */
function drupal_tweaks_clear_all_caches($form, &$form_state = array()) {
  drupal_flush_all_caches();
  node_access_rebuild(TRUE); // rebuild node permissions
  drupal_set_message(t('All caches has been cleared.'));
  $form_state['redirect'] = 'admin/drupal_tweaks/op';
  drupal_goto($form_state['redirect']);
}

/**
 * Get a list of tables in the db. Make additional operation for each of it if necessary.
 */
function drupal_tweaks_db_tables($which = '*', $op = NULL) {
  global $db_type;
  $res = array();
  switch ($db_type) {
      case 'mysql':
      case 'mysqli':
        // get auto_increment values and names of all tables
        $query = "show tables" . ($which != '*' ? " LIKE '%s'" : '');
        $tables = db_query($query, $which);
        while ($table = db_fetch_array($tables)) {
          $tname = current($table);
          $res[$tname] = $op ? db_result(db_query(str_replace('{}', "{{$tname}}", $op))) : $tname;
        }
      case 'pgsql':
      default:
        /* TODO: database not supported */
    }
  return $res;
}

/**
 * Get a list of tables in the db. Make additional operation for each of it if necessary.
 */
function drupal_tweaks_get_perm_details($which = '*', $op = NULL) {
  $res = array();
  if ($db_res = db_query('SELECT realm, COUNT(*) FROM {node_access} GROUP BY realm')) {
    while ($row = db_fetch_array($db_res)) {
      $res[current($row)] = next($row);
    }
  }
  return $res;
}

