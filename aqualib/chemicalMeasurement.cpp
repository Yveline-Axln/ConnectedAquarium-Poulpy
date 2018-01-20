#include "chemicalMeasurement.h"

chemicalMeasurement::chemicalMeasurement()
{
    _pH=0.0;
    _nitrite=0.0;
    _nitrate=0.0;
    _waterHardness=0.0;
}


void chemicalMeasurement::setPH(float ph){
    _pH=ph;
}

float chemicalMeasurement::getPH(){
    return _pH;
}

void chemicalMeasurement::setNitrite(float nitrite){
    _nitrite=nitrite;
}

float chemicalMeasurement::getNitrite(){
    return _nitrite;
}

void chemicalMeasurement::setNitrate(float nitrate){
    _nitrate=nitrate;
}

float chemicalMeasurement::getNitrate(){
    return _nitrate;
}

void chemicalMeasurement::setWaterHardness(float waterHardness){
    _waterHardness= waterHardness;
 }

float chemicalMeasurement::getWaterHardness(){
    return _waterHardness;
}

chemicalMeasurement::~chemicalMeasurement()
{
}
