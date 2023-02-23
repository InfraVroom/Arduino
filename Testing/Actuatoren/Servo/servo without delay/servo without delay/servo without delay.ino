

// ----------LIBRARIES--------------

#include <Servo.h>

// --------CONSTANTS (won't change)---------------

const int servoPin = 10; // the pin number for the servo signal

const int servoMinDegrees = 20; // the limits to servo movement
const int servoMaxDegrees = 150;


//------------ VARIABLES (will change)---------------------


Servo servo1;  // create servo object to control a servo 

int servoPosition = servoMinDegrees;     // the current angle of the servo - starting at 90.
int servoInterval = 30; // initial millisecs between servo moves
int servoDegrees = 2;       // amount servo moves at each step 
                            //    will be changed to negative value for movement in the other direction
int servoDegreeCounter = 0; 

unsigned long currentMillis = 0;    // stores the value of millis() in each iteration of loop()

unsigned long previousServoMillis = 0; // the time when the servo was last moved


//========================================

void setup() {

  Serial.begin(9600);
  // Serial.println("Starting SeveralThingsAtTheSameTimeRev1.ino");  // so we know what sketch is running
  
  servo1.write(servoPosition); // sets the initial position
  servo1.attach(servoPin);
 
}

//========================================

void loop() {

      // Notice that none of the action happens in loop() apart from reading millis()
      //   it just calls the functions that have the action code

  currentMillis = millis();   // capture the latest value of millis()
                              //   this is equivalent to noting the time from a clock
                              //   use the same time for all LED flashes to keep them synchronized
  
  
  servoSweep();

}

//========================================


//======================================

void servoSweep() {

      // this is similar to the servo sweep example except that it uses millis() rather than delay()

      // nothing happens unless the interval has expired
      // the value of currentMillis was set in loop()
  for(servoDegreeCounter = servoMaxDegrees; servoDegreeCounter >= servoMinDegrees; servoDegreeCounter = servoDegreeCounter - 2){

    if (currentMillis - previousServoMillis >= servoInterval) {
        // its time for another move
      previousServoMillis += servoInterval;
    
      servoPosition = servoPosition + servoDegrees; // servoDegrees might be negative

      if ((servoPosition >= servoMaxDegrees) || (servoPosition <= servoMinDegrees))  {
          // if the servo is at either extreme change the sign of the degrees to make it move the other way
      servoDegrees = - servoDegrees; // reverse direction
          // and update the position to ensure it is within range
      servoPosition = servoPosition + servoDegrees; 
      }
    }
        // make the servo move to the next position
    servo1.write(servoPosition);
        // and record the time when the move happened
    previousServoMillis += servoInterval;
  
  }

}

//========================================END
