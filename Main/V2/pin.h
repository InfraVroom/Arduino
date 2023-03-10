//Motorshield PMW
const int PWM2A = 11;
const int PWM2B = 3;
const int PWM0A = 6;
const int PWM0B = 5;

//Motorshield data
const int DIR_CLK = 4;
const int DIR_EN = 7;
const int DATA = 8;
const int DIR_LATCH = 12;

//IR SENSOR
const int IR_pins[] = {22, 24, 26, 28, 30, 32, 34, 36};
const int IR_sensoramount = sizeof(IR_pins) / sizeof(IR_pins[0]);

//SONAR SENSOR
const int sonartrig_pins[] = {25, 33, 29};
const int sonarecho_pins[] = {23, 31, 27};
const int Sonar_sensoramount = sizeof(sonartrig_pins) / sizeof(sonartrig_pins[0]);

//9 Axis I2C adress
Adafruit_BNO055 bno = Adafruit_BNO055(-1, 0x28, &Wire);
