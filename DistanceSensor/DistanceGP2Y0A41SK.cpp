// Arduino library for distance sensors
// Copyright 2011-2015 Jeroen Doggen (jeroendoggen@gmail.com)

#include <Arduino.h>
#include <DistanceGP2Y0A41SK.h>

/// Constructor
DistanceGP2Y0A41SK::DistanceGP2Y0A41SK()
{
}

/// getDistanceCentimeter(): Returns the distance in centimeters: between 4-36cm (3 & 37 are boundary values)
int DistanceGP2Y0A41SK::getDistanceCentimeter()
{
  int adcValue=getDistanceRaw();
  if (adcValue > 600)                             // lower boundary: 4 cm (3 cm means under the boundary)
  {
    return (3);
  }

  if (adcValue < 80 )                             //upper boundary: 36 cm (returning 37 means over the boundary)
  {
    return (37);
  }

  else
  {
    return (1 / (0.000413153 * adcValue - 0.0055266887));
  }
}
