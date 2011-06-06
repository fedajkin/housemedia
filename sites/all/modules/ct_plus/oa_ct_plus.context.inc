<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function oa_ct_plus_context_default_contexts() {
  $export = array();
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'book_ct_plus';
  $context->description = '';
  $context->tag = 'CT Plus';
  $context->conditions = array(
    'bookroot' => array(
      'values' => array(
        'ct_plus_project' => 'ct_plus_project',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'diff-inline' => array(
          'module' => 'diff',
          'delta' => 'inline',
          'region' => 'right',
          'weight' => 0,
        ),
      ),
    ),
    'menu' => 'ct_plus',
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('CT Plus');

  $export['book_ct_plus'] = $context;
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'ct_plus_listing';
  $context->description = '';
  $context->tag = 'CT Plus';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'ct_plus_project' => 'ct_plus_project',
        'ct_plus_task' => 'ct_plus_task',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'views' => array(
      'values' => array(
        'ct_plus_projects' => 'ct_plus_projects',
        'ct_plus_tasks' => 'ct_plus_tasks',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-ct_plus_tasks-block_1' => array(
          'module' => 'views',
          'delta' => 'ct_plus_tasks-block_1',
          'region' => 'right',
          'weight' => 0,
        ),
        'views-ct_plus_projects-block_1' => array(
          'module' => 'views',
          'delta' => 'ct_plus_projects-block_1',
          'region' => 'page_tools',
          'weight' => 0,
        ),
      ),
    ),
    'menu' => 'ct_plus',
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('CT Plus');

  $export['ct_plus_listing'] = $context;
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'ct_plus_listing_all_tasks';
  $context->description = '';
  $context->tag = 'CT Plus';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'ct_plus_tasks:page_1' => 'ct_plus_tasks:page_1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views--exp-ct_plus_tasks-page_1' => array(
          'module' => 'views',
          'delta' => '-exp-ct_plus_tasks-page_1',
          'region' => 'right',
          'weight' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('CT Plus');

  $export['ct_plus_listing_all_tasks'] = $context;
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'ct_plus_listing_gantt';
  $context->description = '';
  $context->tag = 'CT Plus';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'ct_plus_tasks:page_4' => 'ct_plus_tasks:page_4',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views--exp-ct_plus_tasks-page_4' => array(
          'module' => 'views',
          'delta' => '-exp-ct_plus_tasks-page_4',
          'region' => 'right',
          'weight' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('CT Plus');

  $export['ct_plus_listing_gantt'] = $context;
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'ct_plus_listing_my_tasks';
  $context->description = '';
  $context->tag = 'CT Plus';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'ct_plus_tasks:page_2' => 'ct_plus_tasks:page_2',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views--exp-ct_plus_tasks-page_2' => array(
          'module' => 'views',
          'delta' => '-exp-ct_plus_tasks-page_2',
          'region' => 'right',
          'weight' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('CT Plus');

  $export['ct_plus_listing_my_tasks'] = $context;
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'ct_plus_listing_project_tasks';
  $context->description = '';
  $context->tag = 'CT Plus';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'ct_plus_tasks:page_3' => 'ct_plus_tasks:page_3',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views--exp-ct_plus_tasks-page_3' => array(
          'module' => 'views',
          'delta' => '-exp-ct_plus_tasks-page_3',
          'region' => 'right',
          'weight' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('CT Plus');

  $export['ct_plus_listing_project_tasks'] = $context;
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'ct_plus_project';
  $context->description = '';
  $context->tag = 'CT Plus';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'ct_plus_project' => 'ct_plus_project',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-ct_plus_tasks-block_3' => array(
          'module' => 'views',
          'delta' => 'ct_plus_tasks-block_3',
          'region' => 'right',
          'weight' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('CT Plus');

  $export['ct_plus_project'] = $context;
  return $export;
}
