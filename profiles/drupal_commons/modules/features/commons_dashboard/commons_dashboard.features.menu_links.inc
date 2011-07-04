<?php

/**
 * Implementation of hook_menu_default_menu_links().
 */
function commons_dashboard_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: primary-links:dashboard
  $menu_links['primary-links:dashboard'] = array(
    'menu_name' => 'primary-links',
    'link_path' => 'dashboard',
    'router_path' => 'dashboard',
    'link_title' => 'Panel',
    'options' => array(
      'minipanel' => '',
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-48',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Panel');


  return $menu_links;
}
