/* Set the delay between fresh samples */
#define BNO055_SAMPLERATE_DELAY_MS (100)

void IRstate() { //Reading IR state
  for (int i = 0; i<IR_sensoramount; i++){
    IR_sensor[i].state = digitalRead(IR_pins[i]);
   }}

void Sonarstate(){ //Reading Sonar state/distance
  for (int i = 0; i<Sonar_sensoramount; i++){
  digitalWrite(sonartrig_pins[i], LOW); 
  delayMicroseconds(2);
  digitalWrite(sonartrig_pins[i], HIGH); // set trigger pin to High to send a pulse into the real world
  delayMicroseconds(10);
  digitalWrite(sonartrig_pins[i], LOW); 
  Sonar_sensor[i].duration = pulseIn(sonarecho_pins[i], HIGH); // measure the time it takes to receive the pulse
  Sonar_sensor[i].distance = Sonar_sensor[i].duration * 0.034 / 2; //calculate the distance in cm
  }}

void AXISstate(){//Reading 9Axis State
  imu::Vector<3> euler = bno.getVector(Adafruit_BNO055::VECTOR_EULER);
  AXIS_sensor[0].xaxis = euler.x();
  AXIS_sensor[0].yaxis = euler.y();
  AXIS_sensor[0].zaxis = euler.z();
  /* Display the floating point data */
  delay(BNO055_SAMPLERATE_DELAY_MS);
}