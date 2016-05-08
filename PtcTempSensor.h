/** @file PtcTempSensor.h 
  *  Copyright (c) 2016 Ozbotics 
  *  Distributed under the MIT license (see LICENSE)
  */ 
#ifndef _PTC_TEMP_SENSOR_H
  #define _PTC_TEMP_SENSOR_H
  
#include <Arduino.h>
#include "MappedAnalogSensor.h"

/**
 *  PTC Temperature Sensor
 */
class PtcTempSensor : public MappedAnalogSensor {
  public:
  
  /**
    * Constructor
    *
    * @param pin The Analog Input pin
    * @param displayLength The minimum number of charcters to display
    * @param displayDecimals The number of charcters to display as decimal places
    * @param divideBy The amount to divide the raw value by  to form the display value
    */
    PtcTempSensor(byte pin, byte displayLength=4, byte displayDecimals=1, unsigned int divideBy=1) : MappedAnalogSensor(pin, displayLength, displayDecimals, divideBy) {
      value->setDisplayLength(displayLength);
      value->setDisplayDecimals(displayDecimals);
      value->setDivideBy(divideBy);

      _translationMap.add((TranslationPair) {0, 20} );

      _translationMap.add((TranslationPair) {249, 20} );
      _translationMap.add((TranslationPair) {288, 50} );
      _translationMap.add((TranslationPair) {435, 170} );
      _translationMap.add((TranslationPair) {563, 280} );
      _translationMap.add((TranslationPair) {678, 400} );
      _translationMap.add((TranslationPair) {800, 550} );

      _translationMap.add((TranslationPair) {1024, 550} );
      
      _translationMapLength = _translationMap.size();
    }
};

#endif // _PTC_TEMP_SENSOR_H
