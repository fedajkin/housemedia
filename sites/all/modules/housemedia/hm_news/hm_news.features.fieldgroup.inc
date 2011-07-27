<?php

/**
 * Implementation of hook_fieldgroup_default_groups().
 */
function hm_news_fieldgroup_default_groups() {
  $groups = array();

  // Exported group: group_news_photo
  $groups['news-group_news_photo'] = array(
    'group_type' => 'standard',
    'type_name' => 'news',
    'group_name' => 'group_news_photo',
    'label' => 'Zdjęcie',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'description' => '',
        'label' => 'above',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '2' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '3' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
      ),
    ),
    'weight' => '-2',
    'fields' => array(
      '0' => 'field_news_photo',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Zdjęcie');

  return $groups;
}
