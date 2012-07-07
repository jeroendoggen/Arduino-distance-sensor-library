// DistanceGP2Y0A21YK.h - Arduino library for retrieving data from the analog GP2Y0A21YK IR Distance sensor
// Copyright 2011-2012 Jeroen Doggen (jeroendoggen@gmail.com)
// For more information: variable declaration, changelog,... see DistanceGP2Y0A21YK.h
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

#include <DistanceGP2Y0A21YK.h>

/// Constructor
DistanceGP2Y0A21YK::DistanceGP2Y0A21YK()
{
}

/// getDistanceCentimeter(): Returns the distance in centimeters
int DistanceGP2Y0A21YK::getDistanceCentimeter()
{
  int adcValue=getDistanceRaw();
  if (adcValue > 600)                             // lower boundary: 4 cm (3 cm means under the boundary)
  {
    return (3);
  }

  if (adcValue < 80 )                             //upper boundary: 36 cm (returning 37 means over the boundary)
  {
    return (37);
  }

  else
  {
    return (1 / (0.0002391473 * adcValue - 0.0100251467));
  }
}
