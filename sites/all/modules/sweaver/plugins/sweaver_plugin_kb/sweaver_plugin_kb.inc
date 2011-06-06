<?php
// $Id: sweaver_plugin_kb.inc,v 1.1.2.10 2010/09/30 13:54:03 swentel Exp $

/**
 * @file
 * Key bindings plugin.
 */
class sweaver_plugin_kb extends sweaver_plugin {

  /**
   * Sweaver dependencies.
   */
  public function sweaver_dependencies() {
    if (!variable_get('sweaver_plugin_status_sweaver_plugin_styles', FALSE)) {
      return array('Manage styles');
    }
    return array();
  }

  /**
   * Menu registry.
   */
  public function sweaver_menu(&$weight, $page_arguments, $base) {
    $items = array();

    $items['admin/settings/sweaver/kb'] = $base + array(
      'title' => 'Keyboard',
      'page arguments' => array($page_arguments),
      'type' => MENU_LOCAL_TASK,
      'weight' => $weight++,
    );

    return $items;
  }

  /**
   * Frontend css and js.
   */
  public function sweaver_form_css_js(&$inline_settings) {
    drupal_add_js(drupal_get_path('module', 'sweaver') .'/plugins/sweaver_plugin_kb/jquery.hotkeys.js', 'module');
    drupal_add_js(drupal_get_path('module', 'sweaver') .'/plugins/sweaver_plugin_kb/sweaver_plugin_kb.js', 'module');
    $first_key = (variable_get('sweaver_plugin_kb_firstkey', '') != '') ? variable_get('sweaver_plugin_kb_firstkey', '') .'+': '';
    $bindings = $this->sweaver_kb_bindings();

    foreach ($bindings as $key => $value) {

      // Do not add when a certain variable isn't set. (eg delete tab)
      if (isset($value['variable']) && !variable_get($value['variable'], FALSE)) {
        continue;
      }

      // Get keyboard key. Make sure it's not empty.
      $keyboard_key = variable_get('sweaver_plugin_kb_'. $key, $value['default']);
      if (!empty($keyboard_key)) {
        $inline_settings['sweaver']['kb'][$key] = array(
          'combination' => $value['double'] ? $first_key . $keyboard_key : $keyboard_key,
          'element' => isset($value['element']) ? $value['element'] : '',
        );
      }
    }
  }

  /**
   * Keyboard bindings settings form.
   */
  public function sweaver_menu_callback() {
    $form = array();
    $bindings = $this->sweaver_kb_bindings();
    $binding_options_firstkey = drupal_map_assoc($this->sweaver_kb_binding_firstkeys());
    $binding_options = drupal_map_assoc($this->sweaver_kb_binding_options());

    $form['info'] = array(
      '#type' => 'markup',
      '#value' => t('Select keys for every event possible. Note, there is no validation when saving this form, so make sure every event has a unique key combination.'),
    );

    $form['sweaver_plugin_kb_firstkey'] = array(
      '#type' => 'select',
      '#title' => t('First key'),
      '#options' => $binding_options_firstkey,
      '#description' => t('Can be used for all events, except the close popup'),
      '#default_value' => variable_get('sweaver_plugin_kb_firstkey', ''),
    );

    foreach ($bindings as $key => $value) {
      $form['sweaver_plugin_kb_'. $key] = array(
        '#type' => 'select',
        '#options' => $binding_options,
        '#title' => $value['title'],
        '#default_value' => variable_get('sweaver_plugin_kb_'. $key, $value['default']),
      );
    }

    return system_settings_form($form);
  }

  /**
   * Possible keyboard bindings.
   */
  public function sweaver_kb_bindings() {
    $bindings = array(
      'save' => array(
        'title' => t('Save style popup'),
        'default' => 's',
        'element' => '.save-style-popup',
        'double' => TRUE,
      ),
      'load' => array(
        'title' => t('Load style popup'),
        'default' => 'l',
        'element' => '.load-style-popup',
        'double' => TRUE,
      ),
      'publish' => array(
        'title' => t('Publish style popup'),
        'default' => 'p',
        'element' => '.publish-style-popup',
        'double' => TRUE,
      ),
      'delete' => array(
        'title' => t('Delete style popup'),
        'default' => 'd',
        'variable' => 'sweaver_styles_delete_tab',
        'element' => '.delete-style-popup',
        'double' => TRUE,
      ),
      'close' => array(
        'title' => t('Close popup'),
        'default' => 'esc',
        'double' => FALSE,
      ),
    );

    return $bindings;
  }

  /**
   * First key options
   */
  public function sweaver_kb_binding_firstkeys() {
    return array(
      '',
      'shift',
      'ctrl',
      'alt',
    );
  }

  /**
   * All possible keyboard bindings.
   */
  public function sweaver_kb_binding_options() {
    return array(
      '',
      'esc',
      'left',
      'up',
      'right',
      'down',
      '0',
      '1',
      '2',
      '3',
      '4',
      '5',
      '6',
      '7',
      '8',
      '9',
      'a',
      'b',
      'c',
      'd',
      'e',
      'f',
      'g',
      'h',
      'i',
      'j',
      'k',
      'l',
      'm',
      'n',
      'o',
      'p',
      'q',
      'r',
      's',
      't',
      'u',
      'v',
      'w',
      'x',
      'y',
      'z',
      'f1',
      'f2',
      'f3',
      'f4',
      'f5',
      'f6',
      'f7',
      'f8',
      'f9',
      'f10',
      'f11',
      'f12',
    );
  }
}
