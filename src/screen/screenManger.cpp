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
static String nextText = displayText;
static bool needsUpdate = false;

static ColorProvider* displayProvider;
static ColorProvider* nextProvider = displayProvider;

static uint8_t displayScrollSpeed;
static uint8_t nextScrollSpeed = displayScrollSpeed;

static uint8_t displayScrollMode;
static uint8_t nextScrollMode = displayScrollMode;

static uint8_t** nextColors = new uint8_t*[1]{new uint8_t[3]{255,255,255}};

static ColorProvider* solidColorProvider = new SolidColorProvider();
static ColorProvider* colorInterpolator = new ColorInterpolator();
static ColorProvider* randomColorProvider = new RandomColorProvider();
static ColorProvider* twoColorSwapProvider = new TwoColorSwapProvider();

static int cursorPos = 0;
static Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(64, 16, 7,
        NEO_MATRIX_TOP     + NEO_MATRIX_LEFT +
        NEO_MATRIX_COLUMNS + NEO_MATRIX_ZIGZAG,
        NEO_GRB            + NEO_KHZ800);

void ScreenManager::init(){
    matrix.begin();
    matrix.setTextWrap(false);
    //sets default matrix settings
    matrix.setBrightness(10);
    cursorPos = 0;// matrix.width();
    displayProvider = randomColorProvider;
    //displayProvider->setColors(new uint8_t*[1]{new uint8_t[3]{255,255,255}});
}

void ScreenManager::update(){
    matrix.fillScreen(0);
    matrix.setCursor(cursorPos,3);
    matrix.print(displayText);
    uint8_t* currColor = displayProvider->getColor();
    matrix.setTextColor(matrix.Color(currColor[0], currColor[1], currColor[2]));
    matrix.show();
    delay(50);

    /*f(--cursorPos == -((displayText.length() + 1) * 6)){
        cursorPos = matrix.width();
        if(needsUpdate){
            displayText = nextText;
            displayScrollMode = nextScrollMode;
            displayScrollSpeed = nextScrollSpeed;
            displayProvider = nextProvider;
            displayProvider->setColors(nextColors);
            needsUpdate = false;
        }
    }*/
}

void ScreenManager::setAttributes(uint8_t scrollMode, uint8_t scrollspeed, uint8_t colorMode, uint8_t** colors){
    needsUpdate = true;
    nextScrollMode = scrollMode;
    nextScrollSpeed = scrollspeed;
    nextColors = colors;
    switch(colorMode) {
    case 0: 
        nextProvider = solidColorProvider;
        break;
    case 1: 
        nextProvider = colorInterpolator;
        break;
    case 2:
        nextProvider = randomColorProvider;
        break;
    case 3:
        nextProvider = twoColorSwapProvider;
        break;
    }  
}  

void ScreenManager::setText(String text){
    nextText = text;
}