/** @file MappedAnalogSensor.h 
  *  Copyright (c) 2016 Ozbotics 
  *  Distributed under the MIT license (see LICENSE)
  */ 
#ifndef _MAPPED_ANALOG_SENSOR_H
 #define _MAPPED_ANALOG_SENSOR_H

#include <Arduino.h>
#include <LinkedList.h>
#include <AnalogSensor.h>

/**
 * Association between raw-input value and translated-output value
 *
 * An List of TranslationPair(s) defines the envelope of a mapping curve
 */
struct TranslationPair {
  int analog;  /**< the raw-input value */ 
  int sensor;  /**< the translated-output value */ 
};

/**
 * The Base class of all MappedAnalogSensor
 *
 * Provides method of transforming raw Analog input into processed-out values
 *  by interpolating along an envelope specified by a list of TranslationPair(s)
 */
class MappedAnalogSensor : public AnalogSensor {
  protected:
    LinkedList<TranslationPair> _translationMap; /**< protected variable _actuator  The list of TranslationPair(s) */ 
    byte _translationMapLength;                  /**< protected variable _actuator  The length of the list of TranslationPair(s) */ 
    
   /**
    * Transform the input value into the translated-output value
    *  by interpolating between TranslationPair(s)
    *
    * @param value the raw-input value
    * @return the translated-output value
    */
    int _translateValue(int value);
    
  public:
  
   /**
    * Constructor
    *
    * @param pin The Analog Input pin
    * @param maxValue The maximum reasonable value
    * @param minValue The minimum reasonable value
    * @param displayLength The minimum number of charcters to display
    * @param displayDecimals The number of charcters to display as decimal places
    * @param divideBy The amount to divide the raw value by  to form the display value
    */
    MappedAnalogSensor(byte pin, unsigned int maxValue=0, unsigned int minValue=0, byte displayLength=1, byte displayDecimals=0, unsigned int divideBy=1) : AnalogSensor(pin, maxValue, minValue, displayLength, displayDecimals, divideBy) {}
    
   /**
    * Transform the input value into the translated-output value
    *  by interpolating between TranslationPair(s)
    *
    * @return the translated-output value
    */
    int getMappedValue();
    
   /**
    *  update the value
    *
    *  update the value from the translated rawValue
    */
    virtual void refreshValue();
};

#endif  // _MAPPED_ANALOG_SENSOR_H