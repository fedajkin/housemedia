// $Id: privacy_status_dialog.js,v 1.1.2.4 2009/08/07 10:38:29 markuspetrux Exp $

(function ($) {

/**
 * Private namespace for local methods and properties.
 */
Drupal.CCKPrivateFieldsDialog = Drupal.CCKPrivateFieldsDialog || {};

/**
 * Drupal behavior for CCK Private Fields dialog.
 */
Drupal.behaviors.CCKPrivateFieldsDialog = function(context) {
  var self = Drupal.CCKPrivateFieldsDialog, settings = Drupal.settings.CCKPrivateFields;

  // Target fields in multigroups when using table with multiple columns.
  $('.content-multiple-table:not(.cck-private-field-processed)').addClass('cck-private-field-processed').each(function() {
    var $group_table = $(this);
    var group_table_id = $group_table.attr('id');
    for (var fieldName in settings.privateFields) {
      if (settings.privateFields[fieldName].group_type == 'multigroup' && settings.privateFields[fieldName].multiple_columns && settings.privateFields[fieldName].group_table_id == group_table_id) {
        var $headerCell = $('th.content-multigroup-cell-'+ fieldName.replace(/_/g, '-'), $group_table);
        $headerCell.wrapInner('<div class="cck-private-field-table-header"></div>');
        $headerCell.wrapInner('<div class="cck-private-field-wrapper cck-private-field-wrapper-single cck-private-field-name-'+ fieldName +'"></div>');
        $('.cck-private-field-wrapper', $headerCell).append($('<div class="cck-private-field-status-icon"/>'));
      }
    }
  });

  $('.cck-private-field-wrapper:not(.cck-private-field-processed)').addClass('cck-private-field-processed').each(function() {
    var $wrapper = $(this);
    var $statusIcon = $('.cck-private-field-status-icon', $wrapper);
    var hoverClass = ($wrapper.hasClass('cck-private-field-wrapper-multiple') ? 'cck-private-field-wrapper-multiple-hover' : 'cck-private-field-wrapper-single-hover');
    var fieldName = this.className.replace(/^.*cck-private-field-name-(field_[_a-z0-9]+).*$/, '$1');

    self.setStatusIcon(context, fieldName, $statusIcon);

    $statusIcon.bind('click', function() {
      self.openDialog(context, fieldName);
      return false;
    }).hover(
      function() { $wrapper.addClass(hoverClass); },
      function() { $wrapper.removeClass(hoverClass); }
    );
  });
};

/**
 * CCK Private Fields dialog.
 */
Drupal.CCKPrivateFieldsDialog.setStatusIcon = function(context, fieldName, $statusIcon) {
  var self = this, settings = Drupal.settings.CCKPrivateFields;

  var privacyStatus = $('input[name="cck_private_fields['+ fieldName +']"]', context).val();
  if (!settings.privacyStatusOptions[privacyStatus]) {
    privacyStatus = 0;
  }
  $statusIcon.fadeOut('fast', function() {
    $statusIcon.each(function() {
      this.className = 'cck-private-field-status-icon cck-private-field-status-icon-'+ fieldName +' '+ settings.privacyStatusOptions[privacyStatus]['class'];
    });
    $statusIcon.attr('title', Drupal.t('Privacy status: @status. Click here to change...', {'@status': settings.privacyStatusOptions[privacyStatus]['name']}));
    $statusIcon.fadeIn('normal');
  });
};

/**
 * CCK Private Fields dialog.
 */
Drupal.CCKPrivateFieldsDialog.openDialog = function(context, fieldName) {
  var self = this, settings = Drupal.settings.CCKPrivateFields;

  // Build the dialog container.
  var $dialogContainer;
  if ($('#cck-private-field-dialog-container').size()) {
    $dialogContainer = $('#cck-private-field-dialog-container');
  }
  else {
    $dialogContainer = $('<div id="cck-private-field-dialog-container"/>');
    $('body').append($dialogContainer);
  }

  // Update the dialog container with a form for the given field.
  $dialogContainer.empty().append($(settings.privacyStatusForm.replace(/@field/g, settings.privateFields[fieldName].label)));

  // Replace the form action to make sure it is never submitted.
  $('form', $dialogContainer).attr('action', 'javascript:void(0)');

  // Get the current privacy status for this field from the corresponding
  // hidden element in the form.
  var privacyStatus = $('input[name="cck_private_fields['+ fieldName +']"]', context).val();

  // Set the privacy status in the dialog form element.
  $('input[name="cck-private-fields-dialog-status-options"][value='+ privacyStatus +']', $dialogContainer).attr('checked', 'checked');

  // Attach onclick callback to 'Ok' button to update the privacy status in the
  // corresponding hidden element, and then close the dialog.
  $('#edit-cck-private-fields-dialog-status-button-ok', $dialogContainer).bind('click', function() {
    var privacyStatus = $('input[name="cck-private-fields-dialog-status-options"]:checked', $dialogContainer).val();
    $('input[name="cck_private_fields['+ fieldName +']"]', context).val(privacyStatus);
    self.setStatusIcon(context, fieldName, $('.cck-private-field-status-icon-'+ fieldName));
    $dialogContainer.dialog('close');
    return false;
  });

  // Attach onclick callback to 'Cancel' button to close the dialog.
  $('#edit-cck-private-fields-dialog-status-button-cancel', $dialogContainer).bind('click', function() {
    $dialogContainer.dialog('close');
    return false;
  });

  function destroyDialog() {
    $dialogContainer.dialog('destroy').remove();
    self.fixPosition($('.cck-private-field-dialog'), false);
  };

  // Allow themers override the modal dialog size (in pixels).
  var dialogSize = Drupal.theme('CCKPrivateFieldsDialogSize');

  $dialogContainer.closing = false;
  $dialogContainer.dialog({
    modal: true,
    autoOpen: false,
    closeOnEscape: true,
    resizable: false,
    title: Drupal.t('Choose an option...'),
    dialogClass: 'cck-private-field-dialog',
    open: function() {
      $('.cck-private-field-dialog .ui-dialog-titlebar-close').attr('title', Drupal.t('Close'));
      self.fixPosition($('.cck-private-field-dialog'), true);
    },
    beforeclose: function() {
      if ($.browser.msie) {
        return true;
      }
      if (!$dialogContainer.closing) {
        $dialogContainer.closing = true;
        $('.cck-private-field-dialog').animate({height: 'hide', opacity: 'hide'}, 200, function() {
          destroyDialog();
        });
      }
      return false;
    },
    close: function() {
      destroyDialog();
    },
    width: dialogSize.width,
    height: dialogSize.height
  });

  $dialogContainer.dialog('open');
  if (!$.browser.msie) {
    $('.cck-private-field-dialog').hide().animate({height: 'show', opacity: 'show'});
  }
};

/**
 * Fix the position of the modal frame.
 *
 * Possible alternative to position:'fixed' for IE6:
 * @see http://www.howtocreate.co.uk/fixedPosition.html
 */
Drupal.CCKPrivateFieldsDialog.fixPosition = function($element, isOpen) {
  var $window = $(window);
  if ($.browser.msie && parseInt($.browser.version) <= 6) {
    // IE6 does not support position:'fixed'.
    // Lock the window scrollBar instead.
    if (isOpen) {
      var yPos = $window.scrollTop();
      var xPos = $window.scrollLeft();
      $window.bind('scroll.cck-private-field-event', function() {
        window.scrollTo(xPos, yPos);
        // Default browser action cannot be prevented here.
      });
    }
    else {
      $window.unbind('scroll.cck-private-field-event');
    }
  }
  else {
    // Use CSS to do it on other browsers.
    if (isOpen) {
      var offset = $element.offset();
      $element.css({
        left: (offset.left - $window.scrollLeft()),
        top: (offset.top - $window.scrollTop()),
        position: 'fixed'
      });
    }
  }
};

/**
 * Allow themers override the modal dialog size (in pixels).
 */
Drupal.theme.prototype.CCKPrivateFieldsDialogSize = function() {
  return {width: 500, height: 250};
};

})(jQuery);
