<?php

/**
 * @file
 * Contains class \Drupal\pagebuilder\Entity\Tier\TierController.
 */

namespace Drupal\pagebuilder\Entity\Tier;

class TierController extends \EntityAPIController {

  /**
   * {@inheritdoc}
   */
  public function create(array $values = array()) {
    global $user;
    $values += array(
      'title'        => '',
      'created'      => REQUEST_TIME,
      'changed'      => REQUEST_TIME,
      'uid'          => $user->uid,
      'parent_nid'   => 0,
      'row_position' => 0,
    );
    return parent::create($values);
  }

  /**
   * {@inheritdoc}
   */
  public function buildContent($entity, $view_mode = 'full', $langcode = NULL, $content = array()) {
    $wrapper = entity_metadata_wrapper('tier', $entity);
    // $content['author'] = array('#markup' => t('Created by: !author', array('!author' => $wrapper->uid->name->value(array('sanitize' => TRUE)))));

    // Make Description and Status themed like default fields.
    // $content['description'] = array(
    //  '#theme' => 'field',
    //  '#weight' => 0,
    //  '#title' => t('Description'),
    //  '#access' => TRUE,
    //  '#label_display' => 'above',
    //  '#view_mode' => 'full',
    //  '#language' => LANGUAGE_NONE,
    //  '#field_name' => 'field_fake_description',
    //  '#field_type' => 'text',
    //  '#entity_type' => 'tier',
    //  '#bundle' => $entity->type,
    //  '#items' => array(array('value' => $entity->description)),
    //  '#formatter' => 'text_default',
    //  0 => array('#markup' => check_plain($entity->description)),
    //);

    return parent::buildContent($entity, $view_mode, $langcode, $content);
  }

}
