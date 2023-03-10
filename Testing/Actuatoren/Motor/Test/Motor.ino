

<<<<<<< HEAD
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);


=======
int PWM1 = 11;
int in1 = 8;
int in2 = 7;
>>>>>>> 93f05473ad89d89067f79cf4dc882bd3fbdfebb4
void setup() {
  
  Serial.begin(9600);
  Serial.println("Serial working");
pinMode(PWM1, OUTPUT);
pinMode(in1, OUTPUT);
pinMode(in2, OUTPUT);
}

<<<<<<< HEAD
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
=======
void loop(){
>>>>>>> 93f05473ad89d89067f79cf4dc882bd3fbdfebb4

digitalWrite(PWM1, HIGH);
digitalWrite(in1, HIGH);
digitalWrite(in2, HIGH);
}
