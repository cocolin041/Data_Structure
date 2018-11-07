/**
 * @file maptiles.cpp
 * Code for the maptiles function.
 */

#include <iostream>
#include <map>
#include "maptiles.h"
//#include "cs225/RGB_HSL.h"

using namespace std;


Point<3> convertToXYZ(LUVAPixel pixel) {
    return Point<3>( pixel.l, pixel.u, pixel.v );
}

MosaicCanvas* mapTiles(SourceImage const& theSource,
                       vector<TileImage>& theTiles)
{
    /**
     * @todo Implement this function!
     */
    std::map<Point<3>, TileImage*> colorTile;
    for (unsigned i = 0; i < theTiles.size(); i++) {
        colorTile.insert(std::make_pair(Point<3>(theTiles[i].getAverageColor().l, theTiles[i].getAverageColor().u, theTiles[i].getAverageColor().v), &theTiles[i]));
    }

    vector<Point<3>> colors;
    for (std::map<Point<3>, TileImage*>::iterator it = colorTile.begin(); it != colorTile.end(); it++) {
      colors.push_back(it->first);
    }
    KDTree<3> colorTree(colors);

    MosaicCanvas* mosaic = new MosaicCanvas(theSource.getRows(), theSource.getColumns());

    for (int row = 0; row < theSource.getRows(); row++) {
        for (int col = 0; col < theSource.getColumns(); col++) {
            Point<3> regionColor = Point<3>(theSource.getRegionColor(row, col).l, theSource.getRegionColor(row, col).u, theSource.getRegionColor(row, col).v);
            Point<3> closestColor = colorTree.findNearestNeighbor(regionColor);
            TileImage *closeseTile = colorTile.find(closestColor)->second;

            mosaic->setTile(row, col, closeseTile);

        }
    }
    return mosaic;

    // return NULL;
}

