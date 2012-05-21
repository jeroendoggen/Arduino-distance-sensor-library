/************************************************************************************************************
 * DistanceSensor.h - Arduino library for retrieving data from Distance sensors                             *
 * Copyright 2011 Jeroen Doggen (jeroendoggen@gmail.com)                                                    *
 * More info: http://www.robot-electronics.co.uk/files/SRF04.pde                                            *
 ************************************************************************************************************
 * Version History:                                                                                         *
 *  Version 0.1: getDistanceCentimeter, blocking                                                            *
 *                                                                                                          *
 * Roadmap:                                                                                                 *
 *  Version 0.2: add filtering (low pass filter?)                                                           *
 *  Version 0.3: getDistanceCentimeter, interrupt based                                                     *                                                                                          *
 ************************************************************************************************************
 * This library is free software; you can redistribute it and/or                                            *
 * modify it under the terms of the GNU Lesser General Public                                               *
 * License as published by the Free Software Foundation; either                                             *
 * version 2.1 of the License, or (at your option) any later version.                                       *
 *                                                                                                          *
 * This library is distributed in the hope that it will be useful,                                          *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of                                           *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU                                        *
 * Lesser General Public License for more details.                                                          *
 *                                                                                                          *
 * You should have received a copy of the GNU Lesser General Public                                         *
 * License along with this library; if not, write to the Free Software                                      *
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA                               *
 ***********************************************************************************************************/

/// <summary>
/// DistanceSensor.cpp - Library for retrieving data from Distance sensors
/// </summary>

#include <DistanceSensor.h>

/// <summary>
/// isCloser: check whether the distance to the detected object is smaller than a given threshold
/// </summary>
boolean DistanceSensor::isCloser(int threshold)
{
	if (threshold>getDistanceCentimeter())
	{
		return (true);
	}
	else
	{
		return (false);
	}
}

/// <summary>
/// isFarther: check whether the distance to the detected object is bigger than a given threshold
/// </summary>
boolean DistanceSensor::isFarther(int threshold)
{
	if (threshold>getDistanceCentimeter())
	{
		return true;
	}
	else
	{
		return false;
	}
}

/// <summary>
/// setAveraging(int avg): Sets how many samples have to be averaged in getDistanceCentimeter, default value is 1.
/// </summary>
void UltrasonicDistanceSensor::setAveraging(int avg)
{
	_average=avg;
}
