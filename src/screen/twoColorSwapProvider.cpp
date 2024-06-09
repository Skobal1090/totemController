#include "twoColorSwapProvider.h"
#include "Arduino.h"

static uint8_t* colors[2];
TwoColorSwapProvider::TwoColorSwapProvider(){

}

int selectedColor = 0;
static uint8_t t;

uint8_t* TwoColorSwapProvider::getColor(){

  t += 1;
  if (t >= 20){
    selectedColor = (selectedColor + 1) % 2;
    t = 0;
  }
  
  return colors[selectedColor];
}

void TwoColorSwapProvider::setColors(uint8_t** inputColors){
  colors[0] = inputColors[0];
  colors[1] = inputColors[1];
}
