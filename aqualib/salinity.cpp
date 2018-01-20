#include "salinity.h"

Salinity::Salinity(int pin):Module(){
	_pin=pin;
	pinMode(pin, INPUT);
	type=SENSOR;
}

void Salinity::setPin(int pin){
	_pin=pin;
}
int Salinity::getValue(){
	// TO DO
	//analogReference(DEFAULT); //5V
	//analogRead(pin);
	return 0;
}