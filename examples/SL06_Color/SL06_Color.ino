/*************************************************************
  This is an examples for the SL06
  Digital Proximity, Ambient Light, RGB and Gesture Sensor

  You can buy one on our store!
  -----> https://xinabox.cc/products/SL06/

  This example uses the SL06 to detect colors in RGB format

  The sensor communicates over the I2C Bus.

*************************************************************/

#include <xCore.h>
#include <arduino-SL06.h>

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

  // Start running the SL06 gesture sensor engine
  if (SL06.enableLightSensor(false)) {
    Serial.println(F("Light sensor is now running"));
  } else {
    Serial.println(F("Something went wrong during light sensor init!"));
  }

  // Delayy for Sensor to normalise
  delay(1000);

}

void loop() {
  uint16_t red = 0, green = 0, blue = 0;

  // Read the light levels (ambient, red, green, blue)
  if (!SL06.getRedLight(red) || !SL06.getGreenLight(green) || !SL06.getBlueLight(blue) ) {
    Serial.println("Error reading light values");
  } else {
    Serial.print("RGB : [");
    Serial.print(red);
    Serial.print(", ");
    Serial.print(green);
    Serial.print(", ");
    Serial.print(blue);
    Serial.println("]");
  }
  // Wait 1 second before next reading
  delay(1000);
}

