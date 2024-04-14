class HRSR04 {
private:
    float distance;
    float duration;


public:
    HRSR04();
    HRSR04(float, float);

    int getDistance();
    int analogRead();
    void calcDistance();

};
