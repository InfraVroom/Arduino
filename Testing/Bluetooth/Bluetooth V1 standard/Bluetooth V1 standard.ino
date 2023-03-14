/* Standaard programma voor het uitlezen van data via BT. 
De ontvangen data wordt geprint op de Seriële monitor.
De pinnen Rx1 en Tx1 op Mega kunnen worden gebruikt door Serial1. te gebruiken
BT-Rx ==> Mega-Tx1
BT-Tx ==> Mega-Rx1
*/

char bluetoothValue;

void setup()   {//Here the code only runs once.
  
  Serial.begin(9600);
  Serial1.begin(9600);
}

void loop() {

while(Serial1.available()>0){ 
  
bluetoothValue = Serial1.read();

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
      Serial.println(" Faster");
  }else if(bluetoothValue == '5'){
      Serial.println(" Slower");
  }else if(bluetoothValue == '6'){
      Serial.println(" Left rotation");
  }else if(bluetoothValue == '7'){
      Serial.println(" Stop");
  }else if (bluetoothValue == '8'){
      Serial.println(" Right rotation"); 
    }
}
}
