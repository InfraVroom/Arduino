#include "LedControl.h"
#include "binary.h"

/*
 DIN connects to pin 12
 CLK connects to pin 11
 CS connects to pin 10 
*/
LedControl lc=LedControl(50,51,53,1);
//FORWARD
byte BYTEFORWARD[8] = {
  0b00011000,
  0b00111100,
  0b01011010,
  0b10011001,
  0b00011000,
  0b00011000,
  0b00011000,
  0b00011000
};
byte BYTESTOP[8] = {
  0b00111100,
  0b01000010,
  0b10000001,
  0b11111111,
  0b11111111,
  0b10000001,
  0b01000010,
  0b00111100
};

byte BYTELEFT[8] ={
  0b00010000,
  0b00100000,
  0b01000000,
  0b11111111,
  0b11111111,
  0b01000000,
  0b00100000,
  0b00010000
};

byte BYTERIGHT[8] = {
  0b00001000,
  0b00000100,
  0b00000010,
  0b11111111,
  0b11111111,
  0b00000010,
  0b00000100,
  0b00001000
};

byte BYTEBACKWARD[8] = {
  0b00011000,
  0b00011000,
  0b00011000,
  0b00011000,
  0b10011001,
  0b01011010,
  0b00111100,
  0b00011000
};



void MATRIX_FORWARD(){
  for (int i = 0; i < 8; i++) {
  lc.setRow(0,i,BYTEFORWARD[i]);}
}
void MATRIX_STOP(){
  for (int i = 0; i < 8; i++) {
  lc.setRow(0,i,BYTESTOP[i]);}
}
void MATRIX_LEFT(){
  for (int i = 0; i < 8; i++) {
  lc.setRow(0,i,BYTELEFT[i]);
}}
void MATRIX_RIGHT(){
    for (int i = 0; i < 8; i++) {
  lc.setRow(0,i,BYTERIGHT[i]);
}}
void MATRIX_BACKWARD(){
    for (int i = 0; i < 8; i++) {
  lc.setRow(0,i,BYTEBACKWARD[i]);
}}