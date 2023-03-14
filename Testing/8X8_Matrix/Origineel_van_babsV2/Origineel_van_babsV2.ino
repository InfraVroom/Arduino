#include <LedControl.h>

const int DIN_PIN = 50;
const int CS_PIN = 53;
const int CLK_PIN = 51;

const uint64_t IMAGES[] = {
  0x081c3e0808080808,
  0x08080808083e1c08,
  0x002060ff60200000,
  0x000406ff06040000,
  0x000042e242423c00,
  0x0000424742423c00,
  0x0102040890e0e0f0,
  0x804020100907070f,
  0x0f07070910204080,
  0xf0e0e09008040201
};
const int IMAGES_LEN = sizeof(IMAGES)/8;

LedControl display = LedControl(DIN_PIN, CLK_PIN, CS_PIN);

void setup()
 { 
   display.clearDisplay(0);
   display.shutdown(0,false);
   display.setIntensity(0, 5); 
}

void displayImage(uint64_t image) {
  for (int i = 0; i < 8; i++) {
    byte row = (image >> i * 8) & 0xFF;
    for (int j = 0; j < 8; j++) {
      display.setLed(0, i, j, bitRead(row, j));
    }
  }
}

int i = 0;

void loop() {
  displayImage(IMAGES[i]);
  if (++i >= IMAGES_LEN ) {
    i = 0;
  }
  delay(2000);
}


