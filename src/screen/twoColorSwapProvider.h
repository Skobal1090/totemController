#ifndef _TWO_COLOR_SWAP_PROVIDER_H
#define _TWO_COLOR_SWAP_PROVIDER_H
#include "colorProvider.h"

class TwoColorSwapProvider : public ColorProvider {
  public:
    //color1, color2 are passed in RGB format
    TwoColorSwapProvider(uint8_t** inputColors);
    virtual uint8_t* getColor();
};
#endif