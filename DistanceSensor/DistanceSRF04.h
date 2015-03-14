// Arduino library for distance sensors
// Copyright 2011-2015 Jeroen Doggen (jeroendoggen@gmail.com)

#ifndef DistanceSRF04_h
#define DistanceSRF04_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#include <pins_arduino.h>
#endif

#include "UltrasonicDistanceSensor.h"

class DistanceSRF04 : public UltrasonicDistanceSensor
{
  public:
    DistanceSRF04();
    int getDistanceTime();

  private:
    long _duration;
};
#endif
