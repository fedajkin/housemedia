/**
 * @file
 * This file includes custom control for GMAP API v2
 *
 * It is made by "inheriting" GControl class, which 
 * adds two additional buttons (search for properties / search 
 * for investements)
 */
Drupal.geo_search = Drupal.geo_search || {};

Drupal.geo_search.SearchControl = function (obj) {
  this.gmap_data = obj;
};

Drupal.geo_search.SearchControl.prototype = new GControl();




/**
 * Implementation of parent::getDefaultPosition method.
 *
 * This one should place control on pretty center of map widget.
 */
Drupal.geo_search.SearchControl.prototype.getDefaultPosition = function() {
  size = this.map.getSize();
  return new GControlPosition(
    G_ANCHOR_TOP_LEFT, 
    new GSize((size.width / 2) - 60, (size.height / 2) - 60)
  );
};


/**
 * Implementation of parent::initialize method.
 *
 * This one adds two buttons (search for investement, search for property)
 */
Drupal.geo_search.SearchControl.prototype.initialize = function(map) {
  // getDefaultPosition() will need that.
  this.map = map;

  // TODO: How to create something similar in jquery?
  // We need to create Node and TextNode objects
  widget_wrapper = document.createElement("div");
  button1_content = document.createTextNode(Drupal.t("Search for Investenments"));
  button2_content = document.createTextNode(Drupal.t("Search for Properties"));
  button3_content = document.createTextNode(Drupal.t("Search for Advisor"));
  button1_wrapper = this._prepareButtonStyle(document.createElement("div"));
  button2_wrapper = this._prepareButtonStyle(document.createElement("div"));
  button3_wrapper = this._prepareButtonStyle(document.createElement("div"));

  $(button1_wrapper).attr('class', 'gmap-search-button');
  $(button2_wrapper).attr('class', 'gmap-search-button');
  $(button3_wrapper).attr('class', 'gmap-search-button');


  widget_wrapper.appendChild(button1_wrapper);
  // Add event listener for both buttons
  GEvent.addDomListener(button1_wrapper, "click", this._handleSearch("group"));
  button1_wrapper.appendChild(button1_content);

  widget_wrapper.appendChild(button2_wrapper);
  GEvent.addDomListener(button2_wrapper, "click", this._handleSearch("mieszkanie"));
  button2_wrapper.appendChild(button2_content);

  widget_wrapper.appendChild(button3_wrapper);
  GEvent.addDomListener(button3_wrapper, "click", this._handleSearch("doradca"));
  button3_wrapper.appendChild(button3_content);



  map.getContainer().appendChild(widget_wrapper);
  return widget_wrapper;
};


/**
 * Helper function.
 *
 * Set proper style for control buttons.
 */
Drupal.geo_search.SearchControl.prototype._prepareButtonStyle = function(
    element) {
  element.style.width = "12em";
  return element;
};


/**
 * Search for properties search button click handler.
 *
 * This function will make an ajax request to backend and retrieve list 
 * of properties from backend.
 */
Drupal.geo_search.SearchControl.prototype._handleSearch = function(node_type) {  
  // We do this functional way => simple create and return event callback.
  // (By default, callback is call in static way, without object state as an context).
  handler_gmap_data = this.gmap_data;


  return function() {
    // Remove search buttons
    handler_gmap_data.map.removeControl(
      Drupal.geo_search.control
    );


    Drupal.geo_search.toggleAjaxIndicator(handler_gmap_data, true);
    sw_bond = handler_gmap_data.search_area.getBounds().getSouthWest();
    ne_bond = handler_gmap_data.search_area.getBounds().getNorthEast();
    data = {
      'type' : node_type,
      'ne_lat' : ne_bond.lat(),
      'ne_lon' : ne_bond.lng(),
      'sw_lat' : sw_bond.lat(),
      'sw_lon' : sw_bond.lng() 
    };

    size = handler_gmap_data.search_area.getVertexCount();

    for (i = 0; i < size; i++) {
      vertex = handler_gmap_data.search_area.getVertex(i);
      data['point_' + i + '_lat'] = vertex.lat();
      data['point_' + i + '_lng'] = vertex.lng();
    }

    Drupal.geo_search.toggleAjaxIndicator(handler_gmap_data, true);
    $.post(
      Drupal.settings.hm_gmap_search.search_url,
      data,
      function (data) {
        // Enable search again button.

        parsed_data = Drupal.parseJson(data);
        Drupal.geo_search.toggleAjaxIndicator(handler_gmap_data, false);

        if (!parsed_data.status || parsed_data.status === 0) {
          handler_gmap_data.change('clearmarkers', -1);

          if (parsed_data.length > 0) {
            Drupal.geo_search.placeResults(parsed_data, handler_gmap_data);
          }
          else {
            Drupal.geo_search.showNoResultInfo(handler_gmap_data);
          };

        }
      }
    );
  };
};


/**
 * Search for investement search button click handler.
 *
 * This function will make an ajax request to backend and retrieve list 
 * of properties from backend.
 */
Drupal.geo_search.SearchControl.prototype._handleInvestSearch = function(
) {
  // Same story as at _handlerPropertiesSearch.
  return function() {
  };
};


Drupal.geo_search.SearchRefreshControl = function (obj) {
  this.gmap_data = obj;
};

Drupal.geo_search.SearchRefreshControl.prototype = new GControl();


/**
 * Implementation of parent::initialize method.
 *
 * This one adds two buttons (search for investement, search for property)
 */
Drupal.geo_search.SearchRefreshControl.prototype.initialize = function(map) {
  // getDefaultPosition() will need that.
  this.map = map;

  // TODO: How to create something similar in jquery?
  // We need to create Node and TextNode objects
  widget_wrapper = document.createElement("div");
  button1_content = document.createTextNode(Drupal.t("Search again"));
  //button2_content = document.createTextNode(Drupal.t("Search for investements"));
  button1_wrapper = this._prepareButtonStyle(document.createElement("div"));
  //button2_wrapper = this._prepareButtonStyle(document.createElement("div"));
  $(button1_wrapper).attr('class', 'gmap-search-button');


  widget_wrapper.appendChild(button1_wrapper);
  // Add event listener for both buttons
  GEvent.addDomListener(button1_wrapper, "click", this._restartSearch());
  button1_wrapper.appendChild(button1_content);


  //widget_wrapper.appendChild(button2_wrapper);

  //GEvent.addDomListener(button2_wrapper, "click", this._handleInvestSearch());
  //button2_wrapper.appendChild(button2_content);

  map.getContainer().appendChild(widget_wrapper);
  return widget_wrapper;
};

Drupal.geo_search.SearchRefreshControl.prototype._restartSearch = function() {
  handler_gmap_data = this.gmap_data;

  return function() {
    handler_gmap_data.change('clearmarkers', -1);

//    for (i = 0; i < handler_gmap_data.search_area.getVertexCount(); i++) {
//      handler_gmap_data.search_area.deleteVertex(i);
//    }

    handler_gmap_data.map.removeControl(Drupal.geo_search.control);
    handler_gmap_data.map.removeOverlay(handler_gmap_data.search_area);

    Drupal.geo_search.factoryArea(handler_gmap_data);


    // Do not remove search button
    //handler_gmap_data.map.removeControl(
    //  Drupal.geo_search.refresh_search_control
    //);
  };
};


/**
 * Implementation of parent::getDefaultPosition method.
 *
 * This one should place control on pretty center of map widget.
 */
Drupal.geo_search.SearchRefreshControl.prototype.getDefaultPosition = function() {
  size = this.map.getSize();
  return new GControlPosition(
    G_ANCHOR_BOTTOM_LEFT, 
    new GSize(5, 5)
  );
};


/**
 * Helper function.
 *
 * Set proper style for control buttons.
 */
Drupal.geo_search.SearchRefreshControl.prototype._prepareButtonStyle = function(
    element) {
  element.style.width = "10em";

  return element;
};


