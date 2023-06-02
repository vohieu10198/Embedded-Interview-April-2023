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

#define INPUT_INFORMATION(information, format, content, condition)\
    do{                                                         \
        cout << information;                                       \
        cin >> format;                               \
        cin >> content;                             \
    }while(condition);  


class Beverage{
    private:
    uint8_t _id;
    string _name;
    double _price;
    public:
    Beverage(string name, double price);
    string getName();
    void setName(string name);
    double getPrice();
    void setPrice(double price);
    uint8_t getID();
};

Beverage::Beverage(string name, double price){
    Beverage::_name = name;
    Beverage::_price = price;
}

/*
 * Class: Beverage
 * Function: getName
 * Description: use to get name of beverage
 * Input:
 *    none
 * Output:
 *    return: name of beverage
*/

string Beverage::getName(){
    return this->_name;
}

/*
 * Class: Beverage
 * Function: setName
 * Description: use to get name of beverage
 * Input:
 *    string: name
 * Output:
 *    return: none
*/
void Beverage::setName(string name){
    Beverage::_name = name;
}

/*
 * Class: Beverage
 * Function: getPrice
 * Description: use to get price of beverage
 * Input:
 *    none
 * Output:
 *    return: price of beverage
*/

double Beverage::getPrice(){
    return this->_price;
}

/*
 * Class: Beverage
 * Function: setPrice
 * Description: use to set price of beverage
 * Input:
 *    double: name
 * Output:
 *    return: none
*/

void Beverage::setPrice(double price){
    Beverage::_price = price;
}

/*
 * Class: Beverage
 * Function: getID
 * Description: use to get id of beverage
 * Input:
 *    none
 * Output:
 *    return: id
*/

uint8_t Beverage::getID(){
    static uint8_t id = 1;
    Beverage::_id =id;
    id++;
}

class Manager{
    private:
    vector<Beverage> databaseBeverage;
    void addNewBeverage();
    void editMenu();
    void deleteMenu();
    void beverageMenu();

    public:
    Manager();
    uint8_t getNumberOfTable();
    vector<Beverage> getDatabase();
    
};

uint8_t Manager::getNumberOfTable(){
    uint8_t numberTable = 0;

}

typedef struct{
    uint8_t NoTable;
    bool Status;
    vector<Order> databaseOrder;
}Table;

class Staff{
    private:
    vector<Table> DatabaseTable;
    vector<Beverage> databaseBaverage;
    void takeOrder();
    void editOrder();
    void deleteOrder();
    void addOrder();
    void payment();
    public:
    Staff(vector<Beverage> databaseBaverage, uint8_t numberOfTable);
};

struct{
    Beverage name;
    uint8_t amount;
}Order;



Staff::Staff(vector<Beverage> databaseBaverage, uint8_t numberOfTable){
    for(Beverage beverage : databaseBaverage){
        databaseBaverage.push_back(beverage);
    }
    for (uint8_t i = 1; i <= numberOfTable; i++){
        Table _table;
        _table.numberOfTable = i;


    }
}
void Staff::takeOrder(){
    string orderName;
    uint8_t orderAmount;
    std::cout << "Name of beverage" << endl;
    std::cin >> orderName;
    Order.name =  orderName;
    std::cout << "Amount of beverage: " << endl;
    std::cin >> orderAmount;
    Order.amount = orderAmount;
}
