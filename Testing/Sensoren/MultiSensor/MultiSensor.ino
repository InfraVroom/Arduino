//Library BNO055
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>

/* Set the delay between fresh samples */
#define BNO055_SAMPLERATE_DELAY_MS (100)

//Pins

// Check I2C device address and correct line below (by default address is 0x29 or 0x28)
//                                   id, address
Adafruit_BNO055 bno = Adafruit_BNO055(-1, 0x28, &Wire);

//IR SENSOR
uint8_t IR_pins[] = {2, 3, 4, 5, 6, 7, 8, 9};
uint8_t IR_sensoramount = sizeof(IR_pins) / sizeof(IR_pins[0]);

//SONAR SENSOR
const int sonartrig_pins[] = {10, 12, 14};
const int sonarecho_pins[] = {11, 13, 15};
uint8_t Sonar_sensoramount = sizeof(sonartrig_pins) / sizeof(sonartrig_pins[0]);

//Struct data localisation
struct data{
  char location[5];
  int state; //IR
  long duration; //US
  int distance; //US
  int angle; //US
  int anglepolarity; //0 = min, 1 = plus 
  char sensor_type[30];
};

//AxisSensor
struct axis{
  float xaxis;
  float yaxis;
  float zaxis;
  char sensor_type[30];
};

struct axis AXIS_sensor[] ={
{0, 0, 0, "9 Axis Sensor"}  
};

struct data IR_sensor[] ={
{"RF", 0, 0, 0, 0, 1, "IR Sensor"},
{"LF", 0, 0, 0, 0, 0, "IR Sensor"},
{"LB", 0, 0, 0, 0, 1, "IR Sensor"},
{"RB", 0, 0, 0, 0, 0, "IR Sensor"},
{"RF", 0, 0, 0, 45, 1, "IR Sensor"},
{"LF", 0, 0, 0, 45, 0, "IR Sensor"},
{"LB", 0, 0, 0, 45, 1, "IR Sensor"},
{"RB", 0, 0, 0, 45, 0, "IR Sensor"}
};


struct data Sonar_sensor[] ={ //declaring 3 sonar sensors by using a struct
  {"FRONT", 0, 0, 0, 0, 0, "Sonar sensor"},
  {"LEFT", 0, 0, 0, 0, "Sonar sensor"},
  {"RIGHT", 0, 0, 0, 0, "Sonar sensor"}
};

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

void AXISstate(){
 imu::Vector<3> euler = bno.getVector(Adafruit_BNO055::VECTOR_EULER);
AXIS_sensor[0].xaxis = euler.x();
AXIS_sensor[0].yaxis = euler.y();
AXIS_sensor[0].zaxis = euler.z();
  /* Display the floating point data */
  delay(BNO055_SAMPLERATE_DELAY_MS);
}

void setup() {
  //Open Serial Monitor
  Serial.begin(115200); 
  Serial.println("Serial Working"); 
  
  //wait for serial port to open!
  while (!Serial) delay(10); 
  //Initialise the sensor
  if(!bno.begin())
  {
    //There was a problem detecting the BNO055 ... check your connections
    Serial.print("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
    while(1);
  }

  //Declaring IRpins
  for (int i = 0; i<IR_sensoramount; i++){
    pinMode(IR_pins[i], INPUT);
  }
  for (int i = 0; i<Sonar_sensoramount; i++){
    pinMode(sonarecho_pins[i], INPUT);
    pinMode(sonartrig_pins[i], OUTPUT);
  }delay(1000);}


void debug(){ //print the values from the sensors to the Serial Monitor
  Serial.print("SONAR SENSOR:");
  for (int i = 0; i<Sonar_sensoramount; i++){
    Serial.print(" | ");
    Serial.print(Sonar_sensor[i].location);
    Serial.print(" [");
    if(Sonar_sensor[i].anglepolarity==1){Serial.print("+");}
    else {Serial.print("-");}
    Serial.print(Sonar_sensor[i].angle);
    Serial.print("] : ");
    Serial.print(Sonar_sensor[i].distance);
  }
  Serial.print(" |     IR SENSOR:");
  for (int i = 0; i<IR_sensoramount; i++){
    Serial.print(" | ");
    Serial.print(IR_sensor[i].location);
    Serial.print(" [");
    if(IR_sensor[i].anglepolarity==1){Serial.print("+");}
    else {Serial.print("-");}
    Serial.print(IR_sensor[i].angle);
    Serial.print("] : ");
    Serial.print(IR_sensor[i].state);
  }
  Serial.print(" |     AXIS SENSOR: X: ");
  Serial.print(AXIS_sensor[0].xaxis);
  Serial.print(" Y: ");
  Serial.print(AXIS_sensor[0].yaxis);
  Serial.print(" Z: ");
  Serial.print(AXIS_sensor[0].zaxis);
  Serial.println(" |"); 
   }


void loop() {
  IRstate();
  AXISstate();
  Sonarstate();  
  // debug(); // this function is used if you want to see the data in the Serial Monitor
}

