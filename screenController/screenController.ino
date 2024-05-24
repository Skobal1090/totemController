#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>
#ifndef PSTR
 #define PSTR // Make Arduino Due happy
#endif

#define PIN 7

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(32, 16, PIN,
  NEO_MATRIX_TOP     + NEO_MATRIX_LEFT +
  NEO_MATRIX_COLUMNS + NEO_MATRIX_ZIGZAG,
  NEO_RGB            + NEO_KHZ800);

void setup() {
  matrix.begin();
  matrix.setTextWrap(false);
  matrix.setBrightness(10);
  randomSeed(analogRead(0));
}

int x    = matrix.width();
int pass = 0;

int target = 1;

uint8_t currColors[] = { 255, 0, 0};

void loop() {
  matrix.fillScreen(0);
  matrix.setCursor(x,3);
  matrix.print(F("Connect Me!"));
  matrix.setTextColor(matrix.Color(currColors[0], currColors[1], currColors[2]));
  matrix.show();
  delay(50);

  if(currColors[target] < 255){
    currColors[target]+=5;
    return;
  }

  bool onTarget = true;
  int i = 0;
  while (i < 3){
    if(currColors[i] > 0 && i != target){
      currColors[i]-=5;
      onTarget = false;
    }
    i++;
  }

  if(onTarget){
    int newTarget = target;
    while(newTarget == target)
      newTarget = random(3);

    target = newTarget;
  }

  if(--x == -70){
    x = matrix.width();
  }
}
