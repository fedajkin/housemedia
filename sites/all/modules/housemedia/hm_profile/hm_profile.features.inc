<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function hm_profile_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => 3);
  }
  elseif ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_node_info().
 */
function hm_profile_node_info() {
  $items = array(
    'doradca' => array(
      'name' => t('Doradca finansowy'),
      'module' => 'features',
      'description' => t('Profil doradcy finansowego'),
      'has_title' => '1',
      'title_label' => t('Tytuł'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
    'uzytkownik' => array(
      'name' => t('Uzytkownik'),
      'module' => 'features',
      'description' => t('Profil uzytkownika'),
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

/**
 * Implementation of hook_views_api().
 */
function hm_profile_views_api() {
  return array(
    'api' => '2',
  );
}
