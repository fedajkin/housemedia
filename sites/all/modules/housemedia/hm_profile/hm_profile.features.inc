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
 * Implementation of hook_imagecache_default_presets().
 */
function hm_profile_imagecache_default_presets() {
  $items = array(
    'hm_profile_pictures' => array(
      'presetname' => 'hm_profile_pictures',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '100',
            'height' => '100',
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
function hm_profile_node_info() {
  $items = array(
    'deweloper' => array(
      'name' => t('Deweloper'),
      'module' => 'features',
      'description' => t('Profil dewelopera'),
      'has_title' => '1',
      'title_label' => t('Tytuł'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
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
 * Implementation of hook_rules_defaults().
 */
function hm_profile_rules_defaults() {
  return array(
    'rules' => array(
      'rules_redirect_user_to_stream_page' => array(
        '#type' => 'rule',
        '#set' => 'event_user_login',
        '#label' => 'Redirect user to stream page',
        '#active' => 1,
        '#weight' => '0',
        '#categories' => array(
          '0' => 'hm_profile',
        ),
        '#status' => 'default',
        '#conditions' => array(),
        '#actions' => array(
          '0' => array(
            '#weight' => 0,
            '#info' => array(
              'label' => 'Page redirect',
              'module' => 'System',
              'eval input' => array(
                '0' => 'path',
                '1' => 'query',
                '2' => 'fragment',
              ),
            ),
            '#name' => 'rules_action_drupal_goto',
            '#settings' => array(
              'path' => 'stream',
              'query' => '',
              'fragment' => '',
              'force' => 0,
              'immediate' => 0,
              '#eval input' => array(
                'token_rules_input_evaluator' => array(
                  'path' => array(
                    '0' => ':global',
                  ),
                  'query' => array(
                    '0' => ':global',
                  ),
                  'fragment' => array(
                    '0' => ':global',
                  ),
                ),
              ),
            ),
            '#type' => 'action',
          ),
        ),
        '#version' => 6003,
      ),
    ),
  );
}

/**
 * Implementation of hook_views_api().
 */
function hm_profile_views_api() {
  return array(
    'api' => '2',
  );
}
