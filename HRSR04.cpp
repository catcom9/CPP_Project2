#include "HRSR04.h"
#include <stdlib.h>
#include <time.h>

using namespace std;

//Default Constructor
HRSR04::HRSR04(){
    srand(time(NULL));
    distance = 0;
    duration = 0;
    zone = 0;
}

//Tell the sensor what zone its in.
HRSR04::HRSR04(int initial_zone){
    srand(time(NULL));
    zone = initial_zone;
}

//Test Constructor
HRSR04::HRSR04(int initial_zone, float new_distance, int new_duration){
    srand(time(NULL));
    zone = initial_zone;
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




