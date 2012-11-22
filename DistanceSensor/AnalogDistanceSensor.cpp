// AnalogDistanceSensor.h - Arduino library from Analog Distance sensors
// Copyright 2011-2012 Jeroen Doggen (jeroendoggen@gmail.com)
// For more information.. see AnalogDistanceSensor.h
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

#include <AnalogDistanceSensor.h>

/// Constructor
AnalogDistanceSensor::AnalogDistanceSensor()
{
  _distancePin=0;
  _refVoltage=0;
}

/// Begin function to set input pins: distancePin = A0.
void AnalogDistanceSensor::begin()
{
  begin (A0);
}

/// Begin variables
/// - int _distancePin: number indicating the distance to an object: ANALOG IN
/// When you use begin() without parameters standard values are loaded: A0
void AnalogDistanceSensor::begin(int distancePin)
{
  pinMode(distancePin, INPUT);
  _distancePin=distancePin;
  setAveraging(1);                                //1: all samples passed to higher level
  setARefVoltage(5);                              // 5: default analog reference of 5 volts (on 5V Arduino boards) or 3.3 volts (on 3.3V Arduino boards)
//setARefVoltage(3);  // external analog reference: for 3.3V: put a wire between the AREF pin and the 3.3V VCC pin.
//This increases accuracy (and uses a different LUT)
}

/// getDistanceRaw(): Returns the distance as a raw value: ADC output: 0 -> 1023
int AnalogDistanceSensor::getDistanceRaw()
{
  return (analogRead(_distancePin));
}

/// getDistanceVolt(): Returns the distance as a Voltage: ADC Input: 0V -> 5V (or 0V -> 3.3V)
int AnalogDistanceSensor::getDistanceVolt()
{
  return _mapGP2Y0A21YK_V(getDistanceRaw());
}

/// _mapGP2Y0A21YKV: maps the ADC output to the input voltage of the ADC
int AnalogDistanceSensor::_mapGP2Y0A21YK_V(int value)
{
  if (_refVoltage == 3)
  {
    return map(value,0,1023,0,3300);
  }
  if (_refVoltage == 5)
  {
    return map(value,0,1023,0,5000);
  }
  else
  {
    return (0);
  }
}

/// setARefVoltage:set the ADC reference voltage: (default value: 5V, set to 3 for external reference value, typically 3.3 on Arduino boards)
void AnalogDistanceSensor::setARefVoltage(int refV)
{
  _refVoltage=refV;
  if (_refVoltage == 5)
  {
    analogReference(DEFAULT);
  }
  if (_refVoltage == 3)
  {
    analogReference(EXTERNAL);
  }
}
