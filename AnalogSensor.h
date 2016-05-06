#ifndef _ANALOG_SENSOR_H
 #define _ANALOG_SENSOR_H

#include <Arduino.h>
#include <Sensor.h>

class AnalogSensor : public Sensor<unsigned int> {
  protected:
    byte _pin;
    
  public:
    AnalogSensor(byte pin, byte displayLength=1, byte displayDecimals=0, unsigned int divideBy=1) : _pin(pin), Sensor<unsigned int>(displayLength, displayDecimals, divideBy) {}
    
    inline int getRawValue() { return analogRead(_pin); }
    
    virtual unsigned long requestValue() { return 0; }
    virtual void refreshValue() { value->setValue(getRawValue()); }

};

#endif  // _ANALOG_SENSOR_H