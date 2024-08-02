uint8_t motor_PWM = 5 ; //  Speed
uint8_t motor_DIR = 4; //  Direction


// the actual values for "fast" and "slow" depend on the motor
int dir_Forward = 0;
int dir_Back = 255;

int PWM_STOP = 0;
int PWM_SLOW = 230; // arbitrary slow speed PWM duty cycle
int PWM_FAST = 255; // arbitrary fast speed PWM duty cycle

void setupmotor() {
  pinMode(motor_PWM, OUTPUT);
  pinMode(motor_DIR, OUTPUT);
  analogWrite(motor_DIR, dir_Forward );
  analogWrite( motor_PWM, PWM_STOP );
} 


void handle_Forward_Fast() {
  Serial.println("kilroy FF");
 // analogrite(Flight, HIGH); // Flash light will turn on
  analogWrite(motor_DIR, dir_Forward ); // direction = forward
  analogWrite( motor_PWM, PWM_FAST ); // PWM speed = fast
  server.send(200, "text/plain", "ok");

}

void handle_Forward_Slow() {

  //analogWrite(Flight, LOW);
  
  Serial.println("kilroy Fs");
  analogWrite(motor_DIR, dir_Forward ); // direction = forward
  analogWrite( motor_PWM, PWM_SLOW  ); // PWM speed = fast
  server.send(200, "text/plain", "ok");
}

void handle_Back_Slow() {
//  //analogWrite(Flight, LOW);

  Serial.println("kilroy bs");
  analogWrite(motor_DIR, dir_Back ); // direction = Back
  analogWrite( motor_PWM, 255 - PWM_SLOW ); // PWM speed = Slow  motor_PWM, 180 - PWM_SLOW
  server.send(200, "text/plain", "ok");
}

void handle_Back_Fast() {
  //analogWrite(Flight, LOW);

  Serial.println("kilroy bF");
  analogWrite(motor_DIR, dir_Back ); // direction = Back
  analogWrite( motor_PWM, 255 - PWM_FAST ); // PWM speed = Retro
  server.send(200, "text/plain", "ok");
}

void handle_Stop() {
  //analogWrite(Flight, LOW);

  Serial.println("kilroy STOP");
  analogWrite( motor_PWM, PWM_STOP );
  analogWrite(motor_DIR, dir_Forward);
  server.send(200, "text/plain", "ok");
}

