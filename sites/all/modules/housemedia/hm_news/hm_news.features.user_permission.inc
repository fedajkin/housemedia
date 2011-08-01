<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function hm_news_user_default_permissions() {
  $permissions = array();

  // Exported permission: edit field_news_photo
  $permissions['edit field_news_photo'] = array(
    'name' => 'edit field_news_photo',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: view field_news_photo
  $permissions['view field_news_photo'] = array(
    'name' => 'view field_news_photo',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
    ),
  );

  return $permissions;
}
