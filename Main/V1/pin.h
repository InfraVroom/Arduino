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
uint8_t IR_pins[] = {2, 3, 4, 5, 6, 7, 8, 9};
uint8_t IR_sensoramount = sizeof(IR_pins) / sizeof(IR_pins[0]);

//SONAR SENSOR
const int sonartrig_pins[] = {25, 33, 29};
const int sonarecho_pins[] = {23, 31, 27};
uint8_t Sonar_sensoramount = sizeof(sonartrig_pins) / sizeof(sonartrig_pins[0]);

//9 Axis I2C adress
Adafruit_BNO055 bno = Adafruit_BNO055(-1, 0x28, &Wire);
