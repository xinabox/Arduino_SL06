/*************************************************************
  This is an examples for the SL06
  Digital Proximity, Ambient Light, RGB and Gesture Sensor

  You can buy one on our store!
  -----> https://xinabox.cc/products/SL06/

  This example request a Ambient Light measurements to be
  made by the SL06 and display the data over the Serial
  bus.

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
  Serial.println("   XINABOX SL06 Ambient Light ");
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

  // Start running the SL06 light sensor (no interrupts)
  if ( SL06.enableLightSensor(false) ) {
    Serial.println(F("Light sensor is now running"));
  } else {
    Serial.println(F("Something went wrong during light sensor init!"));
    while (1) {
      delay(100);
    }
  }

  // Delayy for Sensor to normalise
  delay(1000);
}

void loop() {
  // Create a variable to store the incoming measurements
  uint16_t ambient_light = 0;

  if (!SL06.getAmbientLight(ambient_light)) {
    Serial.println("Error reading light values");
  } else {
    // Display Data on the Serial monitor
    Serial.print("Ambient Light: ");
    Serial.print(ambient_light);
    Serial.println(" LUX");
    Serial.println();
  }
  delay(DELAY_TIME);
}
