#ifndef _SOLID_COLOR_PROVIDER_H
#define _SOLID_COLOR_PROVIDER_H
#include "colorProvider.h"

class SolidColorProvider : public ColorProvider{
  public:
    SolidColorProvider();
    virtual uint8_t* getColor();
    virtual void setColors(uint8_t** inputColors);
};

#endif