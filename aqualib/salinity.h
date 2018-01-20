/****************************************
 * 				salinity.h
 * 
 *  class definition for the home-made salinity sensor
 *
 ***************************************/
#ifndef SALINITY_H
#include "module.h"

class Salinity: public Module{

protected :

	int _pin;

public :

	// Constructors
	Salinity(int pin);
	// Destructor
	~Salinity(){};
	// Methods
	void setPin(int pin);
	int getValue();

};

#define TURBIDITY_H_H
#endif