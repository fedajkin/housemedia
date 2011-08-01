<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function hm_investment_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_views_api().
 */
function hm_investment_views_api() {
  return array(
    'api' => '2',
  );
}

/**
 * Implementation of hook_node_info().
 */
function hm_investment_node_info() {
  $items = array(
    'inw_detal' => array(
      'name' => t('Inwestycje - detale'),
      'module' => 'features',
      'description' => t('Szczegółowy opis inwestycji'),
      'has_title' => '1',
      'title_label' => t('Tytuł'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}
