<?php

/**
 * @file
 */

/**
 * Implementation of hook_views_plugins().
 */
function views_jsgantt_views_plugins() {
  return array(
    'style' => array(
      'views_jsgantt' => array(
        'title' => t('jsgantt'),
        'theme' => 'views_view_views_jsgantt',
        'help' => t('views_jsgantt help.'),
        'handler' => 'views_jsgantt_style_plugin',
        'uses row plugin' => FALSE,
        'uses fields' => TRUE,
        'uses options' => TRUE,
        'type' => 'normal',
      ),
    ),
  );
}
