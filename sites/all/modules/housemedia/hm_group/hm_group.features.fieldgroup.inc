<?php

/**
 * Implementation of hook_fieldgroup_default_groups().
 */
function hm_group_fieldgroup_default_groups() {
  $groups = array();

  // Exported group: group_gallery
  $groups['group-group_gallery'] = array(
    'group_type' => 'standard',
    'type_name' => 'group',
    'group_name' => 'group_gallery',
    'label' => 'Galeria zdjęć',
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
    'weight' => '-9',
    'fields' => array(
      '0' => 'field_group_gallery',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Galeria zdjęć');

  return $groups;
}
