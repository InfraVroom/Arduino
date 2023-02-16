//PWM
const int PWM2A = 11;
const int PWM2B = 3;
const int PWM0A = 6;
const int PWM0B = 5;

//DATA
const int DIR_CLK = 4;
const int DIR_EN = 7;
const int DATA = 8;
const int DIR_LATCH = 12;

//Directions
const int Forward = 39;  // 8 bit decimaal 
const int STOP = 0;

//MotorSpeed
int MotorPWM1 = 0; //LF
int MotorPWM2 = 0; //RF
int MotorPWM3 = 0; //LB
int MotorPWM4 = 0; //RB

void setup() {
  //Data
  pinMode(DIR_CLK, OUTPUT);
  pinMode(DATA, OUTPUT);
  pinMode(DIR_EN, OUTPUT);
  pinMode(DIR_LATCH, OUTPUT);

  //Motor-output
  pinMode(PWM0B, OUTPUT); //RB
  pinMode(PWM0A, OUTPUT); //LB
  pinMode(PWM2A, OUTPUT); //LF
  pinMode(PWM2B, OUTPUT); //RF

  //Predefine function
void MOTOR(int Direction, int MotorPWM1, int MotorPWM2, int MotorPWM3, int MotorPWM4);
 }
 
void loop() {
MOTOR(Forward, MotorPWM1, MotorPWM2, MotorPWM3, MotorPWM4);
delay(2000);
MOTOR(STOP, MotorPWM1, MotorPWM2, MotorPWM3, MotorPWM4);
delay(1000);
}

void MOTOR(int Direction, int MotorPWM1, int MotorPWM2, int MotorPWM3, int MotorPWM4) {
  analogWrite(PWM2A, MotorPWM1);
  analogWrite(PWM2B, MotorPWM2);
  analogWrite(PWM0A, MotorPWM3);
  analogWrite(PWM0B, MotorPWM4);
  digitalWrite(DIR_LATCH, LOW);
  shiftOut(DATA, DIR_CLK, MSBFIRST,Direction);
  digitalWrite(DIR_LATCH, HIGH); 
}