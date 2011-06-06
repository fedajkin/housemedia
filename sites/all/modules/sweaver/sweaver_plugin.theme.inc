<?php
// $Id: sweaver_plugin.theme.inc,v 1.1.2.1 2010/09/30 13:54:03 swentel Exp $

/**
 * @file
 * Sweaver theming functions.
 */

/**
 * Plugins drag and drop configuration screen.
 */
function template_preprocess_sweaver_plugin_config_plugins(&$vars) {
  $form = &$vars['form'];
  $rows = array();

  asort($form['#plugins']);
  foreach ($form['#plugins'] as $plugin => $weight) {
    $row = new stdClass;
    $row->name = drupal_render($form[$plugin]['name']);
    $row->status = drupal_render($form[$plugin]['status']);
    $row->weight = drupal_render($form[$plugin]['weight']);
    $rows[] = $row;
  }

  drupal_add_js('misc/tableheader.js');
  drupal_add_tabledrag('plugins-configuration', 'order', 'sibling', 'plugin-weight', NULL, NULL, TRUE);

  $vars['rows'] = $rows;
  $vars['submit'] = drupal_render($form);
}
