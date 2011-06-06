<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function ct_plus_user_default_permissions() {
  $permissions = array();

  // Exported permission: create ct_plus_project content
  $permissions['create ct_plus_project content'] = array(
    'name' => 'create ct_plus_project content',
    'roles' => array(
      '0' => 'authenticated user',
    ),
  );

  // Exported permission: create ct_plus_task content
  $permissions['create ct_plus_task content'] = array(
    'name' => 'create ct_plus_task content',
    'roles' => array(
      '0' => 'authenticated user',
    ),
  );

  // Exported permission: delete own ct_plus_project content
  $permissions['delete own ct_plus_project content'] = array(
    'name' => 'delete own ct_plus_project content',
    'roles' => array(
      '0' => 'authenticated user',
    ),
  );

  // Exported permission: delete own ct_plus_task content
  $permissions['delete own ct_plus_task content'] = array(
    'name' => 'delete own ct_plus_task content',
    'roles' => array(
      '0' => 'authenticated user',
    ),
  );

  // Exported permission: drive ALL properties through comments (for EVERY content type!)
  $permissions['drive ALL properties through comments (for EVERY content type!)'] = array(
    'name' => 'drive ALL properties through comments (for EVERY content type!)',
    'roles' => array(
      '0' => 'authenticated user',
    ),
  );

  // Exported permission: edit own ct_plus_project content
  $permissions['edit own ct_plus_project content'] = array(
    'name' => 'edit own ct_plus_project content',
    'roles' => array(
      '0' => 'authenticated user',
    ),
  );

  // Exported permission: edit own ct_plus_task content
  $permissions['edit own ct_plus_task content'] = array(
    'name' => 'edit own ct_plus_task content',
    'roles' => array(
      '0' => 'authenticated user',
    ),
  );

  return $permissions;
}
