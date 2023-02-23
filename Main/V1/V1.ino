//Library BNO055
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

void setup() {
  //Open Serial Monitor
  Serial.begin(115200); 
  Serial.println("Serial Working"); 
  //wait for serial port to open
  while (!Serial) delay(10); 
  //Initialise the sensor
  if(!bno.begin())
  {
    Serial.print("Check wiring BNO055");
    while(1);
  }
  //Declaring IRpins
  for (int i = 0; i<IR_sensoramount; i++){
    pinMode(IR_pins[i], INPUT);
  }
  for (int i = 0; i<Sonar_sensoramount; i++){
    pinMode(sonarecho_pins[i], INPUT);
    pinMode(sonartrig_pins[i], OUTPUT);
  }
  void MOTOR(int Direction, int MotorPWM1, int MotorPWM2, int MotorPWM3, int MotorPWM4);
  delay(1000);
  }

void loop() {
  IRstate();
  AXISstate();
  Sonarstate();  
  // debug(); // this function is used if you want to see the data in the Serial Monitor
}