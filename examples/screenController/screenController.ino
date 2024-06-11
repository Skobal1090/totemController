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
int i = 0;
static String* texts = new String[3] {"This is the first", "The second", "now a third!"};
static uint8_t* colorModes = new uint8_t[3] {1, 2, 3};
static uint8_t*** colors = new uint8_t**[3] { 
  new uint8_t*[2] {new uint8_t[3]{255,0,0}, new uint8_t[3]{0,0,255}},
  new uint8_t*[1] {new uint8_t[0]},
  new uint8_t*[2] {new uint8_t[3]{0,255,0}, new uint8_t[3]{255,0,255}}
};

void loop() {
  screenManager.update();
  if(c % 200 == 0){
    Serial.print("Looped ");
    Serial.print(c);
    Serial.println((" times"));
    Serial.println("Sending attributes");
    screenManager.setAttributes(1, 1, colorModes[i], colors[i]);
    Serial.println("Sending new text");
    screenManager.setText(texts[i]);
    i++;
    if(i % 3 == 0)
      i = 0;
  }
  c++;
}
