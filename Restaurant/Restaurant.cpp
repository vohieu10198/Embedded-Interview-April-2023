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
    available = 1,
    booked = 0,
}checkStatus;

typedef enum{
    BACK = 0,
    MANAGER = 1,
    STAFF = 2
}homePage;

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
    Order();
    int getOrderId();
    void setOrderId(int id);
    int getOrderAmount();
    void setOrderAmount(int amount);
    void listCommand();
    void takeOrder();
    void editOrder();
    void showCustomerOrder();
    void payment();

};

Order::Order(){

}

Order::Order(int id, int amount){
    Order::_id = id;
    Order::_amount = amount;
}

/*
* Class: Order
* Function: getOrderId
* Description: This function use for getting id of order
* Input:
*   None
* Output:
*   return: id
*/

int Order::getOrderId(){
    return this->_id;
}

/*
* Class: Order
* Function: setOrderId
* Description: This function use for setting id of order
* Input:
*   int: id
* Output:
*   return: none
*/

void Order::setOrderId(int id){
    Order::_id = id;
}

/*
* Class: Order
* Function: getOrderAmount
* Description: This function use for getting amount of beverage to take order 
* Input:
*   None
* Output:
*   return: amount
*/

int Order::getOrderAmount(){
    return this->_amount;
}

/*
* Class: Order
* Function: setOrderAmount
* Description: This function use for setting amount of beverage to take order 
* Input:
*   int: amount
* Output:
*   return: none
*/

void Order::setOrderAmount(int amount){
    Order::_amount = amount;
}



class Table{
    private:
    int _table_id;
    int _table_status;
    public:
    Table();
    Table(int id, int status);

    int getTableID();
    void setTableID(int id);

    int getTableStatus();
    void setTableStatus(int status);
};

Table::Table(){}

Table::Table(int id, int status){
    Table::_table_id = id;
    Table::_table_status = status;
}

/*
* Class: Table
* Function: getTableID
* Description: This function use for getting ID of Table 
* Input:
*   None
* Output:
*   return: table id
*/

int Table::getTableID(){
    return this->_table_id;
}

/*
* Class: Table
* Function: setTableID
* Description: This function use for setting ID of Table 
* Input:
*   int: id
* Output:
*   return: None
*/

void Table::setTableID(int id){
    Table::_table_id = id;
}

/*
* Class: Table
* Function: getTableStatus
* Description: This function use for getting ID of Table 
* Input:
*   None
* Output:
*   return: table status
*/

int Table::getTableStatus(){
    return this->_table_status;
}

/*
* Class: Table
* Function: setTableStatus
* Description: This function use for setting status of Table 
* Input:
*   int: status
* Output:
*   return: None
*/

void Table::setTableStatus(int status){
    Table::_table_status = status;
}


int main(int argc, char const *argv[])
{
    int command;

    while(1){
        

        switch (command)
        {
        case BACK: 
            return 0;
            break;

        case MANAGER:
            
            break;

        case STAFF:
    
            break;
        default:
            printf("ERROR!\n");
            break;
        }

        }
    return 0;
}
