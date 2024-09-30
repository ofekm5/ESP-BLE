#include "BLEClient.h"

BLEClient client;

void setup() {
  client.Init();
  while(!client.FinishedSync()){
    client.Update();
  }
}

void loop() {}
