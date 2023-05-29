#include <stdio.h>
#include <math.h>
#include <iostream>
#include <string>

using namespace std;

class book{
    private: 
    string _name;
    string _author;
    int _publish_year;
    int _amount;
    public:
    book(string name, string author, int year, int amount);
    string getName();
    string getAuthor();
    int getPublishYear();
    int getAmount();
    void bookinfo();
};

book::book(string name, string author, int year, int amount){
    book::_name = name;
    book::_author = author;
    book:: _publish_year = year;
    book::_amount = amount;
}

/*
* Class: book
* Function: getName
* Description: This function use for getting name of book
* Input:
*   None
* Output:
*   return: Name of book
*/

string book::getName(){
    return this->_name;
}

/*
* Class: book
* Function: getAuthor
* Description: This function use for getting Author of book
* Input:
*   None
* Output:
*   return: Author of book
*/

string book::getAuthor(){
    return this->_author;
}

/*
* Class: book
* Function: getPublishYear
* Description: This function use for getting Author of book
* Input:
*   None
* Output:
*   return: The published year of book
*/

int book::getPublishYear(){
    return this->_publish_year;
}

/*
* Class: book
* Function: getAmount
* Description: This function use for getting amount of book
* Input:
*   None
* Output:
*   return: amount of book
*/

int book::getAmount(){
    return this->_amount;
}
/*
* Class: book
* Function: getAmount
* Description: This function use for exporting information of book
* Input:
*   None
* Output:
*   return: all information of book
*/

void book::bookinfo(){
    cout << "Name: " << _name << endl;
    cout << "Author: " << _author << endl;
    cout << "Publised year: " << _publish_year << endl;
}



int main(int argc, char const *argv[])
{
    book mybook("C How to program", "Paul Deitel", 1992, 10);
    mybook.bookinfo();

    return 0;
}
