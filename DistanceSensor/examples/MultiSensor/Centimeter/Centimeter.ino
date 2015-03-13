// Arduino library for distance sensors
// Copyright 2011-2015 Jeroen Doggen (jeroendoggen@gmail.com)
//
// Creates several "sensor objects" of different ADC pins: A0 -> A3
// Read the sensors in print the distance

// TODO: warning the code compiles (but untested on hardware)

#include <DistanceGP2Y0A41SK.h>
#include <DistanceGP2Y0A21YK.h>

DistanceGP2Y0A41SK DistSK_1;
DistanceGP2Y0A41SK DistSK_2;

DistanceGP2Y0A21YK DistYK_1;
DistanceGP2Y0A21YK DistYK_2;

int distance1, distance2, distance3, distance4;

void setup()
{
  Serial.begin(9600);
  DistSK_1.begin(A0);
  DistSK_2.begin(A1);
  DistYK_1.begin(A2);
  DistYK_2.begin(A3);
}

void loop()
{
  distance1 = DistSK_1.getDistanceCentimeter();
  distance2 = DistSK_2.getDistanceCentimeter();
  distance3 = DistYK_1.getDistanceCentimeter();
  distance4 = DistYK_2.getDistanceCentimeter();

  Serial.print("Sensor1: ");
  Serial.print(distance1);
  Serial.print(" | Sensor2: ");
  Serial.print(distance2);
  Serial.print(" | Sensor3: ");
  Serial.print(distance3);
  Serial.print(" | Sensor4: ");
  Serial.println(distance4);
  delay(500);                                     //make it readable
}
