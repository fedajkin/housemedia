/**
 * Disable the form button on click for all search views
 * (prevents users from sending multiple queries)
 */
$(document).ready(function(){
  $('form.search-view').submit(function() {
    $('input[type=submit]', this).attr('disabled', 'disabled');
  });
  // Enable all buttons on page load to solve problem about users
  // not being able to click search after hitting the browser
  // back button (http://drupal.org/node/1115268).
  $('input[type=submit]', this).removeAttr('disabled');
});



/**
 * Define behaviors for Views Search module
 */
Drupal.behaviors.views_search = function () {

  /**
   * Add the "Modify Search" capability
   */
  $('.view input#edit-view-modify').click(function(event) {
    // Prevent the default click behavior
    event.preventDefault();
    // Set a couple of shortcuts
    var $viewFilterForm = $(this).parents(".view").find(".view-filters form.search-view");
    var $viewFilterFormCheckboxOverwrite = $viewFilterForm.find("input#edit-overwrite-saved-search");
    var $viewSearchAttachment = $(this).parents("#views-search-attachment-ahah");
    // Check the button to overwrite this saved searched by default
    $viewFilterFormCheckboxOverwrite.attr('checked', true);
    // If a user modifies the existing search, hide the views
    // search attachment display and show the view filter form
    $viewSearchAttachment.fadeOut('fast');
    $viewFilterForm.slideToggle('fast');
  });

  /**
   * Add the "Cancel Modify Search" capability
   */
  $('.view input#edit-cancel-modify').click(function(event) {
    // Prevent the default click behavior
    event.preventDefault();
    // Set a couple of shortcuts
    var $parentView = $(this).parents(".view");
    var $viewFilterForm = $parentView.find(".view-filters form.search-view");
    var $viewAttachmentBefore = $parentView.find("#views-search-attachment-ahah");
    // Show the views search attachment display
    $viewAttachmentBefore.fadeIn('fast');
    // Hide the view filter form
    $viewFilterForm.slideToggle('fast');
  });

  /**
   * Add functionality to the "Overwrite Search" button
   */
  $('.view-filters form.search-view input#edit-overwrite-saved-search').click(function() {
    var $savedSearchWrapper = $(this).parents(".views-exposed-widget").find("#edit-saved-search-name-wrapper");
    var $savedSearchButtonOverwrite = $(this).parents(".views-exposed-widget").find("input.form-submit:first");
    // Change the text of the "Overwrite Search" button
    if($(this).is(':checked')) {
      $savedSearchButtonOverwrite.attr('value','Overwrite Saved Search');
    }
    else {
      $savedSearchButtonOverwrite.attr('value','Search Again');
    }
    // Toggle visibility of the "Saved Search" name field
    $savedSearchWrapper.slideToggle('fast');
  });

  /**
   * Check user input when the user saves a search.
   * Users should only be able to use plain text.
   */
  $('form.search-view-attachment-form input#edit-save-search').click(function(event) {
    // Make sure the name of this saved search is plain text
    var savedSearchName = $('form.search-view-attachment-form input#edit-save-search-name').val();
    var savedSearchNameClean = Drupal.checkPlain(savedSearchName);

    if (savedSearchName != savedSearchNameClean) {
      alert('Please only use plain text for the name of your Saved Search.');
      event.preventDefault();
      return;
    }
    // Make sure the user entered a name at all
    if (savedSearchName == '') {
      alert('Please enter a name for your Saved Search.');
      event.preventDefault();
      return;
    }
    // Make sure this name isn't already used by this user
    $.ajax({
      async: false,
      type: 'GET',
      url: Drupal.settings.views_search.check_saved_search_name_url + '/' + savedSearchName,
      success: function(data) {
        // Make sure this is valid JSON data
        checkNameData = Drupal.parseJson(data);
        // Make sure the request isn't empty
        if (checkNameData.status == true) {
          if (checkNameData.data) {
            alert('You already used this name for one of your Saved Searches. Please choose a different name');
            event.preventDefault();
          }
        }
      }
    });
  });

  /**
   * Check user input for invalid characters or missing name
   * when a user overwrites a saved search with a new name.
   * TODO: Implement this with a nicer function instead of duplicating code.
   */
  $('form.search-view-saved input.saved-search-overwrite').click(function(event) {
    // Make sure the name of this saved search is plain text
    var savedSearchName = $('form.search-view-saved input#edit-saved-search-name').val();
    var savedSearchNameClean = Drupal.checkPlain(savedSearchName);
    if (savedSearchName != savedSearchNameClean) {
      alert('Please only use plain text for the name of your Saved Search.');
      event.preventDefault();
      return;
    }
    // Make sure the user entered a name at all
    if (savedSearchName == '') {
      alert('Please enter a name for your Saved Search.');
      event.preventDefault();
      return;
    }
  });

};