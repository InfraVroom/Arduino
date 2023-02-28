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

//declaring 8 IR sensors by using a struct
struct data IR_sensor[] ={
  {"LB", 0, 0, 0, 180, 1, "IR Sensor"},
  {"LB", 0, 0, 0, 90, 0, "IR Sensor"},
  {"LF", 0, 0, 0, 0, 1, "IR Sensor"},
  {"LF", 0, 0, 0, 90, 0, "IR Sensor"},
  {"RB", 0, 0, 0, 180, 1, "IR Sensor"},
  {"RB", 0, 0, 0, 90, 1, "IR Sensor"},
  {"RF", 0, 0, 0, 90, 1, "IR Sensor"},
  {"RF", 0, 0, 0, 0, 1, "IR Sensor"}
};

//declaring 3 sonar sensors by using a struct
struct data Sonar_sensor[] ={ 
  {"FRONT", 0, 0, 0, 0, 0, "Sonar sensor"},
  {"LEFT", 0, 0, 0, 0, "Sonar sensor"},
  {"RIGHT", 0, 0, 0, 0, "Sonar sensor"}
};

//AxisSensor struct
struct axis{
  float xaxis;
  float yaxis;
  float zaxis;
  char sensor_type[30];
};

//AxisSensor data struct
struct axis AXIS_sensor[] ={
  {0, 0, 0, "9 Axis Sensor"}  
};