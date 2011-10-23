<?php

/**
 * Implementation of hook_menu_default_menu_links().
 */
function hm_core_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-hm-primary-links:<front>
  $menu_links['menu-hm-primary-links:<front>'] = array(
    'menu_name' => 'menu-hm-primary-links',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Strona główna',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '1',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-50',
  );
  // Exported menu link: menu-hm-primary-links:bookmarks
  $menu_links['menu-hm-primary-links:bookmarks'] = array(
    'menu_name' => 'menu-hm-primary-links',
    'link_path' => 'bookmarks',
    'router_path' => 'bookmarks',
    'link_title' => 'Moje zakładki',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-47',
    'parent_path' => 'user',
  );
  // Exported menu link: menu-hm-primary-links:contact
  $menu_links['menu-hm-primary-links:contact'] = array(
    'menu_name' => 'menu-hm-primary-links',
    'link_path' => 'contact',
    'router_path' => 'contact',
    'link_title' => 'Kontakt',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Exported menu link: menu-hm-primary-links:faq
  $menu_links['menu-hm-primary-links:faq'] = array(
    'menu_name' => 'menu-hm-primary-links',
    'link_path' => 'faq',
    'router_path' => 'faq',
    'link_title' => 'FAQ',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Exported menu link: menu-hm-primary-links:groups
  $menu_links['menu-hm-primary-links:groups'] = array(
    'menu_name' => 'menu-hm-primary-links',
    'link_path' => 'groups',
    'router_path' => 'groups',
    'link_title' => 'Inwestycje',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-49',
  );
  // Exported menu link: menu-hm-primary-links:groups/mine
  $menu_links['menu-hm-primary-links:groups/mine'] = array(
    'menu_name' => 'menu-hm-primary-links',
    'link_path' => 'groups/mine',
    'router_path' => 'groups/mine',
    'link_title' => 'Moje grupy',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-49',
    'parent_path' => 'user',
  );
  // Exported menu link: menu-hm-primary-links:mycontent
  $menu_links['menu-hm-primary-links:mycontent'] = array(
    'menu_name' => 'menu-hm-primary-links',
    'link_path' => 'mycontent',
    'router_path' => 'mycontent',
    'link_title' => 'Moje treści',
    'options' => array(
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
    'parent_path' => 'user',
  );
  // Exported menu link: menu-hm-primary-links:myprofile
  $menu_links['menu-hm-primary-links:myprofile'] = array(
    'menu_name' => 'menu-hm-primary-links',
    'link_path' => 'myprofile',
    'router_path' => 'myprofile',
    'link_title' => 'Mój profil',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-50',
    'parent_path' => 'user',
  );
  // Exported menu link: menu-hm-primary-links:myuserpoints
  $menu_links['menu-hm-primary-links:myuserpoints'] = array(
    'menu_name' => 'menu-hm-primary-links',
    'link_path' => 'myuserpoints',
    'router_path' => 'myuserpoints',
    'link_title' => 'Moje punkty',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-45',
    'parent_path' => 'user',
  );
  // Exported menu link: menu-hm-primary-links:relationships
  $menu_links['menu-hm-primary-links:relationships'] = array(
    'menu_name' => 'menu-hm-primary-links',
    'link_path' => 'relationships',
    'router_path' => 'relationships',
    'link_title' => 'Znajomi',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-46',
    'parent_path' => 'user',
  );
  // Exported menu link: menu-hm-primary-links:user
  $menu_links['menu-hm-primary-links:user'] = array(
    'menu_name' => 'menu-hm-primary-links',
    'link_path' => 'user',
    'router_path' => 'user',
    'link_title' => 'Moje konto',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '1',
    'expanded' => '1',
    'weight' => '0',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('FAQ');
  t('Inwestycje');
  t('Kontakt');
  t('Moje grupy');
  t('Moje konto');
  t('Moje punkty');
  t('Moje treści');
  t('Moje zakładki');
  t('Mój profil');
  t('Strona główna');
  t('Znajomi');


  return $menu_links;
}
