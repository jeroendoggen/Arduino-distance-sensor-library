// Arduino library for distance sensors
// Copyright 2011-2015 Jeroen Doggen (jeroendoggen@gmail.com)

// TODO: warning the code compiles and should work correctly (but untested on hardware)

#ifndef CombinedDistanceSensors_h
#define CombinedDistanceSensors_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#include <pins_arduino.h>
#endif

#include <DistanceGP2Y0A41SK.h>
#include <DistanceGP2Y0A21YK.h>


//Class CombinedDistanceSensors
class CombinedDistanceSensors
{
  public:
    CombinedDistanceSensors();

    void begin();
    void begin(int distancePin1, int distancePin2, int distancePin3, int distancePin4);

    int getDistanceCentimeter();

  private:
    DistanceGP2Y0A41SK _DistSK_1;
    DistanceGP2Y0A41SK _DistSK_2;

    DistanceGP2Y0A21YK _DistYK_1;
    DistanceGP2Y0A21YK _DistYK_2;

    int _distance;
    int _distance1;
    int _distance2;
    int _distance3;
    int _distance4;
};
#endif
