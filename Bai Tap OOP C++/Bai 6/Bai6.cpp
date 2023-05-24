#include <stdio.h>
#include <math.h>
#include <iostream>

class fraction{
    private:
    int _numerator;
    int _denominator;
    public:
    fraction(int numerator, int denominator);
    int getNumerator();
    int getDenominator();
    double addTwoFraction();
    double subTwoFraction();
    double mulTwoFraction();
    double didTwoFraction();
};

fraction::fraction(int numerator, int denominator){
    fraction::_numerator = numerator;
    fraction::_denominator = denominator;
}

int fraction::getNumerator(){
    return this->_numerator;
}

int fraction::getDenominator(){
    return this->_denominator;
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
