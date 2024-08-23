uint8_t motor_PWM = 5 ; //  Speed
uint8_t motor_DIR = 4; //  Direction

int dir_Forward = 0;
int dir_Back = 255;

int PWM_STOP = 0;
int PWM_SLOW = 160; // arbitrary slow speed PWM duty cycle, actual value for "slow" depend on the battery voltage, motor and gearbox design
int PWM_FAST = 255; // fast speed PWM duty cycle

void setupmotor() {

  pinMode(motor_PWM, OUTPUT);
  pinMode(motor_DIR, OUTPUT);
  analogWrite(motor_DIR, dir_Forward );
  analogWrite( motor_PWM, PWM_STOP );
} 

void handle_Forward_Fast() {

  neopixelWrite(PIN_NEOPIXEL, RGB_BRIGHTNESS, 0, 0);  // Red
  analogWrite(motor_DIR, dir_Forward ); // direction = forward
  analogWrite( motor_PWM, PWM_FAST ); // PWM speed = fast
}

void handle_Forward_Slow() {

  neopixelWrite(PIN_NEOPIXEL, 0, RGB_BRIGHTNESS, 0);  // Green
  analogWrite(motor_DIR, dir_Forward ); // direction = forward
  analogWrite( motor_PWM, PWM_SLOW  ); // PWM speed = fast
}

void handle_Back_Slow() {

  neopixelWrite(PIN_NEOPIXEL, 0, RGB_BRIGHTNESS, 0);  // Green
  analogWrite(motor_DIR, dir_Back ); // direction = Back
  analogWrite( motor_PWM, 255 - PWM_SLOW ); // PWM speed = Slow  motor_PWM, 180 - PWM_SLOW
}

void handle_Back_Fast() {

  neopixelWrite(PIN_NEOPIXEL, RGB_BRIGHTNESS, 0, 0);  // Red
  analogWrite(motor_DIR, dir_Back ); // direction = Back
  analogWrite( motor_PWM, 255 - PWM_FAST ); // PWM speed = Retro
}

void handle_Stop() {

  neopixelWrite(PIN_NEOPIXEL, 0, 0, 0);  // Off / black
  analogWrite( motor_PWM, PWM_STOP );
  analogWrite(motor_DIR, dir_Forward);
}

