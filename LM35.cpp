#include "LM35.h"

#include <iostream>
#include <stdlib.h>

//Default Constructor
LM35::LM35(){
    temperature = 0;
    voltage = 0;
    adcData = 0;
}


//Test constructor
LM35::LM35(float initial_temp, float initial_volts, int initial_adcData){
    temperature = initial_temp;
    voltage = initial_volts;
    adcData = initial_adcData;
}

//Generate the adcData
int LM35::analogRead(){
    adcData = rand() % 100 + 30 ;
    return adcData;
}

//calculate the temperature and voltage
void LM35::updateTemp(){
    voltage = (float)adcData * 5000/1023;
    temperature = voltage / 10;
}

//return the temperature
int LM35::getTemp(){
    return temperature;
}




