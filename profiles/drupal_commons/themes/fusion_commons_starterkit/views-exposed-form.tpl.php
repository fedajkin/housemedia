<?php
// $Id: views-exposed-form.tpl.php 8347 2011-03-02 01:44:22Z sheena $
/**
 * @file views-exposed-form.tpl.php
 *
 * This template handles the layout of the views exposed filter form.
 *
 * Variables available:
 * - $widgets: An array of exposed form widgets. Each widget contains:
 * - $widget->label: The visible label to print. May be optional.
 * - $widget->operator: The operator for the widget. May be optional.
 * - $widget->widget: The widget itself.
 * - $button: The submit button for the form.
 *
 * @ingroup views_templates
 */
?>
<?php 
//add collapsible fieldset js if it is not already included
global $BASE_URL;
drupal_add_js($BASE_URL.'misc/drupal.js');
drupal_add_js($BASE_URL.'misc/collapse.js');
?>

<?php if (!empty($q)): ?>
  <?php
    // This ensures that, if clean URLs are off, the 'q' is added first so that
    // it shows up first in the URL.
    print $q;
  ?>
<?php endif; ?>
<fieldset class="views-exposed-form collapsible collapsed">
<legend><?php print(t("Filter")); ?></legend>
  <div class="views-exposed-wrapper clear-block">
  <div class="views-exposed-widgets clear-block">
    <?php foreach($widgets as $id => $widget): ?>
      <div class="views-exposed-widget">
        <?php if (!empty($widget->label)): ?>
          <label for="<?php print $widget->id; ?>">
            <?php print $widget->label; ?>
          </label>
        <?php endif; ?>
        <?php if (!empty($widget->operator)): ?>
          <div class="views-operator">
            <?php print $widget->operator; ?>
          </div>
        <?php endif; ?>
        <div class="views-widget">
          <?php print $widget->widget; ?>
        </div>
      </div>
    <?php endforeach; ?>
    </div>
    <div class="views-exposed-widget views-exposed-submit">
      <?php print $button ?>
    </div>
  </div>
</fieldset>