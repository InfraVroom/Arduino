#include <SPI.h> // for SPI communication

#include <nRF24L01.h>

#include <RF24.h>

RF24 radio(8,9); // CE, CSN
const byte address[6] = "10000"; // the address the the module
void setup() {

Serial.begin(9600);
radio.begin();
radio.openReadingPipe(0, address);
radio.setPALevel(RF24_PA_MAX);
radio.startListening();
Serial.println("starting...");

}

void loop() {
if (radio.available()) { // if nrf has any incoming data
Serial.println("receiving");
char text[32] = "";
radio.read(&text, sizeof(text));
Serial.println(text);

delay(5);
}
}

