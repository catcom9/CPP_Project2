class LM35 {
private:
    float temperature;
    float voltage;
    int adcData;

public:
    LM35();
    LM35(float, float, int);
    int analogRead();
    void updateTemp();
    int getTemp();
    void currentStatus();
};
