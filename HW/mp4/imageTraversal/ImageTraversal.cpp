#include <cmath>
#include <iterator>
#include <iostream>

#include "../cs225/HSLAPixel.h"
#include "../cs225/PNG.h"
#include "../Point.h"

#include "ImageTraversal.h"

/**
 * Calculates a metric for the difference between two pixels, used to
 * calculate if a pixel is within a tolerance.
 * 
 * @param p1 First pixel
 * @param p2 Second pixel
 * @return the difference between two HSLAPixels
 */
double ImageTraversal::calculateDelta(const HSLAPixel & p1, const HSLAPixel & p2) {
  double h = fabs(p1.h - p2.h);
  double s = p1.s - p2.s;
  double l = p1.l - p2.l;

  // Handle the case where we found the bigger angle between two hues:
  if (h > 180) { h = 360 - h; }
  h /= 360;

  return sqrt( (h*h) + (s*s) + (l*l) );    
}

/**
 * Default iterator constructor.
 */
ImageTraversal::Iterator::Iterator() {
  /** @todo [Part 1] */
  taversal_ = nullptr;
}
// on my own
ImageTraversal::Iterator::Iterator(ImageTraversal* dfs_bfs, Point x) {
  taversal_ = dfs_bfs;
  position_ = x;
  for (int i = 0; i < (int)dfs_bfs->getPNG()->width(); i++) {
    std::vector<bool> visit;
    visited.push_back(visit);
    for (int j = 0; j < (int)dfs_bfs->getPNG()->height(); j++) {
      visited[i].push_back(false);
    }
  }
}

/**
 * Iterator increment opreator.
 *
 * Advances the traversal of the image.
 */
ImageTraversal::Iterator & ImageTraversal::Iterator::operator++() {
  /** @todo [Part 1] */

  //mark the current position as visited
  visited[position_.x][position_.y] = true;

  PNG * curr_image = taversal_->getPNG();

  //calculate current delta from start point
  Point *start_position = taversal_->getStart();
  HSLAPixel start_pixel = curr_image->getPixel(start_position->x, start_position->y);

  //start to add neighbor points: right->below->left->above

  //1: check if the point is not out of bound
  if (position_.x + 1 < curr_image->width()) {
    Point* right = new Point(position_.x + 1, position_.y);
    HSLAPixel pixel = curr_image->getPixel(right->x, right->y);
    //2: check if the point is within tolerance
    if (calculateDelta(start_pixel, pixel) < taversal_->getTolerance()) {
      taversal_->add(*right);
    }
  }
  if (position_.y + 1 < curr_image->height()) {
    Point* below = new Point(position_.x, position_.y + 1);
    HSLAPixel pixel = curr_image->getPixel(below->x, below->y);
    if (calculateDelta(start_pixel, pixel) < taversal_->getTolerance()) {
      taversal_->add(*below);
    }
  }
  if (position_.x >= 1) {
    Point* left = new Point(position_.x - 1, position_.y);
    HSLAPixel pixel = curr_image->getPixel(left->x, left->y);
    if (calculateDelta(start_pixel, pixel) < taversal_->getTolerance()) {
      taversal_->add(*left);
    }
  }
  if (position_.y >= 1) {
    Point* above = new Point(position_.x, position_.y - 1);
    HSLAPixel pixel = curr_image->getPixel(above->x, above->y);
    if (calculateDelta(start_pixel, pixel) < taversal_->getTolerance() && position_.y >= 1) {
      taversal_->add(*above);
    }  
  }

  //move the current position to the next position: top(DFS), front(BFS)
  if (taversal_->empty() == false) {
    Point move_to = taversal_->pop();

    //check if the point had been visited, if yes, pop and find the next one
    while (visited[move_to.x][move_to.y] == true && taversal_->empty() == false) {
      move_to = taversal_->pop();
    }

    //add a new iterator of the next point that you're moving to
    Iterator *iter = new Iterator(taversal_, move_to);

    //update the current position to the point "move_to"
    position_ = move_to;
    return *iter;
  } else {
    Iterator *iter = new Iterator();
    return *iter;
  }
}

/**
 * Iterator accessor opreator.
 * 
 * Accesses the current Point in the ImageTraversal.
 */
Point ImageTraversal::Iterator::operator*() {
  /** @todo [Part 1] */
  return position_;
}

/**
 * Iterator inequality operator.
 * 
 * Determines if two iterators are not equal.
 */
bool ImageTraversal::Iterator::operator!=(const ImageTraversal::Iterator &other) {
  /** @todo [Part 1] */
  
  bool v1 = (this->taversal_ == NULL) || (this->taversal_->empty());
  bool v2 = (other.taversal_ == NULL) || (other.taversal_->empty());

  if (v1 != v2) {
    return true;
  } else {
    return false;
  }

  if (this->position_ == other.position_) {
    return false;
  } else {
    return true;
  }
}



