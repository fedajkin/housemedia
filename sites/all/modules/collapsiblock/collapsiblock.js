// $Id: collapsiblock.js,v 1.8 2010/10/02 00:42:28 gagarine Exp $

Drupal.Collapsiblock = Drupal.Collapsiblock || {};

Drupal.behaviors.collapsiblock = function (context) {
  var cookieData = Drupal.Collapsiblock.getCookieData();
  var slidetype = Drupal.settings.collapsiblock.slide_type;
  var defaultState = Drupal.settings.collapsiblock.default_state;
  var slidespeed = parseInt(Drupal.settings.collapsiblock.slide_speed);
  var title = Drupal.settings.collapsiblock.block_title;
  var block = Drupal.settings.collapsiblock.block;
  var block_content = Drupal.settings.collapsiblock.block_content;
  $(block + ':not(.collapsiblock-processed)', context).addClass('collapsiblock-processed').each(function () {
    var id = this.id;
    var titleElt = $(title, this).not($('.content :header',this));
    if (titleElt.size()) {
      titleElt = titleElt[0];
      // Status values: 1 = not collapsible, 2 = collapsible and expanded, 3 = collapsible and collapsed, 4 = always collapsed
      var stat = Drupal.settings.collapsiblock.blocks[this.id] ? Drupal.settings.collapsiblock.blocks[this.id] : defaultState;
      if (stat == 1) {
        return;
      }

      titleElt.target = $(this).find(block_content);
      $(titleElt)
      .wrapInner('<a href="#" role="link" />')
      .addClass('collapsiblock')
      .click(function (e) {
        var st = Drupal.Collapsiblock.getCookieData();
        if ($(this).is('.collapsiblockCollapsed')) {
          $(this).removeClass('collapsiblockCollapsed');
          if (slidetype == 1) {
            $(this.target).slideDown(slidespeed).attr('aria-hidden', false); ;
          }
          else {
            $(this.target).animate({
              height:'show',
              opacity:'show'
            }, slidespeed);
          }

          // Don't save cookie data if the block is always collapsed.
          if (stat != 4) {
            st[id] = 1;
          }
        }
        else {
          $(this).addClass('collapsiblockCollapsed');
          if (slidetype == 1) {
            $(this.target).slideUp(slidespeed).attr('aria-hidden', true);
          }
          else {
            $(this.target).animate({
              height:'hide',
              opacity:'hide'
            }, slidespeed);
          }

          // Don't save cookie data if the block is always collapsed.
          if (stat != 4) {
            st[id] = 0;
          }
        }
        // Stringify the object in JSON format for saving in the cookie.
        var cookieString = '{ ';
        var cookieParts = [];
        $.each(st, function (id, setting) {
          cookieParts[cookieParts.length] = ' "' + id + '": ' + setting;
        });
        cookieString += cookieParts.join(', ') + ' }';
        $.cookie('collapsiblock', cookieString, {
          path: Drupal.settings.basePath
          });
        e.preventDefault();
      });
      // Leave active blocks uncollapsed. If the block is expanded, do nothing.
      if (stat ==  4 || (cookieData[id] == 0 || (stat == 3 && cookieData[id] == undefined)) && !$(this).find('a.active').size()) {
        $(titleElt).addClass('collapsiblockCollapsed');
        $(titleElt.target).hide();
      }
    }
  });
};

Drupal.Collapsiblock.getCookieData = function () {
  var cookieString = $.cookie('collapsiblock');
  return cookieString ? Drupal.parseJson(cookieString) : {};
};

  

