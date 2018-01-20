#include "waterLevel.h"

//** Constructors **//
waterLevel::waterLevel(uint8_t pin):Module(pin){
	//_pin=pin;
	type=SENSOR;
	//_pullup=0;
	pinMode(pin, INPUT);
}
waterLevel::waterLevel(uint8_t pin, int mode):Module(pin){
	//_pin=pin;
	_mode = mode;
	type=SENSOR;
	pinMode(pin,mode);
}

void waterLevel::setPin(uint8_t pin){
	_pin=pin;
}

uint8_t waterLevel::getPin(void){
	return _pin;
}

int waterLevel:: getState(void){
	return digitalRead(_pin);
}
