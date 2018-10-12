#include <cstdlib>
#include <cmath>
//
#include <iostream>

#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"

using namespace cs225;
using namespace std;
using std::cout;
using std::endl;

// sets up the output image
PNG* setupOutput(unsigned w, unsigned h) {
  PNG* image = new PNG(w, h);
  return image;
}

// Returns my favorite color
HSLAPixel* myFavoriteColor(double hue) {
    
//   HSLAPixel p(hue, 0.8, 0.5);
//   return &p;
  HSLAPixel *p = new HSLAPixel(hue, 0.8, 0.5);   //debug here
  return p;
}

void sketchify(std::string inputFile, std::string outputFile) {

    // Load in.png
    // PNG* original = NULL;

    //debug 2 here
    cs225::PNG png;
    png.readFromFile(inputFile);

    PNG * original = new PNG;
    *original = png;
    //end bug 2 here

    //original->readFromFile(inputFile);   //cannot use the class function of a NULL
    unsigned width = original->width();
    unsigned height = original->height();

    // Create out.png
    PNG* output = setupOutput(width, height);
    // setupOutput(width, height);

    // Load our favorite color to color the outline
    // cout << myFavoriteColor(44) << endl;
    HSLAPixel* myPixel = myFavoriteColor(280.098);

    // Go over the whole image, and if a pixel differs from that to its upper
    // left, color it my favorite color in the output
    for (unsigned y = 1; y < height; y++) {
        for (unsigned x = 1; x < width; x++) {
            // Calculate the pixel difference
            HSLAPixel& prev = original->getPixel(x - 1, y - 1);
            HSLAPixel& curr = original->getPixel(x, y);
            double diff = std::fabs(curr.h - prev.h);

            // If the pixel is an edge pixel,
            // color the output pixel with my favorite color
            //(original) HSLAPixel currOutPixel = (*output).getPixel(x, y);
            //because we want to modify the original output data, we need not a copy but a alias
            HSLAPixel & currOutPixel = (*output).getPixel(x, y);
            if (diff > 20) {
                currOutPixel = *myPixel;
            }
        }
    }

    //Save the output file
    output->writeToFile(outputFile);

    //Clean up memory
    delete myPixel;  //delete a pointer that allocate heap memory
    delete output;   //delete a pointer that allocate heap memory
    delete original;  //cannot delete a pointer that allocate stack memory, make original as heap memory pointer
    
}