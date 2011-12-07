<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function hm_profile_context_default_contexts() {
  $export = array();
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'hm_profile-profile-me';
  $context->description = '';
  $context->tag = 'Housemedia Profile';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'stream' => 'stream',
      ),
    ),
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
        'views-hm_credit_form-block_1' => array(
          'module' => 'views',
          'delta' => 'hm_credit_form-block_1',
          'region' => 'sidebar_first',
          'weight' => 1,
        ),
        'views-hm_credit_form-block_2' => array(
          'module' => 'views',
          'delta' => 'hm_credit_form-block_2',
          'region' => 'sidebar_first',
          'weight' => 2,
        ),
        'views-hm_profile_friends-block_1' => array(
          'module' => 'views',
          'delta' => 'hm_profile_friends-block_1',
          'region' => 'sidebar_first',
          'weight' => 3,
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
      ),
    ),
    'theme' => array(
      'title' => '',
      'subtitle' => '',
      'class' => 'page-profile',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Housemedia Profile');

  $export['hm_profile-profile-me'] = $context;
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'hm_profile-profile-other';
  $context->description = '';
  $context->tag = 'Housemedia Profile';
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
        'hm_credit_form-request_link' => array(
          'module' => 'hm_credit_form',
          'delta' => 'request_link',
          'region' => 'sidebar_first',
          'weight' => 1,
        ),
        'views-profile_friends-block_1' => array(
          'module' => 'views',
          'delta' => 'profile_friends-block_1',
          'region' => 'sidebar_first',
          'weight' => 2,
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
  t('Housemedia Profile');

  $export['hm_profile-profile-other'] = $context;
  return $export;
}
