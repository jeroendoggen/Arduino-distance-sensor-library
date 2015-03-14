// Arduino library for distance sensors
// Copyright 2011-2015 Jeroen Doggen (jeroendoggen@gmail.com)

#include <Arduino.h>
#include <DistanceSRF04.h>

/// <summary>
/// Constructor
/// </summary>
DistanceSRF04::DistanceSRF04()
{
  _duration=0;
  _average=0;
}

/// <summary>
/// getDistanceTime(): Returns the time between transmission and echo receive
/// </summary>
int DistanceSRF04::getDistanceTime()
{
  long sum = 0;
  for (int i=0;i<_average;i++)
  {
    digitalWrite(_trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(_trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(_trigPin, LOW);
    _duration = pulseIn(_echoPin, HIGH,17400);
    sum=sum+_duration;
  }
  return(int(sum/_average));
}
