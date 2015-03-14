// Arduino library for distance sensors
// Copyright 2011-2015 Jeroen Doggen (jeroendoggen@gmail.com)

#ifndef DistanceGP2Y0A21YK_h
#define DistanceGP2Y0A21YK_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#include <pins_arduino.h>
#endif

#include "AnalogDistanceSensor.h"

class DistanceGP2Y0A21YK : public AnalogDistanceSensor
{
  public:
    DistanceGP2Y0A21YK();
    int getDistanceCentimeter();
};
#endif
