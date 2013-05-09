<?php

/**
 * @file
 * Admin callbacks for Islandora OpenSeadragon
 */

/**
 * Admin form. Descriptions taken from the deepzoom module.
 */
function islandora_openseadragon_admin($form, &$form_state) {
  drupal_add_css(drupal_get_path('module', 'islandora_openseadragon') . '/css/islandora_openseadragon.admin.css');

  // Get settings.
  $settings = islandora_openseadragon_get_settings();

  $form = array();
  $form['islandora_openseadragon_settings'] = array(
    '#type' => 'container',
    '#tree' => TRUE,
  );
  // Debug mode.
  $form['islandora_openseadragon_settings']['debugMode'] = array(
    '#type' => 'checkbox',
    '#title' => t('Debug mode'),
    '#default_value' => $settings['debugMode'],
    '#description' => t('Toggles whether messages should be logged and fail-fast behavior should be provided.'),
  );
  // Animation time.
  $form['islandora_openseadragon_settings']['animationTime'] = array(
    '#type' => 'textfield',
    '#title' => t('Animation time'),
    '#size' => 10,
    '#element_validate' => array('element_validate_number'),
    '#default_value' => $settings['animationTime'],
    '#description' => t('The amount of time in seconds that animations should last.'),
  );
  // Blend time.
  $form['islandora_openseadragon_settings']['blendTime'] = array(
    '#type' => 'textfield',
    '#title' => t('Blend time'),
    '#size' => 10,
    '#element_validate' => array('element_validate_number'),
    '#default_value' => $settings['blendTime'],
    '#description' => t('The amount of time in seconds that new tiles take to blend from transparent to opaque.'),
  );
  // Always blend.
  $form['islandora_openseadragon_settings']['alwaysBlend'] = array(
    '#type' => 'checkbox',
    '#title' => t('Always blend'),
    '#default_value' => $settings['alwaysBlend'],
    '#description' => t("Toggles whether tiles should always blend in and out, and not just when they're first loaded."),
  );
  // Auto hide controls.
  $form['islandora_openseadragon_settings']['autoHideControls'] = array(
    '#type' => 'checkbox',
    '#title' => t('Auto-hide controls'),
    '#default_value' => $settings['autoHideControls'],
    '#description' => t("Toggles whether controls should get automatically hidden when the user's mouse is off the viewer and the image has stopped animating."),
  );
  // Immediate render.
  $form['islandora_openseadragon_settings']['immediateRender'] = array(
    '#type' => 'checkbox',
    '#title' => t('Immediate render'),
    '#default_value' => $settings['immediateRender'],
    '#description' => t('Toggles whether the most appropriate tiles should always be rendered first, before any lower-resolution tiles are rendered. This loses the "sharpening" effect and instead creates a very visible "tiling" effect.'),
  );
  // Wrap horizontal.
  $form['islandora_openseadragon_settings']['wrapHorizontal'] = array(
    '#type' => 'checkbox',
    '#title' => t('Wrap horizontal'),
    '#default_value' => $settings['wrapHorizontal'],
    '#description' =>
    t('Toggles whether tiles should be "wrapped" horizontally, so that there are no left or right edges.') . '<br />' .
    '<strong>' . t('NOTE: this is an experimental API and is not guaranteed to work. The API is also very likely to change in the future. Use at your own risk!') . '</strong>',
  );
  // Wrap vertical.
  $form['islandora_openseadragon_settings']['wrapVertical'] = array(
    '#type' => 'checkbox',
    '#title' => t('Wrap vertical'),
    '#default_value' => $settings['wrapVertical'],
    '#description' =>
    t('Toggles whether tiles should be "wrapped" vertically, so that there are no top or bottom edges.') . '<br />' .
    '<strong>' . t('NOTE: this is an experimental API and is not guaranteed to work. The API is also very likely to change in the future. Use at your own risk!') . '</strong>',
  );
  // Wrap overlays.
  $form['islandora_openseadragon_settings']['wrapOverlays'] = array(
    '#type' => 'checkbox',
    '#title' => t('Wrap overlays'),
    '#default_value' => $settings['wrapOverlays'],
    '#description' =>
    t('Toggles whether overlays should be continually repositioned to match any horizontal or vertical wrapping. This has no effect if neither Wrap Horizontal nor Wrap Vertical are set.') . '<br />' .
    '<strong>' . t('NOTE: this is an experimental API and is not guaranteed to work. The API is also very likely to change in the future. Use at your own risk!') . '</strong>',
  );
  // Pan horizontal.
  $form['islandora_openseadragon_settings']['panHorizontal'] = array(
    '#type' => 'checkbox',
    '#title' => t('Pan horizontal'),
    '#default_value' => $settings['panHorizontal'],
    '#description' => t('Toggles whether images can be moved along the horizontal axis of the viewer.'),
  );
  // Pan vertical.
  $form['islandora_openseadragon_settings']['panVertical'] = array(
    '#type' => 'checkbox',
    '#title' => t('Pan vertical'),
    '#default_value' => $settings['panVertical'],
    '#description' => t('Toggles whether images can be moved along the vertical axis of the viewer.'),
  );
  // Minimum zoom image ratio.
  $form['islandora_openseadragon_settings']['minZoomImageRatio'] = array(
    '#type' => 'textfield',
    '#title' => t('Minimum zoom image ratio'),
    '#size' => 10,
    '#element_validate' => array('element_validate_number'),
    '#default_value' => $settings['minZoomImageRatio'],
    '#description' => t('The minimum image ratio (image size to viewer size) in both dimensions that can result from zooming out.'),
  );
  // Maximum zoom pixel ratio.
  $form['islandora_openseadragon_settings']['maxZoomPixelRatio'] = array(
    '#type' => 'textfield',
    '#title' => t('Maximum zoom pixel ratio'),
    '#size' => 10,
    '#element_validate' => array('element_validate_number'),
    '#default_value' => $settings['maxZoomPixelRatio'],
    '#description' => t('The maximum pixel ratio (screen pixels to image file pixels) that can result from zooming in.'),
  );
  // Visibility ratio.
  $form['islandora_openseadragon_settings']['visibilityRatio'] = array(
    '#type' => 'textfield',
    '#title' => t('Visibility ratio'),
    '#size' => 10,
    '#element_validate' => array('element_validate_number'),
    '#default_value' => $settings['visibilityRatio'],
    '#description' => t('The minimum portion of the viewport that must show visible content in both dimensions.'),
  );
  // Spring stiffness.
  $form['islandora_openseadragon_settings']['springStiffness'] = array(
    '#type' => 'textfield',
    '#title' => t('Spring stiffness'),
    '#size' => 10,
    '#element_validate' => array('element_validate_number'),
    '#default_value' => $settings['springStiffness'],
    '#description' => t('Determines how sharply the springs used for animations move.'),
  );
  // Image loader limit.
  $form['islandora_openseadragon_settings']['imageLoaderLimit'] = array(
    '#type' => 'textfield',
    '#title' => t('Image loader limit'),
    '#size' => 10,
    '#element_validate' => array('element_validate_number'),
    '#default_value' => $settings['imageLoaderLimit'],
    '#description' => t('The maximum number of concurrent image downloads that can be performed by each viewer.'),
  );
  // Click time threshold.
  $form['islandora_openseadragon_settings']['clickTimeThreshold'] = array(
    '#type' => 'textfield',
    '#title' => t('Click time threshold'),
    '#size' => 10,
    '#element_validate' => array('element_validate_number'),
    '#default_value' => $settings['clickTimeThreshold'],
    '#description' => t('The maximum number of milliseconds that can pass between a mousedown and a mouseup for the action to still be considered a "quick" click.'),
  );
  // Cl.ick dist threshold.
  $form['islandora_openseadragon_settings']['clickDistThreshold'] = array(
    '#type' => 'textfield',
    '#title' => t('Click distance threshold'),
    '#size' => 10,
    '#element_validate' => array('element_validate_number'),
    '#default_value' => $settings['clickDistThreshold'],
    '#description' => t('The maximum number of pixels the mouse can move between a mousedown and a mouseup for the action to still be considered a "quick" click.'),
  );
  // Zoom per click.
  $form['islandora_openseadragon_settings']['zoomPerClick'] = array(
    '#type' => 'textfield',
    '#title' => t('Zoom per click'),
    '#size' => 10,
    '#element_validate' => array('element_validate_number'),
    '#default_value' => $settings['zoomPerClick'],
    '#description' => t('The factor by which images should zoom when clicked on.'),
  );
  // Zoom per scroll.
  $form['islandora_openseadragon_settings']['zoomPerScroll'] = array(
    '#type' => 'textfield',
    '#title' => t('Zoom per scroll'),
    '#size' => 10,
    '#element_validate' => array('element_validate_number'),
    '#default_value' => $settings['zoomPerScroll'],
    '#description' => t('The factor by which images should zoom when scrolled over.'),
  );
  // Zoom per second.
  $form['islandora_openseadragon_settings']['zoomPerSecond'] = array(
    '#type' => 'textfield',
    '#title' => t('Zoom per second'),
    '#size' => 10,
    '#element_validate' => array('element_validate_number'),
    '#default_value' => $settings['zoomPerSecond'],
    '#description' => t('The factor by which images should zoom every second when the zoom buttons are held down.'),
  );

  // Tile size.
  $form['islandora_openseadragon_tile_size'] = array(
    '#type' => 'textfield',
    '#title' => t('Tile size'),
    '#size' => 10,
    '#element_validate' => array('element_validate_integer'),
    '#default_value' => variable_get('islandora_openseadragon_tile_size', '256'),
    '#description' => t('The size of image tiles used to compose the image as a whole, in pixels.'),
  );
  // Tile overlap.
  $form['islandora_openseadragon_tile_overlap'] = array(
    '#type' => 'textfield',
    '#title' => t('Tile overlap'),
    '#size' => 10,
    '#element_validate' => array('element_validate_integer'),
    '#default_value' => variable_get('islandora_openseadragon_tile_overlap', '0'),
    '#description' => t('The number of pixels by which each tile will overlap adjacent ones.'),
  );

  // Actions.
  $form['actions'] = array(
    '#type' => 'actions',
  );
  $form['actions']['reset'] = array(
    '#type' => 'submit',
    '#value' => t('Reset to defaults'),
    '#weight' => 1,
    '#submit' => array('islandora_openseadragon_admin_submit'),
  );

  return system_settings_form($form);
}

/**
 * Handles a submit from the admin pane.
 */
function islandora_openseadragon_admin_submit($form, &$form_state) {
  $op = $form_state['clicked_button']['#id'];
  switch ($op) {
    case 'edit-reset':
      variable_del('islandora_openseadragon_settings');
      variable_del('islandora_openseadragon_tile_size');
      variable_del('islandora_openseadragon_tile_overlap');
      break;
  }
}
