// $Id: arrange_fields_node_edit.js,v 1.7 2010/11/06 21:07:47 richardp Exp $ 


/*
  This js file is meant to be used on the node/edit page of the form.  Meaning, this is not
  a user who is arranging fields, but is actually entering data into the form.
*/

var arrangeFieldsFSZI;
var tabval;

Drupal.behaviors.arrangeFieldsNodeEditStartup = function() {


  // If vertical tabs is installed, we want to wrap a div around them and
  // give it an ID we can use later when specifying position.
  $(".arrange-fields-container .vertical-tabs").wrap("<div class='draggable-form-item' id='arrange-fields-vertical-tabs'></div>");
  
  // In order to get the CSS to work correctly for textareas, we need to wrap a div around them.
  // Happens when we try to make the labels be inline.
  $("textarea").wrap("<div></div>");
  
  // Make it so when you click on a fieldset, it's z-index goes up (so it
  // is in the foreground).
  arrangeFieldsFSZI = 300;  
  $(".arrange-fields-container .draggable-form-item-fieldset").bind("mousedown", function (event, ui) {
    $(this).css("z-index", arrangeFieldsFSZI);    
    arrangeFieldsFSZI++;
  });

  ////////////////////////////////////
  // We want to adjust the tabindex's of all the elements so that they are more logical.
  // Tab index will be based calculated by: (top x multiplier) + left.
  var multiplier = 10000;
  var tabvalArray = new Array();
  var elementArray = new Array();

  $(".arrange-fields-container .draggable-form-item").each(function (index, element) {

    var postop = $(element).css("top");
    var posleft = $(element).css("left");
        
    postop = $(element).css("top").replace("px", "");
    posleft = $(element).css("left").replace("px", "");

    if (postop == "auto") postop = 0;  
    if (posleft == "auto") posleft = 0;
    
    var tabval = (parseInt(postop) * multiplier) + parseInt(posleft);

    if (tabval == 0) tabval = 1;
    // Now, grab the form element within this element, and assign this tabval.
    $(element).find("input,textarea,select,a").each(function (sindex, sub_element) {
      tabvalArray.push(tabval);
      elementArray[tabval] = $(sub_element);
      tabval++;  // in case there were more than one here.
    });
   
  });

  // Now, let's sort the tabvalArray.
  tabvalArray.sort(function(a,b){return a - b}); // have to do this because of the way JS sorts numerical values.
  // Okay, with the tabvalArray sorted, let's go through and assign each
  // element in the elementArray a tabindex (based on the index that their tabval
  // appeard in the tabvalArray).
  $(tabvalArray).each(function (index, value) {
    var sub_element = elementArray[value];
    $(sub_element).attr("tabindex", (index+1)); 
  });

  
}