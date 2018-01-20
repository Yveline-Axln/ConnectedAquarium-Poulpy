// this is taken from OneWire library
#if ARDUINO >= 100
#include "Arduino.h"       // for delayMicroseconds, digitalPinToBitMask, etc
#else
#include "WProgram.h"      // for delayMicroseconds
#include "pins_arduino.h"  // for digitalPinToBitMask, etc
#endif
#include <OneWire.h>
#include <DallasTemperature.h>
#include "temperature.h"

//** Constructor **//
Temperature::Temperature(uint8_t pin):Module(pin),_oneWire(pin),_sensor(&_oneWire)
{
//_pin(pin)

//	_pin(pin): Data wire is plugged into port "pin" on the Arduino
//	_oneWire(pin): Data wire is plugged into port "pin" on the Arduino
//	_sensor(&_oneWire): Pass our oneWire reference to Dallas Temperature.

	_sensor.begin();// Start up the library

}
void Temperature::begin()
    {
    _sensor.begin();
    }

uint8_t Temperature::getPin(){
    return _pin;
}

float Temperature::getTempCel(){
	 _sensor.requestTemperatures();// Send the command to get temperatures
   // float temp = _sensor.getTempCByIndex(0);
    return _sensor.getTempCByIndex(0);
}

float Temperature::getTempFah()
    {
    _sensor.requestTemperatures();// Send the command to get temperatures
   // float temp = _sensor.getTempFByIndex(0);
    return _sensor.getTempFByIndex(0);;
    }
