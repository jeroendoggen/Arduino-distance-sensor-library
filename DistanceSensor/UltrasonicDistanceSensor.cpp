/*******************************************************************************************************
 * UltrasonicDistanceSensor.cpp - Arduino library for retrieving data from ultrasonic distance sensors *
 * Copyright 2011-2012 Jeroen Doggen (jeroendoggen@gmail.com)                                          *
 * For more information: variable declaration, changelog,... see UltrasonicDistanceSensor.h            *
 *******************************************************************************************************
 * This library is free software; you can redistribute it and/or                                       *
 * modify it under the terms of the GNU Lesser General Public                                          *
 * License as published by the Free Software Foundation; either                                        *
 * version 2.1 of the License, or (at your option) any later version.                                  *
 *                                                                                                     *
 * This library is distributed in the hope that it will be useful,                                     *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of                                      *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU                                   *
 * Lesser General Public License for more details.                                                     *
 *                                                                                                     *
 * You should have received a copy of the GNU Lesser General Public                                    *
 * License along with this library; if not, write to the Free Software                                 *
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA                          *
 ******************************************************************************************************/

/// <summary>
/// UltrasonicDistanceSensor.cpp - Library for retrieving data from the GP2Y0A21YK IR Distance sensor.
/// For more information: variable declaration, changelog,... see UltrasonicDistanceSensor.h
/// </summary>

#include <UltrasonicDistanceSensor.h>

/// <summary>
/// Begin function to set default pins
/// </summary>
void UltrasonicDistanceSensor::begin()
{
	begin (2,3);
}

/// <summary>
/// Begin variables
/// - int trigPin: pin used to activate the sensor
/// - int echoPin: pin used to read the reflection
/// </summary>
void UltrasonicDistanceSensor::begin(int echoPin, int trigPin)
{
	_trigPin=trigPin;
	_echoPin=echoPin;
	pinMode(_trigPin, OUTPUT);
	pinMode(_echoPin, INPUT);
	setAveraging(1);		      //1: all samples passed to higher level
}

/// <summary>
/// setAveraging(int avg): Sets how many samples have to be averaged in getDistanceCentimeter, default value is 100.
/// </summary>
void UltrasonicDistanceSensor::setAveraging(int avg)
{
	_average=avg;
}

/// <summary>
/// getDistanceCentimeter(): Returns the distance in centimeters
/// </summary>
int UltrasonicDistanceSensor::getDistanceCentimeter()
{
	return (getDistanceTime()/29/2);
}