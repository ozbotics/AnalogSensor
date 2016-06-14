#include <Arduino.h>
#include "MappedAnalogSensor.h"

void MappedAnalogSensor::refreshValue() { 
  _updateValue(getMappedValue());  
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
  int value = getRawValue();
  
  for (int i=0; i<5; i++) {
    value = (value + getRawValue()) / 2;
  }
  
  return _translateValue(value);
}
