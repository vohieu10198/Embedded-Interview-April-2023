#include <stdio.h>

#define PI 3.14
using namespace std;

class Circle{
    private:
    double _radius;
    public:
    typedef enum Format{
        NOT_CORRECT = 0,
        CORRECT
    }Format;
    Format format;
    Circle(double radius);
    double getRadius();
    double getArea();
    double getPerimeter();
};

Circle::Circle(double radius){
    if(radius <= 0){
        printf("Error, Re-Enter radius greater than 0\n");
        format = NOT_CORRECT;
        return;
    }
    this->_radius = radius;
}

double Circle::getRadius(){
    if(format == NOT_CORRECT){
        printf("Error, Re-Enter radius greater than 0\n");
        return -1;
    }
    return this->_radius;
}

double Circle::getArea(){
    if(format == NOT_CORRECT){
        printf("Error, Re-Enter radius greater than 0\n");
        return -1;
    }
    return _radius*PI*_radius;
}

double Circle::getPerimeter(){
    if(format == NOT_CORRECT){
        printf("Error, Re-Enter radius greater than 0\n");
        return -1;
    }
    return (2*_radius*PI);
}

int main(int argc, char const *argv[])
{
    Circle circle(3);

    printf("Radius of circle is: %.4lf\n", circle.getRadius());
    printf("Area of circle is: %.4lf\n", circle.getArea());
    printf("Perimeter of circle is: %.4lf\n", circle.getPerimeter());

    return 0;
}
