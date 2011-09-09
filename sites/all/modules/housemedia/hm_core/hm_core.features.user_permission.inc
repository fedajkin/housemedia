<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function hm_core_user_default_permissions() {
  $permissions = array();

  // Exported permission: access vote up/down statistics
  $permissions['access vote up/down statistics'] = array(
    'name' => 'access vote up/down statistics',
    'roles' => array(),
  );

  // Exported permission: administer forums
  $permissions['administer forums'] = array(
    'name' => 'administer forums',
    'roles' => array(),
  );

  // Exported permission: administer vote up/down
  $permissions['administer vote up/down'] = array(
    'name' => 'administer vote up/down',
    'roles' => array(),
  );

  // Exported permission: administer vote up/down on nodes
  $permissions['administer vote up/down on nodes'] = array(
    'name' => 'administer vote up/down on nodes',
    'roles' => array(),
  );

  // Exported permission: create forum topics
  $permissions['create forum topics'] = array(
    'name' => 'create forum topics',
    'roles' => array(
      '0' => 'authenticated user',
    ),
  );

  // Exported permission: delete any forum topic
  $permissions['delete any forum topic'] = array(
    'name' => 'delete any forum topic',
    'roles' => array(),
  );

  // Exported permission: delete own forum topics
  $permissions['delete own forum topics'] = array(
    'name' => 'delete own forum topics',
    'roles' => array(),
  );

  // Exported permission: edit any forum topic
  $permissions['edit any forum topic'] = array(
    'name' => 'edit any forum topic',
    'roles' => array(),
  );

  // Exported permission: edit own forum topics
  $permissions['edit own forum topics'] = array(
    'name' => 'edit own forum topics',
    'roles' => array(
      '0' => 'authenticated user',
    ),
  );

  // Exported permission: reset vote up/down votes
  $permissions['reset vote up/down votes'] = array(
    'name' => 'reset vote up/down votes',
    'roles' => array(),
  );

  // Exported permission: see vote up/down node stats
  $permissions['see vote up/down node stats'] = array(
    'name' => 'see vote up/down node stats',
    'roles' => array(),
  );

  // Exported permission: use vote up/down
  $permissions['use vote up/down'] = array(
    'name' => 'use vote up/down',
    'roles' => array(
      '0' => 'Użytkownik',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: use vote up/down on nodes
  $permissions['use vote up/down on nodes'] = array(
    'name' => 'use vote up/down on nodes',
    'roles' => array(
      '0' => 'Użytkownik',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: view imagecache Wyszukiwanie_nieruchomosci_64x46
  $permissions['view imagecache Wyszukiwanie_nieruchomosci_64x46'] = array(
    'name' => 'view imagecache Wyszukiwanie_nieruchomosci_64x46',
    'roles' => array(
      '0' => 'Użytkownik',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
    ),
  );

  // Exported permission: view imagecache crop_102x73
  $permissions['view imagecache crop_102x73'] = array(
    'name' => 'view imagecache crop_102x73',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: view imagecache crop_140x100
  $permissions['view imagecache crop_140x100'] = array(
    'name' => 'view imagecache crop_140x100',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: view imagecache crop_40x40
  $permissions['view imagecache crop_40x40'] = array(
    'name' => 'view imagecache crop_40x40',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: view imagecache group_images_featured
  $permissions['view imagecache group_images_featured'] = array(
    'name' => 'view imagecache group_images_featured',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: view imagecache group_images_medium
  $permissions['view imagecache group_images_medium'] = array(
    'name' => 'view imagecache group_images_medium',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: view imagecache image_thumb_30
  $permissions['view imagecache image_thumb_30'] = array(
    'name' => 'view imagecache image_thumb_30',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: view imagecache news
  $permissions['view imagecache news'] = array(
    'name' => 'view imagecache news',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: view imagecache news_thumb
  $permissions['view imagecache news_thumb'] = array(
    'name' => 'view imagecache news_thumb',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: view imagecache scale_150x
  $permissions['view imagecache scale_150x'] = array(
    'name' => 'view imagecache scale_150x',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: view imagecache scale_800x
  $permissions['view imagecache scale_800x'] = array(
    'name' => 'view imagecache scale_800x',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: view vote up/down count on nodes
  $permissions['view vote up/down count on nodes'] = array(
    'name' => 'view vote up/down count on nodes',
    'roles' => array(
      '0' => 'Deweloper',
      '1' => 'Doradca',
      '2' => 'Użytkownik',
      '3' => 'anonymous user',
      '4' => 'authenticated user',
    ),
  );

  return $permissions;
}
