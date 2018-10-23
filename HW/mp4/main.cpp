
#include "cs225/PNG.h"
#include "FloodFilledImage.h"
#include "Animation.h"

#include "imageTraversal/DFS.h"
#include "imageTraversal/BFS.h"

#include "colorPicker/RainbowColorPicker.h"
#include "colorPicker/GradientColorPicker.h"
#include "colorPicker/GridColorPicker.h"
#include "colorPicker/SolidColorPicker.h"
#include "colorPicker/MyColorPicker.h"

using namespace cs225;

int main() {

  // @todo [Part 3]
  // - The code below assumes you have an Animation called `animation`
  // - The code provided below produces the `myFloodFill.png` file you must
  //   submit Part 3 of this assignment -- uncomment it when you're ready.
  
  /*
  PNG lastFrame = animation.getFrame( animation.frameCount() - 1 );
  lastFrame.writeToFile("myFloodFill.png");
  animation.write("myFloodFill.gif");
  */
  PNG ref;
  // ref.readFromFile("conan.png");
  // ref.readFromFile("darren2.png");
  ref.readFromFile("erin.png");

  unsigned int width = ref.width();
  unsigned int height = ref.height();

  PNG draw(width, height);
  
  FloodFilledImage image(draw);
  BFS dfs2(draw, Point(0, 0), 100);

  MyColorPicker skeching(ref, draw, "sketch");
  image.addFloodFill( dfs2, skeching );
  Animation animation = image.animate(4000);
  
  draw = animation.getFrame( animation.frameCount() - 1 );
  // DFS dfs1(draw, Point(0, 0), 5);
  DFS dfs1(draw, Point(0, 0), 100);
  MyColorPicker coloring(ref, draw, "coloring");
  image.addFloodFill( dfs1, coloring );

  animation = image.animate(4000, animation);

  PNG lastFrame = animation.getFrame( animation.frameCount() - 1 );
  lastFrame.writeToFile("myFloodFill.png");
  animation.write("myFloodFill.gif");

  return 0;
}
