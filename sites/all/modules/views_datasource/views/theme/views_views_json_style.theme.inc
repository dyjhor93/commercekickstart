<?php

/**
 * @file
 * Views theme to render view fields as JSON.
 *
 * - $view: The view in use.
 * - $rows: Array of row objects as rendered by _views_json_render_fields
 * - $attachment: Not used currently
 * - $options: The options for the style passed in from the UI.
 *
 * @ingroup views_templates
 * @see views_json.views.inc
 */
function template_preprocess_views_views_json_style_simple(&$vars) {
  $view = $vars["view"];
  $rows = $vars["rows"];
  $options = $vars["options"];
  $base = $view->base_table;
  $root_object = $options["root_object"];
  $top_child_object = $options["top_child_object"];
  $plaintext_output = $options["plaintext_output"];
  $objects = array();

  // Create bitmask for json_encode.
  $option_defs = $vars['view']->style_plugin->option_definition();
  $bitmasks = $option_defs['encoding']['contains'];
  $bitmask = NULL;
  foreach ($bitmasks as $mask_key => $_bitmask) {
    if (isset($options[$mask_key]) && $options[$mask_key] && !is_array($options[$mask_key])) {
      $bitmask = $bitmask | constant($_bitmask['bitmask']);
    }
  }
  $vars['bitmask'] = $bitmask;

  foreach ($rows as $row) {

    $object = array();
    /* Convert the $rows into a hierachial key=>value array */
    foreach ($row as $field) {
      if ($options["field_output"] == "normal") {
        if ($field->label) {
          $label = $plaintext_output ? strip_tags($field->label) : $field->label;
        }
        else {
          $label = $plaintext_output ? strip_tags($field->id) : $field->id;
        }
        if (!$field->is_multiple) {
          if (is_array($field->content)) {
            $content = array();
            foreach ($field->content as $key => $value) {
              $safe = $plaintext_output ? strip_tags(html_entity_decode($value, ENT_QUOTES)) : $value;
              $safe = mb_check_encoding($safe, 'UTF-8') ? $safe : utf8_encode($safe);
              $content[$key] = $safe;
            }
          }
          else {
            $content = $plaintext_output ? strip_tags(html_entity_decode($field->content, ENT_QUOTES)) : $field->content;
            $content = mb_check_encoding($content, 'UTF-8') ? $content : utf8_encode($content);
          }
        }
        else {
          $content = array();
          foreach ($field->content as $n => $oc) {
            if (is_array($oc)) {
              foreach ($oc as $key => $value) {
                $content[$n][$key] = ($plaintext_output ? strip_tags($value) : $value);
              }
            }
            else {
              $content[$n] = ($plaintext_output ? strip_tags($oc) : $oc);
            }
          }
        }
      }
      elseif ($options["field_output"] == "raw") {
        $label = $plaintext_output ? strip_tags($field->id) : $field->id;
        if (!$field->is_multiple) {
          $content = $plaintext_output ? strip_tags($field->raw) : $field->raw;
        }
        else {
          $content = array();
          foreach ($field->raw as $n => $oc) {
            if (is_array($oc)) {
              foreach ($oc as $key => $value) {
                $content[$n][$key] = ($plaintext_output ? strip_tags($value) : $value);
              }
            }
            else {
              $content[$n] = ($plaintext_output ? strip_tags($oc) : $oc);
            }
          }
        }
      }

      // check if user wants nested arrays
      if (strlen($top_child_object) != 0) {
        $object[$top_child_object][$label] = $content;
      }
      else {
        $object[$label] = $content;
      }
    }
    $objects[] = $object;
  }

  // check if user wants nested arrays
  $vars["rows"] = strlen($root_object) != 0 ? array($root_object => $objects) : $objects;

  // For pagination, output the total number of pages, the current page, the
  // total result count, and the limit per page.
  global $pager_total, $pager_page_array, $pager_total_items, $pager_limits;
  if (isset($pager_total[0])) {
    $pager_object = array(
      'pages' => $pager_total[0],
      'page' => $pager_page_array[0],
      'count' => intval($pager_total_items[0]),
      'limit' => intval($pager_limits[0]),
    );
    $vars["rows"]["pager"] = $pager_object;
  }
}

/**
 * Theme preprocess for "single simple object" format.
 *
 * Set only one row as view rows as object with properties.
 */
function template_preprocess_views_views_json_style_simple_object(&$vars) {
  $rows = &$vars['rows'];
  $options = $vars["options"];
  $root_object = $options["root_object"];
  $top_child_object = $options["top_child_object"];
  $size = count($rows);

  if ($size < 1) {
    $rows = new stdClass();
    return;
  }

  // We need just only one element.
  $rows = $size < 1 ? $rows : array_slice($rows, 0, 1);

  template_preprocess_views_views_json_style_simple($vars);

  $row = empty($root_object) ? $rows[0] : $rows[$root_object][0];

  if (array_key_exists($top_child_object, $row)) {
    $row = $row[$top_child_object];
  }

  $rows = (object) $row;
}

function template_preprocess_views_views_json_style_exhibit(&$vars) {
  $view = $vars["view"];
  $rows = $vars["rows"];
  $options = $vars["options"];
  $base = $view->base_table;
  $root_object = "Items";
  $top_child_object = $options["top_child_object"];
  $plaintext_output = $options["plaintext_output"];
  $objects = array();
  foreach ($rows as $row) {
    $object = array($top_child_object => array());
    /* Convert the $rows into a hierachial key=>value array */
    foreach ($row as $field) {
      if ($options["field_output"] == "normal") {
        if ($field->label) {
          $label = $plaintext_output ? strip_tags($field->label) : $field->label;
        }
        else {
          $label = $plaintext_output ? strip_tags($field->id) : $field->id;
        }
        if (!$field->is_multiple) {
          $content = $plaintext_output ? strip_tags(html_entity_decode($field->content, ENT_QUOTES)) : $field->content;
          $content = mb_check_encoding($content, 'UTF-8') ? $content : utf8_encode($content);
        }
        else {
          $content = array();
          foreach ($field->content as $n => $oc) {
            $content[$n] = ($plaintext_output ? strip_tags($oc) : $oc);
          }
        }
      }
      elseif ($options["field_output"] == "raw") {
        $label = $plaintext_output ? strip_tags($field->id) : $field->id;
        if (!$field->is_multiple) {
          $content = $plaintext_output ? strip_tags($field->raw) : $field->raw;
        }
        else {
          $content = array();
          foreach ($field->raw as $n => $oc) {
            $content[$n] = $plaintext_output ? strip_tags($oc) : $oc;
          }
        }
      }

      // check if user wants nested arrays
      if (strlen($top_child_object) != 0) {
        $object[$top_child_object][$label] = $content;
      }
      else {
        $object[$label] = $content;
      }
    }
    if (!array_key_exists("label", $object)) {
      $object["label"] = "Item";
    }
    if (!array_key_exists("type", $object)) {
      $object["type"] = $top_child_object;
    }
    $objects[] = $object;
  }

  // check if user wants nested arrays
  $vars["rows"] = strlen($root_object) != 0 ? array($root_object => $objects) : $objects;
}

function template_preprocess_views_views_json_style_jqgrid(&$vars) {
  $view = $vars["view"];
  $rows = $vars["rows"];
  $options = $vars["options"];
  $base = $view->base_table;
  $root_object = $options["root_object"];
  $top_child_object = $options["top_child_object"];
  $plaintext_output = $options["plaintext_output"];
  $objects = array();

  foreach ($rows as $row) {
    $object = array();
    foreach ($row as $field) {
      if ($options["field_output"] == "normal") {
        if ($field->label) {
          $label = $plaintext_output ? strip_tags($field->label) : $field->label;
        }
        else {
          $label = $plaintext_output ? strip_tags($field->id) : $field->id;
        }

        if (!$field->is_multiple) {
          $content = $plaintext_output ? strip_tags(html_entity_decode($field->content, ENT_QUOTES)) : $field->content;
          $content = mb_check_encoding($content, 'UTF-8') ? $content : utf8_encode($content);
        }
        else {
          $content = array();
          foreach ($field->content as $n => $oc) {
            $content[$n] = ($plaintext_output ? strip_tags($oc) : $oc);
          }
        }
      }
      elseif ($options["field_output"] == "raw") {
        $label = $plaintext_output ? strip_tags($field->id) : $field->id;
        if (!$field->is_multiple) {
          $content = $plaintext_output ? strip_tags($field->raw) : $field->raw;
        }
        else {
          $content = array();
          foreach ($field->raw as $n => $oc) {
            $content[$n] = $plaintext_output ? strip_tags($oc) : $oc;
          }
        }
      }
      $object[$label] = $content;
    }
    $objects[] = $object;
  }

  if (isset($view->query->pager)) {
    global $pager_total, $pager_total_items;

    $pager_id = $view->query->pager->options['id'];
    $very_top['page'] = $view->query->pager->current_page + 1;
    $very_top['records'] = $pager_total_items[$pager_id];
    $very_top['total'] = $pager_total[$pager_id];
    $very_top['rows'] = $objects;
  }

  $vars["rows"] = $very_top;//array($root_object => $objects);
}
