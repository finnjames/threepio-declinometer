/**************************************************************************/
/*!
    @file     Threepio declinometer
    @author   Finn James (github.com/finnsjames)
    @license  GPLv3 (see LICENSE.txt)
*/
/**************************************************************************/

#include <Wire.h>
#include <Adafruit_MMA8451.h>
#include <Adafruit_Sensor.h>

Adafruit_MMA8451 mma = Adafruit_MMA8451();

void setup(void) {
  Serial.begin(9600);

  mma.begin();
  if (! mma.begin()) {
//    Serial.println("COULD NOT START");
    while (1);
  }
  
  mma.setRange(MMA8451_RANGE_2_G);

//  Serial.println("x, y, z");
}

void loop() { 
  // Get a new sensor event
  sensors_event_t event; 
  mma.getEvent(&event);

  // Output results
//  Serial.print(event.acceleration.x); Serial.print(", ");
//  Serial.print(event.acceleration.y); Serial.print(", ");
//  Serial.print(event.acceleration.z); Serial.println();
  Serial.print(
    event.acceleration.y/sqrt(
      pow(event.acceleration.x,2.0) +
      pow(event.acceleration.y,2.0) +
      pow(event.acceleration.z,2.0)
    ), 6
  );
  Serial.println();
  
  delay(10); // 100Hz
  
}
