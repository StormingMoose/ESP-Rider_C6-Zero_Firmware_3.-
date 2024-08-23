/*
   Adapted from the following:
   
   ESP32 Web Server Demo using Accesspoint
   https://circuits4you.com
   21-11-2018
*/

#include <WiFi.h>
#include <NetworkClient.h>
#include <WiFiAP.h>
//#include <WebServer.h>
#include "index.h"  //Web page header file

//Enter your desired WiFi SSID and PASSWORD
const char* ssid = "ESP_Rider_Little_Truck";
const char* password = "********";

NetworkServer server(80);

//===============================================================
// Setup
//===============================================================
void setup() {

  //Serial.begin(115200);
  //Serial.println();
  //Serial.println("Booting Sketch...");

  setupmotor();
  // Serial.println("Booting motors...");
  setupservo();  // setting up the servo first then motors caused the servo to lose connection on startup 
  // Serial.println("Booting Servo...");
  setuplight();
  // Serial.println("Booting lights...");
  setupwifi();  // done last to avoid button pushes that might get done at the wrong time.
  // Serial.println("Booting wifi...");
  
}

//===============================================================
// This routine is executed when you open its IP in browser
//===============================================================
void loop() {
  handleClient();
 // Serial.println("LOOPING");
}
