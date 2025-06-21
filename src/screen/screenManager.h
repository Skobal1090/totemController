#ifndef _SCREEN_MANAGER_H
#define _SCREEN_MANAGER_H
#include "Arduino.h"
#include <stdint.h>
#include "colorProvider.h"
#include "colorInterpolator.h"
#include "solidColorProvider.h"
#include "randomColorProvider.h"
#include "twoColorSwapProvider.h"
#include "../model/attributes.h"

class ScreenManager{
    public:
        void init();
        void update();
        void setAttributes(uint8_t scrollMode, uint8_t scrollspeed, uint8_t colorMode, uint8_t colors[2][3]);
        void setText(String text);
};

#endif