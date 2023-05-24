/*
* File: bai1.cpp
* Author: VO MINH HIEU
* Date: 23/05/2023
* Description: Tinh khoang cach va dien tich tam giac trong he toa do Oxy
*/

#include <stdio.h>
#include <stdint.h>
#include <math.h>

using namespace std;

class Diem{
    private:
    int8_t OX;
    int8_t OY;
    public:
    Diem(int8_t ox = 0, int8_t oy = 0);
    int8_t getToaDoX();
    int8_t getToaDoY();
    double khoangCanh();
    double dienTich();
};

Diem::Diem(int8_t ox, int8_t oy){
    Diem::OX = ox;
    Diem::OY = oy;
}


int8_t Diem::getToaDoX(){
    return Diem::OX;
}

int8_t Diem::getToaDoY(){
    return Diem::OY;
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
