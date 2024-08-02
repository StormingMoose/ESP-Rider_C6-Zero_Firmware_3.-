
void setupwifi(){

  //ESP32 As access point IP: 192.168[.4.1
  WiFi.mode(WIFI_AP); //Access Point mode
  WiFi.softAP(ssid, password);    //Password length minimum 8 char

 
  server.on("/", handle_OnConnect);
  server.on("/A", handle_Forward_Fast);
  server.on("/B", handle_Forward_Slow);
  server.on("/C", handle_Back_Slow);
  server.on("/D", handle_Back_Fast);
  server.on("/off", handle_Stop);
  server.on("/R", handle_Go_Righter);
  server.on("/L", handle_Go_Lefter);
  server.on("/FO", handle_Flashlight_Off);
  server.on("/Pos", handle_Steering_Slider_Input);

  server.onNotFound(handle_NotFound);

  server.begin();                  //Start server
  Serial.println("HTTP server started");
}


void handle_NotFound () {
}


void handle_OnConnect() {
  String s = MAIN_page; //Read HTML contents
  server.send(200, "text/html", s); //Send web page
  Serial.println("connected to your phone");
}
