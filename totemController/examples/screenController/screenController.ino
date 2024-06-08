#include "totemHeaders.h"

ScreenManager screenManager;

void setup() {
  Serial.begin(9600);
  while(!Serial);
  screenManager.init();
}

void display_freeram() {
  Serial.print(F("- SRAM left: "));
  Serial.println(freeRam());
}

int freeRam() {
  extern int __heap_start,*__brkval;
  int v;
  return (int)&v - (__brkval == 0  
    ? (int)&__heap_start : (int) __brkval);  
}

void loop() {
  screenManager.update();
}
