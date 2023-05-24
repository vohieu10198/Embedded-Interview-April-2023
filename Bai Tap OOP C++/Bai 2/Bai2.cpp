#include <stdio.h>
#include <stdint.h>
#include <math.h>

class Rectangle{
    private:
    double _length;
    double _width;
    public:
    Rectangle(double length, double width);
    double getLength();
    double getWidth();
    double getArea();
    double getPerimeter();
    double getDiagonalLine();
    typedef enum Format{
        NOT_CORRECT = 0,
        CORRECT
    }Format;
    Format format;
    void checkSquare();
};

Rectangle::Rectangle(double length, double width){
    if(length <= 0 || width <=0){
        printf("Error, Re-Enter the value greater than 0\n");
        format = NOT_CORRECT;
        return;
    }
    Rectangle::_length = length;
    Rectangle::_width = width;
}

double Rectangle::getLength(){
    if(format == NOT_CORRECT){
        printf("Error, Re-Enter the value greater than 0\n");
        format = NOT_CORRECT;
        return -1;
    }
    return this->_length;
}

double Rectangle::getWidth(){
    if(format == NOT_CORRECT){
        printf("Error, Re-Enter the value greater than 0\n");
        format = NOT_CORRECT;
        return -1;
    }
    return this->_width;
}

double Rectangle::getArea(){
 if(format == NOT_CORRECT){
        printf("Error, Re-Enter the value greater than 0\n");
        format = NOT_CORRECT;
        return -1;
    }
    return (double)(_length*_width);
}
double Rectangle::getPerimeter(){
    if(format == NOT_CORRECT){
        printf("Error, Re-Enter the value greater than 0\n");
        format = NOT_CORRECT;
        return -1;
    }
    return (double)((_length+_width)*2);
}

double Rectangle::getDiagonalLine(){
    if(format == NOT_CORRECT){
        printf("Error, Re-Enter the value greater than 0\n");
        format = NOT_CORRECT;
        return -1;
    }
    return (double)sqrt((_length*_length)+(_width*_width));
}

void Rectangle::checkSquare(){
    if (format == NOT_CORRECT){
        printf("Error, Re-Enter the value greater than 0\n");
        return;
    }
    if(_length == _width){
        printf("This is a square\n");
    }
    else{
        printf("This is not a square\n");
    }
}

int main(int argc, char const *argv[])
{
    Rectangle rectangle(2,3);
    Rectangle rectangle2(3,3);

    printf("Area of rectangle: %.4lf\n", rectangle.getArea());
    printf("Perimeter of rectangle: %.4lf\n", rectangle.getPerimeter());
    printf("Diagonal line of rectangle: %.4lf\n", rectangle.getDiagonalLine());
    rectangle.checkSquare();

    printf("Area of rectangle: %.4lf\n", rectangle2.getArea());
    printf("Perimeter of rectangle: %.4lf\n", rectangle2.getPerimeter());
    printf("Diagonal line of rectangle: %.4lf\n", rectangle2.getDiagonalLine());
    rectangle2.checkSquare();
    
    return 0;
}
