/** @file AnalogSensor.h 
  *  Copyright (c) 2016 Ozbotics 
  *  Distributed under the MIT license (see LICENSE)
  */ 
#ifndef _ANALOG_SENSOR_H
 #define _ANALOG_SENSOR_H

#include <Arduino.h>
#include <Sensor.h>

/**
 *  Base class of all Analog Sensors
 *
 *  Provides method to get value from an Analog Input (ADC)
 */
class AnalogSensor : public Sensor<unsigned int> {
  protected:
    byte _pin; /**< protected variable _pin  The Analog Input pin */ 
    
  public:
  
   /**
    * Constructor
    *
    * @param pin The Analog Input pin
    * @param displayLength The minimum number of charcters to display
    * @param displayDecimals The number of charcters to display as decimal places
    * @param divideBy The amount to divide the raw value by  to form the display value
    */
    AnalogSensor(byte pin, byte displayLength=1, byte displayDecimals=0, unsigned int divideBy=1) : _pin(pin), Sensor<unsigned int>(displayLength, displayDecimals, divideBy) {}
    
   /**
    *  get the raw value directly from the Analog Input ADC
    */
    inline int getRawValue() { return analogRead(_pin); }
    
   /**
    *  request a reading
    *
    *  reading a value takes 0ms preparation
    */
    virtual unsigned long requestValue() { return 0; }
    
    
   /**
    *  update the value
    *
    *  update the value from the rawValue
    */
    virtual void refreshValue() { value->setValue(getRawValue()); }

};

#endif  // _ANALOG_SENSOR_H