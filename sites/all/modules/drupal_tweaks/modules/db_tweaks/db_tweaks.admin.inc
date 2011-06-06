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
function db_tweaks_settings_form() {
  global $db_type;
  $form['db_tweaks'] = array(
    '#type' => 'fieldset',
    '#title' => t('Database tweaks.'),
    '#collapsible' => TRUE,
  ); 
  $form['db_tweaks']['db_tweaks_activated'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable database tweaks.'),
    '#description' => t('Select if you want to enable above changes.'),
    '#default_value' => variable_get('db_tweaks_activated', FALSE),
  );

  global $db_type;
  switch ($db_type) {
      case 'mysql':
      case 'mysqli':
          module_load_include('inc', 'db_tweaks');
          $mysql_conf = db_tweaks_get_mysql_configuration(); // get actual settings
          if ((bool)$mysql_conf['sql_big_selects']['mysql'] !== (bool)$mysql_conf['sql_big_selects']['conf']) {
              drupal_set_message(t("Actual %variable is differ than it was set, probably you do not have proper privileges.", array('%variable' => 'SQL_BIG_SELECTS')),'error');
          }
          if ((int)$mysql_conf['max_join_size']['mysql'] !== (int)$mysql_conf['max_join_size']['conf']) {
              drupal_set_message(t("Actual %variable is differ than it was set, probably you do not have proper privileges.", array('%variable' => 'MAX_JOIN_SIZE')),'error');
          }
          if ((int)$mysql_conf['max_allowed_packet']['mysql'] !== (int)$mysql_conf['max_allowed_packet']['conf']) {
              drupal_set_message(t("Actual %variable is differ than it was set, probably you do not have proper privileges.", array('%variable' => 'MAX_ALLOWED_PACKET')),'error');
          }
          if ((int)$mysql_conf['wait_timeout']['mysql'] !== (int)$mysql_conf['wait_timeout']['conf']) {
              drupal_set_message(t("Actual %variable is differ than it was set, probably you do not have proper privileges.", array('%variable' => 'WAIT_TIMEOUT')),'error');
          }

          $sql_big_selects_description = t('Useful when an inadvisable WHERE statement has been issued.')
              .t('<br>').t('If not active, MySQL aborts SELECT statements that are likely to take a very long time to execute (that is, statements for which the optimizer estimates that the number of examined rows exceeds the value of max_join_size). This is useful when an inadvisable WHERE statement has been issued. As default value for a new connection is enabled, which allows all SELECT statements.');
          $max_join_size_description = t('Set it if your users tend to perform joins that lack a WHERE clause, that take a long time, or that return millions of rows.')
              .t('<br>').t('Do not allow SELECT statements that probably need to examine more than max_join_size rows (for single-table statements) or row combinations (for multiple-table statements) or that are likely to do more than max_join_size disk seeks. By setting this value, you can catch SELECT statements where keys are not used properly and that would probably take a long time. Set it if your users tend to perform joins that lack a WHERE clause, that take a long time, or that return millions of rows. Setting this variable to a value other than DEFAULT resets the value of sql_big_selects to 0. If you set the sql_big_selects value again, the max_join_size variable is ignored. If a query result is in the query cache, no result size check is performed, because the result has previously been computed and it does not burden the server to send it to the client.');
          $max_allowed_packet_description = t('The maximum size of one packet. Should be minimum %size MB. This value by default is small, to catch large (possibly incorrect) packets. You must increase this value if you are using large BLOB columns or long strings. It should be as big as the largest BLOB you want to use. The protocol limit for max_allowed_packet is 1GB.', array('%size' => 1));
          $sql_mode_description = t('Server SQL modes define what SQL syntax MySQL should support and what kind of data validation checks it should perform. This makes it easier to use MySQL in different environments and to use MySQL together with other database servers.')
              .t('<br>').t('If you want set as default, please leave unselected.');

          $form['db_tweaks']['mysql'] = array(
              '#type' => 'fieldset',
              '#title' => t('MySQL settings'),
              '#description' => t('You may check your actual MySQL configuration on <a href="!url">Status Report page</a> or on <a href="!url_php">MySQL Info page</a>.', array('!url' => url('admin/reports/status'), '!url_php' => url('admin/reports/status/sql'))),
              '#collapsible' => TRUE,
          ); 
          $form['db_tweaks']['mysql']['db_tweaks_mysql_sql_big_selects'] = array(
              '#type' => 'select',
              '#title' => t('Enable SQL_BIG_SELECTS value'),
              '#description' => $sql_big_selects_description,
              '#default_value' => $mysql_conf['sql_big_selects']['mysql'],
              '#options' => array('ON' => t('ON'), 'OFF' => t('OFF')),
              '#suffix' => t('Current !name is: !value', array('!name' => 'SQL_BIG_SELECTS', '!value' => (bool)$mysql_conf['sql_big_selects']['mysql'])) . ' '
                         . t('Config !name is: !value', array('!name' => 'SQL_BIG_SELECTS', '!value' => (bool)$mysql_conf['sql_big_selects']['conf'])),
          ); 
          $form['db_tweaks']['mysql']['db_tweaks_mysql_max_join_size'] = array(
              '#type' => 'textfield',
              '#title' => t('Default MAX_JOIN_SIZE value'),
              '#value' => $mysql_conf['max_join_size']['mysql'],
              '#default_value' => $mysql_conf['max_join_size']['mysql'],
              '#size' => 20,
              '#maxlength' => 20,
              '#description' => $max_join_size_description,
              '#disabled' => $mysql_conf['sql_big_selects']['mysql'] == 'ON',
              '#field_suffix' => t('joins'),
              '#suffix' => t('Current !name is: !value', array('!name' => 'MAX_JOIN_SIZE', '!value' => $mysql_conf['max_join_size']['mysql'])) . ' '
                         . t('Config !name is: !value', array('!name' => 'MAX_JOIN_SIZE', '!value' => $mysql_conf['max_join_size']['conf'])),
          ); 
          $form['db_tweaks']['mysql']['db_tweaks_mysql_max_allowed_packet'] = array(
              '#type' => 'textfield',
              '#title' => t('Default MAX_ALLOWED_PACKET value'),
              '#default_value' => $mysql_conf['max_allowed_packet']['mysql'],
              '#size' => 20,
              '#maxlength' => 20,
              '#description' => $max_allowed_packet_description,
              '#suffix' => t('Current !name is: !value', array('!name' => 'MAX_ALLOWED_PACKET', '!value' => $mysql_conf['max_allowed_packet']['mysql'])) . ' '
                         . t('Config !name is: !value', array('!name' => 'MAX_ALLOWED_PACKET', '!value' => $mysql_conf['max_allowed_packet']['conf'])),
          ); 
          $form['db_tweaks']['mysql']['db_tweaks_mysql_wait_timeout'] = array(
              '#type' => 'textfield',
              '#title' => t('Default wait_timeout value'),
              '#default_value' => $mysql_conf['wait_timeout']['mysql'],
              '#size' => 10,
              '#maxlength' => 8,
              '#description' => t('Defines the number of seconds a mysql thread waits in idle state before mysql preempts and kills it'),
              '#field_suffix' => t('sec'),
              '#suffix' => t('Current !name is: !value', array('!name' => 'wait_timeout', '!value' => $mysql_conf['wait_timeout']['mysql'])) . ' '
                         . t('Config !name is: !value', array('!name' => 'wait_timeout', '!value' => $mysql_conf['wait_timeout']['conf'])),
          ); 
          $options = db_tweaks_get_mysql_modes();
          $form['db_tweaks']['mysql']['db_tweaks_mysql_sql_mode'] = array(
              '#type' => 'select',
              '#multiple' => TRUE,
              '#title' => t('Change SQL mode'),
              '#description' => $sql_mode_description,
              '#default_value' => $mysql_conf['sql_mode']['conf'],
              '#options' => $options,
              '#suffix' => t('Current !name is: !value', array('!name' => 'SQL mode', '!value' => $mysql_conf['sql_mode']['mysql'])) . ' '
                         . t('Config !name is: !value', array('!name' => 'SQL mode', '!value' => $mysql_conf['sql_mode']['conf'])),
          ); 
      case 'pgsql':
  }
  $form['#validate'] = array('db_tweaks_settings_form_validate');

  if (!variable_get('db_tweaks_activated', FALSE)) {
    drupal_set_message(t('Please enable database tweaks to activate following settings.'), 'warning');
  }

  return system_settings_form($form); 
}
 
/**
 * Form API callback to validate the upload settings form.
 */
function db_tweaks_settings_form_validate($form, &$form_state) {
    global $db_type;
    switch ($db_type) {
        case 'mysql':
        case 'mysqli':
            module_load_include('inc', 'db_tweaks');
            $mysql_conf = db_tweaks_get_mysql_configuration(TRUE); // get mysql configuration

            // get actual variables from configuration
            $sql_big_selects = $form_state['values']['db_tweaks_mysql_sql_big_selects'];
            $max_join_size = $form_state['values']['db_tweaks_mysql_max_join_size'];
            $max_allowed_packet = parse_size($form_state['values']['db_tweaks_mysql_max_allowed_packet']);
            $wait_timeout = $form_state['values']['db_tweaks_mysql_wait_timeout'];
            $sql_mode = implode(',', $form_state['values']['db_tweaks_mysql_sql_mode']);

            // validate BIG_SELECTS
            if (!$mysql_conf['sql_big_selects']['mysql'] && empty($max_join_size)) {
                if (!is_numeric($max_join_size) || ($max_join_size <= 0)) {
                    form_set_error('mysql_max_join_size', t('The MAX_JOIN_SIZE limit must be a number and greater than zero (current size is: %size).', array('%size' => $mysql_conf['max_join_size']['mysql'])));
                } else {
                    unset($form_state['values']['mysql_max_join_size']);
                }
            }

            // validate WAIT_TIMEOUT
            if (!is_numeric($wait_timeout) || ($wait_timeout <= 0)) {
                form_set_error('db_tweaks_mysql_wait_timeout', t('The wait_timeout must be a number and greater than 0 (current timeout is: %size).', array('%size' => $mysql_conf['wait_timeout']['mysql'])));
            }

            /* validate configuration on MySQL server */
            if ($mysql_conf['sql_big_selects']['mysql'] <> $sql_big_selects) {
                if (!db_tweaks_set_mysql_variable('sql_big_selects', $sql_big_selects)) {
                  form_set_error('db_tweaks_mysql_sql_big_selects', t('Cannot change `%variable` in your database configuration! Probably you do not have proper privileges.', array('%variable' => 'sql_big_selects')));
                }
            }
            if (!$sql_big_selects && $mysql_conf['max_join_size']['mysql'] <> $max_join_size && is_numeric($max_join_size)) {
              drupal_set_message('set:'.sql_max_join_size);
                if (!db_tweaks_set_mysql_variable('sql_max_join_size', $sql_max_join_size)) {
                  form_set_error('db_tweaks_mysql_max_join_size', t('Cannot change `%variable` in your database configuration! Probably you do not have proper privileges.', array('%variable' => 'sql_max_join_size')));
                }
            }

            // validate MAX_ALLOWED_PACKET
            if (parse_size($max_allowed_packet) <= parse_size(DRUPAL_MINIMUM_MYSQL_MAX_ALLOWED_PACKET)) {
                form_set_error('db_tweaks_mysql_max_allowed_packet', t('The %name limit must be a number and greater than %min_size (current size is: %size).', array('%name' => 'MAX_ALLOWED_PACKET', '%min_size' => DRUPAL_MINIMUM_MYSQL_MAX_ALLOWED_PACKET, '%size' => $mysql_conf['max_allowed_packet']['mysql'])));
            } else if (parse_size($mysql_conf['max_allowed_packet']['mysql']) <> parse_size($max_allowed_packet)) {
                if (!db_tweaks_set_mysql_variable('max_allowed_packet', $max_allowed_packet)) {
                  form_set_error('db_tweaks_mysql_max_allowed_packet', t('Cannot change `%variable` in your database configuration! Probably you do not have proper privileges.', array('%variable' => 'max_allowed_packet')));
                }
            }

            if ($mysql_conf['wait_timeout']['mysql'] <> $wait_timeout && is_numeric($wait_timeout)) {
                if (!db_tweaks_set_mysql_variable('wait_timeout', $wait_timeout)) {
                  form_set_error('db_tweaks_mysql_wait_timeout', t('Cannot change `%variable` in your database configuration! Probably you do not have proper privileges.', array('%variable' => 'wait_timeout')));
                }
            }
            if ($mysql_conf['sql_mode']['mysql'] <> $sql_mode) {
                if (!db_tweaks_set_mysql_variable('sql_mode', $sql_mode)) {
                  form_set_error('db_tweaks_mysql_sql_mode', t('Cannot change `%variable` in your database configuration! Probably you do not have proper privileges.', array('%variable' => 'sql_mode')));
                }
            }
        case 'pgsql': ;
    }
} 

