/************************************************************************************************************
 * DistanceGP2Y0A41SK.h - Arduino library for retrieving data from the analog GP2Y IR Distance sensor *
 * Copyright 2011 Jeroen Doggen (jeroendoggen@gmail.com)                                                    *
 * For more information: variable declaration, changelog,... see DistanceGP2Y0A41SK.h                       *
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
/// DistanceGP2Y0A41SK.cpp - Library for retrieving data from the GP2Y IR Distance sensor.
/// For more information: variable declaration, changelog,... see DistanceGP2Y0A41SK.h
/// </summary>

#include <Arduino.h>
#include <DistanceGP2Y0A41SK.h>

/// <summary>
/// Constructor
/// </summary>
DistanceGP2Y0A41SK::DistanceGP2Y0A41SK()
{
}

/// <summary>
/// getDistanceCentimeter(): Returns the distance in centimeters: between 4-36cm (3 & 37 are boundary values)
/// </summary>
int DistanceGP2Y0A41SK::getDistanceCentimeter()
{
	int adcValue=getDistanceRaw();
	if (adcValue > 600){  // lower boundary: 4 cm (3 cm means under the boundary)
		return (3);
	}
	
	if (adcValue < 80 ){  //upper boundary: 36 cm (returning 37 means over the boundary)
		return (37);
	}
	
	else{
		return (1 / (0.000413153 * adcValue - 0.0055266887));
	}
}