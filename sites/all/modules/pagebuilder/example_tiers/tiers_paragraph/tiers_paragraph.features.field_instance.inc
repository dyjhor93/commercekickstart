<?php
/**
 * @file
 * tiers_paragraph.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function tiers_paragraph_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'tier-rw_pagemanager_tiers_paragraph-field_enable_image'.
  $field_instances['tier-rw_pagemanager_tiers_paragraph-field_enable_image'] = array(
    'bundle' => 'rw_pagemanager_tiers_paragraph',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => 'Add an image with optional caption to this paragraph',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 3,
      ),
      'row' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 11,
      ),
    ),
    'entity_type' => 'tier',
    'field_name' => 'field_enable_image',
    'label' => 'Add image',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 12,
    ),
  );

  // Exported field_instance:
  // 'tier-rw_pagemanager_tiers_paragraph-field_enable_pullquote'.
  $field_instances['tier-rw_pagemanager_tiers_paragraph-field_enable_pullquote'] = array(
    'bundle' => 'rw_pagemanager_tiers_paragraph',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => 'Add a pull quotation to this paragaph',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
      'row' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 13,
      ),
    ),
    'entity_type' => 'tier',
    'field_name' => 'field_enable_pullquote',
    'label' => 'Add pullquote',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 10,
    ),
  );

  // Exported field_instance: 'tier-rw_pagemanager_tiers_paragraph-field_quote'.
  $field_instances['tier-rw_pagemanager_tiers_paragraph-field_quote'] = array(
    'bundle' => 'rw_pagemanager_tiers_paragraph',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'The text to display as a pullquote',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
      'row' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 12,
      ),
    ),
    'entity_type' => 'tier',
    'field_name' => 'field_quote',
    'label' => 'Quote',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 11,
    ),
  );

  // Exported field_instance:
  // 'tier-rw_pagemanager_tiers_paragraph-field_tier_image'.
  $field_instances['tier-rw_pagemanager_tiers_paragraph-field_tier_image'] = array(
    'bundle' => 'rw_pagemanager_tiers_paragraph',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
      'row' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 9,
      ),
    ),
    'entity_type' => 'tier',
    'field_name' => 'field_tier_image',
    'label' => 'Image',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'image_field_caption' => 0,
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'medium',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 13,
    ),
  );

  // Exported field_instance:
  // 'tier-rw_pagemanager_tiers_paragraph-field_tier_paragraph'.
  $field_instances['tier-rw_pagemanager_tiers_paragraph-field_tier_paragraph'] = array(
    'bundle' => 'rw_pagemanager_tiers_paragraph',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Add your content here',
    'display' => array(
      'admin' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'column' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'row' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 10,
      ),
      'token' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'tier',
    'field_name' => 'field_tier_paragraph',
    'label' => 'Paragraph text',
    'required' => 1,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 9,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Add a pull quotation to this paragaph');
  t('Add an image with optional caption to this paragraph');
  t('Add image');
  t('Add pullquote');
  t('Add your content here');
  t('Image');
  t('Paragraph text');
  t('Quote');
  t('The text to display as a pullquote');

  return $field_instances;
}
