/*
    Bank Management System
 */
#include <iostream>
#include <iomanip>
using namespace std;

int account_number();

class Account
{
    double balance;
    char name[100];
    char address[100];
    int accountNumber;
public:
    Account()
    {
        accountNumber = account_number();
        balance = 0.00;
    }
    void createAccout();
    void displayInfo();
    void withdraw();
    void deposit();
    
};

void Account::createAccout()
{
    cout << "Enter you full name: ";
    cin.getline(name, 100);
    cout << "Enter your address: ";
    cin.getline(address, 100);
}

void Account::displayInfo()
{
    cout << "\nAccount number: " << accountNumber << endl;
    cout << "Full name: " << name << endl;
    cout << "Address : " << address << endl;
    cout << "Balance : €" << setprecision(2) << fixed << balance << endl;
}

void Account::withdraw()
{
    double amount;
    cout << "How much would you like to withdraw?: ";
    cin >> amount;
    balance -= amount;
}

void Account::deposit()
{
    double amount;
    cout << "How much would you like to deposit?: ";
    cin >> amount;
    balance += amount;
}

int account_number()
{
    static int accountNumber = 1;
    return accountNumber++;
}

int main() {
    Account accOne;
    
    accOne.createAccout();
    accOne.displayInfo();
    accOne.deposit();
    accOne.withdraw();
    accOne.displayInfo();
    
    return 0;
}
