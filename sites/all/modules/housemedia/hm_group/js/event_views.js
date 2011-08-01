if (Drupal.jsEnabled) {
  Drupal.behaviors.hmGroupJsCalendar = function(context) {
    $('.js_calendar_link:not(.js_calendar_link-processed)').each(function () {
      $(this).addClass('js_calendar_link-processed');
      $(this).click(function () {
        $('.view-id-group_event_calendar').parent().load($(this).attr('href'), function () { Drupal.attachBehaviors();} );
        return false;
      }
      )
    })
  };
}
