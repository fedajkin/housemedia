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
 * Menu callback; Retrieve a JSON object containing autocomplete suggestions for modules which can be enabled or disabled
 */
function drupal_tweaks_autocomplete_modules($string = '') {
  $status = (int)(arg(3) == 'enabled_modules');
  $matches = array();
  if ($string) {
    $result = db_query_range("SELECT name, info FROM {system} WHERE type = 'module' AND status = %d AND name LIKE LOWER('%%%s%%') ORDER BY weight ASC, filename ASC", $status, $string, 0, 10);
    while ($row = db_fetch_object($result)) {
      $info = unserialize($row->info);
      $matches[$row->name] = check_plain($info['name'] . ' - ' . $info['description']);
    }
  }

  drupal_json($matches);
}

function drupal_tweaks_filter_modules($string = '')
{
  $matches = array();
  if ($string) {
    $result = db_query_range("SELECT name, info FROM {system} WHERE type = 'module'", 0, 10000);
    while ($row = db_fetch_object($result)) {
      $info = unserialize($row->info);
      if( !(strpos(strtolower($info['name']), strtolower($string)) === false) )
        $matches[] = check_plain($row->name);
    }
  }
  
  drupal_json($matches);
}

/**
 * Menu callback; Retrieve a JSON object containing autocomplete suggestions for nodes
 */
function drupal_tweaks_autocomplete_nodes($string = '') {
  $matches = array();
  if ($string) {
    $result = db_query_range("SELECT nid, title FROM {node} WHERE title LIKE LOWER('%%%s%%') ORDER BY changed ASC", $string, 0, 10);
    while ($row = db_fetch_object($result)) {
      $matches[base_path() . 'node/' . $row->nid] = check_plain($row->nid . ': ' . $row->title);
    }
  }

  drupal_json($matches);
}

/**
 * Menu callback; Retrieve a JSON object containing autocomplete suggestions for existing users.
 */
function drupal_tweaks_autocomplete_users($string = '') {
  $matches = array();
  if ($string) {
    $result = db_query_range("SELECT uid, name FROM {users} WHERE LOWER(name) LIKE LOWER('%s%%')", $string, 0, 10);
    while ($user = db_fetch_object($result)) {
      $matches[base_path() . 'user/' . $user->uid] = check_plain($user->uid . ': ' . $user->name);
    }
  }

  drupal_json($matches);
}

/**
 * Menu callback; Retrieve a JSON object containing autocomplete suggestions for form_ids
 */
function drupal_tweaks_autocomplete_form_id($string = '') {
  $menu_items = module_invoke_all('menu');
  foreach ($menu_items as $path => $item) {
    if ($item['page callback'] == 'drupal_get_form') {
      if (strpos($path, $string) !== FALSE || strpos($item["page arguments"][0], $string) !== FALSE) {
        $form_id = $item["page arguments"][0];
        $form_callbacks[$form_id] = "$form_id ($path)";
      }
    }
  }
  drupal_json($form_callbacks);
}

