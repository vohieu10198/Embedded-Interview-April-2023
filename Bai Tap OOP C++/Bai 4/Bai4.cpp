#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <string>
#include <iostream>

using namespace std;

class animal{
    private:
    string _name;
    int8_t _age;
    int8_t _weight;
    double _height;
    public:
    animal(string name, int8_t age, int8_t weight, double height);
    string getName();
    double getAge();
    double getWeight();
    double getHeight();
    double getBMI();
    void ageComparision();
    void weightComparision();
};

animal::animal(string name, int8_t age, int8_t weight, double height){
    animal::_name = name;
    animal::_age = age;
    animal::_weight = weight;
    animal::_height = height;
}

string animal::getName(){
    return this->_name;
}

double animal::getAge(){
    return this->_age;
}

double animal::getWeight(){
    return this->_weight;
}
double animal::getHeight(){
    return this->_height;
}

double animal::getBMI(){
    return (double)(_weight/(_height*_height));
}

int main(int argc, char const *argv[])
{
    animal people("Embedded Interview April 2023", 25, 80, 1.75);

    cout <<"Name: " << people.getName() << endl;
    printf("Age: %.2lf year(s) old\n", people.getAge());
    printf("Weight: %.2lfKg\n", people.getWeight());
    printf("Height: %.2lfm\n", people.getHeight());
    printf("BMI: %.2lf\n", people.getBMI());


    return 0;
}
