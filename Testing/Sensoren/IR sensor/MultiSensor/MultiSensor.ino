uint8_t IR_pins[] = {3, 4, 5, 6, 7, 8, 9, 10};
uint8_t IR_sensoramount = sizeof(IR_pins) / sizeof(IR_pins[0]);

uint8_t sonartrig_pins[] = {11};
uint8_t sonarecho_pins[] = {12};
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
{"RF", 0, 0, 0, 0, 1, "IR Sensor "},
{"LF", 0, 0, 0, 0, 0, "IR Sensor "},
{"LB", 0, 0, 0, 0, 1, "IR Sensor "},
{"RB", 0, 0, 0, 0, 0, "IR Sensor "},
{"RF", 0, 0, 0, 0, 1, "IR Sensor "},
{"LF", 0, 0, 0, 0, 0, "IR Sensor "},
{"LB", 0, 0, 0, 0, 1, "IR Sensor "},
{"RB", 0, 0, 0, 0, 0, "IR Sensor "}
};

struct data Sonar_sensor[] ={
  {"test", 0, 0, 0, 0, "", "Sonar sensor"},
 // {"test", 0, 0, 0, "", "Sonar sensor"},
  //{"test", 0, 0, 0, "", "Sonar sensor"}
};

void IRstate() { //Reading and printing(If detected) IR state
Serial.print("IR SENSOR: ");
  for (int i = 0; i<IR_sensoramount; i++){
    IR_sensor[i].state = digitalRead(IR_pins[i]);
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

void Sonarstate(){
  Serial.print("SONAR SENSOR: ");
  for (int i = 0; i<Sonar_sensoramount; i++){
  // Clears the trigPin
  digitalWrite(sonartrig_pins[i], LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(sonarecho_pins[i], HIGH);
  delayMicroseconds(10);
  digitalWrite(sonartrig_pins[i], LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  Sonar_sensor[i].duration = pulseIn(sonarecho_pins[i], HIGH);
  // Calculating the distance
  Sonar_sensor[i].distance = Sonar_sensor[i].duration * 0.034 / 2; 
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(Sonar_sensor[i].duration);
  }
  Serial.println(" |");
}

void setup() {
  //Open Serial Monitor
  Serial.begin(9600); 
  Serial.println("Serial Working"); 
  
  //Declaring IRpins
  for (int i = 0; i<IR_sensoramount; i++){
    pinMode(IR_pins[i], INPUT);
  }
  for (int i = 0; i<Sonar_sensoramount; i++){
    pinMode(sonarecho_pins[i], INPUT);
    pinMode(sonartrig_pins[i], OUTPUT);
  }


 
}

void loop() {
  IRstate();
  Sonarstate();  
  
}
