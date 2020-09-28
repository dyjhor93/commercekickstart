<?php
/**
 * @file
 * tiers_paragraph.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function tiers_paragraph_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_advanced|tier|rw_pagemanager_tiers_paragraph|form';
  $field_group->group_name = 'group_advanced';
  $field_group->entity_type = 'tier';
  $field_group->bundle = 'rw_pagemanager_tiers_paragraph';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Advanced features',
    'weight' => '10',
    'children' => array(
      0 => 'field_enable_pullquote',
      1 => 'field_quote',
      2 => 'field_enable_image',
      3 => 'field_tier_image',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Advanced features',
      'instance_settings' => array(
        'required_fields' => 0,
        'id' => '',
        'classes' => 'group-advanced field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_advanced|tier|rw_pagemanager_tiers_paragraph|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Advanced features');

  return $field_groups;
}
