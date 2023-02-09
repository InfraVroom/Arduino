uint8_t IR_pins[] = {9};
uint8_t IR_sensoramount = sizeof(IR_pins) / sizeof(IR_pins[0]);

//Struct data localisation
struct data{
  char location[5];
  int state;
  char sensor_type[30];
};

struct data IR_sensor[] ={
{"RF ", 0, "IR Sensor "},
//{"LF", 0, "IR Sensor "}
};

void printvalues(void){
  for (int i = 0; i < IR_sensoramount; i++){
    Serial.print("Detected ");
    Serial.print(IR_sensor[i].sensor_type);
    Serial.print(": ");
    Serial.println(IR_sensor[i].location);
  }
}

void readvalues(void) {
  for (int i = 0; i<IR_sensoramount; i++){
    IR_sensor[i].state = digitalRead(IR_pins[i]);
  }

}

void setup() {
  Serial.begin(9600); // Init Serial at 115200 Baud Rate.
  Serial.println("Serial Working"); // Test to check if serial is working or not
  
  for (int i = 0; i<IR_sensoramount; i++){
    pinMode(IR_pins[i], INPUT);
  }
 
}

void loop() {
  // put your main code here, to run repeatedly:
  readvalues();
   for (int i = 0; i < IR_sensoramount; i++){
     if (IR_sensor[i].state == 0){ // Check if the pin high or not
    printvalues();
     }
  }
 
  
}
