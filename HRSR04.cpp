#include "HRSR04.h"
#include <stdlib.h>

using namespace std;

//Default Constructor
HRSR04::HRSR04(){
    distance = 0;
    duration = 0;
}

//Test Constructor
HRSR04::HRSR04(float new_distance, float new_duration){
    distance = new_distance;
    duration = new_duration;
}


//Generate duration value
int HRSR04::analogRead(){
    duration = rand() % 30 + 300;
    return duration;
}

//Calculte the distance
void HRSR04::calcDistance(){
    distance = ((float)duration / 2) * 0.0343;
}

int HRSR04::getDistance(){
    return distance;
}




