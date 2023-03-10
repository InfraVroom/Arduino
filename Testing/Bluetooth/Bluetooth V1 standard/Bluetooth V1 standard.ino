
char bluetoothValue;

void setup()   {//Here the code only runs once.
  
  Serial.begin(9600);

}

void loop() {

while(Serial.available()>0){ 
  
bluetoothValue = Serial.read();

Serial.print(bluetoothValue);
//Serial.print("\n");
delay(10);

  if(bluetoothValue =='0'){
      Serial.println(" Left ");
  }else if(bluetoothValue == '1'){
      Serial.println(" Forward ");
  }else if(bluetoothValue == '2'){
      Serial.println(" Right ");
  }else if(bluetoothValue == '3'){
      Serial.println(" Backwards ");
  }else if(bluetoothValue == '4'){
      Serial.println(" ND");
  }else if(bluetoothValue == '5'){
      Serial.println(" ND");
  }else if(bluetoothValue == '6'){
      Serial.println(" ND");
  }else if(bluetoothValue == '7'){
      Serial.println(" Stop");
  }
}
}
