<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function hm_promotion_user_default_permissions() {
  $permissions = array();

  // Exported permission: create promotion content
  $permissions['create promotion content'] = array(
    'name' => 'create promotion content',
    'roles' => array(),
  );

  // Exported permission: delete any promotion content
  $permissions['delete any promotion content'] = array(
    'name' => 'delete any promotion content',
    'roles' => array(),
  );

  // Exported permission: delete own promotion content
  $permissions['delete own promotion content'] = array(
    'name' => 'delete own promotion content',
    'roles' => array(),
  );

  // Exported permission: edit any promotion content
  $permissions['edit any promotion content'] = array(
    'name' => 'edit any promotion content',
    'roles' => array(),
  );

  // Exported permission: edit own promotion content
  $permissions['edit own promotion content'] = array(
    'name' => 'edit own promotion content',
    'roles' => array(),
  );

  return $permissions;
}
