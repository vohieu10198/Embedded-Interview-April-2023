#include <stdio.h>
#include <iostream>

using namespace std;

class PersonalInformation{
    private:
    string _name;
    int _age;
    string _address;
    public:
    PersonalInformation(string name, int age, string address);
    string getName();
    int getAge();
    string getAddress();
    void printPersonalInformation();
};

PersonalInformation::PersonalInformation(string name, int age, string address){
    PersonalInformation::_name = name;
    PersonalInformation::_age = age;
    PersonalInformation::_address = address;
}

string PersonalInformation::getName(){
    return this->_name;
}

int PersonalInformation::getAge(){
    return this->_age;
}

string PersonalInformation::getAddress(){
    return this->_address;
}

void PersonalInformation::printPersonalInformation(){
    cout << "Name: " << _name << endl;
    cout << "Age: " << _age << endl;
    cout << "Address: " << _address << endl;
}

int main(int argc, char const *argv[])
{
    PersonalInformation info("Hieu", 25, "Dang Van Ngu, Phu Nhuan");
    info.printPersonalInformation();
    return 0;
}
