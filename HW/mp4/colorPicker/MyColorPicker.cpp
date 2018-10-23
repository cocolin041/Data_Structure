#include "../cs225/HSLAPixel.h"
#include "../cs225/PNG.h"
#include "../Point.h"

#include "ColorPicker.h"
#include "MyColorPicker.h"

#include <cstdlib>
#include <cmath>

using namespace cs225;

/**
 * Picks the color for pixel (x, y).
 * Using your own algorithm
 */
MyColorPicker::MyColorPicker(PNG ref, PNG draw, string draw_type) {
  ref_ = ref;
  draw_ = draw;
  draw_type_ = draw_type;
}

HSLAPixel MyColorPicker::getColor(unsigned x, unsigned y) {
  /* @todo [Part 3] */
  HSLAPixel pixel_ref = ref_.getPixel(x, y);
  HSLAPixel pixel_draw = draw_.getPixel(x, y);

  HSLAPixel love(1, 1, 0.54);

  if (draw_type_ == "sketch") {
    // if (y >= 70 && y < ref_.height() - 40) {
    //   if (pixel_ref.l > 0.2) { //not black
    //     pixel_draw.l = 0;  
    //   } else { //black
    //     pixel_draw.l = 1; 
    //   }
    // } else {
    //   pixel_draw.l = 1;
    // }
    if (pixel_ref.l < 0.4 && x < 500) {
      pixel_draw.l = 0;
    }
  }
  if (draw_type_ == "coloring") {
    // if (y >= 70 && y < ref_.height() - 40) {
    //   if (pixel_ref.l > 0) { //not black
    //     pixel_draw.l = pixel_ref.l;
    //   } else { //black
    //     pixel_draw.l = 0; 
    //   }
    // } else {
    //   pixel_draw = pixel_ref;
    // }
    if (pixel_ref.l < 0.4 && x < 500) {
      pixel_draw = pixel_ref;
    } else {
      if (x > ref_.width() - 56 && pixel_ref.l == 0) {
        pixel_draw = love;
      } else {
        pixel_draw = pixel_ref;
      }
    }
  }

  return pixel_draw;
}
