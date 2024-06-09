#include "solidColorProvider.h"

uint8_t color[3]; 
SolidColorProvider::SolidColorProvider(uint8_t** inputColors){
  color[0] = inputColors[0][0]; //R
  color[1] = inputColors[0][1]; //G
  color[2] = inputColors[0][2]; //B
};

uint8_t* SolidColorProvider::getColor(){
  return color;
}