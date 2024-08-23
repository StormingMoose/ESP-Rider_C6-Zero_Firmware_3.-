

int Flight = 14;   // Neopixel
// 

void setuplight() {
   #define RGB_BRIGHTNESS 24    
}

void handle_Flashlight_Off() {
  /*  neopixelWrite(PIN_NEOPIXEL, RGB_BRIGHTNESS, 0, 0);  // Red
  delay(1000);
  neopixelWrite(PIN_NEOPIXEL, 0, RGB_BRIGHTNESS, 0);  // Green
  delay(1000);
  neopixelWrite(PIN_NEOPIXEL, 0, 0, RGB_BRIGHTNESS);  // Blue
  delay(1000);
  */
  neopixelWrite(PIN_NEOPIXEL, 0, 0, 0);  // Off / black
}
