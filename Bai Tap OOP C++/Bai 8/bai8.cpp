#include <stdio.h>
#include <math.h>
#include <iostream>
#include <string>

using namespace std;

class bankaccount{
    private:
    int _account_number;
    string _name;
    double _balance;
    public:
    bankaccount(int number, string name, double balance);
    getAccountNumber();
    getAccountName();
    getBalance();
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
