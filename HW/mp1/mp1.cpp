#include "cs225/PNG.h"
using cs225::PNG;

#include "cs225/HSLAPixel.h"
using cs225::HSLAPixel;

#include <string>
#include <cmath>
#include <iostream>
using std::cout;
using std::endl;



void rotate(std::string inputFile, std::string outputFile) {
  // TODO: Part 2
  cs225::PNG png, png2;
  png.readFromFile(inputFile);
  png2 = png;

  for (unsigned x = 0; x < png.width(); x++) {
    for (unsigned y = 0; y < png.height(); y++) {
      HSLAPixel & pixel_1 = png.getPixel(x, y);
      HSLAPixel & pixel_2 = png2.getPixel((png2.width() - 1 - x), png2.height() -1 - y);

      pixel_2.s = pixel_1.s;
      pixel_2.l = pixel_1.l;
      pixel_2.a = pixel_1.a;
      pixel_2.h = pixel_1.h;
    }
  }
  png2.writeToFile(outputFile);
}

PNG myArt(unsigned int width, unsigned int height) {
  PNG png(width, height);
  // TODO: Part 3[]

  double height_flag = 600;
  double width_flag = 800;
  double circle_origin_x = width_flag / 4;
  double circle_origin_y = height_flag / 4;
  double raduis = 50;

  //Red flag background
  for (unsigned x = 0; x < width_flag; x++) {
    for (unsigned y = 0; y < height_flag; y++) {
      HSLAPixel & pixel = png.getPixel(x, y);
      cs225::Red red; 
      pixel.h = red.h;
      pixel.s = red.s;
      pixel.l = red.l;
      pixel.a = red.a;
    }
  }

  //Blue small flag background
  for (unsigned x = 0; x < width_flag/2; x++) {
    for (unsigned y = 0; y < height_flag/2; y++) {
      HSLAPixel & pixel = png.getPixel(x, y);
      cs225::Blue blue;
      pixel.h = blue.h;
      pixel.s = blue.s;
      pixel.l = blue.l;
      pixel.a = blue.a;
    }
  }

  //stars
  double min_x = circle_origin_x - (raduis + 50) * tan(15 * M_PI / 180);
  double max_x = circle_origin_x + (raduis + 50) * tan(15 * M_PI / 180);
  double middle_x = (min_x + max_x) / 2;
  for (unsigned x = min_x; x < max_x; x++) {
    double max_y;
    if (x < middle_x) {
      max_y = (x - min_x) / tan(15 * M_PI / 180);
    } else {
      max_y = (max_x - x) / tan(15 * M_PI / 180);
    }
    for (unsigned y = circle_origin_y; y < circle_origin_y + max_y; y++) {
      HSLAPixel & pixel = png.getPixel(x, y);
      cs225::White white;
      pixel.s = white.s;
      pixel.l = white.l;
      pixel.a = white.a;
    }
    for (unsigned y = circle_origin_y - max_y; y < circle_origin_y; y++) {
      HSLAPixel & pixel = png.getPixel(x, y);
      cs225::White white;
      pixel.s = white.s;
      pixel.l = white.l;
      pixel.a = white.a;
    }
  }

  double min_y = circle_origin_y - (raduis + 50) * tan(15 * M_PI / 180);
  double max_y = circle_origin_y + (raduis + 50) * tan(15 * M_PI / 180);
  double middle_y = (min_y + max_y) / 2;
  for (unsigned y = min_y; y < max_y; y++) {
    double max_x;
    if (y < middle_y) {
      max_x = (y - min_y) / tan(15 * M_PI / 180);
    } else {
      max_x = (max_y - y) / tan(15 * M_PI / 180);
    }
    for (unsigned x = circle_origin_x; x < circle_origin_x + max_x; x++) {
      HSLAPixel & pixel = png.getPixel(x, y);
      cs225::White white;
      pixel.s = white.s;
      pixel.l = white.l;
      pixel.a = white.a;
    }
    for (unsigned x = circle_origin_x - max_x; x < circle_origin_x; x++) {
      HSLAPixel & pixel = png.getPixel(x, y);
      cs225::White white;
      pixel.s = white.s;
      pixel.l = white.l;
      pixel.a = white.a;
    }
  }

  min_x = circle_origin_x - (raduis + 50) * tan(15 * M_PI / 180) * cos(30 * M_PI / 180);
  max_x = circle_origin_x + (raduis + 50) * cos(60 * M_PI / 180);
  double height_y = (raduis + 50) * tan(15 * M_PI / 180) * cos(30 * M_PI / 180) * tan(30 * M_PI / 180);
  middle_x = max_x - ((raduis + 50) * sin(75 * M_PI / 180) - height_y) / tan(75 * M_PI / 180);
  for (unsigned x = min_x; x < max_x; x++) {
    double min_y = circle_origin_y - height_y - (x - min_x) * tan(45 * M_PI / 180);
    if (x < middle_x) {
      max_y = circle_origin_y - height_y;
    } else {
      max_y = circle_origin_y - height_y - (x - middle_x) * tan(75 * M_PI / 180);
    }
    for (unsigned y = min_y; y < max_y; y++) {
      HSLAPixel & pixel = png.getPixel(x, y);
      cs225::White white;
      pixel.s = white.s;
      pixel.l = white.l;
      pixel.a = white.a;
    }
    max_y = circle_origin_y + height_y + (x - min_x) * tan(45 * M_PI / 180);
    if (x < middle_x) {
      min_y = circle_origin_y + height_y;
    } else {
      min_y = circle_origin_y + height_y + (x - middle_x) * tan(75 * M_PI / 180);
    }
    for (unsigned y = min_y; y < max_y; y++) {
      HSLAPixel & pixel = png.getPixel(x, y);
      cs225::White white;
      pixel.s = white.s;
      pixel.l = white.l;
      pixel.a = white.a;
    }
  }

  max_x = circle_origin_x + (raduis + 50) * tan(15 * M_PI / 180) * cos(30 * M_PI / 180);
  min_x = circle_origin_x - (raduis + 50) * cos(60 * M_PI / 180);
  height_y = (raduis + 50) * tan(15 * M_PI / 180) * cos(30 * M_PI / 180) * tan(30 * M_PI / 180);
  middle_x = min_x + ((raduis + 50) * sin(75 * M_PI / 180) - height_y) / tan(75 * M_PI / 180);
  for (unsigned x = min_x; x < max_x; x++) {
    double max_y = circle_origin_y + height_y + (max_x - x) * tan(45 * M_PI / 180);
    if (x < middle_x) {
      min_y = circle_origin_y + height_y + (middle_x - x) * tan(75 * M_PI / 180);
    } else {
      min_y = circle_origin_y + height_y;
    }
    for (unsigned y = min_y; y < max_y; y++) {
      HSLAPixel & pixel = png.getPixel(x, y);
      cs225::White white;
      pixel.s = white.s;
      pixel.l = white.l;
      pixel.a = white.a;
    }
    min_y = circle_origin_y - height_y - (max_x - x) * tan(45 * M_PI / 180);
    if (x < middle_x) {
      max_y = circle_origin_y - height_y - (middle_x - x) * tan(75 * M_PI / 180);
    } else {
      max_y = circle_origin_y - height_y;
    }
    for (unsigned y = min_y; y < max_y; y++) {
      HSLAPixel & pixel = png.getPixel(x, y);
      cs225::White white;
      pixel.s = white.s;
      pixel.l = white.l;
      pixel.a = white.a;
    }
  }

  //
  min_x = circle_origin_x - (raduis + 50) * tan(15 * M_PI / 180) * cos(60 * M_PI / 180);
  max_x = circle_origin_x + (raduis + 50) * cos(30 * M_PI / 180);
  height_y = (raduis + 50) * tan(15 * M_PI / 180) * sin(60 * M_PI / 180);
  middle_x = max_x - (raduis + 50) * sin(30 * M_PI / 180);
  for (unsigned x = min_x; x < max_x; x++) {
    min_y = circle_origin_y - height_y - (x - min_x) * tan(15 * M_PI / 180);
    if (x < middle_x) {
      max_y = circle_origin_y;
    } else {
      max_y = circle_origin_y - (x - middle_x) * tan(45 * M_PI / 180);
    }
    for (unsigned y = min_y; y < max_y; y++) {
      HSLAPixel & pixel = png.getPixel(x, y);
      cs225::White white;
      pixel.s = white.s;
      pixel.l = white.l;
      pixel.a = white.a;
    }
    max_y = circle_origin_y + height_y + (x - min_x) * tan(15 * M_PI / 180);
    if (x < middle_x) {
      min_y = circle_origin_y;
    } else {
      min_y = circle_origin_y + (x - middle_x) * tan(45 * M_PI / 180);
    }
    for (unsigned y = min_y; y < max_y; y++) {
      HSLAPixel & pixel = png.getPixel(x, y);
      cs225::White white;
      pixel.s = white.s;
      pixel.l = white.l;
      pixel.a = white.a;
    }
  }

  max_x = circle_origin_x + (raduis + 50) * tan(15 * M_PI / 180) * cos(60 * M_PI / 180);
  min_x = circle_origin_x - (raduis + 50) * cos(30 * M_PI / 180);
  height_y = (raduis + 50) * tan(15 * M_PI / 180) * sin(60 * M_PI / 180);
  middle_x = min_x + (raduis + 50) * sin(30 * M_PI / 180);
  for (unsigned x = min_x; x < max_x; x++) {
    max_y = circle_origin_y + height_y + (max_x - x) * tan(15 * M_PI / 180);
    if (x < middle_x) {
      min_y = circle_origin_y + (middle_x - x) * tan(45 * M_PI / 180);
    } else {
      min_y = circle_origin_y;
    }
    for (unsigned y = min_y; y < max_y; y++) {
      HSLAPixel & pixel = png.getPixel(x, y);
      cs225::White white;
      pixel.s = white.s;
      pixel.l = white.l;
      pixel.a = white.a;
    }
    min_y = circle_origin_y - height_y - (max_x - x) * tan(15 * M_PI / 180);
    if (x < middle_x) {
      max_y = circle_origin_y - (middle_x - x) * tan(45 * M_PI / 180);
    } else {
      max_y = circle_origin_y;
    }
    for (unsigned y = min_y; y < max_y; y++) {
      HSLAPixel & pixel = png.getPixel(x, y);
      cs225::White white;
      pixel.s = white.s;
      pixel.l = white.l;
      pixel.a = white.a;
    }
  }

  //
  for (unsigned x = (circle_origin_x - (raduis + 10)); x < (circle_origin_x + (raduis + 10)); x++) {
    double circle = sqrt(pow((raduis + 10),2) - pow(fabs((int) x-circle_origin_x),2));
    for (unsigned y = circle_origin_y - circle; y < circle_origin_y + circle; y++) {
      HSLAPixel & pixel = png.getPixel(x, y);
      cs225::Blue blue;
      pixel.h = blue.h;
      pixel.s = blue.s;
      pixel.l = blue.l;
      pixel.a = blue.a;
    }
  }

  //
  for (unsigned x = (circle_origin_x - raduis); x < (circle_origin_x + raduis); x++) {
    double circle = sqrt(pow(raduis,2) - pow(fabs((int) x-circle_origin_x),2));
    for (unsigned y = circle_origin_y - circle; y < circle_origin_y + circle; y++) {
      HSLAPixel & pixel = png.getPixel(x, y);
      cs225::White white;
      pixel.s = white.s;
      pixel.l = white.l;
      pixel.a = white.a;
    }
  }
  for (unsigned y = 600; y < 800; y++) {
    for (unsigned x = 0; x < 160; x++) {
      HSLAPixel & pixel = png.getPixel(x, y);
      cs225::Orange rainbow;
      pixel.h = rainbow.h;
      pixel.s = rainbow.s;
      pixel.l = rainbow.l;
      pixel.a = rainbow.a;
    }
    for (unsigned x = 160; x < 160*2; x++) {
      HSLAPixel & pixel = png.getPixel(x, y);
      cs225::Yellow rainbow;
      pixel.h = rainbow.h;
      pixel.s = rainbow.s;
      pixel.l = rainbow.l;
      pixel.a = rainbow.a;
    }
    for (unsigned x = 160*2; x < 160*3; x++) {
      HSLAPixel & pixel = png.getPixel(x, y);
      cs225::Green rainbow;
      pixel.h = rainbow.h;
      pixel.s = rainbow.s;
      pixel.l = rainbow.l;
      pixel.a = rainbow.a;
    }
    for (unsigned x = 160*3; x < 160*4; x++) {
      HSLAPixel & pixel = png.getPixel(x, y);
      cs225::Light_blue rainbow;
      pixel.h = rainbow.h;
      pixel.s = rainbow.s;
      pixel.l = rainbow.l;
      pixel.a = rainbow.a;
    }
    for (unsigned x = 160*4; x < 160*5; x++) {
      HSLAPixel & pixel = png.getPixel(x, y);
      cs225::Purple rainbow;
      pixel.h = rainbow.h;
      pixel.s = rainbow.s;
      pixel.l = rainbow.l;
      pixel.a = rainbow.a;
    }
  }
  // for (unsigned x = 20; x < 113; x++) {
  //   for (unsigned y = 620; y < 640; y++) {
  //     HSLAPixel & pixel = png.getPixel(x, y);
  //     cs225::Red red;
  //     pixel.s = red.h;
  //     pixel.s = red.s;
  //     pixel.l = red.l;
  //     pixel.a = red.a;
  //   }
  // }
  // for (unsigned x = 20 + 93/2 - 10; x < 20 + 93/2 - 10 + 20; x++) {
  //   for (unsigned y = 640; y < 640 + 93; y++) {
  //     HSLAPixel & pixel = png.getPixel(x, y);
  //     cs225::Red red;
  //     pixel.s = red.h;
  //     pixel.s = red.s;
  //     pixel.l = red.l;
  //     pixel.a = red.a;
  //   }
  // }
  // for (unsigned x = 133 + 20; x < 133 + 20 + 113 * tan(30 * M_PI / 180); x++) {
  //   double min_y = 620 + 113 - (x - (133 + 20)) * tan(60 * M_PI / 180);
  //   for (unsigned y = min_y; y < 620 + 113; y++) {
  //     HSLAPixel & pixel = png.getPixel(x, y);
  //     cs225::Red red;
  //     pixel.s = red.h;
  //     pixel.s = red.s;
  //     pixel.l = red.l;
  //     pixel.a = red.a;
  //   }
  // }
  // for (unsigned x = 133 + 20 + 113 * tan(30 * M_PI / 180); x < 133 + 20 + 113 * tan(30 * M_PI / 180) + (113 - 2 * 113 * tan(30 * M_PI / 180)); x++) {
  //   for (unsigned y = 620; y < 620 + 113; y++) {
  //     HSLAPixel & pixel = png.getPixel(x, y);
  //     cs225::Red red;
  //     pixel.s = red.h;
  //     pixel.s = red.s;
  //     pixel.l = red.l;
  //     pixel.a = red.a;
  //   }
  // }

  return png;
}
