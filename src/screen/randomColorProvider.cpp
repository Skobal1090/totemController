#include "randomColorProvider.h"
#include "Arduino.h"

uint8_t randomColor[3];
uint8_t** colorList = new uint8_t*[11]{
  //Colors are in RGB format
  new uint8_t[3]{255,0,0},
  new uint8_t[3]{0,255,0},
  new uint8_t[3]{0,0,255},
  new uint8_t[3]{255,255,0},
  new uint8_t[3]{255,0,255},
  new uint8_t[3]{255,255,255},
  new uint8_t[3]{255,0,200},
  new uint8_t[3]{255,200,0},
  new uint8_t[3]{200,255,0},
  new uint8_t[3]{200,0,255},
  new uint8_t[3]{200,0,200},
  
};

RandomColorProvider::RandomColorProvider(){
};

static uint8_t t = 0;
static int i = 0;
uint8_t* RandomColorProvider::getColor(){

  t += 1;
  if(t >= 10){
    int j = i;
    while(j == i)
      j = random(0,11);
    i = j;
    randomColor[0]  = colorList[i][0];
    randomColor[1]  = colorList[i][1];
    randomColor[2]  = colorList[i][2];
    t = 0;
  }
  return randomColor;
}

void RandomColorProvider::setColors(uint8_t** inputColors){
  
}