// Arduino library for distance sensors
// Copyright 2011-2013 Jeroen Doggen (jeroendoggen@gmail.com)

#ifndef AnalogDistanceSensor_h
#define AnalogDistanceSensor_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#include <pins_arduino.h>
#endif

#define __cxa_pure_virtual()

#include "DistanceSensor.h"

//abstract class AnalogDistanceSensor
class AnalogDistanceSensor : public DistanceSensor
{
  public:
    AnalogDistanceSensor();
    void begin();
    void begin(int distancePin);

    int getDistanceRaw();

    void setARefVoltage(int _refV);

  private:
    int _mapGP2Y0A21YK_V(int value);
    int _distancePin;

  protected:
    int _refVoltage;
};
#endif
