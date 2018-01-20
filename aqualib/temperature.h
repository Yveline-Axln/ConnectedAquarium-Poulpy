/****************************************
 * 				temperature.h
 *
 *  class definition for the temperature sensor
 *
 ***************************************/
#ifndef TEMPERATURE_H
#define TEMPERATURE_H

// this is taken from OneWire library
#if ARDUINO >= 100
#include "Arduino.h"       // for delayMicroseconds, digitalPinToBitMask, etc
#else
#include "WProgram.h"      // for delayMicroseconds
#include "pins_arduino.h"  // for digitalPinToBitMask, etc
#endif

#include "module.h"
#include <inttypes.h>
#include <OneWire.h>
#include <DallasTemperature.h>

class Temperature: public Module{

//class Temperature{

public :

	// Constructors
	Temperature(uint8_t pin);// takes a byte pin number where the temperature sensor is connected
	// Destructor
	~Temperature(){};
	// Methods
	void  begin();
	uint8_t getPin();
	float getTempCel(); //get the temperature in celsius
	float getTempFah();//get the temperature in fahrenheit


protected:

	//uint8_t _pin;
    OneWire _oneWire;//An instance of the oneWire bus for the sensor.
    DallasTemperature _sensor; //An instance of DallasTemperature for the sensor.

};


#endif
