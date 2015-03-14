// Arduino library for distance sensors
// Copyright 2011-2015 Jeroen Doggen (jeroendoggen@gmail.com)

#ifndef DistanceSensor_h
#define DistanceSensor_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#include <pins_arduino.h>
#endif

#define __cxa_pure_virtual()

//abstract class DistanceSensor
class DistanceSensor
{
  public:
    boolean isCloser(int threshold);              // Compare distance value to threshold
    boolean isFarther(int threshold);             // Compare distance value to threshold

    void setAveraging(int avg);                   // calculate average of multiple samples

  protected:
    int _average;

  private:
    virtual int getDistanceCentimeter()=0;
//    inline virtual void begin(){ /*void*/ };
// Is implemented in derived classes
};
#endif
