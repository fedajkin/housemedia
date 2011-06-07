<?php

// $Id: groupadmin.menu.inc.php,v 1.1.2.2 2010/03/14 18:49:52 netgenius Exp $

/********************************************************
Original development by: netgenius.co.uk
Commercial support is available from www.netgenius.co.uk
Contact: drupal(a)netgenius.co.uk
*********************************************************/

/**
 * Implementation of hook_menu().
 */
function groupadmin_menu() {
  // NB: Remember, titles and descriptions should NOT be wrapped in t().

  // Module configuration page.
  $items['admin/og/groupadmin'] = array(
    'title' => 'Group Admin configuration',
    'access callback' => '_groupadmin_user_access',
    'access arguments' => array('ga-admin'),
    'description' => 'Configure the <em>Group Admin</em> module.',
    'page callback' => 'drupal_get_form',
    'page arguments' => array('_groupadmin_settings_form'),
  );

  // If enabled, extra configuration by group-type.
  if(_groupadmin_settings('x_configuration_per_group_type')) {
    // Add a menu item to the content-type edit page for each group type.
    // Tried to do this using a single menu path with %  but it didn't work.'
    $types = _groupadmin_group_types();
    foreach($types as $type) {
      $path = sprintf('admin/content/node-type/%s/groupadmin', $type);
      $items[$path] = array(
        'title' => 'GroupAdmin',
        'access arguments' => array('administer content types'),
        'description' => 'Configure <em>Group Admin</em> for .',
        'page arguments' => array('_groupadmin_settings_form', 2, 3),
        'page callback' => 'drupal_get_form',
        'type' => MENU_LOCAL_TASK,
      );
    }
  }

  // Main page.
  $main_page = array(
    'title' => 'Members',
    'access callback' => '_groupadmin_access',
    'access arguments' => array(1),
    'description' => 'Group membership and administration.',
    'page callback' => 'drupal_get_form',
    'page arguments' => array('_groupadmin_manage', 1),
    'type' => MENU_LOCAL_TASK,
  );

  // Depending on configuration, create more menu paths...
  if(_groupadmin_settings('x_show_on_node_page')) {
    $items['node/%/groupadmin'] = $main_page;
  }

  if(_groupadmin_settings('x_show_on_members_page')) {
    // Tweak parameters...
    $main_page['page arguments'] = array('_groupadmin_manage', 2);
    $main_page['access arguments'] = array(2);

    if (_groupadmin_settings('x_use_standard_path')) {
      // Replace OG member list.
      $main_page['weight'] = -1;
      $main_page['type'] = MENU_DEFAULT_LOCAL_TASK;
      $items['og/users/%'] = $main_page;
    }
    else {
      // Add as tab on OG members page.
      $items['og/users/%/groupadmin'] = $main_page;
    }
  }

  // Update confirmation page.
  $items['og/groupadmin/%/%/%/%'] = array(
    'title' => 'Update membership',
    'access callback' => '_groupadmin_access_admin',
    'access arguments' => array(2),
    'page callback' => 'drupal_get_form',
    'page arguments' => array('_groupadmin_confirm', 2, 3, 4, 5),
    'type' => MENU_CALLBACK,
  );
  return $items;
}

/**
* Implementation of hook_menu_alter().
* If enabled, remove the standard "add users" tab.
*/
function groupadmin_menu_alter(&$items) {
  //drupal_set_message(print_r($items, 1));
  //foreach ($items as $key => $value)  drupal_set_message($key);

  if (_groupadmin_settings('x_remove_standard_link')) {
    unset($items['og/users/%node/add_user']);
  }
}
