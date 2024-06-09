#ifndef _ATTRIBUTES_H
#define _ATTRIBUTES_H
#include "Arduino.h"
#include <stdint.h>

class Attributes {
  public:
    // "scrollMode: 1, scrollSpeed: 1, colorMode: 0, numColors: 2, c1r: 255, c1g: 0, c1b: 0, c2r: 0, c2b: 255, c2g: 0"
    Attributes(uint8_t* parms);
    Attributes();
    uint8_t colorMode;
    uint8_t scrollMode;
    uint8_t scrollSpeed;
    uint8_t* colors[10];
};

#endif