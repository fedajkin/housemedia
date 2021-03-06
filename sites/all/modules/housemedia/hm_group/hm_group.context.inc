<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function hm_group_context_default_contexts() {
  $export = array();
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'hm_group-group';
  $context->description = '';
  $context->tag = 'Housemedia Group';
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
        'hm_group-members' => array(
          'module' => 'hm_group',
          'delta' => 'members',
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
        'hm_group-info_tabs' => array(
          'module' => 'hm_group',
          'delta' => 'info_tabs',
          'region' => 'content',
          'weight' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Housemedia Group');

  $export['hm_group-group'] = $context;
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'hm_group-listing';
  $context->description = '';
  $context->tag = 'Housemedia Group';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'groups_main_listing' => 'groups_main_listing',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'commons_core-create_group' => array(
          'module' => 'commons_core',
          'delta' => 'create_group',
          'region' => 'sidebar_last',
          'weight' => 0,
        ),
        'views-groups_my_groups-block_1' => array(
          'module' => 'views',
          'delta' => 'groups_my_groups-block_1',
          'region' => 'sidebar_last',
          'weight' => 1,
        ),
        'views-hm_group_most_active-block_1' => array(
          'module' => 'views',
          'delta' => 'hm_group_most_active-block_1',
          'region' => 'sidebar_last',
          'weight' => 2,
        ),
        'views-hm_group_newest-block_1' => array(
          'module' => 'views',
          'delta' => 'hm_group_newest-block_1',
          'region' => 'sidebar_last',
          'weight' => 3,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Housemedia Group');

  $export['hm_group-listing'] = $context;
  return $export;
}
