// Arduino library for distance sensors
// Copyright 2011-2015 Jeroen Doggen (jeroendoggen@gmail.com)

// TODO: warning the code compiles and should work correctly (but untested on hardware)

#include <CombinedDistanceSensors.h>

/// Constructor
CombinedDistanceSensors::CombinedDistanceSensors()
{
}

/// Begin function to set input pins
void CombinedDistanceSensors::begin()
{
    _DistSK_1.begin(A0);
    _DistSK_2.begin(A1);

    _DistYK_1.begin(A2);
    _DistYK_2.begin(A3);
}


void CombinedDistanceSensors::begin(int distancePin1, int distancePin2, int distancePin3, int distancePin4)
{
    _DistSK_1.begin(distancePin1);
    _DistSK_2.begin(distancePin2);

    _DistYK_1.begin(distancePin3);
    _DistYK_2.begin(distancePin4);
}

int CombinedDistanceSensors::getDistanceCentimeter()
{
  _distance1 = _DistSK_1.getDistanceCentimeter();
  _distance2 = _DistSK_2.getDistanceCentimeter();
  _distance3 = _DistYK_1.getDistanceCentimeter();
  _distance4 = _DistYK_2.getDistanceCentimeter();

  _distance = (_distance1 + _distance2 + _distance3 + _distance1 ) / 4;

return (_distance);
}
