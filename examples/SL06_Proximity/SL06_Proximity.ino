/*************************************************************
  This is an examples for the SL06
  Digital Proximity, Ambient Light, RGB and Gesture Sensor

  You can buy one on our store!
  -----> https://xinabox.cc/products/SL06/

  This example uses the SL06 to detect onject proximity 
  towards the sensor

  The sensor communicates over the I2C Bus.

*************************************************************/

#include <xCore.h>
#include <xSL06.h>

const int DELAY_TIME = 1000;

xSL06 SL06;

void setup() {
  // Start the Serial Monitor
  Serial.begin(115200);

  // Starts the I2C communication
#ifdef ESP8266
  Wire.pins(2, 14);
#endif
  Wire.begin();

  Serial.println("================================");
  Serial.println("   XINABOX SL06 Gesture Test ");
  Serial.println("================================");

  // Start the SL06 Sensor
  if (SL06.begin()) {
    Serial.println(F("SL06 initialization complete"));
  } else {
    Serial.println(F("Something went wrong during SL06 init!"));
    while (1) {
      delay(100);
    }
  }

  // Adjust the Proximity sensor gain
  if ( !SL06.setProximityGain(PGAIN_2X) ) {
    Serial.println(F("Something went wrong trying to set PGAIN"));
  }
  
  // Start running the SL06 proximity sensor (no interrupts)
  if ( SL06.enableProximitySensor(false) ) {
    Serial.println(F("Proximity sensor is now running"));
  } else {
    Serial.println(F("Something went wrong during sensor init!"));
  }

  // Delayy for Sensor to normalise
  delay(1000);
}

void loop() {
  uint8_t proximity = 0;
  // Read the proximity value
  if ( !SL06.getProximity(proximity) ) {
    Serial.println("Error reading proximity value");
  } else {
    Serial.print("Proximity: ");
    Serial.println(proximity);
  }
  // Wait 1 second before next reading
  delay(1000);
}

