/****************************************
 * 				turbidity.h
 *
 *  class definition for the turbidity sensor
 *
 ***************************************/
#ifndef TURBIDITY_H
#include "module.h"


class Turbidity: public Module{

protected :

	uint8_t _digitalPin;
	uint8_t _analogPin;
	int _digPinmode;//mode of the digital pin sensor

public :

	// Constructors
	Turbidity();
	//Turbidity(int dpin, int apin);
	//Turbidity(int dpin, int apin, int mode);
	// Destructor
	~Turbidity(){};
	// Methods
	void setAnalogPin(uint8_t apin);
	void setDigitalPin(uint8_t dpin, int mode);
	uint8_t getAnalogPin();
	uint8_t getDigitalPin();
	int getAnalogValue();
	int getDigitalValue();
	float getVoltage();

};

#define TURBIDITY_H_H
#endif
