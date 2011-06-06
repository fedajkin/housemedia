<?php

/**
 * @file
 * Theme preprocess function for content-admin-field-overview-form.tpl.php.
 */
function template_preprocess_drupal_tweaks_msg_rules_form(&$vars) {
  $form = &$vars['form'];

  $vars['help'] = theme('advanced_help_topic', 'content', 'manage-fields') . t('Add fields and groups to the content type, and arrange them on content display and input forms.');
  if (module_exists('fieldgroup')) {
    $vars['help'] .= '<br/>'. t('You can add a field to a group by dragging it below and to the right of the group.');
  }
  if (!module_exists('advanced_help')) {
    $vars['help'] .= '<br/>' . t('Note: Installing the <a href="!adv_help">Advanced help</a> module will let you access more and better help.', array('!adv_help' => 'http://drupal.org/project/advanced_help'));
  }

  $order = _content_overview_order($form, $form['#field_rows'], $form['#group_rows']);
  $rows = array();

  // Identify the 'new item' keys in the form, they look like
  // _add_new_field, add_new_group.
  $keys = array_keys($form);
  $add_rows = array();
  foreach ($keys as $key) {
    if (substr($key, 0, 4) == '_add') {
      $add_rows[] = $key;
    }
  }
  while ($order) {
    $key = reset($order);
    $element = &$form[$key];

    // Only display the 'Add' separator if the 'add' rows are still
    // at the end of the table.
    if (!isset($added_separator)) {
      $remaining_rows = array_diff($order, $add_rows);
      if (empty($remaining_rows) && empty($element['#depth'])) {
        $row = new stdClass();
        $row->row_type = 'separator';
        $row->class = 'tabledrag-leaf region';
        $rows[] = $row;
        $added_separator = TRUE;
      }
    }

    $row = new stdClass();

    // Add target classes for the tabledrag behavior.
    $element['weight']['#attributes']['class'] = 'field-weight';
    $element['parent']['#attributes']['class'] = 'group-parent';
    $element['hidden_name']['#attributes']['class'] = 'field-name';
    // Add target classes for the update selects behavior.
    switch ($element['#row_type']) {
      case 'add_new_field':
        $element['type']['#attributes']['class'] = 'content-field-type-select';
        $element['widget_type']['#attributes']['class'] = 'content-widget-type-select';
        break;
      case 'add_existing_field':
        $element['field_name']['#attributes']['class'] = 'content-field-select';
        $element['widget_type']['#attributes']['class'] = 'content-widget-type-select';
        $element['label']['#attributes']['class'] = 'content-label-textfield';
        break;
    }
    foreach (element_children($element) as $child) {
      $row->{$child} = drupal_render($element[$child]);
    }
    $row->label_class = 'label-'. strtr($element['#row_type'], '_', '-');
    $row->row_type = $element['#row_type'];
    $row->indentation = theme('indentation', isset($element['#depth']) ? $element['#depth'] : 0);
    $row->class = 'draggable';
    $row->class .= isset($element['#disabled_row']) ? ' menu-disabled' : '';
    $row->class .= isset($element['#add_new']) ? ' content-add-new' : '';
    $row->class .= isset($element['#leaf']) ? ' tabledrag-leaf' : '';
    $row->class .= isset($element['#root']) ? ' tabledrag-root' : '';

    $rows[] = $row;
    array_shift($order);
  }
  $vars['rows'] = $rows;
  $vars['submit'] = drupal_render($form);

  // Add tabledrag behavior.
//  drupal_add_tabledrag('content-field-overview', 'match', 'parent', 'group-parent', 'group-parent', 'field-name', FALSE, 1);
  drupal_add_tabledrag('content-field-overview', 'match', 'parent', 'group-parent', 'group-parent', 'field-name', TRUE, 1);
//  drupal_add_tabledrag('content-field-overview', 'order', 'sibling', 'field-weight', NULL, NULL, FALSE);
  drupal_add_tabledrag('content-field-overview', 'order', 'sibling', 'field-weight');

  // Add settings for the update selects behavior.
  $js_fields = array();
  foreach (array_keys(content_existing_field_options($form['#type_name'])) as $field_name) {
    $field = content_fields($field_name);
    $js_fields[$field_name] = array('label' => $field['widget']['label'], 'type' => $field['type'], 'widget' => $field['widget']['type']);
  }
  drupal_add_js(array('contentWidgetTypes' => content_widget_type_options(), 'contentFields' => $js_fields), 'setting');
  drupal_add_js(drupal_get_path('module', 'content') .'/content.js');
}

/**
 * Theme node administration overview.
 *
 * @ingroup themeable
 */
function theme_drupal_tweaks_module_admin_modules($form) {
  // If there are rows in this form, then $form['title'] contains a list of
  // the title form elements.
  $has_posts = isset($form['name']) && is_array($form['name']);
  $select_header = $has_posts ? theme('table_select_header_cell') : '';
  $header = array($select_header, t('Name'), t('Raw name'), t('Version'), t('Package'), t('Schema'), t('Status'));
  // if (isset($form['language'])) { $header[] = t('Language'); }
  // $header[] = t('Operations');
  $output = '';

  $output .= drupal_render($form['options']);
  if ($has_posts) {
    foreach (element_children($form['name']) as $key) {
      $row = array();
      $row[] = drupal_render($form['modules'][$key]);
      $row[] = drupal_render($form['name'][$key]);
      $row[] = drupal_render($form['raw_name'][$key]);
      $row[] = drupal_render($form['version'][$key]);
      $row[] = drupal_render($form['package'][$key]);
      $row[] = drupal_render($form['schema'][$key]);
      $row[] = drupal_render($form['status'][$key]);
      // if (isset($form['language'])) { $row[] = drupal_render($form['language'][$key]); }
      // $row[] = drupal_render($form['operations'][$key]);
      $rows[] = $row;
    }

  }
  else {
    $rows[] = array(array('data' => t('No modules available.'), 'colspan' => '7'));
  }

  $output .= theme('table', $header, $rows);
  if ($form['pager']['#value']) {
    $output .= drupal_render($form['pager']);
  }

  $output .= drupal_render($form);

  return $output;
}

