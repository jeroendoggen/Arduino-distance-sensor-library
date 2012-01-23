/***************************************************************************************************
 * DistanceSRF04.h - Arduino library for retrieving data from the SRF04 Ultrasonic Distance sensor *
 * Copyright 2011 Jeroen Doggen (jeroendoggen@gmail.com)                                           *
 * For more information: variable declaration, changelog,... see DistanceSRF04.h                   *
 ***************************************************************************************************
 * This library is free software; you can redistribute it and/or                                   *
 * modify it under the terms of the GNU Lesser General Public                                      *
 * License as published by the Free Software Foundation; either                                    *
 * version 2.1 of the License, or (at your option) any later version.                              *
 *                                                                                                 *
 * This library is distributed in the hope that it will be useful,                                 *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of                                  *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU                               *
 * Lesser General Public License for more details.                                                 *
 *                                                                                                 *
 * You should have received a copy of the GNU Lesser General Public                                *
 * License along with this library; if not, write to the Free Software                             *
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA                      *
 **************************************************************************************************/

/// <summary>
/// DistanceSRF04.cpp - Library for retrieving data from the GP2Y0A21YK IR Distance sensor.
/// For more information: variable declaration, changelog,... see DistanceSRF04.h
/// </summary>

#include <Arduino.h>
#include <DistanceSRF04.h>

/// <summary>
/// Constructor
/// </summary>
DistanceSRF04::DistanceSRF04()
{
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
		_duration = pulseIn(_echoPin, HIGH);
		sum=sum+_duration;
	}
	return(int(sum/_average));
}

