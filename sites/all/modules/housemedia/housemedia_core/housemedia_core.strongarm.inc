<?php

/**
 * Implementation of hook_strongarm().
 */
function housemedia_core_strongarm() {
  $export = array();
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'context_status';
  $strongarm->value = array(
    'global' => FALSE,
    'home' => TRUE,
    'profile-me' => TRUE,
    'profile-other' => TRUE,
    'profile-track' => FALSE,
    'profile-me-invite' => TRUE,
    'profile-me-most_active_users' => TRUE,
    'group-home-shoutbox' => TRUE,
    'group-home' => TRUE,
    'group-home-events' => TRUE,
  );

  $export['context_status'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'gmap_node_markers';
  $strongarm->value = array(
    'blog' => '',
    'poll' => '',
    'document' => '',
    'event' => '',
    'faq' => '',
    'news' => '',
    'promotion' => '',
    'forum' => '',
    'group' => '',
    'notice' => '',
    'page' => '',
    'deweloper' => '',
    'dew_szczegoly' => '',
    'doradca' => '',
    'grupa_powitanie' => '',
    'inw_detal' => '',
    'mieszkanie' => '',
    'opis_dewelopera' => '',
    'opis_inwestycji' => '',
    'profile' => '',
    'uzytkownik' => '',
  );

  $export['gmap_node_markers'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'gmap_role_markers';
  $strongarm->value = array(
    2 => '',
    3 => '',
    4 => '',
    6 => '',
    7 => '',
    5 => '',
    8 => '',
  );

  $export['gmap_role_markers'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'views_defaults';
  $strongarm->value = array(
    'og' => TRUE,
    'og_members_block' => TRUE,
    'og_my' => TRUE,
    'flag_bookmarks_tab' => TRUE,
    'flag_bookmarks' => FALSE,
    'groups_main_listing' => TRUE,
  );

  $export['views_defaults'] = $strongarm;
  return $export;
}
