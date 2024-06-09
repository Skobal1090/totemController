#ifndef _SCREEN_MANAGER_H
#define _SCREEN_MANAGER_H
#include "Arduino.h"
#include <stdint.h>
#include "../model/attributes.h"

class ScreenManager{
    public:
        void init();
        void update();
        void setAttributes(uint8_t scrollMode, uint8_t scrollspeed, uint8_t colorMode, uint8_t** colors);
        void setText(String text);
};

#endif