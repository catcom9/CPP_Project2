class LM35 {
private:
    float temperature;
    float voltage;
    int adcData;
    int zone;

public:
    LM35();
    LM35(int);
    LM35(float, float, int, int);
    int analogRead();
    void updateTemp();
    int getTemp();
    void currentStatus();
};
