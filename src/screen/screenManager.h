#ifndef _SCREEN_MANAGER_H
#define _SCREEN_MANAGER_H
#include "Arduino.h"
#include <stdint.h>
#include "../model/attributes.h"

class ScreenManager{
    public:
        void init();
        void update();
        void setAttributes(Attributes nextAttributes);
        void setText(String text);
};

#endif