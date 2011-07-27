<?php

/**
 * Implementation of hook_fieldgroup_default_groups().
 */
function hm_promotion_fieldgroup_default_groups() {
  $groups = array();

  // Exported group: group_promotion_date
  $groups['promotion-group_promotion_date'] = array(
    'group_type' => 'standard',
    'type_name' => 'promotion',
    'group_name' => 'group_promotion_date',
    'label' => 'Czas trwania promocji',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'description' => '',
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
        'label' => 'above',
      ),
    ),
    'weight' => '0',
    'fields' => array(
      '0' => 'field_promotion_date_since',
      '1' => 'field_promotion_date_until',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Czas trwania promocji');

  return $groups;
}
