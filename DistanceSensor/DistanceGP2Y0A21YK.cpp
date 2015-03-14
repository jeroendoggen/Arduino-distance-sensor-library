// Arduino library for distance sensors
// Copyright 2011-2015 Jeroen Doggen (jeroendoggen@gmail.com)

#include <DistanceGP2Y0A21YK.h>

/// Constructor
DistanceGP2Y0A21YK::DistanceGP2Y0A21YK()
{
}

/// getDistanceCentimeter(): Returns the distance in centimeters
int DistanceGP2Y0A21YK::getDistanceCentimeter()
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
    return (1 / (0.0002391473 * adcValue - 0.0100251467));
  }
}
