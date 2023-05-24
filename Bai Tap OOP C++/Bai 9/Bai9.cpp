#include <stdio.h>
#include <math.h>
#include <iostream>
#include <string>

using namespace std;

class car{
    private:
    string _color;
    string _engine_type;
    double _kilometer;
    public:
    car(string color, string engine, double km);
    string getColor();
    string getEngineType();
    double getKilometer();

};

int main(int argc, char const *argv[])
{
    
    return 0;
}
