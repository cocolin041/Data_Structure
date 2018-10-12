#include "Image.h"
#include "StickerSheet.h"
#include <iostream>
using namespace std;
using std::cout;
using std::endl;

int main() {

  //
  // Reminder:
  //   Before exiting main, save your creation to disk as myImage.png
  //
  Image origin; 
  origin.readFromFile("part3/maplestory.png");
  origin.scale(1440, 1080);
  
  Image mario;    
  mario.readFromFile("part3/mario.png");
  mario.scale(300, 300);

  Image speed; 
  speed.readFromFile("part3/speed.png");
  speed.scale(250, 250);

  Image rabipen; 
  rabipen.readFromFile("part3/rabipen.png");
  rabipen.scale(250, 250);

  Image pokemon; 
  pokemon.readFromFile("part3/pokemon.png");
  pokemon.scale(300, 300);

  Image kabara; 
  kabara.readFromFile("part3/kabara.png");

  StickerSheet stickerList(origin, 5);
  stickerList.addSticker(mario, 10, 200);
  stickerList.addSticker(pokemon, 300, 100);
  stickerList.addSticker(rabipen, 550, 150);
  stickerList.addSticker(speed, 800, 200);
  stickerList.addSticker(kabara, 950, 450);

  Image myImage;
  myImage = stickerList.render();
  myImage.writeToFile("myImage.png");

  return 0;
}
