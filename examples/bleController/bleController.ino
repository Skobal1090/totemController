#include "totemHeaders.h"

#define PIN 7

BleManager manager;
ScreenManager screenManager;

void onTextUpdated(String text){
  Serial.println("text recieved!");
  screenManager.setText(text);
}

void onAttributesUpdated(uint8_t scrollMode, uint8_t scrollSpeed, uint8_t colorMode){
  Serial.println("Attributes received!");
  Serial.print("Color mode: ");
  Serial.println(colorMode);
}

void setup() {
  Serial.begin(9600);
  while (!Serial);

  manager.setTextUpdatedListener(onTextUpdated);
  manager.setAttributesUpdatedListener(onAttributesUpdated);

  manager.init();
  screenManager.init();
}

void loop() {
  manager.scan();
  screenManager.update();
}