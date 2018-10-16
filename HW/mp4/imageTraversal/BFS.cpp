#include <iterator>
#include <cmath>

#include <list>
#include <queue>
#include <stack>
#include <vector>

#include "../cs225/PNG.h"
#include "../Point.h"

#include "ImageTraversal.h"
#include "BFS.h"

using namespace cs225;

/**
 * Initializes a breadth-first ImageTraversal on a given `png` image,
 * starting at `start`, and with a given `tolerance`.
 * @param png The image this BFS is going to traverse
 * @param start The start point of this BFS
 * @param tolerance If the current point is too different (difference larger than tolerance) with the start point,
 * it will not be included in this BFS
 */
BFS::BFS(const PNG & png, const Point & start, double tolerance) {  
  /** @todo [Part 1] */
  start_ = start;
  tolerance_ = tolerance;
  png_ = png;
  neighbors.push(start);
}

/**
 * Returns an iterator for the traversal starting at the first point.
 */
ImageTraversal::Iterator BFS::begin() {
  /** @todo [Part 1] */
  return ImageTraversal::Iterator(new BFS(png_, start_, tolerance_), start_);
}

/**
 * Returns an iterator for the traversal one past the end of the traversal.
 */
ImageTraversal::Iterator BFS::end() {
  /** @todo [Part 1] */
  return ImageTraversal::Iterator();
}

/**
 * Adds a Point for the traversal to visit at some point in the future.
 */
void BFS::add(const Point & point) {
  /** @todo [Part 1] */
  neighbors.push(point);
}

/**
 * Removes and returns the current Point in the traversal.
 */
Point BFS::pop() {
  /** @todo [Part 1] */
  Point curr = neighbors.front();
  neighbors.pop();
  return curr;
}

/**
 * Returns the current Point in the traversal.
 */
Point BFS::peek() const {
  /** @todo [Part 1] */
  Point curr = neighbors.front();
  return curr;
}

/**
 * Returns true if the traversal is empty.
 */
bool BFS::empty() const {
  /** @todo [Part 1] */
  if (neighbors.size() == 0) {
    return true;
  } else {
    return false;
  }
}

PNG* BFS::getPNG() const {
  PNG* image = new PNG(png_);
  return image;
}
Point* BFS::getStart() const {
 Point* start = new Point(start_.x, start_.y);
 return start;
}

double BFS::getTolerance() const {
  return tolerance_;
}
void BFS::operator=(const BFS& bfs) {
  this->start_ = bfs.start_;
  this->neighbors = bfs.neighbors;
  this->png_ = bfs.png_;
  this->tolerance_ = bfs.tolerance_;
}