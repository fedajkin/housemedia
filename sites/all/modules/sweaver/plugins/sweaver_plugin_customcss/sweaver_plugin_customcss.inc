<?php
// $Id: sweaver_plugin_customcss.inc,v 1.1.2.9 2010/09/30 13:54:03 swentel Exp $

/**
 * @file
 * Custom CSS plugin.
 */
class sweaver_plugin_customcss extends sweaver_plugin {

  /**
   * Frontend form.
   */
  public function sweaver_form() {

    $current_style = Sweaver::get_instance()->get_current_style();

    $form = array();
    $attributes = array();
    $form['sweaver_plugin_custom_css'] = array(
      '#type' => 'textarea',
      '#rows' => 10,
      '#cols' => 80,
      '#resizable' => FALSE,
      '#wysiwyg' => FALSE,
      '#attributes' => array(
        'class' => 'sweaver-400',
      ),
      '#default_value' => (isset($current_style->customcss)) ? $current_style->customcss : '',
      '#prefix' => '<div class="form-floater">',
    );
    $form['sweaver_plugin_custom_css_button'] = array(
      '#type' => 'button',
      '#value' => t('Apply'),
      '#suffix' => '</div>',
    );

    return $form;
  }

  /**
   * Frontend form submit handler.
   */
  function sweaver_form_submit($form, &$form_state) {
    $clicked_button = $form_state['clicked_button']['#value'];

    if (($clicked_button == t('Save and continue') || $clicked_button == t('Save and publish') || $clicked_button == t('Publish style')) && isset($form_state['style_id'])) {
      db_query("UPDATE {sweaver_style_draft} set customcss = '%s' WHERE style_id = %d", $form_state['values']['sweaver_plugin_custom_css'], $form_state['style_id']);
      if ($form_state['publish']) {
        db_query("UPDATE {sweaver_style} set customcss = '%s' WHERE style_id = %d", $form_state['values']['sweaver_plugin_custom_css'], $form_state['style_id']);
      }
    }
  }

  /**
   * Frontend css and js.
   */
  public function sweaver_form_css_js(&$inline_settings) {
    drupal_add_js(drupal_get_path('module', 'sweaver') .'/plugins/sweaver_plugin_customcss/sweaver_plugin_customcss.js', 'module');
    $inline_settings['sweaver']['invokes'][] = 'sweaver_plugin_customcss';
  }
}