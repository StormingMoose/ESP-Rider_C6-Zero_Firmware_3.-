

int Flight = 2;

void setuplight() {
  //digitalWrite(Flight, HIGH); //Flashlight will turn on
}

void handle_Flashlight_Off() {
  //digitalWrite(Flight, LOW);
  server.send(200, "text/plain", "ok");
}
