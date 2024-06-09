#include "attributes.h"
#include "Arduino.h"

Attributes::Attributes(String parms){
    parms = "1,1,0,255,0,0,0,255,0";
    int passes = 0;

    // Split the string into attributes
    while (parms.length() > 0)
    {
        int index = parms.indexOf(',');
        //no comma found (wrong input format)
        if (index == -1) {
            //set defaults
            colorMode = 1;
            scrollMode = 1;
            scrollSpeed = 1;
            colors[0] = 255;
            colors[1] = 0;
            colors[2] = 0;
        }
        else {
            switch (passes){
                case 0:{
                    scrollMode = (parms.substring(0, index)).toInt();
                    break;
                }
                case 1:{
                    scrollSpeed = (parms.substring(0, index)).toInt();
                    break;
                }
                case 2:{
                    colorMode = (parms.substring(0, index)).toInt();
                    break;
                }
                default:{
                    int c = (parms.substring(0, index)).toInt();
                    colors[passes-3] = c;
                    break;
                }
            }
            parms = parms.substring(index+1);
        }
        passes++;
    }
}