/**
 * @file StickerSheet.h
 * Contains your declaration of the interface for the StickerSheet class.
 */
#pragma once
#include "Image.h"
#include "cs225/PNG.h"
using cs225::Image;
using cs225::PNG;

class StickerSheet {
  public:
    //initialize
    StickerSheet(const Image &picture, unsigned max); 

    //Frees all space that was dynamically allocated by this StickerSheet
    ~StickerSheet(); 

    //copy constructor
    StickerSheet(const StickerSheet &other); 

    //assignment operator
    const StickerSheet & 	operator= (const StickerSheet &other);

    //Modifies the maximum number of stickers that can be stored on this StickerSheet without changing existing stickers' indices
    void changeMaxStickers(unsigned max);

    //Adds a sticker to the StickerSheet, so that the top-left of the sticker's Image is at (x, y) on the StickerSheet
    int addSticker(Image &sticker, unsigned x, unsigned y);

    //Changes the x and y coordinates of the Image
    bool translate(unsigned index, unsigned x, unsigned y);

    //Removes the sticker at the given zero-based layer index
    void removeSticker(unsigned index);

    //Returns a pointer to the sticker at the specified index
    Image * getSticker(unsigned index) const;

    //Renders the whole StickerSheet on one Image and returns that Image
    Image render() const;

  private:
    void clear();
    void _copy(StickerSheet const & other);
    Image base_image;
    unsigned max_;
    Image **stickers;
    unsigned index_;
};