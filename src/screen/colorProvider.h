#ifndef _COLOR_PROVIDER_H
#define _COLOR_PROVIDER_H
#include <stdint.h>
class ColorProvider{
  public:
    virtual uint8_t* getColor() = 0;
    virtual void setColors(uint8_t** inputColors);
};

#endif