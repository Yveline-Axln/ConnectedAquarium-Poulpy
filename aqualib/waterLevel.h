/************************************************
 * 				waterLevel.h
 *
 *  class definition for the water Level sensor
 *
 **********************************************/
#ifndef waterLevel_H
#include "module.h"


class waterLevel: public Module{

protected :

	//int _pin;
	int _mode;//mode of the sensor pin

public :

	// Constructors
	waterLevel(uint8_t pin);
	waterLevel(uint8_t pin, int mode);
	// Destructor
	~waterLevel(){};
	// Methods
	void setPin(uint8_t pin);
	uint8_t getPin();
	int getState();

};

#define waterLevel_H
#endif
