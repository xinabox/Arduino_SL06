/*************************************************************
  This is an examples for the SL06
  Digital Proximity, Ambient Light, RGB and Gesture Sensor

  You can buy one on our store!
  -----> https://xinabox.cc/products/SL06/

  This example uses the SL06 to detect user gestures

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

  // Start running the SL06 gesture sensor engine
  if ( SL06.enableGestureSensor(false) ) {
    Serial.println(F("Gesture sensor is now running"));
  } else {
    Serial.println(F("Something went wrong during gesture sensor init!"));
  }

  // Delayy for Sensor to normalise
  delay(1000);
}

void loop() {
  // check if any gesture has been detected by SL06
  handleGesture();
}

void handleGesture() {
  if (SL06.isGestureAvailable()) {
    switch (SL06.getGesture()) {
      case DIR_UP:
        Serial.println("UP");
        break;
      case DIR_DOWN:
        Serial.println("DOWN");
        break;
      case DIR_LEFT:
        Serial.println("LEFT");
        break;
      case DIR_RIGHT:
        Serial.println("RIGHT");
        break;
      case DIR_NEAR:
        Serial.println("NEAR");
        break;
      case DIR_FAR:
        Serial.println("FAR");
        break;
      default:
        Serial.println("NONE");
    }
  }
}
