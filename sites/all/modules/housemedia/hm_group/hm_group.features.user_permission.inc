<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function hm_group_user_default_permissions() {
  $permissions = array();

  // Exported permission: edit field_group_gallery
  $permissions['edit field_group_gallery'] = array(
    'name' => 'edit field_group_gallery',
    'roles' => array(),
  );

  // Exported permission: view field_group_gallery
  $permissions['view field_group_gallery'] = array(
    'name' => 'view field_group_gallery',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
    ),
  );

  return $permissions;
}
