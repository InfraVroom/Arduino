#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>

/* This driver reads raw data from the BNO055

   Connections
   ===========
   Connect SCL to analog 5
   Connect SDA to analog 4
   Connect VDD to 3.3V DC
   Connect GROUND to common ground

   History
   =======
   2015/MAR/03  - First release (KTOWN)
*/

/* Set the delay between fresh samples */
#define BNO055_SAMPLERATE_DELAY_MS (100)

// Check I2C device address and correct line below (by default address is 0x29 or 0x28)
//                                   id, address
Adafruit_BNO055 bno = Adafruit_BNO055(-1, 0x28, &Wire);
void setup(void)
{
  Serial.begin(115200);
  while (!Serial) delay(10);  // wait for serial port to open!
  /* Initialise the sensor */
  if(!bno.begin())
  {
    //There was a problem detecting the BNO055 ... check your connections
    Serial.print("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
    while(1);
  }

  delay(1000);
  
  //LOWPOWERMODE
  // bno.setExtCrystalUse(true);
}

void loop()
{
  imu::Vector<3> euler = bno.getVector(Adafruit_BNO055::VECTOR_EULER);
float xaxis = euler.x();
float yaxis = euler.y();
float zaxis = euler.z();
  /* Display the floating point data */
  Serial.print("X: ");
  Serial.print(xaxis);
  Serial.print(" Y: ");
  Serial.print(euler.y());
  Serial.print(" Z: ");
  Serial.print(euler.z());
  Serial.println("");
  delay(BNO055_SAMPLERATE_DELAY_MS);
}
