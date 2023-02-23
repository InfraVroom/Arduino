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
const int Forward = 39; 
const int STOP = 0;
const int Backward = 216;
const int Left_Sideways = 106;
const int Right_Sideways = 149;
const int Left_AAB = 3;
const int Right_AAB = 36;
const int Forward_Left_Diagonally = 34;
const int Backward_Left_Diagonally = 72;
const int Forward_Right_Diagonally = 5;
const int Backward_Right_Diagonally = 144;
const int Left_Rotation = 139;
const int Right_Rotation = 116;
const int Left_Front_Rotation = 10;
const int Right_Front_Rotation = 20;
const int Left_Back_Rotation = 96;
const int Right_Back_Rotation = 129;
const int drift = 116;

//MotorSpeed
int MotorPWM1 = 200; //LF
int MotorPWM2 = 200; //RF
int MotorPWM3 = 200; //LB
int MotorPWM4 = 200; //RB

void setup() {
  pinMode(DIR_CLK, OUTPUT);
  pinMode(DATA, OUTPUT);
  pinMode(DIR_EN, OUTPUT);
  pinMode(DIR_LATCH, OUTPUT);
  pinMode(PWM0B, OUTPUT); //RB
  pinMode(PWM0A, OUTPUT); //LB
  pinMode(PWM2A, OUTPUT); //LF
  pinMode(PWM2B, OUTPUT); //RF 

  //Predefine function
void MOTOR(int Direction, int MotorPWM1, int MotorPWM2, int MotorPWM3, int MotorPWM4);
 }


void loop() {
MOTOR(Forward, MotorPWM1, MotorPWM2, MotorPWM3, MotorPWM4);
delay(2500);
MOTOR(STOP, MotorPWM1, MotorPWM2, MotorPWM3, MotorPWM4);
delay(1000);

MOTOR(Backward, MotorPWM1, MotorPWM2, MotorPWM3, MotorPWM4);
delay(2500);
MOTOR(STOP, MotorPWM1, MotorPWM2, MotorPWM3, MotorPWM4);
delay(1000);

MOTOR(Left_Sideways, MotorPWM1, MotorPWM2, MotorPWM3, MotorPWM4);
delay(2500);
MOTOR(STOP, MotorPWM1, MotorPWM2, MotorPWM3, MotorPWM4);
delay(1000);

MOTOR(Right_Sideways, MotorPWM1, MotorPWM2, MotorPWM3, MotorPWM4);
delay(2500);
MOTOR(STOP, MotorPWM1, MotorPWM2, MotorPWM3, MotorPWM4);
delay(1000);

MOTOR(Left_AAB, MotorPWM1, MotorPWM2, MotorPWM3, MotorPWM4);
delay(2500);
MOTOR(STOP, MotorPWM1, MotorPWM2, MotorPWM3, MotorPWM4);
delay(1000);

MOTOR(Right_AAB, MotorPWM1, MotorPWM2, MotorPWM3, MotorPWM4);
delay(2500);
MOTOR(STOP, MotorPWM1, MotorPWM2, MotorPWM3, MotorPWM4);
delay(1000);

MOTOR(Forward_Left_Diagonally, MotorPWM1, MotorPWM2, MotorPWM3, MotorPWM4);
delay(2500);
MOTOR(STOP, MotorPWM1, MotorPWM2, MotorPWM3, MotorPWM4);
delay(1000);

MOTOR(Backward_Left_Diagonally, MotorPWM1, MotorPWM2, MotorPWM3, MotorPWM4);
delay(2500);
MOTOR(STOP, MotorPWM1, MotorPWM2, MotorPWM3, MotorPWM4);
delay(1000);

MOTOR(Forward_Right_Diagonally, MotorPWM1, MotorPWM2, MotorPWM3, MotorPWM4);
delay(2500);
MOTOR(STOP, MotorPWM1, MotorPWM2, MotorPWM3, MotorPWM4);
delay(1000);

MOTOR(Backward_Right_Diagonally, MotorPWM1, MotorPWM2, MotorPWM3, MotorPWM4);
delay(2500);
MOTOR(STOP, MotorPWM1, MotorPWM2, MotorPWM3, MotorPWM4);
delay(1000);

MOTOR(Left_Rotation, MotorPWM1, MotorPWM2, MotorPWM3, MotorPWM4);
delay(2500);
MOTOR(STOP, MotorPWM1, MotorPWM2, MotorPWM3, MotorPWM4);
delay(1000);

MOTOR(Right_Rotation, MotorPWM1, MotorPWM2, MotorPWM3, MotorPWM4);
delay(2500);
MOTOR(STOP, MotorPWM1, MotorPWM2, MotorPWM3, MotorPWM4);
delay(1000);

MOTOR(Left_Front_Rotation, MotorPWM1, MotorPWM2, MotorPWM3, MotorPWM4);
delay(2500);
MOTOR(STOP, MotorPWM1, MotorPWM2, MotorPWM3, MotorPWM4);
delay(1000);

MOTOR(Right_Front_Rotation, MotorPWM1, MotorPWM2, MotorPWM3, MotorPWM4);
delay(2500);
MOTOR(STOP, MotorPWM1, MotorPWM2, MotorPWM3, MotorPWM4);
delay(1000);

MOTOR(Left_Back_Rotation, MotorPWM1, MotorPWM2, MotorPWM3, MotorPWM4);
delay(2500);
MOTOR(STOP, MotorPWM1, MotorPWM2, MotorPWM3, MotorPWM4);
delay(1000);

MOTOR(Right_Back_Rotation, MotorPWM1, MotorPWM2, MotorPWM3, MotorPWM4);
delay(2500);
MOTOR(STOP, MotorPWM1, MotorPWM2, MotorPWM3, MotorPWM4);
delay(1000);
}

//
void MOTOR(int Direction, int MotorPWM1, int MotorPWM2, int MotorPWM3, int MotorPWM4) {
  analogWrite(PWM2A, MotorPWM1);
  analogWrite(PWM2B, MotorPWM2);
  analogWrite(PWM0A, MotorPWM3);
  analogWrite(PWM0B, MotorPWM4);
  digitalWrite(DIR_LATCH, LOW);
  shiftOut(DATA, DIR_CLK, MSBFIRST, Direction);
  digitalWrite(DIR_LATCH, HIGH); 
}