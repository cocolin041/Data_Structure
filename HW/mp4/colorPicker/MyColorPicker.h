#pragma once

#include "ColorPicker.h"
#include "../cs225/HSLAPixel.h"
#include "../Point.h"

using namespace cs225;

/**
 * A color picker class using your own color picking algorithm
 */
class MyColorPicker : public ColorPicker {
public:
  MyColorPicker(PNG ref, PNG draw, string draw_type);
  HSLAPixel getColor(unsigned x, unsigned y);

private:
  PNG ref_;
  PNG draw_;
  string draw_type_;
};
