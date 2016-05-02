#ifndef _MAPPED_ANALOG_SENSOR_H
 #define _MAPPED_ANALOG_SENSOR_H

#include <Arduino.h>
#include <LinkedList.h>
#include <AnalogSensor.h>

struct TranslationPair {
  int analog;
  int sensor;
};

class MappedAnalogSensor : public AnalogSensor {
  protected:
    LinkedList<TranslationPair> _translationMap;
    byte _translationMapLength;
    
    int _translateValue(int value);
    
  public:
    MappedAnalogSensor(byte pin, byte displayLength=1, byte displayDecimals=0, unsigned int divideBy=1) : AnalogSensor(pin, displayLength, displayDecimals, divideBy) {}
    
    int getMappedValue();
    
    virtual void refreshValue() { value->setValue(getMappedValue()); }

/*
    float getFloatValue() {
      return ((float)getMappedValue()) / (_displayDecimals * 10.0);
    }
*/    
};

#endif  // _MAPPED_ANALOG_SENSOR_H