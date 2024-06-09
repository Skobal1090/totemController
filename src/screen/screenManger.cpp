#include "screenManager.h"
#include "colorInterpolator.h"
#include "colorProvider.h"
#include "solidColorProvider.h"
#include "randomColorProvider.h"
#include "twoColorSwapProvider.h"
#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>


static String displayText = "Connect Me!";
static String currText = displayText;
static int cursorPos = 0;
static Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(16, 16, 7,
        NEO_MATRIX_TOP     + NEO_MATRIX_LEFT +
        NEO_MATRIX_COLUMNS + NEO_MATRIX_ZIGZAG,
        NEO_GRB            + NEO_KHZ800);
static ColorProvider* provider;

void ScreenManager::init(){
    matrix.begin();
    matrix.setTextWrap(false);
    //sets default matrix settings
    matrix.setBrightness(10);
    cursorPos = 16;
    provider = new SolidColorProvider(new uint8_t*[1]{new uint8_t[3]{255,255,255}});
}

void ScreenManager::update(){
    matrix.fillScreen(0);
    matrix.setCursor(cursorPos,3);
    matrix.print(displayText);
    uint8_t* currColor = provider->getColor();
    matrix.setTextColor(matrix.Color(currColor[0], currColor[1], currColor[2]));
    matrix.show();
    delay(50);

    if(--cursorPos == -((displayText.length() + 1) * 6)){
        cursorPos = matrix.width();
        if(displayText != currText){
            displayText = currText;
        }
    }
}

void ScreenManager::setAttributes(Attributes nextAttributes){
    
    switch(nextAttributes.colorMode) {
    case 0: 
        provider = new SolidColorProvider(nextAttributes.colors);
        break;
    case 1: 
        provider = new ColorInterpolator(nextAttributes.colors);
        break;
    case 2:
        provider = new RandomColorProvider();
        break;
    case 3:
        provider = new TwoColorSwapProvider(nextAttributes.colors);
        break;
    }  
}  

void ScreenManager::setText(String text){

}