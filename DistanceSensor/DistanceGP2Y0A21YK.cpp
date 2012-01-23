/************************************************************************************************************
 * DistanceGP2Y0A21YK.h - Arduino library for retrieving data from the analog GP2Y0A21YK IR Distance sensor *
 * Copyright 2011-2012 Jeroen Doggen (jeroendoggen@gmail.com)                                               *
 * For more information: variable declaration, changelog,... see DistanceGP2Y0A21YK.h                       *
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
/// DistanceGP2Y0A21YK.cpp - Library for retrieving data from the GP2Y0A21YK IR Distance sensor.
/// For more information: variable declaration, changelog,... see DistanceGP2Y0A21YK.h
/// </summary>

#include <DistanceGP2Y0A21YK.h>
#include <DistanceGP2Y0A21YK_LUTs.h>

/// <summary>
/// Constructor
/// </summary>
DistanceGP2Y0A21YK::DistanceGP2Y0A21YK()
{
}

/// <summary>
/// getDistanceCentimeter(): Returns the distance in centimeters
/// </summary>
int DistanceGP2Y0A21YK::getDistanceCentimeter()
{
	return _mapGP2Y0A21YK_CM(getDistanceRaw());
}

/// <summary>
/// _mapGP2Y0A21YK_CM: calculates the distance in centimeters using a lookup table
///    -> Two different LUTs depending on ADC reference voltage
/// </summary>
int DistanceGP2Y0A21YK::_mapGP2Y0A21YK_CM(int value)
{
	if (_refVoltage == 3)
	{
		int sum = 0;
		for (int i=0;i<_average;i++)
		{
			// this code is equivalent to: sum=sum+transferFunctionLUT5V[(getDistanceRaw()/4)];
			// but this alternative syntax is needed to read the program memory
			sum=sum + pgm_read_byte_near (transferFunctionLUT3V + (getDistanceRaw()/4));
		}
		return(sum/_average);
	}
	if (_refVoltage == 5)
	{
		int sum = 0;
		for (int i=0;i<_average;i++)
		{
			sum=sum + pgm_read_byte_near (transferFunctionLUT5V + (getDistanceRaw()/4));
		}
		return(sum/_average);
	}
}

