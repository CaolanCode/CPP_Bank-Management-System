/*
    Bank Management System
 */
#include <iostream>
using namespace std;

class Account
{
    double balance;
    char name[80];
    char address[100];
public:
    void createAccout();
    
    
};

void Account::createAccout()
{
    cout << "Enter you full name";
    cin.getline(name, 80);
    cout << "Enter your address";
    cin.getline(address, 100);
}

int main() {
    
    return 0;
}
