// Arduino library for distance sensors
// Copyright 2011-2015 Jeroen Doggen (jeroendoggen@gmail.com)

#include <MultiDistanceSensors.h>

/// Begin function to set input pins
void AnalogDistanceSensor::begin()
{
    _DistSK_1(AO);
    _DistSK_2(A1);

    _DistYK_1(A2);
    _DistYK_2(A3);
}


void begin(int distancePin1, int distancePin2, int distancePin3, int distancePin4)
{
    _DistSK_1(distancePin1);
    _DistSK_2(distancePin2);

    _DistYK_1(distancePin3);
    _DistYK_2(distancePin4);
}

int getDistanceCentimeter()
{
  _distance1 = _DistSK_1.getDistanceCentimeter();
  _distance2 = _DistSK_2.getDistanceCentimeter();
  _distance3 = _DistYK_1.getDistanceCentimeter();
  _distance4 = _DistYK_2.getDistanceCentimeter();

  _distance = (_distance1 + _distance2 + _distance3 + _distance1 ) / 4;

return (_distance);
  
}