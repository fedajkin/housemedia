<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function hm_promotion_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_node_info().
 */
function hm_promotion_node_info() {
  $items = array(
    'promotion' => array(
      'name' => t('Promocja'),
      'module' => 'features',
      'description' => t('Informacje o promocjach.'),
      'has_title' => '1',
      'title_label' => t('Tytuł'),
      'has_body' => '1',
      'body_label' => t('Opis promocji'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function hm_promotion_views_api() {
  return array(
    'api' => '2',
  );
}
