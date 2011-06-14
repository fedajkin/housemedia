<?php

/**
 * Implementation of hook_default_page_manager_pages().
 */
function commons_home_default_page_manager_pages() {
  $page = new stdClass;
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'commons_homepage';
  $page->task = 'page';
  $page->admin_title = 'Homepage';
  $page->admin_description = 'Community homepage';
  $page->path = 'home';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Home',
    'name' => 'primary-links',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array();
  $page->default_handlers = array();
  $handler = new stdClass;
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_commons_home_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'commons_homepage';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'Home',
    'no_blocks' => 1,
    'css_id' => '',
    'css' => '',
    'contexts' => array(
      0 => array(
        'name' => 'token',
        'id' => 1,
        'identifier' => 'Token',
        'keyword' => 'token',
      ),
    ),
    'relationships' => array(),
    'pipeline' => 'standard',
  );
  $display = new panels_display;
  $display->layout = 'flexible';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'children' => array(
          0 => 1,
          1 => 'main-row',
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'left',
          1 => 'center',
          2 => 'right',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => '39.73757930916851',
        'width_type' => '%',
        'parent' => 'main-row',
      ),
      'left' => array(
        'type' => 'region',
        'title' => 'Left',
        'width' => '16.03704147193599',
        'width_type' => '%',
        'parent' => 'main-row',
      ),
      'right' => array(
        'type' => 'region',
        'title' => 'Right',
        'width' => '24.149962823247854',
        'width_type' => '%',
        'parent' => 'main-row',
      ),
      1 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(),
        'parent' => 'main',
        'class' => '',
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left' => NULL,
      'right' => NULL,
      'top' => NULL,
      'middle' => NULL,
      'bottom' => NULL,
      'center' => NULL,
    ),
    'left' => array(
      'style' => '-1',
    ),
    'style' => 'default',
    'center' => array(
      'style' => '-1',
    ),
    'right' => array(
      'style' => 'default',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass;
    $pane->pid = 'new-1';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'og_inwestycje';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '30',
      'pager_id' => '',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'page_1',
      'override_title' => 1,
      'override_title_text' => '<img src="http://housemedia.pl/sites/default/files/intro/ikony/s16.png" </img>Wyszukaj inwestycję',
    );
    $pane->cache = array();
    $pane->style = array(
      'style' => 'skinr',
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'wyszukaj',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 0;
    $display->content['new-1'] = $pane;
    $display->panels['center'][0] = 'new-1';
    $pane = new stdClass;
    $pane->pid = 'new-2';
    $pane->panel = 'center';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '<img src="http://housemedia.pl/sites/default/files/intro/ikony/task16.png" </img>Zobacz, co możesz zrobić!',
      'body' => '<table style="width: 100%;" border="0" cellpadding="1" cellspacing="1"><tbody><tr><td><h3><img alt="" src="http://housemedia.pl/sites/default/files/intro/find.png" style="float: left; margin-left: 10px; margin-right: 10px; width: 50px; height: 50px;">Znajdź mieszkanie!</h3><p>Wyszukaj interesującą Cię nieruchomość.</p></td><td><h3><img alt="" src="http://housemedia.pl/sites/default/files/intro/kredyt.png" style="width: 50px; height: 50px; float: left; margin-left: 10px; margin-right: 10px;">Znajdź doradce i kredyt!</h3><p>Sprawdź nasz ranking doradców kredytowych i wybierz interesujący Cie kredyt.</p></td></tr><tr><td><h3><img alt="" src="http://housemedia.pl/sites/default/files/intro/join.png" style="width: 50px; height: 50px; float: left; margin-left: 10px; margin-right: 10px;">Dołącz do nas!</h3><p>Wypełnij forumlarz rejestracyjny i zostań członkiem społeczności.</p></td><td><h3><img alt="" src="http://housemedia.pl/sites/default/files/intro/icon-house-key.gif" style="width: 60px; height: 47px; float: left; margin-right: 10px; margin-left: 10px;">Kup mieszkanie!</h3><p>Dopełnij wszelkich formalności dzięki naszej pomocy.</p></td></tr><tr><td><h3><img alt="" src="http://housemedia.pl/sites/default/files/intro/update.png" style="float: left; width: 50px; height: 63px; margin-left: 10px; margin-right: 10px;">Bądź na bieżąco!</h3><p>Śledź zmiany i bądź na bieżąco z wszystkimi ważnymi informacjami.</p></td><td><h3><img alt="" src="http://housemedia.pl/sites/default/files/intro/data-management-icon.png" style="width: 50px; height: 60px; float: left; margin-left: 10px; margin-right: 10px;">Zarządzaj rachunkami!</h3><p>Zarządzaj swoimi rachunkami oraz trminami dzięki naszemu portalowi.</p></td></tr><tr><td colspan="2"><p style="text-align: center;"><img alt="" src="http://housemedia.pl/sites/default/files/intro/people_icon_male.jpg" style="width: 70px; height: 58px;"></p><h3 style="text-align: center;"><strong>Poznaj swoich sąsiadów!</strong></h3></td></tr></tbody></table><p>&nbsp;</p>',
      'format' => '2',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'aktualnosci',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 1;
    $display->content['new-2'] = $pane;
    $display->panels['center'][1] = 'new-2';
    $pane = new stdClass;
    $pane->pid = 'new-3';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'homepage_group_showcase';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '3',
      'pager_id' => '',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'block_1',
      'override_title' => 1,
      'override_title_text' => '<img src="http://housemedia.pl/sites/default/files/intro/ikony/f16.png" </img>Najciekawsze grupy',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'aktualnosci',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 2;
    $display->content['new-3'] = $pane;
    $display->panels['center'][2] = 'new-3';
    $pane = new stdClass;
    $pane->pid = 'new-4';
    $pane->panel = 'center';
    $pane->type = 'block';
    $pane->subtype = 'nodeblock-416';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $display->content['new-4'] = $pane;
    $display->panels['center'][3] = 'new-4';
    $pane = new stdClass;
    $pane->pid = 'new-5';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'og_all';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '200',
      'pager_id' => '',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'block_1',
      'override_title' => 1,
      'override_title_text' => '<img src="http://housemedia.pl/sites/default/files/intro/ikony/map16.png" </img>Mapa inwestycji',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'aktualnosci',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 4;
    $display->content['new-5'] = $pane;
    $display->panels['center'][4] = 'new-5';
    $pane = new stdClass;
    $pane->pid = 'new-6';
    $pane->panel = 'left';
    $pane->type = 'views';
    $pane->subtype = 'vote_inwestycja';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '5',
      'pager_id' => '',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'block_1',
      'override_title' => 1,
      'override_title_text' => '<img src="http://housemedia.pl/sites/default/files/intro/ikony/rank16.png" </img>Najlepsze inwestycje',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'lewo',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 0;
    $display->content['new-6'] = $pane;
    $display->panels['left'][0] = 'new-6';
    $pane = new stdClass;
    $pane->pid = 'new-7';
    $pane->panel = 'left';
    $pane->type = 'views';
    $pane->subtype = 'homepage_tag_cloud';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'block_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'style' => 'skinr',
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'lewo',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 1;
    $display->content['new-7'] = $pane;
    $display->panels['left'][1] = 'new-7';
    $pane = new stdClass;
    $pane->pid = 'new-8';
    $pane->panel = 'left';
    $pane->type = 'views';
    $pane->subtype = 'users_online';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '15',
      'pager_id' => '',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'default',
      'override_title' => 1,
      'override_title_text' => '<img src="http://housemedia.pl/sites/default/files/intro/ikony/profile16.png" </img>Zalogowani',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'lewo',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 2;
    $display->content['new-8'] = $pane;
    $display->panels['left'][2] = 'new-8';
    $pane = new stdClass;
    $pane->pid = 'new-9';
    $pane->panel = 'right';
    $pane->type = 'block';
    $pane->subtype = 'block-3';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '<img src="http://housemedia.pl/sites/default/files/intro/ikony/news40.png" </img><a href="http://www.onet.pl">Aktualności</a>',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(
        'style' => '$',
        'settings' => array(
          'name' => '_temporary',
          'style_base' => 'pane_plain_box',
          'palette' => array(
            'background' => '#FFFFFF',
            'text' => '#000000',
            'border' => '#000000',
            'header-background' => '#FFFFFF',
            'header-text' => '#000000',
            'header-border' => '#000000',
          ),
          'font' => array(
            'font' => '',
            'size' => '',
            'letter_spacing' => '',
            'word_spacing' => '',
            'decoration' => '',
            'weight' => '',
            'style' => '',
            'variant' => '',
            'case' => '',
            'alignment' => '',
          ),
          'header_font' => array(
            'font' => '',
            'size' => '',
            'letter_spacing' => '',
            'word_spacing' => '',
            'decoration' => '',
            'weight' => '',
            'style' => '',
            'variant' => '',
            'case' => '',
            'alignment' => '',
          ),
          'border' => array(
            'thickness' => '',
            'style' => '',
          ),
          'header_border' => array(
            'thickness' => '',
            'style' => '',
          ),
          'padding' => array(
            'top' => '',
            'right' => '',
            'bottom' => '',
            'left' => '',
          ),
        ),
      ),
      'style' => 'stylizer',
    );
    $pane->css = array(
      'css_id' => 'aktualnosci',
      'css_class' => 'blok1',
    );
    $pane->extras = array();
    $pane->position = 0;
    $display->content['new-9'] = $pane;
    $display->panels['right'][0] = 'new-9';
    $pane = new stdClass;
    $pane->pid = 'new-10';
    $pane->panel = 'right';
    $pane->type = 'block';
    $pane->subtype = 'block-4';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '<img src="http://housemedia.pl/sites/default/files/intro/ikony/coins.png" </img>Finanse',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'aktualnosci',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 1;
    $display->content['new-10'] = $pane;
    $display->panels['right'][1] = 'new-10';
    $pane = new stdClass;
    $pane->pid = 'new-11';
    $pane->panel = 'right';
    $pane->type = 'block';
    $pane->subtype = 'block-5';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '<img src="http://housemedia.pl/sites/default/files/intro/ikony/info16.png" </img>Porady',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'aktualnosci',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 2;
    $display->content['new-11'] = $pane;
    $display->panels['right'][2] = 'new-11';
    $pane = new stdClass;
    $pane->pid = 'new-12';
    $pane->panel = 'right';
    $pane->type = 'block';
    $pane->subtype = 'commons_core-4';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $display->content['new-12'] = $pane;
    $display->panels['right'][3] = 'new-12';
    $pane = new stdClass;
    $pane->pid = 'new-13';
    $pane->panel = 'right';
    $pane->type = 'views';
    $pane->subtype = 'homepage_most_active_groups';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '5',
      'pager_id' => '',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'block_1',
      'override_title' => 1,
      'override_title_text' => '<img src="http://housemedia.pl/sites/default/files/intro/ikony/Active16.png" </img>Najaktywniejsze grupy',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'grupy1',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 4;
    $display->content['new-13'] = $pane;
    $display->panels['right'][4] = 'new-13';
    $pane = new stdClass;
    $pane->pid = 'new-14';
    $pane->panel = 'right';
    $pane->type = 'views';
    $pane->subtype = 'content_global_calendar';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'calendar_block_1',
      'context' => array(
        0 => '',
      ),
      'override_title' => 1,
      'override_title_text' => '<img src="http://housemedia.pl/sites/default/files/intro/ikony/c16.png" </img>Kalendarz',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'aktualnosci',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 5;
    $display->content['new-14'] = $pane;
    $display->panels['right'][5] = 'new-14';
    $pane = new stdClass;
    $pane->pid = 'new-15';
    $pane->panel = 'right';
    $pane->type = 'views';
    $pane->subtype = 'homepage_recent_featured';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '5',
      'pager_id' => '',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'block_1',
      'override_title' => 1,
      'override_title_text' => '<img src="http://housemedia.pl/sites/default/files/intro/ikony/fn16.png" </img>Wyróżnione treści',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'aktualnosci',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 6;
    $display->content['new-15'] = $pane;
    $display->panels['right'][6] = 'new-15';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['commons_homepage'] = $page;

 return $pages;

}
