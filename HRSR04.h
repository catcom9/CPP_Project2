class HRSR04 {
private:
    float distance;
    int duration;
    int zone;


public:
    HRSR04();
    HRSR04(int);
    HRSR04(int, float, int);

    int getDistance();
    int analogRead();
    void calcDistance();

};
