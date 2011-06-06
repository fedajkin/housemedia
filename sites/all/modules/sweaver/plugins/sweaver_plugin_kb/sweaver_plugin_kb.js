/* $Id: sweaver_plugin_kb.js,v 1.1.2.13 2010/11/08 19:24:51 swentel Exp $ */

/**
 * Add key bindings when the Styles plugin is enabled.
 *
 * List of key bindings can be found at
 * http://www.weverwijk.net/wordpress/2010/03/23/key-events-in-javascript/
 *
 * More inspiration :
 * - http://rikrikrik.com/jquery/shortkeys/#download
 * - http://code.google.com/p/js-hotkeys/
 * - http://code.google.com/p/js-hotkeys/wiki/about
 */

var kb_popup = '';

/**
 * Bind the keys.
 */
$(document).ready(function() {
  $.each(Drupal.settings.sweaver['kb'], function (index, key_binding) {
    if (key_binding.element != '' && $(key_binding.element).length == 0) {
      return; 
    }
    $(document).bind('keydown', {combi: key_binding.combination, disableInInput: true}, function(event) {
      Drupal.Sweaver.kbShowPopup(index, key_binding.element);
    });
  });
});

/**
 * Show or close the popup.
 */
Drupal.Sweaver.kbShowPopup = function(type, element) {
  if (type != kb_popup && element != '') {
    kb_popup = type;
    Drupal.Sweaver.showPopup($(element), '400px', '200px');
  }
  else {
    kb_popup = '';
    Drupal.Sweaver.hidePopup();
  }
}
