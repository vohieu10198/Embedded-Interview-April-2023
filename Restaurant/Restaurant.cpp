/*
* File: Restaurant.cpp
* Author: VO MINH HIEU
* Date: 29/05/2023
* Description: This is file for restaurant management
*/

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

typedef enum{
    available,
    booked,
}checkStatus;

class Manager{
    private:
    int _beverage_id;
    string _beverage_name;
    int _beverage_price;
    int _remained_amount;
    public:
    Manager(string name, int price, int amount);
    void listCommand();
    
    int getBeverageID();
    
    string getBeverageName();
    void setBeverageName(string name);
    
    int getBeveragePrice();
    void setBeveragePrice(int price);
    
    int getAmount();
    void setAmount(int amount);
  
    void addNewBeverage();
    void editMenu();
    void deleteMenu();
    void beverageMenu();
    
};

Manager::Manager(string name, int price, int amount){
    static int id = 1;
    Manager::_beverage_id = id;
    id++;
    Manager::_beverage_name = name;
    Manager::_beverage_price = price;
    Manager::_remained_amount = amount;
}

/*
* Class: Manager
* Function: getBeverageID
* Description: This function use for get ID of a beverage
* Input:
*   None
* Output:
*   return: id of beverage
*/

int Manager::getBeverageID(){
    return this->_beverage_id;
}

/*
* Class: Manager
* Function: getBeverageName
* Description: This function use for getting name of a beverage
* Input:
*   None
* Output:
*   return: name of beverage
*/

string Manager::getBeverageName(){
    return this->_beverage_name;
}

/*
* Class: Manager
* Function: setBeverageName
* Description: This function use for setting name of a beverage
* Input:
*   string: name
* Output:
*   return: none
*/

void Manager::setBeverageName(string name){
    Manager::_beverage_name = name;
}

/*
* Class: Manager
* Function: getBeveragePrice
* Description: This function use for getting price of a beverage
* Input:
*   None
* Output:
*   return: price of a beverage
*/


int Manager::getBeveragePrice(){
    return this->_beverage_price;
}

/*
* Class: Manager
* Function: setBeveragePrice
* Description: This function use for setting price of a beverage
* Input:
*   int : price
* Output:
*   return: none
*/

void Manager::setBeveragePrice(int price){
    Manager::_beverage_price = price;
}

/*
* Class: Manager
* Function: getAmount
* Description: This function use for getting amount of a beverage
* Input:
*   None
* Output:
*   return: amount of beverage
*/

int Manager::getAmount(){
    return this->_remained_amount;
}

/*
* Class: Manager
* Function: setAmount
* Description: This function use for setting amount of a beverage
* Input:
*   int: amount
* Output:
*   return: none
*/

void Manager::setAmount(int amount){
    Manager::_remained_amount = amount;
}

/*
* Class: listCommand
* Function: getBeverageID
* Description: This function use for listing command to execute with mananger role
* Input:
*   None
* Output:
*   return: none
*/

void Manager::listCommand(){
    cout << "1. ADDING NEW BEVERAGE " << endl;
    cout << "2. EDIT BEVERAGE " << endl;
    cout << "3. DELETE BEVERAGE " << endl;
    cout << "4. LIST OF BEVERAGE " << endl;
    cout << "0. BACK " << endl;
    cout << "ENTER:  " << endl;


}

class Order{
    private:
    int _id;
    int _amount;
    public:
    Order(int id, int amount);
    string getOrderName();
    void setOrderName(string name);
    int getOrderAmount();
    void setOrderAmount(int amount);
    void listCommand();
    void takeOrder();
    void editOrder();
    void showCustomerOrder();
    void payment();

};

Order::Order(int id, int amount){
    Order::_id = id;
    Order::_amount = amount;
}


int main(int argc, char const *argv[])
{
    Manager mn("Pepsi", 10000, 1000);
    mn.listCommand();
    return 0;
}
