#include <stdio.h>
#include <math.h>
#include <iostream>
#include <string>

using namespace std;

class book{
    private: 
    string _name;
    string _author;
    int _publish_yeat;
    int _amount;
    public:
    book(string name, string author, int year, int amount);
    string getName();
    string getAuthor();
    int getPublishYear();
    int getAmount()
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
