
#include <Servo.h>

const int servoPin = 10; // the pin number for the servo signal
const int servoMinDegrees = 60; // the limits to servo movement
const int servoMaxDegrees = 120;

Servo servo1;  // create servo object to control a servo 

int servoPosition = servoMinDegrees;     // the current angle of the servo - starting at 90.
int servoInterval = 30; // initial millisecs between servo moves
int servoDegrees = 1;       // amount servo moves at each step 
int servoDegreeCounter = servoMaxDegrees;

unsigned long currentMillis = 0;    // stores the value of millis() in each iteration of loop()
unsigned long previousServoMillis = 0; // the time when the servo was last moved

void setup() {

  Serial.begin(9600);
  // Serial.println("Starting SeveralThingsAtTheSameTimeRev1.ino");  // so we know what sketch is running
  
  servo1.write(servoPosition); // sets the initial position
  servo1.attach(servoPin);
 
}

void loop() {

  currentMillis = millis();
  servoSweep();
}

void servoSweep() {
    while(currentMillis - previousServoMillis >= servoInterval) {
      previousServoMillis += servoInterval;
      servoPosition = servoPosition + servoDegrees; // servoDegrees might be negative
      if ((servoPosition == servoMaxDegrees) || (servoPosition == servoMinDegrees))  {
      servoDegrees = - servoDegrees; // reverse direction
      servoPosition = servoPosition + servoDegrees; 
      }  
    servo1.write(servoPosition);
  }
}
  


