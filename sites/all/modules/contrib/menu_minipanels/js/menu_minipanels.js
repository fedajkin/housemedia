// $Id: menu_minipanels.js,v 1.6 2011/01/09 09:03:40 willieseabrook Exp $

/**
 * In admin menu edit, this hides and closes the qTip config
 * depending on whether a minipanel is selected.
 * 
 * On every page, it adds minipanel hovers to any menu items that have minipanel
 * qTip config arrays specified in the page footer
 */
Drupal.behaviors.menuMiniPanels = function(context) {
  // In the administration section, hide hover settings unless a minipanel is selected
  var toggleHoverSettings = function() {
    if($('#edit-menu-options-minipanel').val() == '' && $('#menu-minipanels-hover-settings').is(':visible')) {
      $('#menu-minipanels-hover-settings').slideUp(500);
    }
    else if($('#edit-menu-options-minipanel').val() != '') {
      $('#menu-minipanels-hover-settings').slideDown(500);
    }
  }
  
  $('#edit-menu-options-minipanel').change(function(e) {
    toggleHoverSettings();
  });
  
  // Set appropriate on load
  toggleHoverSettings();

  // Add the hovers to each appropriate menu item.
  $('ul li a.menu-minipanel').each(function() {
	var matches = $(this).attr('class').match('menu-minipanel-([0-9]+)');
    var html = $('div.menu-minipanel-' + matches[1]).clone().show();
    var settings = Drupal.settings.menuMinipanels.panels['panel_' + matches[1]];
    settings['hide']['fixed'] = true;
    // Specify a custom target.
    if (settings['position']['target'] == 'custom') {
      var target = $(settings['position']['target_custom']);
      if (target.length > 0) {
        settings['position']['target'] = target;
      }
      else {
        settings['position']['target'] = false; 
      }
    }
    else {
      settings['position']['target'] = false; 
    }
    settings['content'] = html;
    $(this).qtip(settings);
  });
};
