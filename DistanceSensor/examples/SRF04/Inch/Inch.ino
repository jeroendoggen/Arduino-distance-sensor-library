#include <DistanceSRF04.h>

DistanceSRF04 Dist;
int distance;

void setup()
{
  Serial.begin(9600);
  Dist.begin(2,3);
}

void loop()
{
  distance = Dist.getDistanceInch();
  Serial.print("Distance in inches: ");
  Serial.println(distance);
  delay(500);                                     //make it readable
}
