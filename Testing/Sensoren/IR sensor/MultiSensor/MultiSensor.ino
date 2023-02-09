uint8_t IR_pins[] = {7, 8, 9, 10};
uint8_t IR_sensoramount = sizeof(IR_pins) / sizeof(IR_pins[0]);

//Struct data localisation
struct data{
  char location[5];
  int state;
  char sensor_type[30];
};

struct data IR_sensor[] ={
{"RF ", 0, "IR Sensor "},
{"LF", 0, "IR Sensor "},
{"LB", 0, "IR Sensor "},
{"RB", 0, "IR Sensor "}
};

void IRstate() { //Reading and printing(If detected) IR state
  for (int i = 0; i<IR_sensoramount; i++){
    IR_sensor[i].state = digitalRead(IR_pins[i]);
    if (IR_sensor[i].state == 0){ // Check if the pin high or not
    IR_sensor[i].state = digitalRead(IR_pins[i]);
    Serial.print("Detected ");
    Serial.print(IR_sensor[i].sensor_type);
    Serial.print(": ");
    Serial.println(IR_sensor[i].location);
  }}}

void setup() {
  //Open Serial Monitor
  Serial.begin(9600); 
  Serial.println("Serial Working"); 
  
  //Declaring IRpins
  for (int i = 0; i<IR_sensoramount; i++){
    pinMode(IR_pins[i], INPUT);
  }
 
}

void loop() {
  IRstate();
  
}
