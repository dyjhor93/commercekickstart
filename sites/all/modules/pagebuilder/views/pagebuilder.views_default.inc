<?php

/**
 * Implements hook_views_default_views().
 */
function entity_boilerplate_views_default_views() {
  $views = array();

  $view = new view();
  $view->name = 'tier_list';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'tier';
  $view->human_name = 'My entities';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'My entities';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer tier entities';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Tier: My entity ID */
  $handler->display->display_options['fields']['tier_id']['id'] = 'tier_id';
  $handler->display->display_options['fields']['tier_id']['table'] = 'tier';
  $handler->display->display_options['fields']['tier_id']['field'] = 'tier_id';
  /* Field: Tier: Label */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'tier';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'tier/[tier_id]';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'There are no results';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Field: Tier: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'tier';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  /* Field: Tier: Link */
  $handler->display->display_options['fields']['link_tier']['id'] = 'link_tier';
  $handler->display->display_options['fields']['link_tier']['table'] = 'tier';
  $handler->display->display_options['fields']['link_tier']['field'] = 'link_tier';
  $handler->display->display_options['fields']['link_tier']['label'] = '';
  $handler->display->display_options['fields']['link_tier']['exclude'] = TRUE;
  $handler->display->display_options['fields']['link_tier']['element_label_colon'] = FALSE;
  /* Field: Tier: Delete Link */
  $handler->display->display_options['fields']['delete_tier']['id'] = 'delete_tier';
  $handler->display->display_options['fields']['delete_tier']['table'] = 'tier';
  $handler->display->display_options['fields']['delete_tier']['field'] = 'delete_tier';
  $handler->display->display_options['fields']['delete_tier']['label'] = '';
  $handler->display->display_options['fields']['delete_tier']['exclude'] = TRUE;
  $handler->display->display_options['fields']['delete_tier']['element_label_colon'] = FALSE;
  /* Field: Tier: Edit Link */
  $handler->display->display_options['fields']['edit_tier']['id'] = 'edit_tier';
  $handler->display->display_options['fields']['edit_tier']['table'] = 'tier';
  $handler->display->display_options['fields']['edit_tier']['field'] = 'edit_tier';
  $handler->display->display_options['fields']['edit_tier']['label'] = '';
  $handler->display->display_options['fields']['edit_tier']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_tier']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Operations';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[link_tier] [edit_tier] [delete_tier]';
  /* Sort criterion: Tier: My entity ID */
  $handler->display->display_options['sorts']['tier_id']['id'] = 'tier_id';
  $handler->display->display_options['sorts']['tier_id']['table'] = 'tier';
  $handler->display->display_options['sorts']['tier_id']['field'] = 'tier_id';
  $handler->display->display_options['sorts']['tier_id']['order'] = 'DESC';
  /* Filter criterion: Tier: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'tier';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    3 => '3',
    1 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/content/tier';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'My entity list';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  $views['tier_list'] = $view;
  return $views;

}
