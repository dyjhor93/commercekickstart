<?php
/**
 * @file
 * tiers_paragraph.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function tiers_paragraph_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_default_tier_type().
 */
function tiers_paragraph_default_tier_type() {
  $items = array();
  $items['rw_pagemanager_tiers_paragraph'] = entity_import('tier_type', '{
    "type" : "rw_pagemanager_tiers_paragraph",
    "label" : "Formatted paragraph",
    "description" : "A text paragraph tier",
    "rdf_mapping" : []
  }');
  return $items;
}
