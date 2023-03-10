
#include <Servo.h>

int servoPin = 10;
Servo servo;
int pos = 0;   

void setup() {
  servo.attach(10); 
}

void loop() {
  for (pos = 60; pos <= 120; pos += 1) { 
    servo.write(pos);              
    delay(30);                      
  }
  delay(30);
  for (pos = 120; pos >= 60; pos -= 1) {
    servo.write(pos);              
    delay(30);                       
  }
}
