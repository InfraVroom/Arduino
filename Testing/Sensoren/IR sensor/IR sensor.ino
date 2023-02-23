int IRSensor = 9; // connect IR sensor module to Arduino pin D9


void setup(){
  Serial.begin(9600); // Init Serial at 115200 Baud Rate.
  Serial.println("Serial Working"); // Test to check if serial is working or not
  pinMode(IRSensor, INPUT); // IR Sensor pin INPUT
}
void loop(){
  int sensorStatus = digitalRead(IRSensor); // Set the GPIO as Input
  if (sensorStatus != 1) // Check if the pin high or not
  {
    // if the pin is high turn off the onboard Led
    Serial.println("Motion Detected!"); // print Motion Detected! on the serial monitor window
  }
  else  {
    //else turn on the onboard LED
    Serial.println("Motion Ended!"); // print Motion Ended! on the serial monitor window
  }
}