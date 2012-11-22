//
// AnalogDistanceSensor.h - Arduino library for Analog Distance sensors
// Copyright 2011 Jeroen Doggen (jeroendoggen@gmail.com)
// More info: http://www.robot-electronics.co.uk/files/SRF04.pde
//
// Version History:
//  Version 0.1:
//
// Roadmap:
//  Version 0.2: ??
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

#ifndef AnalogDistanceSensor_h
#define AnalogDistanceSensor_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#include <pins_arduino.h>
#endif

#define __cxa_pure_virtual()

#include <DistanceSensor.h>

//abstract class AnalogDistanceSensor
class AnalogDistanceSensor : public DistanceSensor
{
  public:
    AnalogDistanceSensor();
    void begin();
    void begin(int distancePin);

    int getDistanceRaw();
    int getDistanceVolt();

    void setARefVoltage(int _refV);

  private:
    int _mapGP2Y0A21YK_V(int value);
    int _distancePin;

  protected:
    int _refVoltage;
};
#endif
