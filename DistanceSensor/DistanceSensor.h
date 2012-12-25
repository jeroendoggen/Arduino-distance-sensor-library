// DistanceSensor.h - Arduino library for retrieving data from the Distance sensors
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

#ifndef DistanceSensor_h
#define DistanceSensor_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#include <pins_arduino.h>
#endif

#define __cxa_pure_virtual()

//abstract class DistanceSensor
class DistanceSensor
{
  public:
    boolean isCloser(int threshold);              // Compare distance value to threshold
    boolean isFarther(int threshold);             // Compare distance value to threshold

    void setAveraging(int avg);                   // calculate average of multiple samples

  protected:
    int _average;

  private:
    virtual int getDistanceCentimeter()=0;
//    inline virtual void begin(){ /*void*/ };
// Is implemented in derived classes
};
#endif
