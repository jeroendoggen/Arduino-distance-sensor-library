// Arduino library for distance sensors
// Copyright 2011-2015 Jeroen Doggen (jeroendoggen@gmail.com)

#ifndef UltrasonicDistanceSensor_h
#define UltrasonicDistanceSensor_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#include <pins_arduino.h>
#endif

#define __cxa_pure_virtual()

#include "DistanceSensor.h"

class UltrasonicDistanceSensor : public DistanceSensor
{
  public:
    virtual int getDistanceTime()=0;

    void begin();
    void begin(int echoPin, int trigPin);

    int getDistanceCentimeter();
    int getDistanceInch();

  protected:
    int _trigPin;
    int _echoPin;
};
#endif
