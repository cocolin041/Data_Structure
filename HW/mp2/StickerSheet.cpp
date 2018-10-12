#include "StickerSheet.h"
#include "Image.h"
#include "cs225/HSLAPixel.h"
using cs225::HSLAPixel;
using namespace std;
#include <algorithm>


StickerSheet::StickerSheet(const Image &picture, unsigned max) {
  base_image = picture;
  max_ = max;
  stickers = new Image*[max_];
  for (unsigned i = 0; i < max_; i++) {
    stickers[i] = nullptr;
  }
  index_ = 0;
}
StickerSheet::~StickerSheet() {
  clear();
}
StickerSheet::StickerSheet(const StickerSheet &other) {
  _copy(other);
}
void StickerSheet::_copy(StickerSheet const & other) {
  this->max_ = other.max_; 
  this->index_ = other.index_;
  this->base_image = other.base_image;
  this->stickers = new Image*[max_];
  for (unsigned i = 0; i < this->max_; i++) {
    stickers[i] = nullptr;
  }
  for (unsigned i = 0; i < this->index_; i++) {
    this->stickers[i] = new Image;
    this->stickers[i] = other.stickers[i]; 
  }
}

const StickerSheet & 	StickerSheet::operator= (const StickerSheet &other) {
  this->_copy(other);
  return *this;
}

void StickerSheet::changeMaxStickers(unsigned max) {
  if (max > max_) {
    Image **new_stickers = new Image*[max];
    for (unsigned i = 0; i < max; i++) {
      new_stickers[i] = nullptr;
    }
    for (unsigned i = 0; i < index_; i++) {
      new_stickers[i] = new Image;
      *new_stickers[i] = *stickers[i];
    }

    max_ = max;
    stickers = new Image*[max_];
    for (unsigned i = 0; i < max_; i++) {
      stickers[i] = nullptr;
    }
    for (unsigned i = 0; i < index_; i++) {
      stickers[i] = new Image;
      *stickers[i] = *new_stickers[i];
    }
  } else {
    Image **new_stickers = new Image*[max];
    for (unsigned i = 0; i < max; i++) {
      new_stickers[i] = nullptr;
    }
    max_ = max;
    if (index_ > max) {
      index_ = max;
    }
    for (unsigned i = 0; i < index_; i++) {
      new_stickers[i] = new Image;
      *new_stickers[i] = *stickers[i];
    }
    stickers = new Image*[max];
    for (unsigned i = 0; i < max_; i++) {
      stickers[i] = nullptr;
    }
    for (unsigned i = 0; i < index_; i++) {
      stickers[i] = new Image;
      *stickers[i] = *new_stickers[i];
    }
  }
}

int StickerSheet::addSticker(Image &sticker, unsigned x, unsigned y) {
  stickers[index_] = new Image;  
  *stickers[index_] = sticker;

  //store the x and y for the sticker
  stickers[index_]->set_x(x);
  stickers[index_]->set_y(y);

  //The sticker must be added to the lowest possible layer available
  if (index_ <= max_) {
    index_ += 1;
    return index_;
  } else {
    return -1;
  }
}
bool StickerSheet::translate(unsigned index, unsigned x, unsigned y) {
  if (stickers[index] != NULL){
    stickers[index]->set_x(x);
    stickers[index]->set_y(y);
    return true;
  } else {
    return false;
  }
}

void StickerSheet::removeSticker(unsigned index) {
  if (stickers[index] != NULL) {
    if (index < index_ - 1) {
      for (unsigned i = index; i < index_ - 1; i++) {
        if (stickers[i + 1] != NULL) {
          *stickers[i] = *stickers[i + 1];
        } else {
          stickers[i] = nullptr;    
        }
      }
    } else {
      stickers[index] = nullptr;
    }
  }
}

Image * StickerSheet::getSticker(unsigned index) const {
  if (stickers[index] != NULL) {
    return stickers[index];
  } else {
    return NULL;
  }
}

void StickerSheet::clear()
{
  // for (unsigned i = 0; i < max_; i++) {
    if (stickers != NULL) {                              
      delete [] stickers;
      // stickers[i] = nullptr;
    // }
  }
}

Image StickerSheet::render() const {
  //copy the original image so that it won't be changed
  Image copy_baseImage = base_image;

  //find the maximum width & height of the after stickers' center + stickers' width & height
  unsigned int *sticker_width = new unsigned int[index_];
  unsigned int *sticker_height = new unsigned int[index_];

  for (unsigned i = 0; i < index_; i++) {
    if (stickers[i] != NULL) {
      sticker_width[i] = stickers[i]->x() + stickers[i]->width();
      sticker_height[i] = stickers[i]->y() + stickers[i]->height();
    } else{
      sticker_width[i] = 0;
      sticker_height[i] = 0;
    }
  }

  unsigned int max_sticker_width;
  max_sticker_width = *std::max_element(sticker_width, sticker_width + index_);
  unsigned int max_sticker_height;
  max_sticker_height = *std::max_element(sticker_height, sticker_height + index_);

  delete [] sticker_width;
  delete [] sticker_height;

  unsigned int base_image_width;
  unsigned int base_image_height;

  if (max_sticker_width > copy_baseImage.width()) {
    base_image_width = max_sticker_width;
  } else {
    base_image_width = copy_baseImage.width();
  }
  if (max_sticker_height > copy_baseImage.height()) {
    base_image_height = max_sticker_height;
  } else {
    base_image_height = copy_baseImage.height();
  }
  copy_baseImage.resize(base_image_width, base_image_height);

  //draw the ith sticker
  HSLAPixel white(0, 0, 1, 0);
  for (unsigned index = 0; index < index_; index++) {
    if (stickers[index] != NULL) {
      for (unsigned i = 0; i < stickers[index]->width(); i++) {
        for (unsigned j = 0; j < stickers[index]->height(); j++) {
          HSLAPixel & base_pixel = copy_baseImage.getPixel(stickers[index]->x() + i, stickers[index]->y() + j);
          HSLAPixel & sticker_pixel = stickers[index]->getPixel(i, j);
          if (sticker_pixel != white) {
            base_pixel = sticker_pixel;
          }
        }
      } 
    }  
  }
  return copy_baseImage;
}