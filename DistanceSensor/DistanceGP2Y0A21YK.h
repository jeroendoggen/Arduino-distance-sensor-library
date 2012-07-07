// DistanceGP2Y0A21YK.h - Arduino library for retrieving data from the analog GP2Y0A21YK IR Distance sensor
// Copyright 2011-2012 Jeroen Doggen (jeroendoggen@gmail.com)
// Datasheet: http://www.sparkfun.com/datasheets/Components/GP2Y0A21YK.pdf
//
// Version History:
//  Version 0.1: First version using "AnalogDistanceSensor" lib
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

#ifndef DistanceGP2Y0A21YK_h
#define DistanceGP2Y0A21YK_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#include <pins_arduino.h>
#endif

#include <AnalogDistanceSensor.h>

class DistanceGP2Y0A21YK : public AnalogDistanceSensor
{
  public:
    DistanceGP2Y0A21YK();
    int getDistanceCentimeter();
};
#endif
