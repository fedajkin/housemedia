<?php

/**
 * Implementation of hook_fieldgroup_default_groups().
 */
function commons_core_fieldgroup_default_groups() {
  $groups = array();

  // Exported group: group_attributes
  $groups['group-group_attributes'] = array(
    'group_type' => 'standard',
    'type_name' => 'group',
    'group_name' => 'group_attributes',
    'label' => 'Group attributes',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'description' => '',
        'teaser' => array(
          'format' => 'simple',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'simple',
          'exclude' => 0,
        ),
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 1,
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
        'label' => 'hidden',
      ),
    ),
    'weight' => '-6',
    'fields' => array(
      '0' => 'field_group_image',
      '1' => 'field_grouplink',
    ),
  );

  // Exported group: group_promote_content
  $groups['group-group_promote_content'] = array(
    'group_type' => 'standard',
    'type_name' => 'group',
    'group_name' => 'group_promote_content',
    'label' => 'Promote group',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'description' => '',
        'teaser' => array(
          'format' => 'fieldset_collapsed',
          'exclude' => 1,
        ),
        'full' => array(
          'format' => 'fieldset_collapsed',
          'exclude' => 0,
        ),
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 1,
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
    'weight' => '2',
    'fields' => array(
      '0' => 'field_featured_group',
    ),
  );

  // Exported group: group_images
  $groups['notice-group_images'] = array(
    'group_type' => 'standard',
    'type_name' => 'notice',
    'group_name' => 'group_images',
    'label' => 'Images',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'weight' => '-3',
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 1,
        ),
        'label' => 'above',
        'teaser' => array(
          'format' => 'no_style',
          'exclude' => 1,
        ),
        'full' => array(
          'format' => 'no_style',
          'exclude' => 1,
        ),
        'description' => '',
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
      '0' => 'field_content_images',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Group attributes');
  t('Images');
  t('Promote group');

  return $groups;
}
