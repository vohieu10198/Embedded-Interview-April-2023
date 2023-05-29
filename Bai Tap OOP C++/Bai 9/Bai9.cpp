#include <stdio.h>
#include <math.h>
#include <iostream>
#include <string>

using namespace std;

class car{
    private:
    string _color;
    string _engine_type;
    int _kilometer;
    public:
    car(string color, string engine, int km);
    string getColor();
    string getEngine();
    int getKm();
    int cost();
    int odo();
    void exportInfo();  
};

car::car(string color, string engine, int km){
    car::_color = color;
    car::_engine_type = engine;
    car::_kilometer = km;
}

/*
* Class: Car
* Function: getColor
* Description: This function use for get color of car
* Input:
*   Dont None
* Output:
*   return: color of car
*/

string car::getColor(){
    return this->_color;
}

/*
* Class: Car
* Function: getEngine
* Description: This function use for get engine type of car
* Input:
*   Dont None
* Output:
*   return: Engine of car
*/

string car::getEngine(){
    return this->_engine_type;
}

/*
* Class: Car
* Function: getKm
* Description: This function use for get Km of car
* Input:
*   Dont None
* Output:
*   return: Engine of car
*/

int car::getKm(){
    return this->_kilometer;
}

/*
* Class: Car
* Function: getKm
* Description: This function use for returning mantainance cost due to it odo
* Input:
*   Dont None
* Output:
*   return: Cost of maintainance
*/

int car::cost(){
    if(_kilometer < 10000) return (int)1000000;
    else if(_kilometer < 50000) return (int)3000000;
    else if(_kilometer < 100000) return (int)5000000;
    else return (int)10000000;
}

/*
* Class: Car
* Function: odo
* Description: This function use for get color of car
* Input:
*   Dont None
* Output:
*   return: odo of the car
*/

int car::odo(){
    return _kilometer;
}

/*
* Class: Car
* Function: odo
* Description: This function use for exporting information of the car
* Input:
*   Dont None
* Output:
*   return: None
*/

void car::exportInfo(){
    cout << "Car color: " << _color << endl;
    cout << "Engine: " << _engine_type << endl;
    cout << "Odo: " <<_kilometer << " km" <<endl;
    cout << "Mantainnace cost: " << car::cost() << " vnd" << endl;

}

int main(int argc, char const *argv[])
{
    car mycar("Black", "1.5 VTEC Turbo", 10000);
    mycar.exportInfo();
    return 0;
}
