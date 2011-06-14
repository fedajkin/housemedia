<?php

/**
 * Implementation of hook_homebox().
 */
function commons_dashboard_homebox() {
  $homeboxes = array();

  $homeboxes['dashboard'] = array (
    'regions' => 3,
    'cache' => 0,
    'color' => 0,
    'colors' => 
    array (
      0 => '#E4F0F8',
      1 => '#E4F0F8',
      2 => '#E4F0F8',
      3 => '#E4F0F8',
      4 => '#E4F0F8',
      5 => '#E4F0F8',
    ),
    'blocks' => 
    array (
      'views_views_saved_searches-block_1' => 
      array (
        'module' => 'views',
        'delta' => 'views_saved_searches-block_1',
        'region' => 1,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => 'Moje wyszukiwania',
        'weight' => -58,
      ),
      'views_og_dashboard_groups-block_1' => 
      array (
        'module' => 'views',
        'delta' => 'og_dashboard_groups-block_1',
        'region' => 1,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => '',
        'weight' => -57,
      ),
      'privatemsg_privatemsg-menu' => 
      array (
        'module' => 'privatemsg',
        'delta' => 'privatemsg-menu',
        'region' => 1,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => 'Wiadomości prywatne',
        'weight' => -56,
      ),
      'views_my_recent_items-block_1' => 
      array (
        'module' => 'views',
        'delta' => 'my_recent_items-block_1',
        'region' => 1,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => '',
        'weight' => -55,
      ),
      'views_my_unread_items-block_1' => 
      array (
        'module' => 'views',
        'delta' => 'my_unread_items-block_1',
        'region' => 1,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => '',
        'weight' => -54,
      ),
      'user_relationship_blocks_user-1' => 
      array (
        'module' => 'user_relationship_blocks',
        'delta' => 'user-1',
        'region' => 1,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => 'Moi znajomi',
        'weight' => -53,
      ),
      'views_upcoming_events-block_2' => 
      array (
        'module' => 'views',
        'delta' => 'upcoming_events-block_2',
        'region' => 3,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => '',
        'weight' => -52,
      ),
      'views_users_online-block_1' => 
      array (
        'module' => 'views',
        'delta' => 'users_online-block_1',
        'region' => 1,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => '',
        'weight' => -52,
      ),
      'views_vote_deweloper-block_1' => 
      array (
        'module' => 'views',
        'delta' => 'vote_deweloper-block_1',
        'region' => 3,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => 'Ranking deweloperów',
        'weight' => -52,
      ),
      'views_recent_notices-block_1' => 
      array (
        'module' => 'views',
        'delta' => 'recent_notices-block_1',
        'region' => 3,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => '',
        'weight' => -51,
      ),
      'views_og_featured-block_1' => 
      array (
        'module' => 'views',
        'delta' => 'og_featured-block_1',
        'region' => 3,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => '',
        'weight' => -50,
      ),
      'views_most_active_users-block_1' => 
      array (
        'module' => 'views',
        'delta' => 'most_active_users-block_1',
        'region' => 3,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => '',
        'weight' => -49,
      ),
      'views_recent_content_all-block_1' => 
      array (
        'module' => 'views',
        'delta' => 'recent_content_all-block_1',
        'region' => 2,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => '',
        'weight' => -38,
      ),
      'heartbeat_connectedheartbeat' => 
      array (
        'module' => 'heartbeat',
        'delta' => 'connectedheartbeat',
        'region' => 2,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => 'Aktywność',
        'weight' => -37,
      ),
    ),
    'widths' => 
    array (
      1 => 25,
      2 => 50,
      3 => 25,
    ),
    'title' => 'Dashboard',
    'path' => 'dashboard',
    'menu' => 0,
    'enabled' => 1,
    'full' => 1,
    'custom' => 0,
    'roles' => 
    array (
      0 => 'authenticated user',
    ),
  );


  return $homeboxes;
}

/**
 * Implementation of hook_views_api().
 */
function commons_dashboard_views_api() {
  return array(
    'api' => '2',
  );
}
