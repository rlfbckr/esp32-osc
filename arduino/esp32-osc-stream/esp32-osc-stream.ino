#include <WiFi.h>
#include <WiFiMulti.h>
#include <HTTPClient.h>
#include <HTTPUpdate.h>
#include "AsyncUDP.h"
#include <Chrono.h>
#include <OSCBundle.h>

long senddataInterval = 100; // every 50 milliseconds
int networkOutPort = 9999; // remote port to receive OSC

WiFiMulti wifiMulti;
Chrono senddataTimer;
AsyncUDP udpOut;


void setup() {
  Serial.begin(115200);
  Serial.print("esp32 osc stream demo:");
  initWIFI();
}

void loop() {
  // put your main code here, to run repeatedly:

 if (senddataTimer.hasPassed(senddataInterval)) {
    senddataTimer.restart();
    sendDataOSC(); // calls function to send data.
  }
}
