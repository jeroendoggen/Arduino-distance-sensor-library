// Arduino library for distance sensors
// Copyright 2011-2015 Jeroen Doggen (jeroendoggen@gmail.com)

#include <DistanceSensor.h>

/// isCloser: check whether the distance to the detected object is smaller than a given threshold
boolean DistanceSensor::isCloser(int threshold)
{
  if (threshold>getDistanceCentimeter())
  {
    return (true);
  }
  else
  {
    return (false);
  }
}

/// isFarther: check whether the distance to the detected object is bigger than a given threshold
boolean DistanceSensor::isFarther(int threshold)
{
  if (threshold>getDistanceCentimeter())
  {
    return true;
  }
  else
  {
    return false;
  }
}

/// setAveraging(int avg): Sets how many samples have to be averaged in getDistanceCentimeter, default value is 1.
void DistanceSensor::setAveraging(int avg)
{
  _average=avg;
}
