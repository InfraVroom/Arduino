#include <MAX7219.h>

unsigned long currentMillis = 0;
unsigned long previousMillis = 0;
unsigned long previousMillis1 = 0;
int matrixdelay = 1000;

// 8x8 Dot-Matrix
int DIN = 50;
int CS =  53;
int CLK = 51;
MAX7219 Matrix(1, DIN, CLK, CS);


// The sign arrowup 
const static byte arrowup[8] = {
  0b00011000,
  0b00111100,
  0b01111110,
  0b11011011,
  0b00011000,
  0b00011000,
  0b00011000,
  0b00011000,
};


// sign arrowdowm
const static byte arrowdown[8] = {
  0b00011000,
  0b00011000,
  0b00011000,
  0b00011000,
  0b11011011,
  0b01111110,
  0b00111100,
  0b00011000,
};

void setup() {  
}

void loop() {
 
  arrowupmatrix() ;
  arrowdownmatrix() ;  
}

void arrowupmatrix() {
currentMillis = millis();  
while (currentMillis - previousMillis >= matrixdelay) {

  // Make arrowup from array
  for(int row = 0; row <= 7; row++)
  {
    Matrix.setRow(1, row, arrowup[row]);
  }
  
  previousMillis += matrixdelay; //previousMillis = previousMillis + matrixdelay
}
}

void arrowdownmatrix(){
  
   currentMillis = millis(); 
while (currentMillis - previousMillis >= matrixdelay ) {
 
  // Make Letter arrowdown from array
  for(int row = 0; row <= 7; row++)
  {
    Matrix.setRow(1, row, arrowdown[row]);
  }
  previousMillis += matrixdelay; //prevoiusMillis = previousMillis + matrixdelay
  
}
}


