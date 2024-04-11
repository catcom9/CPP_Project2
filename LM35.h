class LM35 {
private:
    int temperature;
    int voltage;

public:
    LM35();
    LM35(int, int);
    int analogRead();
    int display();
};
