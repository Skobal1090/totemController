#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>
#include "colorInterpolator.h"
#ifndef PSTR
 #define PSTR // Make Arduino Due happy
#endif

#define PIN 7

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(16, 16, PIN,
  NEO_MATRIX_TOP     + NEO_MATRIX_LEFT +
  NEO_MATRIX_COLUMNS + NEO_MATRIX_ZIGZAG,
  NEO_RGB            + NEO_KHZ800);

double start[] = { 0.0, 255.0, 0.0 };
double end[] = { 255.0, 0.0, 0.0 };

ColorInterpolator interpolator = ColorInterpolator(start, end);

void setup() {
  matrix.begin();
  matrix.setTextWrap(false);
  matrix.setBrightness(10);
  randomSeed(analogRead(0));
}

int x    = matrix.width();
int pass = 0;

int target = 1;


void loop() {
  matrix.fillScreen(0);
  matrix.setCursor(x,3);
  matrix.print(F("Connect Me!"));
  double* currColor = interpolator.getColor();
  matrix.setTextColor(matrix.Color(currColor[0], currColor[1], currColor[2]));
  matrix.show();
  delay(50);

  if(--x == -125){
    x = matrix.width();
  }
}
