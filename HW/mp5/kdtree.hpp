/**
 * @file kdtree.cpp
 * Implementation of KDTree class.
 */

#include <utility>
#include <algorithm>
#include <math.h>
#include "kdtree.h"
#include "point.h"

using namespace std;

//whether first has smallerDimVal than second?
template <int Dim>
bool KDTree<Dim>::smallerDimVal(const Point<Dim>& first,
                                const Point<Dim>& second, int curDim) const
{
    /**
     * @todo Implement this function!
     */
    if (first[curDim] < second[curDim]) {
        return true;
    }
    if (first[curDim] > second[curDim]) {
        return false;
    }
    if (first[curDim] == second[curDim]) {
        return first < second;
    }

    return false;
}

template <int Dim>
bool KDTree<Dim>::shouldReplace(const Point<Dim>& target,
                                const Point<Dim>& currentBest,
                                const Point<Dim>& potential) const
{
    /**
     * @todo Implement this function!
     */
    double distance_curr = 0;
    double distance_potential = 0;

    for (int i = 0; i < Dim; i++) {
        distance_curr += ((target[i] - currentBest[i]) * (target[i] - currentBest[i]));
        distance_potential += ((target[i] - potential[i]) * (target[i] - potential[i]));
    }
    if (distance_curr > distance_potential) {
        return true;
    }
    if (distance_curr < distance_potential) {
        return false;
    }
    if (distance_curr == distance_potential) {
        return potential < currentBest;
    }

    return false;
}

/**
 * helper function for partition
 * swap two points in a vector
 * @param x, y the two points to swap with
 */
template <int Dim>
void KDTree<Dim>::swap(Point<Dim>& x, Point<Dim>& y) {
    Point<Dim> z = x;
    x = y;
    y = z;
}

/**
 * helper function for kthSmallest
 * partition elements of arr in range [l, r] into smaller than the rth element and greater than the rth element, according to the dimention dim
 * @param arr is the vector of Points
 * @param l is the starting index of which range in the array to partition
 * @param r is the ending index of which range in the array to partition
 * @param dim is which dimension to compare between points
 * @param left is the index that have smaller value
 * @param right is the index that have greater value
 * return the index of the rth element after partition
 */
template <int Dim>
int KDTree<Dim>::partition(vector<Point<Dim>>& arr, int l, int r, int dim) { 
    //let the compare element be the last element in the range
    Point<Dim> x = arr[r];
    //i is the pivot index
    int i = l; 
    //  go through from l to r-1
    //  if the element you go through is smaller than the last element, swap the pivot with the smaller one
    //  that is, move the smaller one to the left, and move pivot one step right
    for (int j = l; j < r ; j++) {
        if (smallerDimVal(arr[j], x, dim)) {  //arr[j] < x on the dim dimension
            swap(arr[i], arr[j]);
            i++; 
        }
    }
    //at last, swap the pivot with the last element
    swap(arr[i], arr[r]);
    return i;
}
/**
 * helper function in building KDTree
 * find kth smallest element in range [l, r], according to the dimention dim
 * @param arr is the vector of Points
 * @param l is the starting index of where to start searching the median in the array
 * @param r is the ending index of where to start searching the median in the array
 * @param dim is which dimension to compare between points
 * return the kthSmallest point
 */
template <int Dim>
Point<Dim> KDTree<Dim>::kthSmallest(vector<Point<Dim>>& arr, int l, int r, int k, int dim)
{  
   //the kth element must be in the array, so it's fixed to smaller than the size of array
   //there're r-l+1 elements in this array range
   if (k >= l && k <= r) { 
        
        //get the index when partition array with according to the last element
        int index = partition(arr, l, r, dim);
  
        //if the index is the median index
        if (index == k) {
            return arr[index]; 
        }
        else if (index > k)  {
            //if the index is greater than the median index => search on the left of the index
            return kthSmallest(arr, l, index - 1, k, dim); 
        }
        else {
            //if the index is smaller than the median index => search on the right of the index
            return kthSmallest(arr, index + 1, r,  k, dim); 
        }
    }
    else {
        //return the kth element
        return arr[r];
    }
}

/**
 * helper function of KDTree constructor
 * Create a KDTree recursively to the left and right of median, and return the root
 * @param newPoints vector of points to build the tree
 * @param left the starting index to build the tree of the vector points
 * @param right the ending index to build the tree of the vector points
 * @param dim the dim to compare when divide each level of nodes into left and right child
 * return the new KDTreeNode
 */
template <int Dim>
typename KDTree<Dim>::KDTreeNode* KDTree<Dim>::KDTree_helper(const vector<Point<Dim>> newPoints, vector<Point<Dim>>& copyOfPoints, int left, int right, int dim)
{
    int m = floor(double(right + left) / (double)2);

    if (left > right) {
        return NULL;
    }

    KDTreeNode* root = new KDTreeNode(kthSmallest(copyOfPoints, left, right, m, dim % Dim));
    
    root->left = KDTree_helper( newPoints, copyOfPoints, left, m - 1, (dim + 1) % Dim );
    root->right = KDTree_helper( newPoints, copyOfPoints, m + 1, right, (dim + 1) % Dim );        
    return root;
}

template <int Dim>
KDTree<Dim>::KDTree(const vector<Point<Dim>>& newPoints)
{
    /**
     * @todo Implement this function!
     */
    vector<Point<Dim>> copyOfPoints = newPoints;
    root = KDTree_helper(newPoints, copyOfPoints, 0, newPoints.size() - 1, 0);
}

/**
 * helper function of Copy Consructor
 * Recursively go through every nodes in the KDTree, and new a KDTreeNode with the same point of the node
 * @param node the node that you want to copy
 * return the new KDTreeNode
 */
template <int Dim>
typename KDTree<Dim>::KDTreeNode* KDTree<Dim>::CopyRecursive(const KDTreeNode* node)
{
    if (node != nullptr) {
        KDTreeNode* newNode = new KDTreeNode(node->point);
        newNode->left = CopyRecursive(node->left);
        newNode->right = CopyRecursive(node->right);
        return newNode;
    }
    return NULL;
}

template <int Dim>
KDTree<Dim>::KDTree(const KDTree<Dim>& other) {
  /**
   * @todo Implement this function!
   */
  this->root = CopyRecursive(other.root);
}

template <int Dim>
const KDTree<Dim>& KDTree<Dim>::operator=(const KDTree<Dim>& rhs) {
  /**
   * @todo Implement this function!
   */
  if (this != &rhs) {
    DestroyRecursive(root);
    this->root = CopyRecursive(rhs.root);
  }
  return *this;
}

/**
 * helper function of Destructor
 * Recursively go through every nodes in the KDTree, and delete it
 * @param node the node that you want to delete
 */
template <int Dim>
void KDTree<Dim>::DestroyRecursive(KDTree<Dim>::KDTreeNode*& node)
{
    if (node != nullptr)
    {
        if (node->left != nullptr) {
            DestroyRecursive(node->left);
        }
        if (node->right != nullptr) {
            DestroyRecursive(node->right);
        }
        delete node;
        node = nullptr;
    }
}

template <int Dim>
KDTree<Dim>::~KDTree() {
  /**
   * @todo Implement this function!
   */
  DestroyRecursive(root);
}

template <int Dim>
Point<Dim> KDTree<Dim>::findNearestNeighbor(const Point<Dim>& query) const
{
    /**
     * @todo Implement this function!
     */
    if (root != nullptr) {
        KDTreeNode* best = findNearestNeighbor_helper(query, root, 0);
        return best->point;
    } else {
        Point<Dim> arr;
        return arr;
    }
}

/**
 * helper function of findNearestNeighbor_helper
 * calculate the distance between two points
 * @param first, second the points that we want to calculate distance with
 * return the distance
*/
template <int Dim>
double KDTree<Dim>::distance(const Point<Dim>& first, const Point<Dim>& second) const {
    double d = 0;

    for (int i = 0; i < Dim; i++) {
        d += ((first[i] - second[i]) * (first[i] - second[i]));
    }
    return d;
}

/**
 * helper function of findNearestNeighbor
 * Find the nearest neighbor for a given query point for a KDTree start with subroot
 * @param query the target point that you want to find the nearest neighbor of
 * @param subroot the starting root when searching the nearest neighbor on a KDTree
 * @param dim get the nearest neighbor according to the dim dimension
 * return the nearest KDTreeNode
*/
template <int Dim>
typename KDTree<Dim>::KDTreeNode* KDTree<Dim>::findNearestNeighbor_helper(const Point<Dim>& query, KDTree<Dim>::KDTreeNode* subroot, int dim) const {

    KDTreeNode* curr = subroot;
    KDTreeNode* best = curr;

    //if the query point is smaller than the current point on dim%Dim dimension => go search on the left tree (since closer point will happen on the left tree)
    if (smallerDimVal(query, curr->point, dim % Dim)) {
        //get the nearest point on the left tree, save as best point
        if (curr->left != NULL) {
            best = findNearestNeighbor_helper(query, curr->left, (dim + 1) % Dim);
        }
        //if the current point is closer than the best point => replace best point with current point
        if (shouldReplace(query, best->point, curr->point)) {
            best = curr;
        } 
        //look whether there's other potential point on the other side of the tree (fall in the radius)
        //if the circle does cross over another region, then search on that region again
        if ( distance(best->point, query) >= ((query[dim] - curr->point[dim]) * (query[dim] - curr->point[dim])) && curr->right != NULL) {
            KDTreeNode* best_another_branch = findNearestNeighbor_helper(query, curr->right, (dim + 1) % Dim);
            if (shouldReplace(query, best->point, best_another_branch->point)) {
                best = best_another_branch;
                // return best_another_branch;
            }
        }
        // return best;
    //if the query point is greater than the current point on dim dimension => go search on the right tree
    } else {
        if (curr->right != NULL) {
            best = findNearestNeighbor_helper(query, curr->right, (dim + 1) % Dim);
        }
        if (shouldReplace(query, best->point, curr->point)) {
            best = curr;
        }
        if ( distance(best->point, query) >= ((query[dim] - curr->point[dim]) * (query[dim] - curr->point[dim])) && curr->left != NULL) {
            KDTreeNode* best_another_branch = findNearestNeighbor_helper(query, curr->left, (dim + 1) % Dim);
            if (shouldReplace(query, best->point, best_another_branch->point)) {
                best = best_another_branch;
                // return best_another_branch;
            }
        }
        // return best;
    }
    return best;
}