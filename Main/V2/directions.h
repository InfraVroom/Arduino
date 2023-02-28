//Directions
const int DIR_Forward = 39; 
const int DIR_STOP = 0;
const int DIR_Backward = 216;
const int DIR_Left_Sideways = 106;
const int DIR_Right_Sideways = 149;
const int DIR_Left_AAB = 3;
const int DIR_Right_AAB = 36;
const int DIR_Forward_Left_Diagonally = 34;
const int DIR_Backward_Left_Diagonally = 72;
const int DIR_Forward_Right_Diagonally = 5;
const int DIR_Backward_Right_Diagonally = 144;
const int DIR_Left_Rotation = 139;
const int DIR_Right_Rotation = 116;
const int DIR_Left_Front_Rotation = 10;
const int DIR_Right_Front_Rotation = 20;
const int DIR_Left_Back_Rotation = 96;
const int DIR_Left_Back_Rotation = 129;
const int DIR_drift = 116;

//MotorSpeed
int MotorPWM1 = 200; //LF
int MotorPWM2 = 200; //RF
int MotorPWM3 = 200; //LB
int MotorPWM4 = 200; //RB

//Driving motor
void MOTOR(int Direction, int MotorPWM1, int MotorPWM2, int MotorPWM3, int MotorPWM4) {
  analogWrite(PWM2A, MotorPWM1);
  analogWrite(PWM2B, MotorPWM2);
  analogWrite(PWM0A, MotorPWM3);
  analogWrite(PWM0B, MotorPWM4);
  digitalWrite(DIR_LATCH, LOW);
  shiftOut(DATA, DIR_CLK, MSBFIRST, Direction);
  digitalWrite(DIR_LATCH, HIGH); 
}

void Forward(){
MOTOR(DIR_Forward, MotorPWM1, MotorPWM2, MotorPWM3, MotorPWM4);
}

void STOP(){
MOTOR(DIR_STOP, MotorPWM1, MotorPWM2, MotorPWM3, MotorPWM4);
}
void DIR_Backward
MOTOR(DIR_Backward, MotorPWM1, MotorPWM2, MotorPWM3, MotorPWM4);
delay(2500);
MOTOR(DIR_STOP, MotorPWM1, MotorPWM2, MotorPWM3, MotorPWM4);
delay(1000);

MOTOR(DIR_Left_Sideways, MotorPWM1, MotorPWM2, MotorPWM3, MotorPWM4);
delay(2500);
MOTOR(DIR_STOP, MotorPWM1, MotorPWM2, MotorPWM3, MotorPWM4);
delay(1000);

MOTOR(DIR_Right_Sideways, MotorPWM1, MotorPWM2, MotorPWM3, MotorPWM4);
delay(2500);
MOTOR(DIR_STOP, MotorPWM1, MotorPWM2, MotorPWM3, MotorPWM4);
delay(1000);

MOTOR(DIR_Left_AAB, MotorPWM1, MotorPWM2, MotorPWM3, MotorPWM4);
delay(2500);
MOTOR(DIR_STOP, MotorPWM1, MotorPWM2, MotorPWM3, MotorPWM4);
delay(1000);

MOTOR(DIR_Right_AAB, MotorPWM1, MotorPWM2, MotorPWM3, MotorPWM4);
delay(2500);
MOTOR(DIR_STOP, MotorPWM1, MotorPWM2, MotorPWM3, MotorPWM4);
delay(1000);

MOTOR(DIR_Forward_Left_Diagonally, MotorPWM1, MotorPWM2, MotorPWM3, MotorPWM4);
delay(2500);
MOTOR(DIR_STOP, MotorPWM1, MotorPWM2, MotorPWM3, MotorPWM4);
delay(1000);

MOTOR(DIR_Backward_Left_Diagonally, MotorPWM1, MotorPWM2, MotorPWM3, MotorPWM4);
delay(2500);
MOTOR(DIR_STOP, MotorPWM1, MotorPWM2, MotorPWM3, MotorPWM4);
delay(1000);

MOTOR(DIR_Forward_Right_Diagonally, MotorPWM1, MotorPWM2, MotorPWM3, MotorPWM4);
delay(2500);
MOTOR(DIR_STOP, MotorPWM1, MotorPWM2, MotorPWM3, MotorPWM4);
delay(1000);

MOTOR(DIR_Backward_Right_Diagonally, MotorPWM1, MotorPWM2, MotorPWM3, MotorPWM4);
delay(2500);
MOTOR(DIR_STOP, MotorPWM1, MotorPWM2, MotorPWM3, MotorPWM4);
delay(1000);

MOTOR(DIR_Left_Rotation, MotorPWM1, MotorPWM2, MotorPWM3, MotorPWM4);
delay(2500);
MOTOR(DIR_STOP, MotorPWM1, MotorPWM2, MotorPWM3, MotorPWM4);
delay(1000);

MOTOR(DIR_Right_Rotation, MotorPWM1, MotorPWM2, MotorPWM3, MotorPWM4);
delay(2500);
MOTOR(DIR_STOP, MotorPWM1, MotorPWM2, MotorPWM3, MotorPWM4);
delay(1000);

MOTOR(DIR_Left_Front_Rotation, MotorPWM1, MotorPWM2, MotorPWM3, MotorPWM4);
delay(2500);
MOTOR(DIR_STOP, MotorPWM1, MotorPWM2, MotorPWM3, MotorPWM4);
delay(1000);

MOTOR(DIR_Right_Front_Rotation, MotorPWM1, MotorPWM2, MotorPWM3, MotorPWM4);
delay(2500);
MOTOR(DIR_STOP, MotorPWM1, MotorPWM2, MotorPWM3, MotorPWM4);
delay(1000);

MOTOR(DIR_Left_Back_Rotation, MotorPWM1, MotorPWM2, MotorPWM3, MotorPWM4);
delay(2500);
MOTOR(DIR_STOP, MotorPWM1, MotorPWM2, MotorPWM3, MotorPWM4);
delay(1000);

MOTOR(DIR_Left_Back_Rotation, MotorPWM1, MotorPWM2, MotorPWM3, MotorPWM4);
delay(2500);
MOTOR(DIR_STOP, MotorPWM1, MotorPWM2, MotorPWM3, MotorPWM4);
delay(1000);
}