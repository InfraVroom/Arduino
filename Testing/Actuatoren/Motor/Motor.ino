#include <AFMotor.h>


AF_DCMotor motor2(1);
AF_DCMotor motor4(2);
AF_DCMotor motor2(3);
AF_DCMotor motor4(4);

void setup() {
  
  Serial.begin(9600);

}

void loop() {
  

  motor2.setSpeed(255);
  motor2.run(BACKWARD);

  motor4.setSpeed(255);
  motor4.run(FORWARD);

  delay(2000);

  motor2.run(RELEASE);
  motor4.run(RELEASE);

}
