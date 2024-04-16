#include <iostream>
#include <time.h>

#include "LM35.h"
#include "HRSR04.h"

#define TEMP_MAX 24
#define TEMP_MIN 18
#define DISTANCE_MAX 500

using namespace std;

int main(){
    srand(time(NULL));

    //Array for temp sensors
    LM35 TempSenors[4] = {LM35(0 ,0 ,0), LM35(0 ,0 ,0), LM35(0 ,0 ,0), LM35(0 ,0 ,0)};

    //Array for Ultra Sonic Sensors. There is 2 per room. I have an array for each zone.
    HRSR04 UltraSonicSensors[4][2];



    //User Menu Start
    cout << "Greenhouse information panel. Please Select an option:" << endl;
    cout << "\t[1] Normal\n\t[2] Test\n\t[3] Exit" << endl;

    int user_option = 0;
    cout << "Your option: ";
    cin >> user_option;

    switch (user_option){
        case 1:

            for (int i = 0; i != 4; i++){
                //Generate and calculate all data for all sensors
                cout << TempSenors[i].analogRead() << endl;

                TempSenors[i].updateTemp();

                for (int x = 0; x != 2; x++){
                    UltraSonicSensors[i][x].analogRead();
                    UltraSonicSensors[i][x].calcDistance();
                }
            }

            break;
        case 2:

            break;
        case 3:
            return 0;
        default:
            cout << "Not an option!" << endl;
            return 0;
    }
    //User Menu End


    //Printing of zone Data Start
    for (int i = 0; i != 4; i++){
        cout << "Zone " << i+1 << ":" << endl;
        cout << "\tCurrent Temperatue: " << TempSenors[i].getTemp() << "\xC2\xB0 C" << endl;
        cout << "\tPerson in room: ";
        cout << UltraSonicSensors[i][0].getDistance() << " ";

        if (UltraSonicSensors[i][0].getDistance() < DISTANCE_MAX || UltraSonicSensors[i][1].getDistance() < DISTANCE_MAX) {
            cout << "True" << endl;
        } else {
            cout << "False" << endl;
        }
    }
    //Printing of zone Data End


}



