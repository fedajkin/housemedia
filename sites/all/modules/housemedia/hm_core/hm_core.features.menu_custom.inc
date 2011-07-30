<?php

/**
 * Implementation of hook_menu_default_menu_custom().
 */
function hm_core_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-hm-primary-links
  $menus['menu-hm-primary-links'] = array(
    'menu_name' => 'menu-hm-primary-links',
    'title' => 'Housemedia primary links',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Housemedia primary links');


  return $menus;
}
