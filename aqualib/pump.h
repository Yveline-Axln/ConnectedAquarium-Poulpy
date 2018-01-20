/****************************************
 * 				pump.h
 * 
 *  class definition for the air pump 
 *
 ***************************************/
#ifndef PUMP_H
#include "module.h"

class Pump: public Module{

protected :

	int _pin;

public :

	// Constructors
	Pump(int pin);
	// Destructor
	~Pump(){};
	// Methods
	void setPin(int pin);
	void setSpeed(int speed);
	void start();
	void stop();

};
#define PUMP_H
#endif