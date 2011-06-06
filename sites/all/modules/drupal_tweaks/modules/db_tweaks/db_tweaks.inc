<?php

/**
 * @file
 *   Include file
 *
 * @version
 *
 * @developers
 *   Rafal Wieczorek <kenorb@gmail.com>
 */

/**
 * Get MySQL configuration
 */
function db_tweaks_get_mysql_configuration($raw = FALSE) {
    $mysql_conf = array();
    // get actual variables from database
    $mysql_conf['sql_big_selects']['mysql'] = (int)db_tweaks_get_mysql_variable('sql_big_selects');
    $mysql_conf['max_join_size']['mysql'] = (int)db_tweaks_get_mysql_variable('max_join_size');
    $mysql_conf['max_allowed_packet']['mysql'] = (int)db_tweaks_get_mysql_variable('max_allowed_packet');
    $mysql_conf['wait_timeout']['mysql'] = (int)db_tweaks_get_mysql_variable('wait_timeout');
    $mysql_conf['sql_mode']['mysql'] = db_tweaks_get_mysql_variable('sql_mode');

    // get actual variables from configuration
    $mysql_conf['sql_big_selects']['conf'] = variable_get('db_tweaks_mysql_sql_big_selects', $mysql_conf['sql_big_selects']['mysql']);
    $mysql_conf['max_join_size']['conf'] = variable_get('db_tweaks_mysql_max_join_size', $mysql_conf['max_join_size']['mysql']);
    $mysql_conf['max_allowed_packet']['conf'] = variable_get('db_tweaks_mysql_max_allowed_packet', (int)format_size($mysql_conf['max_allowed_packet']['mysql']));
    $mysql_conf['wait_timeout']['conf'] = variable_get('db_tweaks_mysql_wait_timeout', $mysql_conf['wait_timeout']['mysql']);
    $mysql_conf['sql_mode']['conf'] = implode(',', variable_get('db_tweaks_mysql_sql_mode', array()));
    if ($raw) {
      $mysql_conf['max_allowed_packet']['conf']  = parse_size($mysql_conf['max_allowed_packet']['conf']);
    } else { // if not set to RAW, then convert numbers to human format
      $mysql_conf['max_allowed_packet']['mysql'] = format_size($mysql_conf['max_allowed_packet']['mysql'], $langcode = NULL);
    }
    return $mysql_conf;
}

/**
 * Return MySQL variable
 */
function db_tweaks_get_mysql_variable($variable_name, $type = 'SESSION') {
    return db_result(db_query('SELECT @@%s.%s', $type, $variable_name));
}

/**
 * Set MySQL variable
 */
function db_tweaks_set_mysql_variable($variable_name, $value, $type = 'SESSION') {
    if (is_numeric($value)) {
        return db_query('SET %s %s = %d', $type, $variable_name, $value);
    } else {
        return db_query('SET %s %s = "%s"', $type, $variable_name, $value);
    }
}

/**
 * Get MySQL sql_modes
 */
function db_tweaks_get_mysql_modes() {
  return drupal_map_assoc(array(
    'ANSI',
    'STRICT_TRANS_TABLES',
    'TRADITIONAL',
    'ALLOW_INVALID_DATES',
    'ANSI_QUOTES',
    'ERROR_FOR_DIVISION_BY_ZERO',
    'HIGH_NOT_PRECEDENCE',
    'IGNORE_SPACE',
    'NO_AUTO_CREATE_USER',
    'NO_AUTO_VALUE_ON_ZERO',
    'NO_BACKSLASH_ESCAPES ',
    'NO_DIR_IN_CREATE',
    'NO_ENGINE_SUBSTITUTION',
    'NO_FIELD_OPTIONS',
    'NO_KEY_OPTIONS',
    'NO_TABLE_OPTIONS',
    'NO_UNSIGNED_SUBTRACTION',
    'NO_ZERO_DATE',
    'NO_ZERO_IN_DATE',
    'ONLY_FULL_GROUP_BY',
    'PIPES_AS_CONCAT',
    'REAL_AS_FLOAT',
    'STRICT_ALL_TABLES',
    'DB2',
    'MAXDB',
    'MSSQL',
    'MYSQL323',
    'MYSQL40',
    'ORACLE',
    'POSTGRESQL'
  ));
}

