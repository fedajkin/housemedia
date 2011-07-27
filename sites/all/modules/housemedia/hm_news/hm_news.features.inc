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
