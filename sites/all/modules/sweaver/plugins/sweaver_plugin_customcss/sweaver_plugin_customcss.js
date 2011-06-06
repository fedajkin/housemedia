/* $Id: sweaver_plugin_customcss.js,v 1.1.2.3 2010/09/18 13:33:25 swentel Exp $ */

/**
 * Implementation of HOOK_updateCss().
 * 
 * Return custom css.
 */
sweaver_plugin_customcss_updateCss = function() {
  var fullCss = '';
  fullCss = $('#edit-sweaver-plugin-custom-css').val();
  return fullCss;
}

/**
 * Preview button onclick behavior.
 */
Drupal.behaviors.SweaverCustomCss = function(context) {
  $('#edit-sweaver-plugin-custom-css-button').click(function(){
    Drupal.Sweaver.writeCss();
    Drupal.Sweaver.setMessage(Drupal.t('Your custom css has been succesfully applied.'), 5000);
    return false;
  });
}