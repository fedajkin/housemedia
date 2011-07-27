<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function housemedia_core_context_default_contexts() {
  $export = array();
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'frontpage';
  $context->description = '';
  $context->tag = 'Housemedia';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-news_last-block_1' => array(
          'module' => 'views',
          'delta' => 'news_last-block_1',
          'region' => 'sidebar_last',
          'weight' => 0,
        ),
        'views-promotion_last-block_1' => array(
          'module' => 'views',
          'delta' => 'promotion_last-block_1',
          'region' => 'sidebar_last',
          'weight' => 1,
        ),
        'housemedia_core-search' => array(
          'module' => 'housemedia_core',
          'delta' => 'search',
          'region' => 'content',
          'weight' => 0,
        ),
        'housemedia_core-ranks' => array(
          'module' => 'housemedia_core',
          'delta' => 'ranks',
          'region' => 'content',
          'weight' => 1,
        ),
        'views-featured_groups-block_1' => array(
          'module' => 'views',
          'delta' => 'featured_groups-block_1',
          'region' => 'postscript_top',
          'weight' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Housemedia');

  $export['frontpage'] = $context;
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'group-homepage';
  $context->description = 'The group home page';
  $context->tag = 'Housemedia';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'group' => 'group',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'commons_core-group_menu' => array(
          'module' => 'commons_core',
          'delta' => 'group_menu',
          'region' => 'sidebar_last',
          'weight' => 0,
        ),
        'commons_core-group_members' => array(
          'module' => 'commons_core',
          'delta' => 'group_members',
          'region' => 'sidebar_last',
          'weight' => 1,
        ),
        'og_subgroups-0' => array(
          'module' => 'og_subgroups',
          'delta' => 0,
          'region' => 'sidebar_last',
          'weight' => 2,
        ),
        'og_views-0' => array(
          'module' => 'og_views',
          'delta' => 0,
          'region' => 'sidebar_last',
          'weight' => 3,
        ),
        'gmap_location-0' => array(
          'module' => 'gmap_location',
          'delta' => 0,
          'region' => 'sidebar_last',
          'weight' => 4,
        ),
        'views-0cde383a1963a6ecc04a0e9e98fa4213' => array(
          'module' => 'views',
          'delta' => '0cde383a1963a6ecc04a0e9e98fa4213',
          'region' => 'sidebar_last',
          'weight' => 5,
        ),
        'housemedia_core-group_info' => array(
          'module' => 'housemedia_core',
          'delta' => 'group_info',
          'region' => 'content',
          'weight' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Housemedia');
  t('The group home page');

  $export['group-homepage'] = $context;
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'userprofile-me';
  $context->description = 'User profile when viewing yourself';
  $context->tag = 'Housemedia';
  $context->conditions = array(
    'user_page' => array(
      'values' => array(
        'view' => 'view',
      ),
      'options' => array(
        'mode' => 'current',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'commons_profile-image_links' => array(
          'module' => 'commons_profile',
          'delta' => 'image_links',
          'region' => 'sidebar_first',
          'weight' => 0,
        ),
        'views-profile_friends-block_1' => array(
          'module' => 'views',
          'delta' => 'profile_friends-block_1',
          'region' => 'sidebar_first',
          'weight' => 1,
        ),
        'views-profile_user_groups-block_1' => array(
          'module' => 'views',
          'delta' => 'profile_user_groups-block_1',
          'region' => 'sidebar_last',
          'weight' => 0,
        ),
        'commons_profile-find_new_friends' => array(
          'module' => 'commons_profile',
          'delta' => 'find_new_friends',
          'region' => 'sidebar_last',
          'weight' => 1,
        ),
        'invite-0' => array(
          'module' => 'invite',
          'delta' => 0,
          'region' => 'sidebar_last',
          'weight' => 2,
        ),
        'views-most_active_users-block_1' => array(
          'module' => 'views',
          'delta' => 'most_active_users-block_1',
          'region' => 'sidebar_last',
          'weight' => 3,
        ),
        'commons_profile-recent_activity' => array(
          'module' => 'commons_profile',
          'delta' => 'recent_activity',
          'region' => 'content',
          'weight' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Housemedia');
  t('User profile when viewing yourself');

  $export['userprofile-me'] = $context;
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'userprofile-other';
  $context->description = 'User profile when viewing another user';
  $context->tag = 'Housemedia';
  $context->conditions = array(
    'user_page' => array(
      'values' => array(
        'view' => 'view',
      ),
      'options' => array(
        'mode' => 'other',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'commons_profile-image_links' => array(
          'module' => 'commons_profile',
          'delta' => 'image_links',
          'region' => 'sidebar_first',
          'weight' => 0,
        ),
        'views-profile_friends-block_1' => array(
          'module' => 'views',
          'delta' => 'profile_friends-block_1',
          'region' => 'sidebar_first',
          'weight' => 1,
        ),
        'views-profile_user_groups-block_2' => array(
          'module' => 'views',
          'delta' => 'profile_user_groups-block_2',
          'region' => 'sidebar_last',
          'weight' => 0,
        ),
        'commons_profile-recent_activity' => array(
          'module' => 'commons_profile',
          'delta' => 'recent_activity',
          'region' => 'content',
          'weight' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Housemedia');
  t('User profile when viewing another user');

  $export['userprofile-other'] = $context;
  return $export;
}
