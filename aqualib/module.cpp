#include "module.h"

int Module::nb_module=0;

Module::Module(){
	nb_module++;
}

Module::Module(uint8_t pin):_pin(pin){
	nb_module++;
}

