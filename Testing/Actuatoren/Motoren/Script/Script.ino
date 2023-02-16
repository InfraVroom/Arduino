const int PWM2A = 11;
const int PWM2B = 3;
const int PWM0A = 6;
const int PWM0B = 5;
const int DIR_CLK = 4;
const int DIR_EN = 7;
const int DATA = 8;
const int DIR_LATCH = 12;
const int Forward = 39;  // 8 bit decimaal 
const int STOP = 0;
int Speed1 = 200;
int Speed2 = 200;
int Speed3 = 200;
int Speed4 = 200;
void setup() {
  pinMode(DIR_CLK, OUTPUT);
  pinMode(DATA, OUTPUT);
  pinMode(DIR_EN, OUTPUT);
  pinMode(DIR_LATCH, OUTPUT);
  pinMode(PWM0B, OUTPUT);
  pinMode(PWM0A, OUTPUT);
  pinMode(PWM2A, OUTPUT);
  pinMode(PWM2B, OUTPUT);
void MOTOR(int Dri, int Speed1, int Speed2, int Speed3, int Speed4);
 }
void loop() {
MOTOR(Forward, Speed1, Speed2, Speed3, Speed4);
delay(2000);
MOTOR(STOP, Speed1, Speed2, Speed3, Speed4);
delay(1000);
}
void MOTOR(int Dri, int Speed1, int Speed2, int Speed3, int Speed4) {
  analogWrite(PWM2A, Speed1);
  analogWrite(PWM2B, Speed2);
  analogWrite(PWM0A, Speed3);
  analogWrite(PWM0B, Speed4);
  digitalWrite(DIR_LATCH, LOW);
  shiftOut(DATA, DIR_CLK, MSBFIRST,Dri);
  digitalWrite(DIR_LATCH, HIGH); 
}