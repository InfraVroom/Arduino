
//print the values from the sensors to the Serial Monitor
void debug(){ 
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
