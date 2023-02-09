uint8_t IR_pins[] = {8};
uint8_t IR_sensoramount = sizeof(IR_pins) / sizeof(IR_pins[0]);
uint8_t i;

//Struct data localisation
struct data{
  char location[5];
  int state;
  char sensor_type[30];
};

struct data IR_sensor[] ={
{"RF ", 0, "IR Sensor "};
}

void printvalues(void){
  for i=0, i<IR_sensoramount; i++){
    Serial.print(IR_sensor[i].sensor_type);
    Serial.print(IR_sensor[i].location);
    Serial.print(IR_sensor[i].state);
  }
}

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
