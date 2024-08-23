
#include <ESP32Servo.h>
Servo myservo;  // create servo object to control a servo

int servoPin = 2;

int pos = 94; // intitial servo postion to be at 90 degrees to make it straight different from 90 for mechanical adjustment

void setupservo(){
 
	myservo.setPeriodHertz(50); 
//	myservo.attach(servoPin,500,2400); // read somewhere that the numbers were different for my servo vs sg90 but they were not
  myservo.attach(servoPin);   
  myservo.write(pos);
  delay(500);

  myservo.write(pos-22);
   delay(1000);
  myservo.write(pos+22);
   delay(1000);
  myservo.write(pos);
   delay(1000);
}

void handle_Steering_Slider_Input() {

  myservo.write(pos);
  delay(200);
  
  neopixelWrite(PIN_NEOPIXEL, 0, 0, RGB_BRIGHTNESS);  // Blue
}


void handle_Go_Lefter() { // Receive an HTTP GET request for steering.  Depending on the position of servo could change name to Righter

  neopixelWrite(PIN_NEOPIXEL, 25, 0, RGB_BRIGHTNESS);  // Blue
  pos = pos - 5;
  if (pos < 62) {
    pos = 62;
  }
  myservo.write(pos);
}


void handle_Go_Righter() { // Receive an HTTP GET request for steering.  And from above comment this could be renamed Lefter instead

  neopixelWrite(PIN_NEOPIXEL, 0, 25, RGB_BRIGHTNESS);  // Blue
  pos = pos + 5;
  if (pos > 126) {
    pos = 126;    
  }
  myservo.write(pos);
}

