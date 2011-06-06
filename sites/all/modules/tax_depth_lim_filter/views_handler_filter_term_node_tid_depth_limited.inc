<?php

// $Id: views_handler_filter_term_node_tid_depth_limited.inc,v 1.2 2010/10/25 18:22:31 brynbellomy Exp $

/**
 * Just like the term_node_tid_depth filter, but adds the option to restrict the exposed dropdown
 * to terms of a given depth
 */
class views_handler_filter_term_node_tid_depth_limited extends views_handler_filter_term_node_tid_depth {
  function operator_options() {
    return array(
      'or' => t('Is one of'),
    );
  }
  
  function option_definition() {
    $options = parent::option_definition();

    $options['max_depth_limit_for_list'] = array('default' => 1);
    $options['min_depth_limit_for_list'] = array('default' => 10);
    $options['do_max_depth_limit'] = array('default' => 0);
    $options['do_min_depth_limit'] = array('default' => 0);
    $options['children_of'] = array('default' => 0);

    return $options;
  }
  
  function extra_options_form(&$form, &$form_state) {
    parent::extra_options_form($form, $form_state);

    $form['do_max_depth_limit'] = array(
      '#type' => 'checkbox',
      '#title' => t('Enable max depth limit filter on exposed select list'),
      '#default_value' => $this->options['do_max_depth_limit'],
      '#description' => t(''),
    );

    $form['max_depth_limit_for_list'] = array(
      '#type' => 'weight',
      '#title' => t('Max depth limit for list'),
      '#default_value' => $this->options['max_depth_limit_for_list'],
      '#description' => t('This will limit the exposed version of this filter to showing terms either above or below the specified depth.'),
    );
    
    $form['do_min_depth_limit'] = array(
      '#type' => 'checkbox',
      '#title' => t('Enable min depth limit filter on exposed select list'),
      '#default_value' => $this->options['do_min_depth_limit'],
      '#description' => t(''),
    );
    
    $form['min_depth_limit_for_list'] = array(
      '#type' => 'weight',
      '#title' => t('Min depth limit for list'),
      '#default_value' => $this->options['min_depth_limit_for_list'],
      '#description' => t('This will limit the exposed version of this filter to showing terms either above or below the specified depth.'),
    );
  }


  function value_form(&$form, &$form_state) {
    $vocabulary = taxonomy_vocabulary_load($this->options['vid']);
    if (empty($vocabulary) && $this->options['limit']) {
      $form['markup'] = array(
        '#prefix' => '<div class="form-item">',
        '#suffix' => '</div>',
        '#value' => t('An invalid vocabulary is selected. Please change it in the options.'),
      );
      return;
    }

    if ($this->options['type'] == 'textfield') {
      $default = '';
      if ($this->value) {
        $result = db_query("SELECT * FROM {term_data} td WHERE td.tid IN (" . implode(', ', $this->value) . ')');
        while ($term = db_fetch_object($result)) {
          if ($default) {
            $default .= ', ';
          }
          $default .= $term->name;
        }
      }

      $form['value'] = array(
        '#title' => $this->options['limit'] ? t('Select terms from vocabulary @voc', array('@voc' => $vocabulary->name)) : t('Select terms'),
        '#type' => 'textfield',
        '#default_value' => $default,
      );

      if ($this->options['limit']) {
        $form['value']['#autocomplete_path'] = 'taxonomy/autocomplete/' . $vocabulary->vid;
      }
    }
    else {
      if (!empty($this->options['hierarchy']) && $this->options['limit']) {
        $tree = taxonomy_get_tree($vocabulary->vid);
        $options = array();
        $all_terms = array();

        if ($tree) {
          foreach ($tree as $term) {
            $choice = new stdClass();
            $choice->option = array($term->tid => str_repeat('-', $term->depth) . $term->name);
            $all_terms[] = $choice;
            if($this->options['do_max_depth_limit']) {
               if($term->depth > $this->options['max_depth_limit_for_list']) {
                 continue;
               }
            }
            if($this->options['do_min_depth_limit']) {
               if($term->depth < $this->options['min_depth_limit_for_list']) {
                 continue;
               }
            }
            if($this->options['children_of'] != 0 && !in_array($this->options['children_of'], array_keys(taxonomy_get_parents($term->tid)))) {
              continue;
            }
            $options[] = $choice;
          }
        }
      }
      else {
        $all_terms = array();
        $options = array();
        if ($this->options['limit']) {
          $tree = taxonomy_get_tree($vocabulary->vid);
          foreach($tree as $term) {
            $choice = new stdClass();
            $choice->option = array($term->tid => $term->name);
            $all_terms[] = $choice;
            if($this->options['do_max_depth_limit']) {
               if($term->depth > $this->options['max_depth_limit_for_list']) {
                 continue;
               }
            }
            if($this->options['do_min_depth_limit']) {
               if($term->depth < $this->options['min_depth_limit_for_list']) {
                 continue;
               }
            }
            if($this->options['children_of'] != 0 && !in_array($this->options['children_of'], array_keys(taxonomy_get_parents($term->tid)))) {
              continue;
            }
            $options[] = $choice;
          }
        }
        else {
          $tree = taxonomy_get_tree();
          foreach($tree as $term) {
            $choice = new stdClass();
            $choice->option = array($term->tid => $term->name);
            $all_terms[] = $choice;
            if($this->options['do_max_depth_limit']) {
               if($term->depth > $this->options['max_depth_limit_for_list']) {
                 continue;
               }
            }
            if($this->options['do_min_depth_limit']) {
               if($term->depth < $this->options['min_depth_limit_for_list']) {
                 continue;
               }
            }
            if($this->options['children_of'] != 0 && !in_array($this->options['children_of'], array_keys(taxonomy_get_parents($term->tid)))) {
              continue;
            }
            $options[] = $choice;
          }
        }
      }

      $default_value = (array) $this->value;

      if (!empty($form_state['exposed'])) {
        $identifier = $this->options['expose']['identifier'];

        if (!empty($this->options['expose']['reduce'])) {
          $options = $this->reduce_value_options($options);

          if (empty($this->options['expose']['single']) && !empty($this->options['expose']['optional'])) {
            $default_value = array();
          }
        }

        if (!empty($this->options['expose']['single'])) {
          if (!empty($this->options['expose']['optional']) && (empty($default_value) || !empty($this->options['expose']['reduce']))) {
            $default_value = 'All';
          }
          else if (empty($default_value)) {
            $keys = array_keys($options);
            $default_value = array_shift($keys);
          }
          else {
            $copy = $default_value;
            $default_value = array_shift($copy);
          }
        }
      }
      $form['value'] = array(
        '#type' => 'select',
        '#title' => $this->options['limit'] ? t('Select terms from vocabulary @voc', array('@voc' => $vocabulary->name)) : t('Select terms'),
        '#multiple' => TRUE,
        '#options' => $options,
        '#size' => min(9, count($options)),
        '#default_value' => $default_value,
      );
      
      $form['children_of'] = array(
        '#title' => t('Limit exposed dropdown to children of term'),
        '#type' => 'select',
        '#multiple' => FALSE,
        '#options' => array(0 => '<Show all>') + $all_terms,
        '#default_value' => $this->options['children_of'],
      );

      if (!empty($form_state['exposed']) && !isset($form_state['input'][$identifier])) {
        $form_state['input'][$identifier] = $default_value;
      }
    }

    if (empty($form_state['exposed'])) {
      // Retain the helper option
      $this->helper->options_form($form, $form_state);
    }
  }
}
