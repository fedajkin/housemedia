<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function hm_news_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_imagecache_default_presets().
 */
function hm_news_imagecache_default_presets() {
  $items = array(
    'news' => array(
      'presetname' => 'news',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '250',
            'height' => '165',
            'upscale' => 0,
          ),
        ),
      ),
    ),
    'news_thumb' => array(
      'presetname' => 'news_thumb',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '102',
            'height' => '73',
          ),
        ),
      ),
    ),
  );
  return $items;
}

/**
 * Implementation of hook_node_info().
 */
function hm_news_node_info() {
  $items = array(
    'news' => array(
      'name' => t('Aktualności'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Tytuł'),
      'has_body' => '1',
      'body_label' => t('Treść'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function hm_news_views_api() {
  return array(
    'api' => '2',
  );
}
