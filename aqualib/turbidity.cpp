#include "turbidity.h"

// SEE 	https://www.dfrobot.com/wiki/index.php/Turbidity_sensor_SKU:_SEN0189
//		https://fr.wikipedia.org/wiki/Turbidit%C3%A9

//** Constructor **//
Turbidity::Turbidity():Module(){
	type=SENSOR;
}

//Turbidity::Turbidity(uint8_t dpin, int apin):Module(){
//	_digitalPin=dpin;
//	_analogPin=apin;
//	pinMode(dpin, INPUT);
//	type=SENSOR;
//}
//
//Turbidity::Turbidity(uint8_t dpin, uint8_t apin, int pullup):Module(){
//	_digitalPin=dpin;
//	_analogPin=apin;
//	pinMode(dpin, INPUT_PULLUP);
//	type=SENSOR;
//}

void Turbidity::setAnalogPin(uint8_t apin){
	_analogPin=apin;
}

void Turbidity::setDigitalPin(uint8_t dpin, int mode){
    _digPinmode=mode;
    pinMode(dpin,mode);
	_digitalPin=dpin;
}

uint8_t Turbidity::getAnalogPin(){
	return _analogPin;
}

uint8_t Turbidity::getDigitalPin(){
	return _digitalPin;
}

int Turbidity::getAnalogValue(){
	return analogRead(_analogPin);
}

int Turbidity::getDigitalValue(){
	return digitalRead(_digitalPin);
}
//return the value in voltage
float Turbidity::getVoltage(){
    // read the input on analog pin 0:
    int sensorValue = analogRead(_analogPin);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
    float voltage = sensorValue * (5.0 / 1024.0);
	return voltage;
}
