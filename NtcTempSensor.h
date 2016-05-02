#ifndef _NTC_TEMP_SENSOR_H
  #define _NTC_TEMP_SENSOR_H
  
#include <Arduino.h>
#include "MappedAnalogSensor.h"

class NtcTempSensor : public MappedAnalogSensor {
  public:
    NtcTempSensor(byte pin, byte displayLength=4, byte displayDecimals=1, unsigned int divideBy=1) : MappedAnalogSensor(pin, displayLength, displayDecimals, divideBy) {
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

/*
      _translationMap.add((TranslationPair) {0, 20} );

      _translationMap.add((TranslationPair) {539, 20} );
      _translationMap.add((TranslationPair) {590, 50} );
      _translationMap.add((TranslationPair) {717, 170} );
      _translationMap.add((TranslationPair) {808, 280} );
      _translationMap.add((TranslationPair) {880, 400} );
      _translationMap.add((TranslationPair) {938, 550} );

      _translationMap.add((TranslationPair) {1024, 550} );
*/

      _translationMapLength = _translationMap.size();
    }
    
};

#endif // _NTC_TEMP_SENSOR_H
