/**
 * @file Image.h
 * Contains your declaration of the interface for the Image class.
 */

#pragma once
#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"

namespace cs225 {
  class Image : public PNG {
    public:
      Image();
      Image(unsigned int width, unsigned int height);
      Image(Image const & other);

      void lighten();
      void lighten(double amount);
      void darken();
      void darken(double amount);
      void saturate();
      void saturate(double amount);
      void desaturate();
      void desaturate(double amount);
      void grayscale();
      void rotateColor(double degrees);
      void illinify();
      void scale();
      void scale(double factor);
      void scale(unsigned w, unsigned h);

      double x() const;
      double y() const;
      void set_x(double px);
      void set_y(double py);

    private:
      //Nothing!
      double x_;
      double y_;
  };
}