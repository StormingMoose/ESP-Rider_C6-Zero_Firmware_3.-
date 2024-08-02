
#include <ESP32Servo.h>
Servo myservo;  // create servo object to control a servo

int servoPin = 19;

int pos = 94; // intitial servo postion to be at 90 degrees to make it straight different from 90 for mechanical adjustment

void setupservo(){
 
	myservo.setPeriodHertz(50); 
	myservo.attach(servoPin,500,2500);
  myservo.attach(servoPin);   // FOR MG996 use 500 and 2400 for 180 degrees 
  myservo.write(pos);
  delay(500);

  myservo.write(0);
   delay(1000);
  myservo.write(180);
   delay(1000);
   myservo.write(94);
}

void handle_Steering_Slider_Input() {
  if(server.arg("value") ){
  int slidervalue = server.arg("value").toInt();   //
  
  pos = slidervalue;
  myservo.write(pos);
  }
server.send(200, "text/plain", "ok");
}



void handle_Go_Lefter() { // Receive an HTTP GET request for steering.  Depending on the position of sg90 servo could change name to Righter
//  digitalWrite(Flight, HIGH);
  pos = pos - 15;
  if (pos < 54) {
    pos = 54;
  }
  myservo.write(pos);
  server.send(200, "text/plain", "ok");
}


void handle_Go_Righter() { // Receive an HTTP GET request for steering.  And from above comment this could be renamed Lefter instead
  digitalWrite(Flight, HIGH);
  pos = pos + 15;
  if (pos > 134) {
    pos = 134;
  }
  myservo.write(pos);
  server.send(200, "text/plain", "ok");
}

