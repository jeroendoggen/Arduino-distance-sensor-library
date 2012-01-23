/************************************************************************************************************
 * DistanceSRF04.h - Arduino library for retrieving data from the SRF04 Distance sensor                     *
 * Copyright 2011-2012 Jeroen Doggen (jeroendoggen@gmail.com)                                               *
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

#ifndef DistanceSRF04_h
#define DistanceSRF04_h

#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
  #include <pins_arduino.h>
#endif

#include <AccousticDistanceSensor.h>

class DistanceSRF04 : public AccousticDistanceSensor
{
	public:
		DistanceSRF04();
		//void begin();
		//void begin(int echoPin, int trigPin);
		
		int getDistanceTime();
		//int getDistanceCentimeter();
		//int getDistanceInch();

		//void setAveraging(int avg);    

	private:
		//int _trigPin;
		//int _echoPin;
		//int _average;
		long _duration;
};
#endif
