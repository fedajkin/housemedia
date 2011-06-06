<?php

/**
 * Implementation of hook_strongarm().
 */
function ct_plus_strongarm() {
  $export = array();
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'atrium_archivable_ct_plus_project';
  $strongarm->value = TRUE;

  $export['atrium_archivable_ct_plus_project'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_ct_plus_project';
  $strongarm->value = 0;

  $export['comment_anonymous_ct_plus_project'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_ct_plus_task';
  $strongarm->value = 0;

  $export['comment_anonymous_ct_plus_task'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_controls_ct_plus_project';
  $strongarm->value = '3';

  $export['comment_controls_ct_plus_project'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_controls_ct_plus_task';
  $strongarm->value = '3';

  $export['comment_controls_ct_plus_task'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_ct_plus_project';
  $strongarm->value = '2';

  $export['comment_ct_plus_project'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_ct_plus_task';
  $strongarm->value = '2';

  $export['comment_ct_plus_task'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_ct_plus_project';
  $strongarm->value = '4';

  $export['comment_default_mode_ct_plus_project'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_ct_plus_task';
  $strongarm->value = '4';

  $export['comment_default_mode_ct_plus_task'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_order_ct_plus_project';
  $strongarm->value = '1';

  $export['comment_default_order_ct_plus_project'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_order_ct_plus_task';
  $strongarm->value = '2';

  $export['comment_default_order_ct_plus_task'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_ct_plus_project';
  $strongarm->value = '50';

  $export['comment_default_per_page_ct_plus_project'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_ct_plus_task';
  $strongarm->value = '50';

  $export['comment_default_per_page_ct_plus_task'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_driven:theme_support';
  $strongarm->value = 'atrium';

  $export['comment_driven:theme_support'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_driven:type:ct_plus_project:driven_props';
  $strongarm->value = array(
    'enabled' => 1,
    'cck' => array(
      'field_files' => array(
        'enabled' => 1,
      ),
      'field_ct_plus_status' => array(
        'enabled' => 1,
      ),
    ),
  );

  $export['comment_driven:type:ct_plus_project:driven_props'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_driven:type:ct_plus_project:settings';
  $strongarm->value = array(
    'empty_comment' => 1,
    'fieldset:collapsed' => 0,
    'fieldset:title' => 'Driven Project',
    'live_render' => '0',
  );

  $export['comment_driven:type:ct_plus_project:settings'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_driven:type:ct_plus_task:driven_props';
  $strongarm->value = array(
    'enabled' => 1,
    'cck' => array(
      'field_ct_plus_project' => array(
        'enabled' => 1,
      ),
      'field_ct_plus_assignees' => array(
        'enabled' => 1,
      ),
      'field_ct_plus_priority' => array(
        'enabled' => 1,
      ),
      'field_ct_plus_type' => array(
        'enabled' => 1,
      ),
      'field_ct_plus_status' => array(
        'enabled' => 1,
      ),
      'field_ct_plus_dependencies' => array(
        'enabled' => 1,
      ),
      'field_ct_plus_progress' => array(
        'enabled' => 1,
      ),
      'field_ct_plus_duration' => array(
        'enabled' => 1,
      ),
      'field_files' => array(
        'enabled' => 1,
      ),
    ),
  );

  $export['comment_driven:type:ct_plus_task:driven_props'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_driven:type:ct_plus_task:settings';
  $strongarm->value = array(
    'empty_comment' => 0,
    'fieldset:collapsed' => 0,
    'fieldset:title' => 'Driven Task',
    'live_render' => '0',
  );

  $export['comment_driven:type:ct_plus_task:settings'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_ct_plus_project';
  $strongarm->value = '1';

  $export['comment_form_location_ct_plus_project'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_ct_plus_task';
  $strongarm->value = '1';

  $export['comment_form_location_ct_plus_task'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_ct_plus_project';
  $strongarm->value = '0';

  $export['comment_preview_ct_plus_project'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_ct_plus_task';
  $strongarm->value = '0';

  $export['comment_preview_ct_plus_task'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_ct_plus_project';
  $strongarm->value = '0';

  $export['comment_subject_field_ct_plus_project'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_ct_plus_task';
  $strongarm->value = '0';

  $export['comment_subject_field_ct_plus_task'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_ct_plus_project';
  $strongarm->value = array(
    'title' => '-5',
    'body_field' => '0',
    'revision_information' => '20',
    'author' => '20',
    'options' => '25',
    'comment_settings' => '30',
    'menu' => '-2',
    'book' => '10',
    'attachments' => '30',
    'og_nodeapi' => '0',
  );

  $export['content_extra_weights_ct_plus_project'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_ct_plus_task';
  $strongarm->value = array(
    'title' => '-5',
    'body_field' => '-1',
    'revision_information' => '2',
    'author' => '3',
    'options' => '4',
    'comment_settings' => '6',
    'menu' => '-4',
    'book' => '1',
    'attachments' => '5',
    'og_nodeapi' => '0',
  );

  $export['content_extra_weights_ct_plus_task'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'driven:assertion_level';
  $strongarm->value = '2';

  $export['driven:assertion_level'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_ct_plus_project';
  $strongarm->value = array(
    0 => 'status',
    1 => 'revision',
  );

  $export['node_options_ct_plus_project'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_ct_plus_task';
  $strongarm->value = array(
    0 => 'status',
    1 => 'revision',
  );

  $export['node_options_ct_plus_task'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_content_type_usage_ct_plus_project';
  $strongarm->value = 'group_post_standard';

  $export['og_content_type_usage_ct_plus_project'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_content_type_usage_ct_plus_task';
  $strongarm->value = 'group_post_standard';

  $export['og_content_type_usage_ct_plus_task'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'upload_ct_plus_project';
  $strongarm->value = '1';

  $export['upload_ct_plus_project'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'upload_ct_plus_task';
  $strongarm->value = '1';

  $export['upload_ct_plus_task'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'xref_view_ct_plus_project';
  $strongarm->value = 0;

  $export['xref_view_ct_plus_project'] = $strongarm;
  return $export;
}
