uint8_t IR_pins[] = {2, 3, 4, 5, 6, 7, 8, 9};
uint8_t IR_sensoramount = sizeof(IR_pins) / sizeof(IR_pins[0]);

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

struct data IR_sensor[] ={
{"RF", 0, 0, 0, 0, 1, "IR Sensor"},
{"LF", 0, 0, 0, 0, 0, "IR Sensor"},
{"LB", 0, 0, 0, 0, 1, "IR Sensor"},
{"RB", 0, 0, 0, 0, 0, "IR Sensor"},
{"RF", 0, 0, 0, 0, 1, "IR Sensor"},
{"LF", 0, 0, 0, 0, 0, "IR Sensor"},
{"LB", 0, 0, 0, 0, 1, "IR Sensor"},
{"RB", 0, 0, 0, 0, 0, "IR Sensor"}
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

void setup() {
  //Open Serial Monitor
  Serial.begin(115200); 
  Serial.println("Serial Working"); 
  //Declaring IRpins
  for (int i = 0; i<IR_sensoramount; i++){
    pinMode(IR_pins[i], INPUT);
<<<<<<< HEAD
  }}

void loop() {
  IRstate();
=======
  }
  for (int i = 0; i<Sonar_sensoramount; i++){
    pinMode(sonarecho_pins[i], INPUT);
    pinMode(sonartrig_pins[i], OUTPUT);
  }}

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
  Serial.println(" |"); 
   }


void loop() {
  IRstate();
  Sonarstate();  
  //debug(); // this function is used if you want to see the data in the Serial Monitor
>>>>>>> 58b7e082446458ca5833bc1c9051450d99b75636
}
