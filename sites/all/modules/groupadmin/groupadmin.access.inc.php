<?php
// $Id: groupadmin.access.inc.php,v 1.1.2.3 2010/03/15 23:38:25 netgenius Exp $

/********************************************************
Original development by: netgenius.co.uk
Commercial support is available from www.netgenius.co.uk
Contact: drupal(a)netgenius.co.uk
*********************************************************/

/**
 * Implementation of hook_perm().
 */
function groupadmin_perm() {
  if (_groupadmin_settings('x_more_permissions')) {
    return array(
      'ga-admin'  => 'administer groupadmin',
      'manager'   => 'act as the manager for any group',
      'admins'    => 'act as an admin for any group',
      'members'   => 'act as a member for any group',
      'visitors'  => 'act as a visitor for any group',
      'email'     => 'view/search email addresses',
      'name'      => 'view/search real names',
    );
  }
  else {
    return array('ga-admin'  => 'administer groupadmin');
  }
}

/**
 * Check user has a permission defined by this module.
 * If permissions are not enabled, return result from 'administer permissions';
 */
function _groupadmin_user_access($perm) {
  //drupal_set_message('_groupadmin_user_access: ' . $perm);
  $perms = groupadmin_perm();
  $access = array_key_exists($perm, $perms) && user_access($perms[$perm]);
  $super = user_access('administer permissions') || user_access('administer groupadmin');
  return $access || $super;
}

/**
 * Test if user has the specified groupadmin role, or return array of all roles.
 */
function _groupadmin_user_has_role($group_node = null, $user = null, $role = null) {

  // All posssible roles in order of decreasing access.
  $all_roles = array('manager', 'admins', 'members', 'visitors');

  // If no group was specified, return array of all possible roles.
  if (!$group_node)  return $all_roles;

  // Check for explicit permission.
  if (_groupadmin_user_access($role)) return TRUE;

  // Test status...
  switch($role) {
    case 'manager':
      $has_role = ($user->uid == $group_node->uid);
      break;

    case 'admins':
      $has_role = og_is_group_admin($group_node, $user);
      break;

    case 'members':
      $has_role = _groupadmin_is_group_member($group_node->nid, $user->uid);
      break;

    case 'visitors':
      $has_role = node_access('view', $group_node, $user);
      break;

    default:
      $has_role = FALSE;
  }

  return $has_role;
}

/**
 * Check whether current user can access groupadmin for given group and action.
 * Result statically cached.
 * Return TRUE if access is allowed, otherwise FALSE;
 */
function _groupadmin_access($gid, $op = 'basic_access') {

  if (!$gid)  return FALSE;

  static $cached;
  $access =& $cached[$gid][$op];
  if (!isset($access))  {
    $access = _groupadmin_access_check($gid, $op);
    // Make sure user has basic access too.
    if ($op != 'basic_access')  $access &= _groupadmin_access($gid);
  }
  return $access;
  //*/
}

/**
 * Check whether current user can perform admin tasks for given group.
 */
function _groupadmin_access_admin($gid) {
  return _groupadmin_access($gid, 'administrate');
}

/**
 * Check whether current user can perform tasks for given group.
 * We don't need to worry too much about performance here, as result
 * will normally be cached via _groupadmin_access() function.
 */
function _groupadmin_access_check($gid, $op) {

  // Initial checks: make sure $gid is a valid Group node.
  if (!_groupadmin_checkfunc('og_is_group_type'))  return FALSE;
  if (!og_is_group_type(_groupadmin_get_group($gid, 'type')))  return FALSE;

  global $user;
  $node = _groupadmin_get_group($gid);

  switch ($op) {
    case 'administrate':
      $required = 'admins';
      break;
    case 'show_all':
      $op = 'show_non-members';
      // don't break
    default:
      $required = _groupadmin_settings('l_' . $op);
  }

  $access = _groupadmin_user_has_role($node, $user, $required);
  return $access;
}
