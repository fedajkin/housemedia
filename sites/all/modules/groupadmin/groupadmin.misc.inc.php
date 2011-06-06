<?php

// $Id: groupadmin.misc.inc.php,v 1.1.2.2 2010/03/14 18:49:52 netgenius Exp $

/********************************************************
Original development by: netgenius.co.uk
Commercial support is available from www.netgenius.co.uk
Contact: drupal(a)netgenius.co.uk
*********************************************************/

/**
 * Check if a required function exists, display an error message if not.
 */
function _groupadmin_checkfunc($func_name) {
  if(is_callable($func_name))  return true;

  $msg = sprintf('[groupadmin] %s: %s()', t('Required function does not exist'), $func_name);
  drupal_set_message($msg, 'error');
  return false;
}

/**
 * Handle session data, used to store "sticky" values on the search form.
 */
function _groupadmin_session($key, $value = null) {
  global $_SESSION;
  $session_data =& $_SESSION['groupadmin'];
  //if ($value === null) drupal_set_message(sprintf('read session (%s) -> %s', $key, print_r($session_data, 1)));

  if ($value === null) {
    $value = $session_data[$key];
  }
  elseif ($value === 'DELETE') {
    unset($session_data[$key]);
  }
  else {
    $session_data[$key] = $value;
  }

  return $value;
}

/**
 * Load and statically cache the group node.
 * Return entire node or specified element.
 */
function _groupadmin_get_group($gid, $element = FALSE) {
  static $node;
  if ($node->gid != $gid)  $node = node_load($gid);
  return $element? $node->$element : $node;
}

/**
 * Test if user is member of Group, via safe call to OG function.
 */
function _groupadmin_is_group_member($gid, $uid) {
  return (_groupadmin_checkfunc('og_is_group_member'))? og_is_group_member($gid, FALSE, $uid) : FALSE;
}

/**
 * Get an array of content types which are Groups.
 */
function _groupadmin_group_types() {
  // Current versions of OG use og_get_types.
  if (is_callable('og_get_types')) {
    $types = og_get_types('group');
  }
  else {
    $types = variable_get('og_node_types', array('og'));
  }

  return empty($types)? FALSE : $types;
}

/**
 * Get data from other modules via hook_groupadmin_ functions.
 */
function _groupadmin_get_modules($op) {
  $hook = 'hook_groupadmin_' . $op;
  $modules = module_implements($hook);
  //drupal_set_message('modules: ' . print_r($modules, 1));
  $data = array();
  foreach($modules as $module)  {
    $data = array_merge($data, module_invoke($module, $hook));
  }
  return $data;
}
