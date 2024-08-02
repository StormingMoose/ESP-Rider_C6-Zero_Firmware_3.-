/*
   Adapted from the following:
   
   ESP32 Web Server Demo using Accesspoint
   https://circuits4you.com
   21-11-2018
*/

#include <WiFi.h>
#include <WebServer.h>
#include "index.h"  //Web page header file

//Enter your desired WiFi SSID and PASSWORD
const char* ssid = "ESP_Rider_Little_Truck";
const char* password = "********";

WebServer server(80);

//===============================================================
// Setup
//===============================================================
void setup() {

  Serial.begin(115200);
  Serial.println();
  Serial.println("Booting Sketch...");

  setupservo();
  setupmotor();
  setuplight();
  setupwifi();

}

//===============================================================
// This routine is executed when you open its IP in browser
//===============================================================
void loop() {
  server.handleClient();
 // Serial.println("LOOPING");
}
