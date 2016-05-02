#ifndef _PTC_TEMP_SENSOR_H
  #define _PTC_TEMP_SENSOR_H
  
#include <Arduino.h>
#include "MappedAnalogSensor.h"

class PtcTempSensor : public MappedAnalogSensor {
  public:
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
