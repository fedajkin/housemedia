/**
 * @file
 * Shape based marker filter implementation
 */

Drupal.geo_search = Drupal.geo_search || {};


Drupal.gmap.addHandler('gmap', function (elem) {
  var obj = this;

  obj.bind("init", function () {
    if (obj.vars.behavior.geo_search) {
      Drupal.geo_search.factoryArea(obj);

      // Add refresh search button
      Drupal.geo_search.refresh_search_control = new 
        Drupal.geo_search.SearchRefreshControl(obj);

     obj.map.addControl(Drupal.geo_search.refresh_search_control);
     var overlay = $(obj.map.getContainer()).
        parent().
        prepend('<div class="overlay"></div>').
        find('.overlay');

      overlay.css('display', 'none');
      overlay.css('width', $(obj.map.getContainer()).css('width'));
      overlay.css('height', $(obj.map.getContainer()).css('height'));
      overlay.css('position', 'absolute');
    }
  });
});


/**
 * Place all dynamic markers on overlay. We wont use an gmap api, we will
 * use gmap module js api. See marker_static.js from gmap module 
 * for more details.
 */
Drupal.geo_search.placeResults = function (markers, obj) {
  for (i = 0; i < markers.length; i++) {
    var marker = markers[i];

    // Event handlers require this.
    if (!marker.opts) {
      marker.opts = {};
    }

    // Pass around the object, bindings can change it if necessary.
    obj.change('preparemarker', -1, marker);
    // And add it.
    obj.change('addmarker', -1, marker);
  }

  obj.change('markersready', -1);
};


/**
 * Factory method for search area polyline object.
 */
Drupal.geo_search.factoryArea = function(obj) {
  obj.map.clearOverlays();
  obj.search_area = null;

  // Create polyline. This will be 
  // out basic for content filtering
  obj.search_area = new GPolygon(
    [], 
    "#ff0000", 
    3, 
    1, 
    '#ff0000',
    0,
    {
      clickable: true,
      geodesic: false
    }
  );
  // Now add this as overlay to existing map object
  obj.map.addOverlay(obj.search_area);

  // Enable drawing mode
  obj.search_area.enableDrawing();
  GEvent.addListener(obj.search_area, "endline", function() {
    Drupal.geo_search.control = new Drupal.geo_search.SearchControl(obj);
    obj.map.addControl(Drupal.geo_search.control);
  });
  GEvent.addListener(obj.search_area, "cancelline", function() {
    callback = Drupal.geo_search.refresh_search_control._restartSearch();
    callback();
  });
};


Drupal.geo_search.showNoResultInfo = function(gmap_data) {
  var overlay = $(gmap_data.map.getContainer()).parent();
  Drupal.geo_search.toggleBlendIndicator(gmap_data, true);
  overlay.prepend('<div class="overlay-message"><b>'+ Drupal.t("No results found") +'</b></div>'); 
  var message = overlay.find('.overlay-message').click(function () {
    $(this).remove();
    Drupal.geo_search.toggleBlendIndicator(gmap_data, false);
    callback = Drupal.geo_search.refresh_search_control._restartSearch();
    callback();
  });
  $('.overlay-message').css('left', $(gmap_data.map.getContainer()).width() / 2 - 100);
  $('.overlay-message').css('top', $(gmap_data.map.getContainer()).height() / 2 - 10);
};


Drupal.geo_search.toggleBlendIndicator = function(gmap_data, toogle) {
  var overlay = $(gmap_data.map.getContainer()).parent().find('.overlay');
  toogle ? overlay.css('display', 'block') : overlay.css('display', 'none');
};


Drupal.geo_search.toggleAjaxIndicator = function(gmap_data, toogle) {
  var overlay = $(gmap_data.map.getContainer()).parent().find('.overlay');
  toogle ? overlay.css('display', 'block') : overlay.css('display', 'none');
};
