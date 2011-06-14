<?php

/**
 * Implementation of hook_menu_default_menu_links().
 */
function commons_document_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: primary-links:content/documents
  $menu_links['primary-links:content/documents'] = array(
    'menu_name' => 'primary-links',
    'link_path' => 'content/documents',
    'router_path' => 'content/documents',
    'link_title' => 'Dokumenty',
    'options' => array(
      'minipanel' => '',
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'commons',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-30',
    'parent_path' => 'community',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Dokumenty');


  return $menu_links;
}
