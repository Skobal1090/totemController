#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>
#include "totemHeaders.h"

BleManager manager;

#define PIN 7

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(16, 16, PIN,
  NEO_MATRIX_TOP     + NEO_MATRIX_LEFT +
  NEO_MATRIX_COLUMNS + NEO_MATRIX_ZIGZAG,
  NEO_GRB            + NEO_KHZ800);

uint8_t colors[2][3] = {{ 0.0, 255.0, 0.0 }, { 255.0, 0.0, 0.0 }};
uint8_t solidColor[2][3] = {{ 0.0, 0.0, 255.0 }, {}};

int x    = matrix.width();
String displayText = "Ayeeeeeeeeeeeeeeeee";
String nextText = displayText;

ColorProvider* provider;

void onConnected(){
  Serial.println("connected from the main file!");
}

void onDisconnected(){
  Serial.println("disconnected from the main file!");
}

void onAttributesUpdated(Attributes attrs){
  Serial.println("Attributes updated");
}

void onTextUpdated(String newText){
  Serial.println("text updated to: " + newText);
  nextText = newText;
}

void setup(){
  Serial.begin(9600);
  while (!Serial);

  manager.setConnectionListener(onConnected, onDisconnected);
  manager.setAttributesUpdatedListener(onAttributesUpdated);
  manager.setTextUpdatedListener(onTextUpdated);

  manager.init();

  Serial.begin(9600);
  while(!Serial);
  matrix.begin();
  matrix.setTextWrap(false);
  matrix.setBrightness(10);
  randomSeed(analogRead(0));
  int selectedColor = 3;//random(0,2);
  switch(selectedColor) {
    case 0: 
      provider = new ColorInterpolator();
      provider->setColors(colors);
      break;
    case 1: 
      provider = new SolidColorProvider();
      provider->setColors(solidColor);
      break;
    case 2:
      provider = new RandomColorProvider();
      break;
    case 3:
      provider = new TwoColorSwapProvider();
      provider->setColors(colors);
      break;
  }
}

void loop(){
  manager.scan();

  matrix.fillScreen(0);
  matrix.setCursor(x,3);
  matrix.print(displayText);
  uint8_t* currColor = provider->getColor();
  matrix.setTextColor(matrix.Color(currColor[0], currColor[1], currColor[2]));
  matrix.show();
  delay(50);

  if(--x == -((displayText.length() + 1) * 6)){
    x = matrix.width();
    if(displayText != nextText){
      displayText = nextText;
    }
  }
}