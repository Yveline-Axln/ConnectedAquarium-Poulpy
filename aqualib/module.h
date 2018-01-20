/****************************************
 * 				module.h
 *
 ***************************************/

#ifndef MODULE_H_
#define MODULE_H_
#include <Arduino.h>

#define ACTUATOR	0
#define SENSOR		1

class Module{

protected:

	uint8_t _pin;

public:

	static int nb_module;
	int type;

    //Constructor
    Module();
	Module(uint8_t pin);
	//Destructor
	virtual ~Module(){};
};

#endif /* MODULE_H_ */
