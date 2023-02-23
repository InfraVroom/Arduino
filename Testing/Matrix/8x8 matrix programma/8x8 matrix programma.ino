#include <MAX7219.h>

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
  
  // Make arrowup from array
  for(int row = 0; row <= 7; row++)
  {
    Matrix.setRow(1, row, arrowup[row]);
    delay(0);
  }
  delay(1000);
  
  // Make Letter arrowdown from array
  for(int row = 0; row <= 7; row++)
  {
    Matrix.setRow(1, row, arrowdown[row]);
    delay(0);
  }
  delay(1000);

  // invert display
  Matrix.invertDisplay(0);
  delay(1000);
  
  // clear display
  Matrix.clearDisplay(0);
  delay(1000);
}
