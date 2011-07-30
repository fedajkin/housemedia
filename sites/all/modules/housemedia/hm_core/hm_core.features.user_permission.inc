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

  // Exported permission: view imagecache scale_150x
  $permissions['view imagecache scale_150x'] = array(
    'name' => 'view imagecache scale_150x',
    'roles' => array(),
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
