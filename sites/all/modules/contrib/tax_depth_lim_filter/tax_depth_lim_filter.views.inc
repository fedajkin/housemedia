<?php

// $Id: tax_depth_lim_filter.views.inc,v 1.1 2010/10/06 16:41:35 brynbellomy Exp $

/**
 * Implementation of hook_views_api().
 */
function tax_depth_lim_filter_views_api() {
  return array(
    'api' => 2,
    'path' => drupal_get_path('module', 'tax_depth_lim_filter'),
  );
}


/**
 * Implementation of hook_views_handlers().
 */
function tax_depth_lim_filter_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'tax_depth_lim_filter'),
    ),
    'handlers' => array(
      'views_handler_filter_term_node_tid_depth_limited' => array(
        'parent' => 'views_handler_filter_term_node_tid_depth',
      ),
    ),
  );
}

function tax_depth_lim_filter_views_data_alter(&$data) {
  $data['node']['term_node_tid_depth_limited'] = array(
    'group' => t('Taxonomy'),
    'title' => t('Term ID (with depth, limited dropdown)'),
    'help' => t('Like Term ID with depth, but adds the option of restricting the exposed filter dropdown to terms that are above, below, or between given depths.'),
    'real field' => 'vid',
    'filter' => array(
      'handler' => 'views_handler_filter_term_node_tid_depth_limited',
    ),
  );
}

