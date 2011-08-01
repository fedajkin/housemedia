<?php

/**
 * Implementation of hook_strongarm().
 */
function hm_investment_strongarm() {
  $export = array();
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_inw_detal';
  $strongarm->value = 0;

  $export['comment_anonymous_inw_detal'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_controls_inw_detal';
  $strongarm->value = '3';

  $export['comment_controls_inw_detal'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_inw_detal';
  $strongarm->value = '4';

  $export['comment_default_mode_inw_detal'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_order_inw_detal';
  $strongarm->value = '1';

  $export['comment_default_order_inw_detal'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_inw_detal';
  $strongarm->value = '50';

  $export['comment_default_per_page_inw_detal'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_inw_detal';
  $strongarm->value = '0';

  $export['comment_form_location_inw_detal'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_inw_detal';
  $strongarm->value = '2';

  $export['comment_inw_detal'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_inw_detal';
  $strongarm->value = '1';

  $export['comment_preview_inw_detal'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_inw_detal';
  $strongarm->value = '1';

  $export['comment_subject_field_inw_detal'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_inw_detal';
  $strongarm->value = array(
    'title' => '-5',
    'revision_information' => '1',
    'author' => '2',
    'options' => '3',
    'comment_settings' => '4',
    'menu' => '-4',
    'path' => '5',
    'attachments' => '6',
    'og_nodeapi' => '-2',
    'detailed_question' => '10',
    'locations' => '-1',
    'nodewords' => '0',
  );

  $export['content_extra_weights_inw_detal'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_inw_detal';
  $strongarm->value = '0';

  $export['language_content_type_inw_detal'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_inw_detal';
  $strongarm->value = array(
    0 => 'status',
  );

  $export['node_options_inw_detal'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'upload_inw_detal';
  $strongarm->value = '1';

  $export['upload_inw_detal'] = $strongarm;
  return $export;
}
