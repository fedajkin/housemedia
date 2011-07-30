<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function hm_core_context_default_contexts() {
  $export = array();
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'hm_core-frontpage';
  $context->description = '';
  $context->tag = 'Housemedia Core';
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
        'views-hm_news_last-block_1' => array(
          'module' => 'views',
          'delta' => 'hm_news_last-block_1',
          'region' => 'sidebar_last',
          'weight' => 0,
        ),
        'views-hm_promotion_last-block_1' => array(
          'module' => 'views',
          'delta' => 'hm_promotion_last-block_1',
          'region' => 'sidebar_last',
          'weight' => 1,
        ),
        'hm_core-search' => array(
          'module' => 'hm_core',
          'delta' => 'search',
          'region' => 'content',
          'weight' => 0,
        ),
        'hm_core-ranks' => array(
          'module' => 'hm_core',
          'delta' => 'ranks',
          'region' => 'content',
          'weight' => 1,
        ),
        'views-hm_group_featured-block_1' => array(
          'module' => 'views',
          'delta' => 'hm_group_featured-block_1',
          'region' => 'postscript_top',
          'weight' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Housemedia Core');

  $export['hm_core-frontpage'] = $context;
  return $export;
}
