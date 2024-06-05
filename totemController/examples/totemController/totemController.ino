#include "totemHeaders.h"

BleManager manager;

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
}

void setup(){
  Serial.begin(9600);
  while (!Serial);

  manager.setConnectionListener(onConnected, onDisconnected);
  manager.setAttributesUpdatedListener(onAttributesUpdated);
  manager.setTextUpdatedListener(onTextUpdated);

  manager.init();
}

void loop(){
  manager.scan();
}