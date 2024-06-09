#include "attributes.h"
#include "Arduino.h"

Attributes::Attributes(uint8_t* parms){
    //parms = {1,1,0,255,0,0,0,255,0}

    scrollMode = (parms[0] <= 10) ? parms[0] : 1;
    scrollSpeed = (parms[1] <= 10) ? parms[1] : 1;
    colorMode = (parms[2] <= 10) ? parms[2] : 0;

    for(int i = 3; i <= 32; i + 3){
        colors[(i / 3) - 1] = new uint8_t[3]{parms[i], parms[i + 1], parms[i + 2]};
    }


}