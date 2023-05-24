#include <stdio.h>
#include <math.h>
#include <iostream>

#define currentYear 2023

class date{
    private:
    int _day;
    int _month;
    int _year;
    public:
    date(int day, int month, int year);
    int getDay();
    int getMonth();
    int getYear();
    int calculateAge();
};
date::date(int day, int month, int year){
    date::_day = day;
    date::_month = month;
    date::_year = year;
}

int date::getDay(){
    return this->_day;
}

int date::getMonth(){
    return this->_month;
}

int date::getYear(){

    return this->_year;
}

int date::calculateAge(){
    int age = currentYear - date::_year;
    printf("Your age is: %d year(s) old!\n", age);
    return 0;
}

int main(int argc, char const *argv[])
{
    date date1(1,1,1998);
    date1.calculateAge();
    
    return 0;
}
