/** @file NtcTempSensor.h 
  *  Copyright (c) 2016 Ozbotics 
  *  Distributed under the MIT license (see LICENSE)
  */ 
#ifndef _NTC_TEMP_SENSOR_H
  #define _NTC_TEMP_SENSOR_H
  
#include <Arduino.h>
#include "MappedAnalogSensor.h"

/**
 *  NTC Temperature Sensor
*/
class NtcTempSensor : public MappedAnalogSensor {
  public:

  /**
    * Constructor
    *
    * @param pin The Analog Input pin
    * @param displayLength The minimum number of charcters to display
    * @param displayDecimals The number of charcters to display as decimal places
    * @param divideBy The amount to divide the raw value by  to form the display value
    */
    NtcTempSensor(byte pin, byte displayLength=4, byte displayDecimals=1, unsigned int divideBy=1) : MappedAnalogSensor(pin, displayLength, displayDecimals, divideBy) {
Serial.print(F("NtcTempSensor displayLength:"));
Serial.print(displayLength);

Serial.print(F(", displayDecimals:"));
Serial.print(displayDecimals);

Serial.print(F(", divideBy:"));
Serial.println(divideBy);

      value->setDisplayLength(displayLength);
      value->setDisplayDecimals(displayDecimals);
      value->setDivideBy(divideBy);

      _translationMap.add((TranslationPair) {0, 600} );
      _translationMap.add((TranslationPair) {62, 600} );
      _translationMap.add((TranslationPair) {92, 500} );
      _translationMap.add((TranslationPair) {130, 400} );
      _translationMap.add((TranslationPair) {190, 300} );
      _translationMap.add((TranslationPair) {265, 200} );
      _translationMap.add((TranslationPair) {308, 150} );
      _translationMap.add((TranslationPair) {360, 100} );
      _translationMap.add((TranslationPair) {460, 20} );
      _translationMap.add((TranslationPair) {1024, 20} );

      _translationMapLength = _translationMap.size();
    }
    
};

#endif // _NTC_TEMP_SENSOR_H
