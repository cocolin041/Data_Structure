#include <iterator>
#include <cmath>

#include <list>
#include <queue>
#include <stack>
#include <vector>

#include "../cs225/PNG.h"
#include "../Point.h"

#include "ImageTraversal.h"
#include "DFS.h"


/**
 * Initializes a depth-first ImageTraversal on a given `png` image,
 * starting at `start`, and with a given `tolerance`.
 * 
 * @param png The image this DFS is going to traverse
 * @param start The start point of this DFS
 * @param tolerance If the current point is too different (difference larger than tolerance) with the start point,
 * it will not be included in this DFS
 */
DFS::DFS(const PNG & png, const Point & start, double tolerance) {  
  /** @todo [Part 1] */
  start_ = start;
  tolerance_ = tolerance;
  png_ = png;
  neighbors.push(start);
}

/**
 * Returns an iterator for the traversal starting at the first point.
 */
ImageTraversal::Iterator DFS::begin() {
  /** @todo [Part 1] */
  ImageTraversal* dfs_bfs = new DFS(png_, start_, tolerance_);
  return ImageTraversal::Iterator(dfs_bfs, start_, png_);
}
/**
 * Returns an iterator for the traversal one past the end of the traversal.
 */
ImageTraversal::Iterator DFS::end() {
  /** @todo [Part 1] */
  return ImageTraversal::Iterator();
}

/**
 * Adds a Point for the traversal to visit at some point in the future.
 */
void DFS::add(const Point & point) {
  /** @todo [Part 1] */
  neighbors.push(point);
}

/**
 * Removes and returns the current Point in the traversal.
 */
Point DFS::pop() {
  /** @todo [Part 1] */
  //only call pop when neighbors is not empty
  Point curr = neighbors.top();
  neighbors.pop();
  return curr;
}

/**
 * Returns the current Point in the traversal.
 */
Point DFS::peek() const {
  /** @todo [Part 1] */
  //only call peek when neighbors is not empty
  Point curr = neighbors.top();
  return curr;
}

/**
 * Returns true if the traversal is empty.
 */
bool DFS::empty() const {
  /** @todo [Part 1] */
  if (neighbors.size() == 0) {
    return true;
  } else {
    return false;
  }
}

// PNG* DFS::getPNG() const {
//   return &png_;
// }
// Point* DFS::getStart() const {
//  return &start_;
// }

double DFS::getTolerance() const {
  return tolerance_;
}
void DFS::operator=(const DFS& dfs) {
  this->start_ = dfs.start_;
  this->neighbors = dfs.neighbors;
  this->png_ = dfs.png_;
  this->tolerance_ = dfs.tolerance_;
}