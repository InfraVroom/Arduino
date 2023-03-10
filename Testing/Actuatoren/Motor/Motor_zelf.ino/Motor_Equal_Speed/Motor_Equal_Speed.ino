#include <AFMotor.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

void setup() {
  
  Serial.begin(9600);

}

void loop() {
  int variableSpeed = 150;
  
  motor1.setSpeed(variableSpeed);
  motor1.run(FORWARD);

  motor2.setSpeed(variableSpeed);
  motor2.run(FORWARD);

  motor3.setSpeed(variableSpeed);
  motor3.run(FORWARD);

  motor4.setSpeed(variableSpeed);
  motor4.run(FORWARD);

  delay(2000);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);

}
