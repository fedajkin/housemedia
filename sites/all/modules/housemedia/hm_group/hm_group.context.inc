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
  return $export;
}
