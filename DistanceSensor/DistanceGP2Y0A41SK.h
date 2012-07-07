/************************************************************************************************************
 * DistanceGP2Y0A41SK.h - Arduino library for retrieving data from the analog GP2Y IR Distance sensor *
 * Copyright 2011 Jeroen Doggen (jeroendoggen@gmail.com)                                                    *
 * Datasheet: http://www.sparkfun.com/datasheets/Components/GP2Y.pdf                                  *
 ************************************************************************************************************
 * Version History:                                                                                         *
 *  Version 0.1: getDistanceRaw, getDistanceVolt, getDistanceCentimeter (with LUT based on datasheet)       *
 *  Version 0.2: Correct LUT for 5V ADC (based on measurements)                                             *
 *  Version 0.3: LUTs moved to flash to save 512 Bytes of RAM                                               *
 * Roadmap:                                                                                                 *
 *  Version 0.4: Correct LUT for 3.3V ADC (based on measurements)                                           *
 *  Version 0.5: Take sensor height above the ground into account                                           *
 *  Version 0.6: Compare different sensors, calculate replacement LUT (at runtime)                          *
 *               based on calibration points                                                                *
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

#ifndef DistanceGP2Y0A41SK_h
#define DistanceGP2Y0A41SK_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#include <pins_arduino.h>
#endif

#include <AnalogDistanceSensor.h>

class DistanceGP2Y0A41SK : public AnalogDistanceSensor
{
  public:
    DistanceGP2Y0A41SK();
    int getDistanceCentimeter();
};
#endif
