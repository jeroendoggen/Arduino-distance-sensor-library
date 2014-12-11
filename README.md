[![DOI](https://zenodo.org/badge/7755/jeroendoggen/Arduino-distance-sensor-library.svg)](http://dx.doi.org/10.5281/zenodo.13196)

# Arduino library for distance sensors
The current version provides a unified interface for four sensors:

 * SRF04 & SRF05 Ultrasonic Ranger
 * Sharp GP2Y0A21YK IR Distance sensor
 * Sharp GP2Y0A41SK IR Distance sensor

Code for the individual sensors in also maintained in separate Google code projects. (will be moved to Github soon) (http://code.google.com/u/104098523773938750140/)

## Other Sharp distance sensors:

Currently this library only supports the sensors mentioned above.
If you want to use other distance sensors with this libraries you can do that by adding the appropriate source files.
Have a look at the class diagram below to get an idea of the structure.

Adding an other analog Sharp sensor would mean copy/pasting some of the existing (.cpp & .h) files and changing some parameters in the calculation in the function "getDistanceCentimeter".
You can either derive the parameters from your datasheet or perform a linear regression on experimental data using (1/distance on the X-axis!)

Feel free to fork this project & send me a pull request if you have some correctly working code.

## Folders:
 * DistanceSensor: source for the Arduino library
 * Documentation: generated with Doxygen (html, Latex)

## Datasheets:
Analog IR Distance sensors:
 *  [Sharp gp2y0a21yk](https://github.com/jeroendoggen/arduino-distance-sensor-library/raw/master/Documentation/datasheets/Distance_IR_Analog_Sharp_gp2y0a21yk_new.pdf)
 *  [Sharp gp2y0a41sk0f](https://github.com/jeroendoggen/arduino-distance-sensor-library/raw/master/Documentation/datasheets/Distance_IR_Analog_Sharp_gp2y0a41sk0f.pdf)

Ultrasonic sensors:
 *  [SRF-04](https://github.com/jeroendoggen/arduino-distance-sensor-library/raw/master/Documentation/datasheets/Distance_Ultrasonic_srf04.pdf)

  
## Class diagram:
![Class diagram](https://raw.github.com/jeroendoggen/arduino-distance-sensor-library/master/Documentation/html/class_distance_sensor__inherit__graph.png)
