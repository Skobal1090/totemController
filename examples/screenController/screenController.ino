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

int c = 1;
void loop() {
  screenManager.update();
  if(c % 200 == 0){
    Serial.print("Looped ");
    Serial.print(c);
    Serial.println((" times"));
    screenManager.setAttributes(1, 1, 3, new uint8_t*[2]{new uint8_t[3]{255,0,0}, new uint8_t[3]{255,0,255}});
    screenManager.setText("Did it change?");
  }
  c++;
}
