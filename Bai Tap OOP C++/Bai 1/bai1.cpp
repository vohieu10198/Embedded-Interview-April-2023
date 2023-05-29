/*
* File Name: Bai1.cpp
* Author: Vo Minh Hieu
* Date: 28/05/2023
* Description: Create a point in 2D coordinates systme. Calculate the distance between 2 points.Calculate the area of triangle created by 3 points
*/

#include <stdio.h>
#include <math.h>

/*
 * Function: Class Point
 * Description: Class get the data of a point
 * Input:
 *    None
 * Output:
 *    None
*/
class Point{
    private:
        int X;
        int Y;
    public:
        Point(int X = 0, int Y = 0);
        int getX();
        int getY();
};

/*
* Constructor: Point
* Description: get data into point
* Input:
*   x - int
*   y - int
* Output:
*   None
*/
Point::Point(int x, int y){
    Point::X = x;
    Point::Y = y;
}

int Point::getX(){
    return Point::X;
}

int Point::getY(){
    return Point::Y;
}

/*
 * Function: Class Data
 * Description: Class calculate the area of triangle and distance between 2 poinnts
 * Input:
 *    None
 * Output:
 *    None
*/
class Data{
    private:
        Point A;
        Point B;
        Point C;
    public:
        Data(Point a, Point b, Point c);
        Data(Point a, Point b);
        void calDistance();
        void calArea();
};

typedef enum{
        Distance,
        Area
    }math;

    math Check;
    
/*
* Constructor: Data
* Description: get input data
* Input:
*   x - int
*   y - int
*   z - int
* Output:
*   None
*/
Data::Data(Point a, Point b){
    Data::A = a;
    Data::B = b;
    Check = Distance;
}

Data::Data(Point a, Point b, Point c){
    Data::A = a;
    Data::B = b;
    Data::C = c;
    Check = Area;
}

/*
* Function: calDistance()
* Description: calculate the length between 2 points
* Input:
*   None
* Output:
*   print the result
*/
void Data::calDistance(){
    if ( Check == Distance){
        double Distance = (double)sqrt((A.getX()-B.getX())*(A.getX()-B.getX()) + (A.getY() - B.getY()) * (A.getY() - B.getY()));
        printf("Distance: %.2f cm\n",Distance);
    }
    else 
        printf("Calculate distance between 2 points is not available \n");
}

/*
* Function: calArea()
* Description: calculate the area of triangle
* Input:
*   None
* Output:
*   print the result
*/
void Data::calArea(){
    if ( Check == Area){
        double Area = (double)abs((B.getX() - A.getX()) * (C.getY() - A.getY()) - (C.getX() -A.getX()) * (B.getY() - A.getY())) / (double)2;
        printf("Area: %.2f cm2\n",Area);
    }
    else 
        printf("Calculate area of triangle is not avaibale\n");
}


int main(){

    Data point1(Point(3,2), Point(2,5));
    Data point2(Point(3,2), Point(2,5), Point(-2,-1));

    point1.calDistance();
    point1.calArea();

    printf("\n--------------------------------------------------------------------------------------------------\n");

    point2.calDistance();
    point2.calArea();
}
