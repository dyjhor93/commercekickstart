<?php

/**
 * @file
 * Contains class \Drupal\pagebuilder\Entity\Tier\TierViewsController.
 */

namespace Drupal\pagebuilder\Entity\Tier;

class TierViewsController extends \EntityDefaultViewsController {

  /**
   * {@inheritdoc}
   */
  public function views_data() {
    $data = parent::views_data();

    $data['tier']['link_tier'] = array(
      'field' => array(
        'title' => t('Link'),
        'help' => t('Provide a link to the Tier.'),
        'handler' => '\Drupal\pagebuilder\Plugin\views\Handlers\TierLink',
      ),
    );
    $data['tier']['edit_tier'] = array(
      'field' => array(
        'title' => t('Edit Link'),
        'help' => t('Provide a link to the edit form for the Tier.'),
        'handler' => '\Drupal\pagebuilder\Plugin\views\Handlers\TierEdit',
      ),
    );
    $data['tier']['delete_tier'] = array(
      'field' => array(
        'title' => t('Delete Link'),
        'help' => t('Provide a link to delete the Tier.'),
        'handler' => '\Drupal\pagebuilder\Plugin\views\Handlers\TierDelete',
      ),
    );

    return $data;
  }

}
