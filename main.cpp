#include <iostream>

#include "LM35.h"
#include "HRSR04.h"

#define TEMP_MAX 24
#define TEMP_MIN 18
#define DISTANCE_MAX 5

using namespace std;

int main(){
    //Array for temp sensors
    LM35 TempSenors[4] = {LM35(1), LM35(2), LM35(3), LM35(4)};

    //Array for Ultra Sonic Sensors. There is 2 per room. I have an array for each zone.
    HRSR04 UltraSonicSensors[4][2] = {{HRSR04(1), HRSR04(1)}, {HRSR04(2), HRSR04(2)}, {HRSR04(2), HRSR04(2)}, {HRSR04(2), HRSR04(2)}};


    for (int i = 0; i != 4; i++){
        //Generate and calculate all data for all sensors
        cout << TempSenors[i].analogRead() << endl;
        TempSenors[i].updateTemp();
        for (int x = 0; x != 2; x++){
            UltraSonicSensors[i][x].analogRead();
            UltraSonicSensors[i][x].calcDistance();
        }


        cout << "Zone " << i+1 << ":" << endl;
        cout << "\tCurrent Temperatue: " << TempSenors[i].getTemp() << "\xC2\xB0 C" << endl;
        cout << "\tPerson in room: ";
        if (UltraSonicSensors[i][0].getDistance() < DISTANCE_MAX || UltraSonicSensors[i][1].getDistance() < DISTANCE_MAX) {
            cout << "True" << endl;
        } else {
            cout << "False" << endl;
        }
    }



}
