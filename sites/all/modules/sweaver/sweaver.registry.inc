<?php
// $Id: sweaver.registry.inc,v 1.1.2.35 2010/11/08 14:54:00 jyve Exp $

/**
 * @file
 * Registry for Sweaver.
 */

/**
 * Menu items.
 */
function _sweaver_menu() {
  $weight = 0;
  $items = array();

  // The sweaver plugins administration.
  $items['admin/settings/sweaver/plugins'] = array(
    'title' => 'Plugins',
    'type' => MENU_LOCAL_TASK,
    'weight' => 2,
    'access arguments' => array('configure sweaver'),
    'page callback' => 'drupal_get_form',
    'page arguments' => array('sweaver_plugin_config_plugins'),
    'file' => 'sweaver.admin.inc'
  );

  $base = array(
    'access arguments' => array('configure sweaver'),
    'page callback' => 'sweaver_menu_callback',
  );

  $sweaver = Sweaver::get_instance();
  foreach (array_keys($sweaver->get_plugins_registry(TRUE)) as $plugin_name) {
    $sweaver_plugin = $sweaver->get_plugin($plugin_name);
    $page_arguments = array(
      'plugin' => $plugin_name,
    );
    $item = $sweaver_plugin->sweaver_menu($weight, $page_arguments, $base);

    $items += $item;
  }

  return $items;
}

/**
 * Theming functions.
 */
function _sweaver_theme() {

  $skin = variable_get('sweaver_skin', SWEAVER_SKIN);
  $theme_functions = array(
    'sweaver_plugin' => array(
      'template' => $skin,
      'file' => $skin .'.theme.inc',
      'path' => drupal_get_path('module', 'sweaver') .'/skins/'. $skin,
      'arguments' => array('form' => NULL),
    ),
    'sweaver_plugin_config_plugins' => array(
      'template' => 'sweaver-plugin-config-plugins',
      'file' => 'sweaver_plugin.theme.inc',
      'path' => drupal_get_path('module', 'sweaver'),
      'arguments' => array('form' => NULL),
    ),
  );

  $sweaver = Sweaver::get_instance();
  foreach (array_keys($sweaver->get_plugins_registry(TRUE)) as $plugin_name) {
    $sweaver_plugin = $sweaver->get_plugin($plugin_name);
    $theme_function = $sweaver_plugin->sweaver_theme();
    $theme_functions += $theme_function;
  }

  return $theme_functions;
}

/**
 * Sweaver plugins.
 */
function _sweaver_sweaver_plugins() {
  $plugins = array();

  $plugins['sweaver_plugin_editor'] = array(
    'handler' => array(
      'tab' => t('Style'),
      'tab_description' => t('Click on the element you want to theme.'),
      'path' => drupal_get_path('module', 'sweaver') .'/plugins/sweaver_plugin_editor',
      'file' => 'sweaver_plugin_editor.inc',
      'class' => 'sweaver_plugin_editor',
      'parent' => 'sweaver_plugin',
    ),
  );
  $plugins['sweaver_plugin_styles'] = array(
    'handler' => array(
      'tab' => t('Manage styles'),
      'path' => drupal_get_path('module', 'sweaver') .'/plugins/sweaver_plugin_styles',
      'file' => 'sweaver_plugin_styles.inc',
      'class' => 'sweaver_plugin_styles',
      'parent' => 'sweaver_plugin',
    ),
  );
  $plugins['sweaver_plugin_customcss'] = array(
    'handler' => array(
      'tab' => t('Custom css'),
      'tab_description' => t('Add custom css.'),
      'path' => drupal_get_path('module', 'sweaver') .'/plugins/sweaver_plugin_customcss',
      'file' => 'sweaver_plugin_customcss.inc',
      'class' => 'sweaver_plugin_customcss',
      'parent' => 'sweaver_plugin',
    ),
  );
  $plugins['sweaver_plugin_images'] = array(
    'handler' => array(
      'tab' => t('Images'),
      'tab_description' => t('Upload images to use as a background image.'),
      'path' => drupal_get_path('module', 'sweaver') .'/plugins/sweaver_plugin_images',
      'file' => 'sweaver_plugin_images.inc',
      'class' => 'sweaver_plugin_images',
      'parent' => 'sweaver_plugin',
    ),
  );
  $plugins['sweaver_plugin_themeswitch'] = array(
    'handler' => array(
      'tab' => t('Switch theme'),
      'tab_description' => t('Switch and style another theme.'),
      'path' => drupal_get_path('module', 'sweaver') .'/plugins/sweaver_plugin_themeswitch',
      'file' => 'sweaver_plugin_themeswitch.inc',
      'class' => 'sweaver_plugin_themeswitch',
      'parent' => 'sweaver_plugin',
    ),
  );
  $plugins['sweaver_plugin_themesettings'] = array(
    'handler' => array(
      'tab' => t('Theme settings'),
      'tab_description' => t('Configure the settings for this theme.'),
      'path' => drupal_get_path('module', 'sweaver') .'/plugins/sweaver_plugin_themesettings',
      'file' => 'sweaver_plugin_themesettings.inc',
      'class' => 'sweaver_plugin_themesettings',
      'parent' => 'sweaver_plugin',
    ),
  );
  $plugins['sweaver_plugin_themeclasses'] = array(
    'handler' => array(
      'tab' => t('Theme styles'),
      'tab_description' => t('Select an item - if any - to style it. Clicking will switch to the style editor form.'),
      'path' => drupal_get_path('module', 'sweaver') .'/plugins/sweaver_plugin_themeclasses',
      'file' => 'sweaver_plugin_themeclasses.inc',
      'class' => 'sweaver_plugin_themeclasses',
      'parent' => 'sweaver_plugin',
    ),
  );
  $plugins['sweaver_plugin_fontface'] = array(
    'handler' => array(
      'tab' => t('Font face'),
      'path' => drupal_get_path('module', 'sweaver') .'/plugins/sweaver_plugin_fontface',
      'file' => 'sweaver_plugin_fontface.inc',
      'class' => 'sweaver_plugin_fontface',
      'parent' => 'sweaver_plugin',
    ),
  );
  $plugins['sweaver_plugin_kb'] = array(
    'handler' => array(
      'tab' => t('Key bindings'),
      'path' => drupal_get_path('module', 'sweaver') .'/plugins/sweaver_plugin_kb',
      'file' => 'sweaver_plugin_kb.inc',
      'class' => 'sweaver_plugin_kb',
      'parent' => 'sweaver_plugin',
    ),
  );
  $plugins['sweaver_plugin_palettes'] = array(
    'handler' => array(
      'tab' => t('Palettes'),
      'path' => drupal_get_path('module', 'sweaver') .'/plugins/sweaver_plugin_palettes',
      'file' => 'sweaver_plugin_palettes.inc',
      'class' => 'sweaver_plugin_palettes',
      'parent' => 'sweaver_plugin',
    ),
  );

  return $plugins;
}

/**
 * Default selectors.
 */
function _sweaver_default_sweaver_selector() {
  $selectors = array();

  $selector = new stdClass;
  $selector->api_version = 1;
  $selector->disabled = FALSE;
  $selector->name = 'allclasses';
  $selector->description = 'All other classes';
  $selector->selector_selector = '';
  $selector->selector_highlight = FALSE;
  $selectors['allclasses'] = $selector;

  $selector = new stdClass;
  $selector->api_version = 1;
  $selector->disabled = FALSE;
  $selector->name = 'allids';
  $selector->description = 'All other id\'s';
  $selector->selector_selector = '';
  $selector->selector_highlight = FALSE;
  $selectors['allids'] = $selector;

  $selector = new stdClass;
  $selector->api_version = 1;
  $selector->disabled = FALSE;
  $selector->name = 'alltags';
  $selector->description = 'All other tags';
  $selector->selector_selector = '';
  $selector->selector_highlight = FALSE;
  $selectors['alltags'] = $selector;

  $selector = new stdClass;
  $selector->api_version = 1;
  $selector->disabled = FALSE;
  $selector->name = 'body';
  $selector->description = 'Body';
  $selector->selector_selector = 'body';
  $selector->selector_highlight = FALSE;
  $selectors['body'] = $selector;

  $selector = new stdClass;
  $selector->api_version = 1;
  $selector->disabled = FALSE;
  $selector->name = 'link';
  $selector->description = 'a link';
  $selector->selector_selector = 'a';
  $selector->selector_highlight = FALSE;
  $selectors['link'] = $selector;

  $selector = new stdClass;
  $selector->api_version = 1;
  $selector->disabled = FALSE;
  $selector->name = 'div';
  $selector->description = 'a region';
  $selector->selector_selector = 'div';
  $selector->selector_highlight = FALSE;
  $selectors['div'] = $selector;

  $selector = new stdClass;
  $selector->api_version = 1;
  $selector->disabled = FALSE;
  $selector->name = 'span';
  $selector->description = 'an item';
  $selector->selector_selector = 'span';
  $selector->selector_highlight = FALSE;
  $selectors['span'] = $selector;

  $selector = new stdClass;
  $selector->api_version = 1;
  $selector->disabled = FALSE;
  $selector->name = 'ul';
  $selector->description = 'an unordered list';
  $selector->selector_selector = 'ul';
  $selector->selector_highlight = FALSE;
  $selectors['ul'] = $selector;

  $selector = new stdClass;
  $selector->api_version = 1;
  $selector->disabled = FALSE;
  $selector->name = 'ol';
  $selector->description = 'an ordered list';
  $selector->selector_selector = 'ol';
  $selector->selector_highlight = FALSE;
  $selectors['ol'] = $selector;

  $selector = new stdClass;
  $selector->api_version = 1;
  $selector->disabled = FALSE;
  $selector->name = 'li';
  $selector->description = 'a list item';
  $selector->selector_selector = 'li';
  $selector->selector_highlight = FALSE;
  $selectors['li'] = $selector;

  $selector = new stdClass;
  $selector->api_version = 1;
  $selector->disabled = FALSE;
  $selector->name = 'h1';
  $selector->description = 'Heading 1';
  $selector->selector_selector = 'h1';
  $selector->selector_highlight = FALSE;
  $selectors['h1'] = $selector;

  $selector = new stdClass;
  $selector->api_version = 1;
  $selector->disabled = FALSE;
  $selector->name = 'h2';
  $selector->description = 'Heading 2';
  $selector->selector_selector = 'h2';
  $selector->selector_highlight = FALSE;
  $selectors['h2'] = $selector;

  $selector = new stdClass;
  $selector->api_version = 1;
  $selector->disabled = FALSE;
  $selector->name = 'h3';
  $selector->description = 'Heading 3';
  $selector->selector_selector = 'h3';
  $selector->selector_highlight = FALSE;
  $selectors['h3'] = $selector;

  $selector = new stdClass;
  $selector->api_version = 1;
  $selector->disabled = FALSE;
  $selector->name = 'p';
  $selector->description = 'a paragraph';
  $selector->selector_selector = 'p';
  $selector->selector_highlight = FALSE;
  $selectors['p'] = $selector;

  $selector = new stdClass;
  $selector->api_version = 1;
  $selector->disabled = FALSE;
  $selector->name = 'form';
  $selector->description = 'a form';
  $selector->selector_selector = 'form';
  $selector->selector_highlight = FALSE;
  $selectors['form'] = $selector;

  $selector = new stdClass;
  $selector->api_version = 1;
  $selector->disabled = FALSE;
  $selector->name = 'label';
  $selector->description = 'a label';
  $selector->selector_selector = 'label';
  $selector->selector_highlight = FALSE;
  $selectors['label'] = $selector;

  $selector = new stdClass;
  $selector->api_version = 1;
  $selector->disabled = FALSE;
  $selector->name = 'input';
  $selector->description = 'an input field';
  $selector->selector_selector = '.form-text';
  $selector->selector_highlight = FALSE;
  $selectors['input'] = $selector;

  $selector = new stdClass;
  $selector->api_version = 1;
  $selector->disabled = FALSE;
  $selector->name = 'textarea';
  $selector->description = 'a textarea';
  $selector->selector_selector = '.form-textarea';
  $selector->selector_highlight = FALSE;
  $selectors['textarea'] = $selector;

  $selector = new stdClass;
  $selector->api_version = 1;
  $selector->disabled = FALSE;
  $selector->name = 'submit';
  $selector->description = 'a submit button';
  $selector->selector_selector = '.form-submit';
  $selector->selector_highlight = FALSE;
  $selectors['submit'] = $selector;

  return $selectors;
}

/**
 * Default properties.
 */
function _sweaver_default_sweaver_property() {
  $propertys = array();

  // Font family.
  $property = new stdClass;
  $property->api_version = 1;
  $property->disabled = FALSE;
  $property->name = 'font-family';
  $property->description = 'Font family';
  $property->property = 'font-family';
  $property->property_parent = '';
  $property->property_type = 'select';
  $property->property_prefix = '';
  $property->property_suffix = '';
  $property->property_slider_min = '';
  $property->property_slider_max = '';
  $property->property_options = array(
        '' => 'Theme default',
        'Arial, Helvetica,Sans-Serif' => 'Arial',
        '\'Arial Black\',Sans-Serif' => 'Arial Black',
        '\'Comic Sans MS\',Cursive' => 'Comic Sans MS',
        '\'Courier New\',Courier,Monospace' => 'Courier',
        'Georgia,Serif' => 'Georgia',
        'Helvetica,Arial,Sans-Serif' => 'Helvetica',
        'Impact,Charcoal,Sans-Serif' => 'Impact',
        '\'Lucida Sans\',\'Lucida Grande\',Sans-Serif' => 'Lucida',
        '\'Palatino Linotype\',Palatino,Serif' => 'Palatino',
        'Tahoma,Geneva,Sans-Serif' => 'Tahoma',
        '\'Times New Roman\',Times,Serif' => 'Times New Roman',
        '\'Trebuchet\',Helvetica,Sans-Serif' => 'Trebuchet',
        'Verdana,Geneva,Sans-Serif' => 'Verdana',
      );
  $propertys['font-family'] = $property;

  // Font style.
  $property = new stdClass;
  $property->api_version = 1;
  $property->disabled = FALSE;
  $property->name = 'font-style';
  $property->description = 'Font style';
  $property->property = 'font-style';
  $property->property_parent = '';
  $property->property_type = 'select';
  $property->property_prefix = '';
  $property->property_suffix = '';
  $property->property_slider_min = '';
  $property->property_slider_max = '';
  $property->property_options = array(
        'normal' => 'Normal',
        'italic' => 'Italic',
      );
  $propertys['font-style'] = $property;

  // Font weight.
  $property = new stdClass;
  $property->api_version = 1;
  $property->disabled = FALSE;
  $property->name = 'font-weight';
  $property->description = 'Font weight';
  $property->property = 'font-weight';
  $property->property_parent = '';
  $property->property_type = 'select';
  $property->property_prefix = '';
  $property->property_suffix = '';
  $property->property_slider_min = '';
  $property->property_slider_max = '';
  $property->property_options = array(
        '400' => 'Normal',
        '800' => 'Bold',
      );
  $propertys['font-weight'] = $property;

  // Font size group
  $property = new stdClass;
  $property->api_version = 1;
  $property->disabled = FALSE;
  $property->name = 'font-size-wrapper';
  $property->description = 'Font size';
  $property->property = '';
  $property->property_parent = '';
  $property->property_type = 'parent';
  $property->property_prefix = '';
  $property->property_suffix = '';
  $property->property_slider_min = '';
  $property->property_slider_max = '';
  $property->property_options = array();
  $propertys['font-size-wrapper'] = $property;

  // Font size
  $property = new stdClass;
  $property->api_version = 1;
  $property->disabled = FALSE;
  $property->name = 'font-size';
  $property->description = 'size';
  $property->property = 'font-size';
  $property->property_parent = 'font-size-wrapper';
  $property->property_type = 'slider';
  $property->property_prefix = '';
  $property->property_suffix = 'px';
  $property->property_slider_min = 1;
  $property->property_slider_max = 200;
  $property->property_options = array();
  $propertys['font-size'] = $property;

  // Line height
  $property = new stdClass;
  $property->api_version = 1;
  $property->disabled = FALSE;
  $property->name = 'line-height';
  $property->description = 'line height';
  $property->property = 'line-height';
  $property->property_parent = 'font-size-wrapper';
  $property->property_type = 'slider';
  $property->property_prefix = '';
  $property->property_suffix = 'px';
  $property->property_slider_min = 1;
  $property->property_slider_max = 200;
  $property->property_options = array();
  $propertys['line-height'] = $property;

  // Text alignment.
  $property = new stdClass;
  $property->api_version = 1;
  $property->disabled = FALSE;
  $property->name = 'text-align';
  $property->description = 'Text alignment';
  $property->property = 'text-align';
  $property->property_parent = '';
  $property->property_type = 'select';
  $property->property_prefix = '';
  $property->property_suffix = '';
  $property->property_slider_min = '';
  $property->property_slider_max = '';
  $property->property_options = array(
        'left' => 'Left',
        'center' => 'Center',
        'right' => 'Right',
        'justify' => 'Justified',
      );
  $propertys['text-align'] = $property;

  // Color.
  $property = new stdClass;
  $property->api_version = 1;
  $property->disabled = FALSE;
  $property->name = 'color';
  $property->description = 'Font color';
  $property->property = 'color';
  $property->property_parent = '';
  $property->property_type = 'color';
  $property->property_prefix = '#';
  $property->property_suffix = '';
  $property->property_slider_min = '';
  $property->property_slider_max = '';
  $property->property_options = array();
  $propertys['color'] = $property;

  // Text-decoration.
  $property = new stdClass;
  $property->api_version = 1;
  $property->disabled = FALSE;
  $property->name = 'text-decoration';
  $property->description = 'Text decoration';
  $property->property = 'text-decoration';
  $property->property_parent = '';
  $property->property_type = 'select';
  $property->property_prefix = '';
  $property->property_suffix = '';
  $property->property_slider_min = '';
  $property->property_slider_max = '';
  $property->property_options = array(
        'none' => 'None',
        'underline' => 'Underline',
        'overline' => 'Overline',
        'line-through' => 'Line through',
      );
  $propertys['text-decoration'] = $property;

  // Background.
  $property = new stdClass;
  $property->api_version = 1;
  $property->disabled = FALSE;
  $property->name = 'background-color';
  $property->description = 'Color';
  $property->property = 'background-color';
  $property->property_parent = '';
  $property->property_type = 'color';
  $property->property_prefix = '#';
  $property->property_suffix = '';
  $property->property_slider_min = '';
  $property->property_slider_max = '';
  $property->property_options = array();
  $propertys['background-color'] = $property;

  $property = new stdClass;
  $property->api_version = 1;
  $property->disabled = FALSE;
  $property->name = 'background-image';
  $property->description = 'Image';
  $property->property = 'background-image';
  $property->property_parent = '';
  $property->property_type = 'image';
  $property->property_prefix = 'url(';
  $property->property_suffix = ')';
  $property->property_slider_min = '';
  $property->property_slider_max = '';
  $property->property_options = array();
  $propertys['background-image'] = $property;

  $property = new stdClass;
  $property->api_version = 1;
  $property->disabled = FALSE;
  $property->name = 'background-repeat';
  $property->description = 'Repeat';
  $property->property = 'background-repeat';
  $property->property_parent = '';
  $property->property_type = 'select';
  $property->property_prefix = '';
  $property->property_suffix = '';
  $property->property_slider_min = '';
  $property->property_slider_max = '';
  $property->property_options = array(
        'no-repeat' => 'None',
        'repeat-x' => 'Horizontally',
        'repeat-y' => 'Vertically',
        'repeat' => 'Both',
      );
  $propertys['background-repeat'] = $property;

  // Background-position.
  $property = new stdClass;
  $property->api_version = 1;
  $property->disabled = FALSE;
  $property->name = 'background-position';
  $property->description = 'Position';
  $property->property = 'background-position';
  $property->property_parent = '';
  $property->property_type = 'select';
  $property->property_prefix = '';
  $property->property_suffix = '';
  $property->property_slider_min = '';
  $property->property_slider_max = '';
  $property->property_options = array(
        'left top' => 'Left top',
        'right top' => 'Right top',
        'left bottom' => 'Left bottom',
        'right bottom' => 'Right bottom',
        'center center' => 'Center center',
        'center bottom' => 'Center bottom',
        'center top' => 'Center top',
      );
  $propertys['background-position'] = $property;

  // Background-attachment.
  $property = new stdClass;
  $property->api_version = 1;
  $property->disabled = FALSE;
  $property->name = 'background-attachment';
  $property->description = 'Attachment';
  $property->property = 'background-attachment';
  $property->property_parent = '';
  $property->property_type = 'select';
  $property->property_prefix = '';
  $property->property_suffix = '';
  $property->property_slider_min = '';
  $property->property_slider_max = '';
  $property->property_options = array(
        'scroll' => 'Scroll',
        'fixed ' => 'Fixed',
      );
  $propertys['background-attachment'] = $property;

  // Padding.
  $property = new stdClass;
  $property->api_version = 1;
  $property->disabled = FALSE;
  $property->name = 'padding';
  $property->description = 'Padding';
  $property->property = '';
  $property->property_parent = '';
  $property->property_type = 'parent';
  $property->property_prefix = '';
  $property->property_suffix = '';
  $property->property_slider_min = '';
  $property->property_slider_max = '';
  $property->property_options = array();
  $propertys['padding'] = $property;

  $property = new stdClass;
  $property->api_version = 1;
  $property->disabled = FALSE;
  $property->name = 'padding-top';
  $property->description = 'Top';
  $property->property = 'padding-top';
  $property->property_parent = 'padding';
  $property->property_type = 'slider';
  $property->property_prefix = '';
  $property->property_suffix = 'px';
  $property->property_slider_min = 0;
  $property->property_slider_max = 500;
  $property->property_options = array();
  $propertys['padding-top'] = $property;

  $property = new stdClass;
  $property->api_version = 1;
  $property->disabled = FALSE;
  $property->name = 'padding-left';
  $property->description = 'Left';
  $property->property = 'padding-left';
  $property->property_parent = 'padding';
  $property->property_type = 'slider';
  $property->property_prefix = '';
  $property->property_suffix = 'px';
  $property->property_slider_min = 0;
  $property->property_slider_max = 500;
  $property->property_options = array();
  $propertys['padding-left'] = $property;

  $property = new stdClass;
  $property->api_version = 1;
  $property->disabled = FALSE;
  $property->name = 'padding-right';
  $property->description = 'Right';
  $property->property = 'padding-right';
  $property->property_parent = 'padding';
  $property->property_type = 'slider';
  $property->property_prefix = '';
  $property->property_suffix = 'px';
  $property->property_slider_min = 0;
  $property->property_slider_max = 500;
  $property->property_options = array();
  $propertys['padding-right'] = $property;

  $property = new stdClass;
  $property->api_version = 1;
  $property->disabled = FALSE;
  $property->name = 'padding-bottom';
  $property->description = 'Bottom';
  $property->property = 'padding-bottom';
  $property->property_parent = 'padding';
  $property->property_type = 'slider';
  $property->property_prefix = '';
  $property->property_suffix = 'px';
  $property->property_slider_min = 0;
  $property->property_slider_max = 500;
  $property->property_options = array();
  $propertys['padding-bottom'] = $property;

  // Margin.
  $property = new stdClass;
  $property->api_version = 1;
  $property->disabled = FALSE;
  $property->name = 'margin';
  $property->description = 'Margin';
  $property->property = '';
  $property->property_parent = '';
  $property->property_type = 'parent';
  $property->property_prefix = '';
  $property->property_suffix = '';
  $property->property_slider_min = '';
  $property->property_slider_max = '';
  $property->property_options = array();
  $propertys['margin'] = $property;

  $property = new stdClass;
  $property->api_version = 1;
  $property->disabled = FALSE;
  $property->name = 'margin-top';
  $property->description = 'Top';
  $property->property = 'margin-top';
  $property->property_parent = 'margin';
  $property->property_type = 'slider';
  $property->property_prefix = '';
  $property->property_suffix = 'px';
  $property->property_slider_min = 0;
  $property->property_slider_max = 500;
  $property->property_options = array();
  $propertys['margin-top'] = $property;

  $property = new stdClass;
  $property->api_version = 1;
  $property->disabled = FALSE;
  $property->name = 'margin-left';
  $property->description = 'Left';
  $property->property = 'margin-left';
  $property->property_parent = 'margin';
  $property->property_type = 'slider';
  $property->property_prefix = '';
  $property->property_suffix = 'px';
  $property->property_slider_min = 0;
  $property->property_slider_max = 500;
  $property->property_options = array();
  $propertys['margin-left'] = $property;

  $property = new stdClass;
  $property->api_version = 1;
  $property->disabled = FALSE;
  $property->name = 'margin-right';
  $property->description = 'Right';
  $property->property = 'margin-right';
  $property->property_parent = 'margin';
  $property->property_type = 'slider';
  $property->property_prefix = '';
  $property->property_suffix = 'px';
  $property->property_slider_min = 0;
  $property->property_slider_max = 500;
  $property->property_options = array();
  $propertys['margin-right'] = $property;

  $property = new stdClass;
  $property->api_version = 1;
  $property->disabled = FALSE;
  $property->name = 'margin-bottom';
  $property->description = 'Bottom';
  $property->property = 'margin-bottom';
  $property->property_parent = 'margin';
  $property->property_type = 'slider';
  $property->property_prefix = '';
  $property->property_suffix = 'px';
  $property->property_slider_min = 0;
  $property->property_slider_max = 500;
  $property->property_options = array();
  $propertys['margin-bottom'] = $property;

  // Border.
  $property = new stdClass;
  $property->api_version = 1;
  $property->disabled = FALSE;
  $property->name = 'border';
  $property->description = 'Border width';
  $property->property = '';
  $property->property_parent = '';
  $property->property_type = 'parent';
  $property->property_prefix = '';
  $property->property_suffix = '';
  $property->property_slider_min = '';
  $property->property_slider_max = '';
  $property->property_options = array();
  $propertys['border'] = $property;

  $property = new stdClass;
  $property->api_version = 1;
  $property->disabled = FALSE;
  $property->name = 'border-top-width';
  $property->description = 'Top';
  $property->property = 'border-top-width';
  $property->property_parent = 'border';
  $property->property_type = 'slider';
  $property->property_prefix = '';
  $property->property_suffix = 'px';
  $property->property_slider_min = 0;
  $property->property_slider_max = 500;
  $property->property_options = array();
  $propertys['border-top-width'] = $property;

  $property = new stdClass;
  $property->api_version = 1;
  $property->disabled = FALSE;
  $property->name = 'border-left-width';
  $property->description = 'Left';
  $property->property = 'border-left-width';
  $property->property_parent = 'border';
  $property->property_type = 'slider';
  $property->property_prefix = '';
  $property->property_suffix = 'px';
  $property->property_slider_min = 0;
  $property->property_slider_max = 500;
  $property->property_options = array();
  $propertys['border-left-width'] = $property;

  $property = new stdClass;
  $property->api_version = 1;
  $property->disabled = FALSE;
  $property->name = 'border-right-width';
  $property->description = 'Right';
  $property->property = 'border-right-width';
  $property->property_parent = 'border';
  $property->property_type = 'slider';
  $property->property_prefix = '';
  $property->property_suffix = 'px';
  $property->property_slider_min = 0;
  $property->property_slider_max = 500;
  $property->property_options = array();
  $propertys['border-right-width'] = $property;

  $property = new stdClass;
  $property->api_version = 1;
  $property->disabled = FALSE;
  $property->name = 'border-bottom-width';
  $property->description = 'Bottom';
  $property->property = 'border-bottom-width';
  $property->property_parent = 'border';
  $property->property_type = 'slider';
  $property->property_prefix = '';
  $property->property_suffix = 'px';
  $property->property_slider_min = 0;
  $property->property_slider_max = 500;
  $property->property_options = array();
  $propertys['border-bottom-width'] = $property;

  // Border color
  $property = new stdClass;
  $property->api_version = 1;
  $property->disabled = FALSE;
  $property->name = 'border-color';
  $property->description = 'Border color';
  $property->property = 'border-top-color border-left-color border-right-color border-bottom-color';
  $property->property_parent = '';
  $property->property_type = 'color';
  $property->property_prefix = '#';
  $property->property_suffix = '';
  $property->property_slider_min = '';
  $property->property_slider_max = '';
  $property->property_options = array();
  $propertys['border-color'] = $property;

  // Border style
  $property = new stdClass;
  $property->api_version = 1;
  $property->disabled = FALSE;
  $property->name = 'border-style';
  $property->description = 'Border style';
  $property->property = 'border-top-style border-left-style border-right-style border-bottom-style';
  $property->property_parent = '';
  $property->property_type = 'select';
  $property->property_prefix = '';
  $property->property_suffix = '';
  $property->property_slider_min = '';
  $property->property_slider_max = '';
  $property->property_options = array(
        'none' => 'None',
        'dashed' => 'Dashed',
        'dotted' => 'Dotted',
        'solid' => 'Solid',
        'double' => 'Double',
        'groove' => 'Groove',
        'inset' => 'Inset',
        'outset' => 'Outset',
        'ridge' => 'Ridge',
  );
  $propertys['border-style'] = $property;

  // Table extras.
  $property = new stdClass;
  $property->api_version = 1;
  $property->disabled = FALSE;
  $property->name = 'border-collapse';
  $property->description = 'Border collapse';
  $property->property = 'border-collapse';
  $property->property_parent = '';
  $property->property_type = 'select';
  $property->property_prefix = '';
  $property->property_suffix = '';
  $property->property_slider_min = '';
  $property->property_slider_max = '';
  $property->property_options = array(
        'collapse' => 'Collapse',
        'separate' => 'Separate',
  );
  $propertys['border-collapse'] = $property;

  $property = new stdClass;
  $property->api_version = 1;
  $property->disabled = FALSE;
  $property->name = 'border-spacing';
  $property->description = 'Border spacing';
  $property->property = 'border-spacing';
  $property->property_parent = '';
  $property->property_type = 'slider';
  $property->property_prefix = '';
  $property->property_suffix = 'px';
  $property->property_slider_min = 0;
  $property->property_slider_max = 500;
  $property->property_options = array();
  $propertys['border-spacing'] = $property;

  $property = new stdClass;
  $property->api_version = 1;
  $property->disabled = FALSE;
  $property->name = 'vertical-align';
  $property->description = 'Vertical align';
  $property->property = 'vertical-align';
  $property->property_parent = '';
  $property->property_type = 'select';
  $property->property_prefix = '';
  $property->property_suffix = '';
  $property->property_slider_min = '';
  $property->property_slider_max = '';
  $property->property_options = array(
        'top' => 'Top',
        'bottom' => 'Bottom',
        'middle' => 'Middle',
  );
  $propertys['vertical-align'] = $property;

  // Width.
  $property = new stdClass;
  $property->api_version = 1;
  $property->disabled = FALSE;
  $property->name = 'width';
  $property->description = 'Width';
  $property->property = 'width';
  $property->property_parent = '';
  $property->property_type = 'slider';
  $property->property_prefix = '';
  $property->property_suffix = 'px';
  $property->property_slider_min = 0;
  $property->property_slider_max = 2000;
  $property->property_options = array();
  $propertys['width'] = $property;

  // Height
  $property = new stdClass;
  $property->api_version = 1;
  $property->disabled = FALSE;
  $property->name = 'height';
  $property->description = 'Height';
  $property->property = 'height';
  $property->property_parent = '';
  $property->property_type = 'slider';
  $property->property_prefix = '';
  $property->property_suffix = 'px';
  $property->property_slider_min = 0;
  $property->property_slider_max = 2000;
  $property->property_options = array();
  $propertys['height'] = $property;

  return $propertys;
}

/**
 * sweaver types.
 */
function _sweaver_default_sweaver_type() {
  $types = array();

  $type = new stdClass;
  $type->api_version = 1;
  $type->disabled = FALSE;
  $type->name = 'block';
  $type->description = 'Block';
  $type->type_options = array(
    'font-family' => 'font-family',
    'font-style' => 'font-style',
    'font-weight' => 'font-weight',
    'font-size' => 'font-size',
    'line-height' => 'line-height',
    'text-align' => 'text-align',
    'color' => 'color',
    'text-decoration' => 'text-decoration',
    'background-color' => 'background-color',
    'background-image' => 'background-image',
    'background-repeat' => 'background-repeat',
    'background-position' => 'background-position',
    'background-attachment' => 'background-attachment',
    'padding-top' => 'padding-top',
    'padding-left' => 'padding-left',
    'padding-right' => 'padding-right',
    'padding-bottom' => 'padding-bottom',
    'margin-top' => 'margin-top',
    'margin-left' => 'margin-left',
    'margin-right' => 'margin-right',
    'margin-bottom' => 'margin-bottom',
    'border-top-width' => 'border-top-width',
    'border-left-width' => 'border-left-width',
    'border-right-width' => 'border-right-width',
    'border-bottom-width' => 'border-bottom-width',
    'border-style' => 'border-style',
    'border-color' => 'border-color',
    'width' => 'width',
    'height' => 'height',
  );
  $types['block'] = $type;

  $type = new stdClass;
  $type->api_version = 1;
  $type->disabled = FALSE;
  $type->name = 'inline';
  $type->description = 'Inline';
  $type->type_options = array(
    'font-family' => 'font-family',
    'font-style' => 'font-style',
    'font-weight' => 'font-weight',
    'font-size' => 'font-size',
    'line-height' => 'line-height',
    'color' => 'color',
    'text-decoration' => 'text-decoration',
    'background-color' => 'background-color',
    'background-image' => 'background-image',
    'background-repeat' => 'background-repeat',
    'background-position' => 'background-position',
    'background-attachment' => 'background-attachment',
    'border-top-width' => 'border-top-width',
    'border-left-width' => 'border-left-width',
    'border-right-width' => 'border-right-width',
    'border-bottom-width' => 'border-bottom-width',
    'border-style' => 'border-style',
    'border-color' => 'border-color',
  );
  $types['inline'] = $type;

  $type = new stdClass;
  $type->api_version = 1;
  $type->disabled = FALSE;
  $type->name = 'inline-block';
  $type->description = 'Inline block';
  $type->type_options = array(
    'font-family' => 'font-family',
    'font-style' => 'font-style',
    'font-weight' => 'font-weight',
    'font-size' => 'font-size',
    'line-height' => 'line-height',
    'text-align' => 'text-align',
    'color' => 'color',
    'text-decoration' => 'text-decoration',
    'background-color' => 'background-color',
    'background-image' => 'background-image',
    'background-repeat' => 'background-repeat',
    'background-position' => 'background-position',
    'background-attachment' => 'background-attachment',
    'padding-top' => 'padding-top',
    'padding-left' => 'padding-left',
    'padding-right' => 'padding-right',
    'padding-bottom' => 'padding-bottom',
    'margin-top' => 'margin-top',
    'margin-left' => 'margin-left',
    'margin-right' => 'margin-right',
    'margin-bottom' => 'margin-bottom',
    'border-top-width' => 'border-top-width',
    'border-left-width' => 'border-left-width',
    'border-right-width' => 'border-right-width',
    'border-bottom-width' => 'border-bottom-width',
    'border-style' => 'border-style',
    'border-color' => 'border-color',
    'width' => 'width',
    'height' => 'height',
  );
  $types['inline-block'] = $type;

  $type = new stdClass;
  $type->api_version = 1;
  $type->disabled = FALSE;
  $type->name = 'inline-table';
  $type->description = 'Inline table';
  $type->type_options = array(
    'font-family' => 'font-family',
    'font-style' => 'font-style',
    'font-weight' => 'font-weight',
    'font-size' => 'font-size',
    'line-height' => 'line-height',
    'text-align' => 'text-align',
    'color' => 'color',
    'text-decoration' => 'text-decoration',
    'background-color' => 'background-color',
    'background-image' => 'background-image',
    'background-repeat' => 'background-repeat',
    'background-position' => 'background-position',
    'background-attachment' => 'background-attachment',
    'margin-top' => 'margin-top',
    'margin-left' => 'margin-left',
    'margin-right' => 'margin-right',
    'margin-bottom' => 'margin-bottom',
    'border-top-width' => 'border-top-width',
    'border-left-width' => 'border-left-width',
    'border-right-width' => 'border-right-width',
    'border-bottom-width' => 'border-bottom-width',
    'border-style' => 'border-style',
    'border-color' => 'border-color',
    'width' => 'width',
    'height' => 'height',
  );
  $types['inline-table'] = $type;

  $type = new stdClass;
  $type->api_version = 1;
  $type->disabled = FALSE;
  $type->name = 'list-item';
  $type->description = 'List item';
  $type->type_options = array(
    'font-family' => 'font-family',
    'font-style' => 'font-style',
    'font-weight' => 'font-weight',
    'font-size' => 'font-size',
    'line-height' => 'line-height',
    'text-align' => 'text-align',
    'color' => 'color',
    'text-decoration' => 'text-decoration',
    'background-color' => 'background-color',
    'background-image' => 'background-image',
    'background-repeat' => 'background-repeat',
    'background-position' => 'background-position',
    'background-attachment' => 'background-attachment',
    'padding-top' => 'padding-top',
    'padding-left' => 'padding-left',
    'padding-right' => 'padding-right',
    'padding-bottom' => 'padding-bottom',
    'margin-top' => 'margin-top',
    'margin-left' => 'margin-left',
    'margin-right' => 'margin-right',
    'margin-bottom' => 'margin-bottom',
    'border-top-width' => 'border-top-width',
    'border-left-width' => 'border-left-width',
    'border-right-width' => 'border-right-width',
    'border-bottom-width' => 'border-bottom-width',
    'border-style' => 'border-style',
    'border-color' => 'border-color',
    'width' => 'width',
    'height' => 'height',
  );
  $types['list-item'] = $type;

  $type = new stdClass;
  $type->api_version = 1;
  $type->disabled = FALSE;
  $type->name = 'run-in';
  $type->description = 'Run in';
  $type->type_options = array(
    'font-family' => 'font-family',
    'font-style' => 'font-style',
    'font-weight' => 'font-weight',
    'font-size' => 'font-size',
    'line-height' => 'line-height',
    'text-align' => 'text-align',
    'color' => 'color',
    'text-decoration' => 'text-decoration',
    'background-color' => 'background-color',
    'background-image' => 'background-image',
    'background-repeat' => 'background-repeat',
    'background-position' => 'background-position',
    'background-attachment' => 'background-attachment',
    'padding-top' => 'padding-top',
    'padding-left' => 'padding-left',
    'padding-right' => 'padding-right',
    'padding-bottom' => 'padding-bottom',
    'margin-top' => 'margin-top',
    'margin-left' => 'margin-left',
    'margin-right' => 'margin-right',
    'margin-bottom' => 'margin-bottom',
    'border-top-width' => 'border-top-width',
    'border-left-width' => 'border-left-width',
    'border-right-width' => 'border-right-width',
    'border-bottom-width' => 'border-bottom-width',
    'border-style' => 'border-style',
    'border-color' => 'border-color',
    'width' => 'width',
    'height' => 'height',
  );
  $types['run-in'] = $type;

  $type = new stdClass;
  $type->api_version = 1;
  $type->disabled = FALSE;
  $type->name = 'table';
  $type->description = 'Table';
  $type->type_options = array(
    'font-family' => 'font-family',
    'font-style' => 'font-style',
    'font-weight' => 'font-weight',
    'font-size' => 'font-size',
    'line-height' => 'line-height',
    'text-align' => 'text-align',
    'color' => 'color',
    'text-decoration' => 'text-decoration',
    'background-color' => 'background-color',
    'background-image' => 'background-image',
    'background-repeat' => 'background-repeat',
    'background-position' => 'background-position',
    'background-attachment' => 'background-attachment',
    'margin-top' => 'margin-top',
    'margin-left' => 'margin-left',
    'margin-right' => 'margin-right',
    'margin-bottom' => 'margin-bottom',
    'border-top-width' => 'border-top-width',
    'border-left-width' => 'border-left-width',
    'border-right-width' => 'border-right-width',
    'border-bottom-width' => 'border-bottom-width',
    'border-style' => 'border-style',
    'border-color' => 'border-color',
    'border-collapse' => 'border-collapse',
    'border-spacing' => 'border-spacing',
    'width' => 'width',
    'height' => 'height',
  );
  $types['table'] = $type;

  $type = new stdClass;
  $type->api_version = 1;
  $type->disabled = FALSE;
  $type->name = 'table-caption';
  $type->description = 'Table caption';
  $type->type_options = array(
    'font-family' => 'font-family',
    'font-style' => 'font-style',
    'font-weight' => 'font-weight',
    'font-size' => 'font-size',
    'line-height' => 'line-height',
    'text-align' => 'text-align',
    'color' => 'color',
    'text-decoration' => 'text-decoration',
    'background-color' => 'background-color',
    'background-image' => 'background-image',
    'background-repeat' => 'background-repeat',
    'background-position' => 'background-position',
    'background-attachment' => 'background-attachment',
    'padding-top' => 'padding-top',
    'padding-left' => 'padding-left',
    'padding-right' => 'padding-right',
    'padding-bottom' => 'padding-bottom',
    'margin-top' => 'margin-top',
    'margin-left' => 'margin-left',
    'margin-right' => 'margin-right',
    'margin-bottom' => 'margin-bottom',
    'border-top-width' => 'border-top-width',
    'border-left-width' => 'border-left-width',
    'border-right-width' => 'border-right-width',
    'border-bottom-width' => 'border-bottom-width',
    'border-style' => 'border-style',
    'border-color' => 'border-color',
    'width' => 'width',
    'height' => 'height',
  );
  $types['table-caption'] = $type;

  $type = new stdClass;
  $type->api_version = 1;
  $type->disabled = FALSE;
  $type->name = 'table-cell';
  $type->description = 'Table cell';
  $type->type_options = array(
    'font-family' => 'font-family',
    'font-style' => 'font-style',
    'font-weight' => 'font-weight',
    'font-size' => 'font-size',
    'line-height' => 'line-height',
    'text-align' => 'text-align',
    'vertical-align' => 'vertical-align',
    'color' => 'color',
    'text-decoration' => 'text-decoration',
    'background-color' => 'background-color',
    'background-image' => 'background-image',
    'background-repeat' => 'background-repeat',
    'background-position' => 'background-position',
    'background-attachment' => 'background-attachment',
    'padding-top' => 'padding-top',
    'padding-left' => 'padding-left',
    'padding-right' => 'padding-right',
    'padding-bottom' => 'padding-bottom',
    'height' => 'height',
  );
  $types['table-cell'] = $type;

  $type = new stdClass;
  $type->api_version = 1;
  $type->disabled = FALSE;
  $type->name = 'table-header-group';
  $type->description = 'Table header';
  $type->type_options = array(
    'font-family' => 'font-family',
    'font-style' => 'font-style',
    'font-weight' => 'font-weight',
    'font-size' => 'font-size',
    'line-height' => 'line-height',
    'text-align' => 'text-align',
    'vertical-align' => 'vertical-align',
    'color' => 'color',
    'text-decoration' => 'text-decoration',
    'background-color' => 'background-color',
    'background-image' => 'background-image',
    'background-repeat' => 'background-repeat',
    'background-position' => 'background-position',
    'background-attachment' => 'background-attachment',
    'padding-top' => 'padding-top',
    'padding-left' => 'padding-left',
    'padding-right' => 'padding-right',
    'padding-bottom' => 'padding-bottom',
    'height' => 'height',
  );
  $types['table-header-group'] = $type;

  $type = new stdClass;
  $type->api_version = 1;
  $type->disabled = FALSE;
  $type->name = 'table-footer-group';
  $type->description = 'Table footer';
  $type->type_options = array(
    'font-family' => 'font-family',
    'font-style' => 'font-style',
    'font-weight' => 'font-weight',
    'font-size' => 'font-size',
    'line-height' => 'line-height',
    'text-align' => 'text-align',
    'vertical-align' => 'vertical-align',
    'color' => 'color',
    'text-decoration' => 'text-decoration',
    'background-color' => 'background-color',
    'background-image' => 'background-image',
    'background-repeat' => 'background-repeat',
    'background-position' => 'background-position',
    'background-attachment' => 'background-attachment',
    'padding-top' => 'padding-top',
    'padding-left' => 'padding-left',
    'padding-right' => 'padding-right',
    'padding-bottom' => 'padding-bottom',
    'height' => 'height',
  );
  $types['table-footer-group'] = $type;

  $type = new stdClass;
  $type->api_version = 1;
  $type->disabled = FALSE;
  $type->name = 'table-row';
  $type->description = 'Table row';
  $type->type_options = array(
    'font-family' => 'font-family',
    'font-style' => 'font-style',
    'font-weight' => 'font-weight',
    'font-size' => 'font-size',
    'line-height' => 'line-height',
    'text-align' => 'text-align',
    'vertical-align' => 'vertical-align',
    'color' => 'color',
    'text-decoration' => 'text-decoration',
    'background-color' => 'background-color',
    'background-image' => 'background-image',
    'background-repeat' => 'background-repeat',
    'background-position' => 'background-position',
    'background-attachment' => 'background-attachment',
  );
  $types['table-row'] = $type;

  return $types;
}
