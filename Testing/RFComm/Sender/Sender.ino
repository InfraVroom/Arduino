#include <SPI.h> // for SPI communication
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(8, 9); // CE, CSN

const byte address[6] = "10000"; // the address the the module

void setup() {
radio.begin();
radio.openWritingPipe(address);
radio.setPALevel(RF24_PA_MAX);
radio.stopListening();
}

void loop() {

const char text[] = "Hello World"; // you can customize this text to your wish

radio.write(&text, sizeof(text));

}