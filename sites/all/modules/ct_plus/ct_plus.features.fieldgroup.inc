<?php

/**
 * Implementation of hook_fieldgroup_default_groups().
 */
function ct_plus_fieldgroup_default_groups() {
  $groups = array();

  // Exported group: group_ct_plus_properties
  $groups['ct_plus_task-group_ct_plus_properties'] = array(
    'group_type' => 'standard',
    'type_name' => 'ct_plus_task',
    'group_name' => 'group_ct_plus_properties',
    'label' => 'Required properties',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'weight' => '-3',
        'label' => 'hidden',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'simple',
          'exclude' => 0,
        ),
        'description' => '',
        '5' => array(
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
    'weight' => '-3',
    'fields' => array(
      '0' => 'field_ct_plus_status',
      '1' => 'field_ct_plus_priority',
      '2' => 'field_ct_plus_type',
      '3' => 'field_ct_plus_project',
      '4' => 'field_ct_plus_progress',
    ),
  );

  // Exported group: group_ct_plus_properties_big
  $groups['ct_plus_task-group_ct_plus_properties_big'] = array(
    'group_type' => 'standard',
    'type_name' => 'ct_plus_task',
    'group_name' => 'group_ct_plus_properties_big',
    'label' => 'Optional properties',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'weight' => '-2',
        'label' => 'hidden',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'simple',
          'exclude' => 0,
        ),
        'description' => '',
        '5' => array(
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
      '0' => 'field_ct_plus_duration',
      '1' => 'field_ct_plus_assignees',
      '2' => 'field_ct_plus_dependencies',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Optional properties');
  t('Required properties');

  return $groups;
}
