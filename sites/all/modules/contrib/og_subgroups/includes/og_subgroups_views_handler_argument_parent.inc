<?php
class og_subgroups_views_handler_argument_parent extends views_handler_argument_numeric {
  function option_definition() {
    $options = parent::option_definition();
    $options['include_parent'] = array('default' => FALSE);

    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    // Remove unwanted options
    unset($form['not']);

    $form['include_parent'] = array(
      '#type' => 'checkbox',
      '#title' => t('Include the parent'),
      '#description' => t('If selected, the parent group specified in the argument will be added to the output.'),
      '#default_value' => $this->options['include_parent'],
    );
  }

  function query() {
    $this->ensure_my_table();

    if (!empty($this->options['break_phrase'])) {
      views_break_phrase($this->argument, $this);
    }
    else {
      $this->value = array($this->argument);
    }

    $arguments = explode(',', $this->argument);
    $placeholders = implode(', ', array_fill(0, sizeof($arguments), '%d'));
    if ($this->options['include_parent']) {
      $base_table = $this->query->base_table;
      $base_field = $this->query->base_field;

      foreach ($arguments as $arg) {
        $arguments[] = $arg;
      }

      $this->query->add_where(0, "$this->table_alias.$this->real_field IN ($placeholders) OR $base_table.$base_field IN ($placeholders)", $arguments);
    }
    else {
      $this->query->add_where(0, "$this->table_alias.$this->real_field IN ($placeholders)", $arguments);
    }
  }
}