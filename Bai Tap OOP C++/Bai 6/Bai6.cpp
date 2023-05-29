/*
* File Name: Bai6.cpp
* Author: Vo Minh Hieu
* Date: 28/05/2023
* Description: Create a class to calculate maths between two fractions
*/


#include <stdio.h>
#include <math.h>

class fraction{
    private:
    int _numerator;
    int _denominator;
    public:
    fraction(int numerator = 0, int denominator = 0);
    double getFraction();
   
};

fraction::fraction(int numerator, int denominator){

    fraction::_numerator = numerator;
    fraction::_denominator = denominator;
}

/*
* Class: fraction
* Function: getFraction
* Description: This function use for getting fraction
* Input: 
*   None
* Output:
*   return: fraction
*/

double fraction::getFraction(){
    return (double)fraction::_numerator/(double)fraction::_denominator;
}

class math{
    private:
    fraction fraction1;
    fraction fraction2;
    public:
    math(fraction fr1, fraction fr2);
    double addTwoFraction();
    double subTwoFraction();
    double mulTwoFraction();
    double didTwoFraction();

};


math::math(fraction fr1, fraction fr2){
    math::fraction1 = fr1;
    math::fraction2 = fr2;
}

/*
* Class: math
* Function: addTwoFraction
* Description: This function use for perform additon between 2 fractions
* Input: 
*   None
* Output:
*   return: None
*/

double math::addTwoFraction(){
    return fraction1.getFraction() + fraction2.getFraction();
}

/*
* Class: math
* Function: addTwoFraction
* Description: This function use for perform Subtraction between 2 fractions
* Input: 
*   None
* Output:
*   return: None
*/

double math::subTwoFraction(){
    return fraction1.getFraction() - fraction2.getFraction();
}

/*
* Class: math
* Function: addTwoFraction
* Description: This function use for perform Multiplication between 2 fractions
* Input: 
*   None
* Output:
*   return: None
*/

double math::mulTwoFraction(){
    return fraction1.getFraction() * fraction2.getFraction();
}

/*
* Class: math
* Function: addTwoFraction
* Description: This function use for perform Division between 2 fractions
* Input: 
*   None
* Output:
*   return: None
*/


double math::didTwoFraction(){
    return fraction1.getFraction() / fraction2.getFraction();
}



int main(int argc, char const *argv[])
{
    printf("Addition = %.2f\n", math(fraction(1,2), fraction(3,4)).addTwoFraction());
    printf("Subtraction = %.2f\n", math(fraction(1,2), fraction(3,4)).subTwoFraction());
    printf("Multiplication = %.2f\n", math(fraction(1,2), fraction(3,4)).mulTwoFraction());
    printf("Division = %.2f\n", math(fraction(1,2), fraction(3,4)).didTwoFraction());
    
    return 0;
}
