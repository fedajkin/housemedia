/* $Id: sweaver_plugin_styles.js,v 1.1.2.11 2010/11/03 22:57:29 swentel Exp $ */

/**
 * @file
 * Styles javascript.
 */

/**
 * Start autosave poller.
 */
$(document).ready(function() {
  var span = 0;
  if (Drupal.settings.sweaver['autosave'] != undefined) {
	var interval = Drupal.settings.sweaver['autosave'];
    if (parseInt(interval) > 0) {
      var interval = (interval * 1000) + span;
      var autosave = setInterval('Drupal.Sweaver.AutoSave()', interval);
      span += 100;
    }
  }
});

/**
 * Autosave function.
 */
Drupal.Sweaver.AutoSave = function(context) {
  if (Drupal.Sweaver.changed) {
    Drupal.Sweaver.changed = false;
	  
    // Get values for css, customcss & palette (if available)
    var css = $('#edit-css').val();
    if ($('#edit-sweaver-plugin-custom-css').length) {
      var customcss = $('#edit-sweaver-plugin-custom-css').val();      
    }
    else {
      var customcss = '';            
    }
    if ($('#edit-sweaver-plugin-palette').length) {
      var palette = $('#edit-sweaver-plugin-palette').val();
    }
    else {
      var palette = '';
    }

    $.ajax({
      type: "POST",
      url: Drupal.settings.basePath + 'index.php?q=sweaver-autosave',
      data: {
        css: css,
        customcss: customcss,
        palette: palette        
      },
      dataType: 'json',
      timeout: 5000,
      success: function(data){
        if (typeof data['message'] == 'undefined' || data['message'] != 0) {
          Drupal.Sweaver.setMessage(Drupal.t('Your changes have been saved.'), 2000);
        }
        if (typeof data['error'] == 'undefined' || data['error'] != 0) {
          Drupal.Sweaver.setMessage(Drupal.t('Your changes have been saved.'), 2000);
        }
      },
      error: function() {
        Drupal.Sweaver.setMessage(Drupal.t('There was an error saving current changes!'), 2000);
      }
    });
    return false;
  }	  
}

/**
 * Behaviors for style actions.
 */
Drupal.behaviors.StylesActions = function(context) {
  $("#style-actions-data-1 select.radio-style-save-type").change(function() {
    var radio_style_save_type = $("#style-actions-data-1 select.radio-style-save-type option:selected").val();
    if (radio_style_save_type == 1) {
      $('#edit-save-style').hide();
      $('#edit-style-existing-id').show();
    }
    else {
      $('#edit-save-style').show();
      $('#edit-style-existing-id').hide();
    }
  });

  $("#sweaver-popup #edit-delete-confirm").click(function() {
    $('#sweaver-popup .delete-style-confirm').hide();
    $('#sweaver-popup .delete-style-question').show();
    return false;
  });

  $("#sweaver-popup #edit-delete-cancel").click(function() {
    $('#sweaver-popup .delete-style-confirm').show();
    $('#sweaver-popup .delete-style-question').hide();
    return false;
  });
}