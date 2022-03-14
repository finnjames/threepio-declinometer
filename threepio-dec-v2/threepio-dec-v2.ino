/**************************************************************************/
/*!
    @file     threepio declinometer v2
    @author   Finn James (github.com/finnsjames)
    @license  GPLv3 (see LICENSE.txt)
*/
/**************************************************************************/


#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>
  
Adafruit_BNO055 bno = Adafruit_BNO055(55);

void setup(void) {
  Serial.begin(9600);
  
  /* Initialize sensor */
  if(!bno.begin()) {
//    Serial.print("COULD NOT START");
    while(1);
  }
  
  delay(100);
    
  bno.setExtCrystalUse(true);
}

void loop(void) {
  /* Get new sensor event */ 
  sensors_event_t event; 
  bno.getEvent(&event);
  
  /* Output z-axis only */
//  Serial.print(event.orientation.x, 4);
//  Serial.print(event.orientation.y, 4);
  Serial.print(event.orientation.z, 4);
  Serial.println("");
  
  delay(10); // 100Hz
}
