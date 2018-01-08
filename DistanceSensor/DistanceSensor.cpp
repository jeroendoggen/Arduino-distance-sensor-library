// Arduino library for distance sensors
// Copyright 2011-2015 Jeroen Doggen (jeroendoggen@gmail.com)

#include <DistanceSensor.h>

/// isCloser: check whether the distance to the detected object is smaller than a given threshold
boolean DistanceSensor::isCloser(int threshold)
{
  return threshold>getDistanceCentimeter();
}

/// isFarther: check whether the distance to the detected object is bigger than a given threshold
boolean DistanceSensor::isFarther(int threshold)
{
  return threshold<getDistanceCentimeter();
}

/// setAveraging(int avg): Sets how many samples have to be averaged in getDistanceCentimeter, default value is 1.
void DistanceSensor::setAveraging(int avg)
{
  _average=avg;
}
