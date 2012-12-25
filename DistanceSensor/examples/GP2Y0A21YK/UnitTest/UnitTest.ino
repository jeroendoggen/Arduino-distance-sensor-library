#include <DistanceGP2Y0A21YK.h>
#include <ArduinoUnit.h>
#include <TestHelper.h>

TestSuite suite;
TestHelper helper;

DistanceGP2Y0A21YK Dist;
int distance=0;
int analog=0;

test(distanceRange)
{
// should be 4 - 80 for the sensor
  assertTrue(helper.inInterval(Dist.getDistanceCentimeter(),4,80));
}

test(analogRange)
{
// should be 65 - 650 for the sensor
  assertTrue(helper.inInterval(analogRead(A0),65,650));
}

test(floatingInputPin)
{
  assertTrue(!(helper.floatingInputPin(A0)));
}

void setup()
{
  Serial.begin(9600);
  Dist.begin(A0);
}

void loop()
{
  suite.run();
}
