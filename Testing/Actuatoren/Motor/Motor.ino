#include <AFMotor.h>


AF_DCMotor motor1(1);
AF_DCMotor motor2(2);


void setup() {
  
  Serial.begin(9600);

}

void loop() {
  
  int variableSpeed = 255;
  float motor1SpeedF = 0.5, motor2SpeedF = 0.7, motor3SpeedF, motor4SpeedF;
  float motor1Speed = motor1SpeedF * variableSpeed;
  float motor2Speed = motor2SpeedF * variableSpeed;
  float motor3Speed = motor3SpeedF * variableSpeed;
  float motor4Speed = motor4SpeedF * variableSpeed;

  motor1.setSpeed(motor1Speed);
  motor1.run(FORWARD);

  motor2.setSpeed(motor2Speed);
  motor2.run(FORWARD);

  delay(2000);

  motor1.run(RELEASE);
  motor2.run(RELEASE);

}
