#include <iostream>
using std::cerr;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <cassert>
#include <algorithm>
#include <functional>

#include "cs225/lodepng/lodepng.h"
#include "Image.h"
#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"

namespace cs225 {
  Image::Image() {}
  Image::Image(unsigned int width, unsigned int height) : PNG(width, height) {}
  Image::Image(Image const & other) : PNG(other) {}

  void Image::lighten() {
    for (unsigned x = 0; x < this->width(); x++) {
      for (unsigned y = 0; y < this->height(); y++) {
        HSLAPixel & pixel = this->getPixel(x, y);

        if ((pixel.l + 0.1) <= 1 && (pixel.l + 0.1) >= 0) {
          pixel.l += 0.1;
        } else if ((pixel.l + 0.1) > 1) {
          pixel.l = 1;
        } else {
          pixel.l = pixel.l;
        }
      }
    }
  }
  void Image::lighten(double amount) {
    for (unsigned x = 0; x < this->width(); x++) {
      for (unsigned y = 0; y < this->height(); y++) {
        HSLAPixel & pixel = this->getPixel(x, y);
        
        if ((pixel.l + amount) <= 1 && (pixel.l + amount) >= 0) {
          pixel.l += amount;
        } else if ((pixel.l + amount) > 1) {
          pixel.l = 1;
        } else {
          pixel.l = pixel.l;
        }
      }
    }
  }
  void Image::darken() {
    for (unsigned x = 0; x < this->width(); x++) {
      for (unsigned y = 0; y < this->height(); y++) {
        HSLAPixel & pixel = this->getPixel(x, y);
        if ((pixel.l - 0.1) <= 1 && (pixel.l - 0.1) >= 0) {
          pixel.l -= 0.1;
        } else if ((pixel.l - 0.1) < 0) {
          pixel.l = 0;
        } else {
          pixel.l = pixel.l;
        }
      }
    }
  }
  void Image::darken(double amount) {
    for (unsigned x = 0; x < this->width(); x++) {
      for (unsigned y = 0; y < this->height(); y++) {
        HSLAPixel & pixel = this->getPixel(x, y);
        if ((pixel.l - amount) <= 1 && (pixel.l - amount) >= 0) {
          pixel.l -= amount;
        } else if ((pixel.l - amount) < 0) {
          pixel.l = 0;
        } else {
          pixel.l = pixel.l;
        }
      }
    }
  }
  void Image::saturate() {
    for (unsigned x = 0; x < this->width(); x++) {
      for (unsigned y = 0; y < this->height(); y++) {
        HSLAPixel & pixel = this->getPixel(x, y);
        if ((pixel.s + 0.1) <= 1 && (pixel.s + 0.1) >= 0) {
          pixel.s += 0.1;
        } else if ((pixel.s + 0.1) > 1) {
          pixel.s = 1;
        } else {
          pixel.s = pixel.s;
        }
      }
    }
  }
  void Image::saturate(double amount) {
    for (unsigned x = 0; x < this->width(); x++) {
      for (unsigned y = 0; y < this->height(); y++) {
        HSLAPixel & pixel = this->getPixel(x, y);
        if ((pixel.s + amount) <= 1 && (pixel.s + amount) >= 0) {
          pixel.s += amount;
        } else if ((pixel.s + amount) > 1) {
          pixel.s = 1;
        } else {
          pixel.s = pixel.s;
        }
      }
    }
  }
  void Image::desaturate() {
    for (unsigned x = 0; x < this->width(); x++) {
      for (unsigned y = 0; y < this->height(); y++) {
        HSLAPixel & pixel = this->getPixel(x, y);
        if ((pixel.s - 0.1) <= 1 && (pixel.s - 0.1) >= 0) {
          pixel.s -= 0.1;
        } else if ((pixel.s - 0.1) < 0) {
          pixel.s = 0;
        } else {
          pixel.s = pixel.s;
        }
      }
    }
  }
  void Image::desaturate(double amount) {
    for (unsigned x = 0; x < this->width(); x++) {
      for (unsigned y = 0; y < this->height(); y++) {
        HSLAPixel & pixel = this->getPixel(x, y);
        if ((pixel.s - amount) <= 1 && (pixel.s - amount) >= 0) {
          pixel.s -= amount;
        } else if ((pixel.s - amount) < 0) {
          pixel.s = 0;
        } else {
          pixel.s = pixel.s;
        }
      }
    }
  }
  void Image::grayscale() {
    for (unsigned x = 0; x < this->width(); x++) {
      for (unsigned y = 0; y < this->height(); y++) {
        HSLAPixel & pixel = this->getPixel(x, y);
        pixel.s = 0;
      }
    }
  }
  void Image::rotateColor(double degrees) {
    for (unsigned x = 0; x < this->width(); x++) {
      for (unsigned y = 0; y < this->height(); y++) {
        HSLAPixel & pixel = this->getPixel(x, y);
        if (degrees < 0) {
          degrees = -degrees;
        }
        if (pixel.h < 0) {
          pixel.h = 360 + pixel.h;
        }
        if ((pixel.h + degrees) <= 360 && (pixel.h + degrees) >= 0) {
          pixel.h += degrees;
        } else {
          pixel.h = pixel.h + degrees - 360;
        }
      }
    }
  }
  void Image::illinify() {
    for (unsigned x = 0; x < this->width(); x++) {
      for (unsigned y = 0; y < this->height(); y++) {
        HSLAPixel & pixel = this->getPixel(x, y);
        double to_illino_orange = pixel.h - 11;
        if (to_illino_orange < 0) {
          to_illino_orange = -to_illino_orange;
        }
        double to_illino_blue = pixel.h - 216;
        if (to_illino_blue < 0) {
          to_illino_blue = -to_illino_blue;
        }
        if (to_illino_orange < to_illino_blue) {
          pixel.h = 11;
        } else {
          pixel.h = 216;
        }
      }
    }
  }
  void Image::scale(double factor){
    if (factor == 1.0 | factor == 2.0 | factor == 0.5) {
      unsigned w = this->width() * factor;
      unsigned h = this->height() * factor;

      Image *img = new Image(w, h);
      HSLAPixel * newImageData = new HSLAPixel[w * h];

      for (unsigned x = 0; x < w; x++) {
        for (unsigned y = 0; y < h; y++) {
          HSLAPixel & oldPixel = this->getPixel(x/factor, y/factor);
          HSLAPixel & newPixel = newImageData[ (x + (y * w)) ];
          newPixel = oldPixel;
        }
      }
      for (unsigned x = 0; x < w; x++) {
        for (unsigned y = 0; y < h; y++) {
          HSLAPixel & oldPixel = newImageData[ (x + (y * w)) ];
          HSLAPixel & newPixel = img->getPixel(x,y);
          newPixel = oldPixel;
        }
      }
      this->resize(w, h);
      *this = *img;
    }
  }
  void Image::scale(unsigned w, unsigned h) {

    double factor_w = (double)w / this->width();
    double factor_h = (double)h / this->height();
    double factor_wh = (double)std::min(factor_w, factor_h);
    unsigned new_w = this->width() * factor_wh;
    unsigned new_h = this->height() * factor_wh;

    Image *img = new Image(new_w, new_h);
    HSLAPixel * newImageData = new HSLAPixel[new_w * new_h];

    for (unsigned x = 0; x < new_w; x++) {
      for (unsigned y = 0; y < new_h; y++) {
        HSLAPixel & oldPixel = this->getPixel(x/factor_wh, y/factor_wh);
        HSLAPixel & newPixel = newImageData[ (x + (y * new_w)) ];
        newPixel = oldPixel;
      }
    }
    for (unsigned x = 0; x < new_w; x++) {
      for (unsigned y = 0; y < new_h; y++) {
        HSLAPixel & oldPixel = newImageData[ (x + (y * new_w)) ];
        HSLAPixel & newPixel = img->getPixel(x,y);
        newPixel = oldPixel;
      }
    }
    this->resize(new_w, new_h);
    *this = *img;
  }
  // double Image::x() const {
  //   return this->x_;
  // }
  // double Image::y() const {
  //   return this->y_;
  // }
  // void Image::set_x(double px) {
  //   this->x_ = px;
  // }
  // void Image::set_y(double py) {
  //   this->y_ = py;
  // }
  double Image::x() const {
    return x_;
  }
  double Image::y() const {
    return y_;
  }
  void Image::set_x(double px) {
    x_ = px;
  }
  void Image::set_y(double py) {
    y_ = py;
  }
}