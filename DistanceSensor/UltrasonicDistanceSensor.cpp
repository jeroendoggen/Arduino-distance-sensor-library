// Arduino library for distance sensors
// Copyright 2011-2015 Jeroen Doggen (jeroendoggen@gmail.com)

#include <UltrasonicDistanceSensor.h>

/// Begin function to set default pins
void UltrasonicDistanceSensor::begin()
{
  begin (2,3);
}

/// Begin variables
/// - int trigPin: pin used to activate the sensor
/// - int echoPin: pin used to read the reflection
void UltrasonicDistanceSensor::begin(int echoPin, int trigPin)
{
  _trigPin=trigPin;
  _echoPin=echoPin;
  pinMode(_trigPin, OUTPUT);
  pinMode(_echoPin, INPUT);
  setAveraging(1);                                //1: all samples passed to higher level
}

/// getDistanceCentimeter(): Returns the distance in centimeters
int UltrasonicDistanceSensor::getDistanceCentimeter()
{
  return (getDistanceTime()/58);
}

/// getDistanceInch(): Returns the distance in inches
int UltrasonicDistanceSensor::getDistanceInch()
{
  return (getDistanceTime()/148);
}
