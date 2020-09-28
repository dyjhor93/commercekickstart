<?php

/**
 * @file
 * Contains class \Drupal\pagebuilder\Entity\Tier\Tier.
 */

namespace Drupal\pagebuilder\Entity\Tier;

class Tier extends \Entity implements TierInterface {

  /**
   * The Tier description.
   *
   * @var int
   */
  public $description;

  /**
   * The Tier changed timestamp.
   *
   * @var int
   */
  public $changed;

  /**
   * {@inheritdoc}
   */
  protected function defaultUri() {
    return array('path' => 'tier/' . $this->identifier());
  }

  /**
   * {@inheritdoc}
   */
  public function save() {
    $this->changed = REQUEST_TIME;
    parent::save();
  }

}
