 String s = MAIN_page; //Read HTML contents

void setupwifi(){

  //ESP32 As access point IP: 192.168[.4.1
//  WiFi.mode(WIFI_AP); //Access Point mode
  WiFi.softAP(ssid, password);    //Password length minimum 8 char
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  server.begin();
  Serial.println("HTTP server started");
}


 void handleClient(){
  NetworkClient client = server.accept();  // listen for incoming clients

  if (client) {                     // if you get a client,
    Serial.println("New Client.");  // print a message out the serial port
    String currentLine = "";        // make a String to hold incoming data from the client
    while (client.connected()) {    // loop while the client's connected
      if (client.available())    {     // if there's bytes to read from the client,
        char c = client.read();     // read a byte, then
        Serial.write(c);           // print it out the serial monitor
        if (c == '\n') {            // if the byte is a newline character

          // if the current line is blank, you got two newline characters in a row.
          // that's the start of the client HTTP request, so sstart a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
           //handle_OnConnect;
           
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println(s);
           // The HTTP response starts with another blank line:
            client.println();
            // break out of the while loop:
            break;
          } else {  // if you got a newline, then clear currentLine:
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the start of the currentLine
        }

          if (currentLine.endsWith("GET /A")){  handle_Forward_Fast();} // Serial.println("kilroy");currentLine= "";}
          if (currentLine.endsWith("GET /B")){  handle_Forward_Slow();}
          if (currentLine.endsWith("GET /C")){  handle_Back_Slow();}
          if (currentLine.endsWith("GET /D")){  handle_Back_Fast();}
          if (currentLine.endsWith("GET /off")){  handle_Stop();}
          if (currentLine.endsWith("GET /R")){  handle_Go_Righter();} //currentLine= "";}
          if (currentLine.endsWith("GET /L")){  handle_Go_Lefter();} //currentLine= "";}
          if (currentLine.endsWith("GET /FO")){  handle_Flashlight_Off();}
          if (currentLine.endsWith("&")){
              int pos1 = currentLine.indexOf('=');               //   these four lines parse the value passed by the slider bar
              int pos2 = currentLine.indexOf('&');               //  
              String posString = currentLine.substring(pos1+1, pos2);    //
              int temppos = posString.toInt();                           //    below the tempos has to be outside a +-7 range of the old setting otherwise slide steering is super slow  
              if ( pos - 7  <= temppos && temppos <= pos+7 ) {Serial.println("too close");}  // 7 makes the slider jump when slid to reduce net traffic
                else  {pos = temppos; handle_Steering_Slider_Input(); }    //   
                                        }    // end of pos handing
                                    }        // client available 
                                  }          // client connected
              }           // if there is a client
 }           // handle client   


void handle_NotFound () {
}


void handle_OnConnect() {
 
}
