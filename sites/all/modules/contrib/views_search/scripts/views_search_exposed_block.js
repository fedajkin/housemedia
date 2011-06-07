/**
 * Hide the exposed search result block on page load.
 */
$(document).ready(function(){
  var exposedBlockId = Drupal.settings.views_search.exposed_form_block_id;
  $('#' + exposedBlockId).addClass('views-search-hide-exposed-block');
});