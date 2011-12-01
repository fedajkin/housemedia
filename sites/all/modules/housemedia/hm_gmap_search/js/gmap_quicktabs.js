/**
* quicktabs_gmap_fix.js
*
* This provides some Javascript code to fix problems that exist with displaying Google Maps
* from the GMap module within a Quicktabs block. Normally, when tabs are clicked and content
* is hidden/shown, the map needs to refresh itself but is not told to do so. This file simply
* forces each map to refresh when the user unhides it.
*/

Drupal.quicktabs_gmap_fix = {};

Drupal.quicktabs_gmap_fix.fixMap = function(event){

var qtBlock = $(event.target).parents('.quicktabs_wrapper');
var activeDiv = qtBlock.find('div.quicktabs_main').children('div.quicktabs_tabpage:not(.quicktabs_hide)');

// Since Quicktabs blocks can contain other Quicktabs blocks, here we need to examine each
// GMap div that is a child of the currently-active quicktab "page" div. Since that div can
// contain other Quicktabs blocks, it may contain other GMap divs that are currently still
// hidden. Therefore, we'll check each GMap div and make sure ALL of its Quicktabs wrapper
// divs are currently visible. If so, the map has just been un-hidden and we need to re-center
// it.
activeDiv.find('div.gmap-gmap').each(function(index, object){
var visible = true;
$(this).parents('div.quicktabs_tabpage').each(function(){
if ($(this).hasClass('quicktabs_hide')){
visible = false;
}
});
if (visible){
var gmap = $(this);
// GMap map IDs are accessible through the CSS ID of the wrapper divs.
var id = gmap.attr('id');
var idArr = id.split('-');
var mapId = idArr[1];
var mapObj = Drupal.gmap.getMap(mapId);
// Re-center the map.
mapObj.map.checkResize();
mapObj.map.setCenter(new GLatLng(mapObj.vars.latitude, mapObj.vars.longitude, false) , mapObj.vars.zoom);
}
});
};

Drupal.behaviors.quicktabs_gmap_fix = function(context, settings){
// Bind map-fixing behavior to the "click" event. Note that this must be bound after the
// Quicktabs behavior, so this JS file must be added later than the Quicktabs sheet.
$('ul.quicktabs_tabs').children('li').each(function(index, object){
$(this).children('a').bind('click', Drupal.quicktabs_gmap_fix.fixMap);
});
};

