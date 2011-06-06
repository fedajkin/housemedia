<?php
/**
 * @file views-view-table.tpl.php
 * Template to display a view as a table.
 *
 * - $title : The title of this group of rows.  May be empty.
 * - $header: An array of header labels keyed by field id.
 * - $fields: An array of CSS IDs to use for each field id.
 * - $class: A class or classes to apply to the table, based on settings.
 * - $row_classes: An array of classes to apply to each row, indexed by row
 *   number. This matches the index in $rows.
 * - $rows: An array of row items. Each row is an array of content.
 *   $rows are keyed by row number, fields within rows are keyed by field ID.
 * @ingroup views_templates
 */
?>
<table class="<?php print $class; ?>">
  <?php if (!empty($title)) : ?>
    <caption><?php print $title; ?></caption>
  <?php endif; ?>
  <thead>
    <tr>
      <?php foreach ($header as $field => $label): ?>
        <th class="views-field views-field-<?php print $fields[$field]; ?>">
          <?php print $label; ?>
        </th>
      <?php endforeach; ?>
    </tr>
  </thead>
  <tbody>
    <?php foreach ($rows as $count => $row): ?>
      <tr class="<?php print implode(' ', $row_classes[$count]); ?>">
        <?php foreach ($row as $field => $content): ?>
          <td class="views-field views-field-<?php print $fields[$field]; ?>">
            <?php
              switch ($fields[$field]) {
                case 'name':
                case 'name active':
                  $data = views_search_generate_saved_search_link($view->result[$count]->ssid);
                  break;
                case 'view-name':
                  $data = views_search_get_nice_display_name($view->result[$count]->ssid);
                  break;
                case 'nothing':
                  $saved_search_link = views_search_generate_saved_search_link($view->result[$count]->ssid, 'Run');
                  $delete_search_link = l('Delete', 'views_search/delete/saved_search/' . $view->result[$count]->ssid);
                  $data = implode(' | ', array($saved_search_link, $delete_search_link));
                  break;
                default:
                  $data = $content;
              }
            ?>
            <?php print $data; ?>
          </td>
        <?php endforeach; ?>
      </tr>
    <?php endforeach; ?>
  </tbody>
</table>