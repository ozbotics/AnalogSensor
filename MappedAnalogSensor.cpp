#include <Arduino.h>
#include "MappedAnalogSensor.h"

void MappedAnalogSensor::refreshValue() { 
  value->setValue(getMappedValue()); 
}

int MappedAnalogSensor::_translateValue(int value) {
  int ret = 0;
  
  for (byte i=1; i<_translationMapLength; i++) {
    if (value < _translationMap.get(i).analog) {
      ret = map(value, _translationMap.get(i-1).analog, _translationMap.get(i).analog, _translationMap.get(i-1).sensor, _translationMap.get(i).sensor);
      break;
    }
  }
  
  return ret;
}

int MappedAnalogSensor::getMappedValue() {
  return _translateValue(getRawValue());
}
