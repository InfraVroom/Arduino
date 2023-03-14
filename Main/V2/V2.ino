// Library BNO055
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>

//Header Files
#include "sensor_struct.h"	
#include "pin.h"
#include "directions.h"
#include "readsensor.h"
#include "debug.h"
#include "servo_function.h"
#include "matrix.h"

void setup() {
  //Display controll
  display.clearDisplay(0);
  display.shutdown(0,false);
  display.setIntensity(0, 5); 
  //Servo Write
  servo1.write(servoPosition); 
  servo1.attach(servoPin);
  //Open Serial Monitor
  Serial.begin(115200); 
  Serial.println("Serial Working"); 
  //wait for serial port to open
  while (!Serial) delay(10); 
  //Initialise the sensor
  if(!bno.begin()){Serial.print("Check wiring BNO055"); while(1);  }
  //Declaring IRpins
  for (int i = 0; i<IR_sensoramount; i++){pinMode(IR_pins[i], INPUT);}
  for (int i = 0; i<Sonar_sensoramount; i++){pinMode(sonarecho_pins[i], INPUT); pinMode(sonartrig_pins[i], OUTPUT);}

  //Pinouts
  pinMode(DIR_CLK, OUTPUT);
  pinMode(DATA, OUTPUT);
  pinMode(DIR_EN, OUTPUT);
  pinMode(DIR_LATCH, OUTPUT);
  pinMode(PWM0B, OUTPUT); //RB
  pinMode(PWM0A, OUTPUT); //LB
  pinMode(PWM2A, OUTPUT); //LF
  pinMode(PWM2B, OUTPUT); //RF 
  void MOTOR(int Direction, int MotorPWM1, int MotorPWM2, int MotorPWM3, int MotorPWM4);
  delay(1000);
  }


void loop() {
  //SERVO
  // currentMillis = millis();
  // servoSweep(currentMillis);

displayImage(IMAGES[6]);

  //SENSOR
  /*
  IRstate();
  AXISstate();
  Sonarstate();  
  
  if(IR_sensor[2].state == 0 && IR_sensor[3].state == 0 && IR_sensor[7].state == 0){
  Right_Rotation();
  MATRIX_RIGHT();
  } else if(IR_sensor[2].state == 0){
  STOP();
  MATRIX_STOP();
  delay(1000);
  Backward();
  MATRIX_BACKWARD();
  delay(1000);
  Right_Rotation();
  MATRIX_RIGHT();
  delay(500);
  } else if(IR_sensor[7].state == 0){
  STOP();
  MATRIX_STOP();
  delay(1000);
  Backward();
  MATRIX_BACKWARD();
  delay(1000);
  Left_Rotation();
  MATRIX_LEFT();
  delay(500);
  }else if(IR_sensor[2].state == 0 && IR_sensor[7].state == 0){
  STOP();
  MATRIX_STOP();
  delay(1000);
  Backward();
  MATRIX_BACKWARD();
  delay(2000);
  Left_Rotation();
  MATRIX_LEFT();
  delay(1000);
  } else {
  Forward();
  MATRIX_FORWARD();
  }
*/

  // debug(); // this function is used if you want to see the data in the Serial Monitor
}