// Arduino library for distance sensors
// Copyright 2011-2015 Jeroen Doggen (jeroendoggen@gmail.com)
//
// Creates several "sensor objects" of different ADC pins: A0 -> A3
// Read the sensors in print the distance

// TODO: warning the code compiles and should work correctly (but untested on hardware)

#include <CombinedDistanceSensors.h>

CombinedDistanceSensors Dist;

int distance;

void setup()
{
  Serial.begin(9600);
  Dist.begin(A0, A1, A2, A3);
}

void loop()
{
  distance = Dist.getDistanceCentimeter();

  Serial.print("Distance: ");
  Serial.println(distance);
  delay(500);                                     //make it readable
}
