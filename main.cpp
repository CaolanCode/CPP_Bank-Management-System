/*
    Bank Management System
 */
#include <iostream>
#include <iomanip>
using std::cout;
using std::endl;
using std::cin;
using std::setprecision;
using std::fixed;


int account_number();

class Account
{
    double balance;
    char name[100];
    char address[100];
    int accountNumber;
public:
    // constructor
    Account()
    {
        accountNumber = account_number();
        balance = 0.00;
    }
    // destructor
    ~Account() {cout << "Account deleted.\n";}
    // define member functions
    void createAccout();
    void displayInfo() const;
    void withdraw();
    void deposit();
};

void Account::createAccout()
{
    cout << "Enter you full name: ";
    cin.ignore();
    cin.getline(name, 100);
    cout << "Enter your address: ";
    cin.getline(address, 100);
}

void Account::displayInfo() const
{
    cout << "\nAccount number: " << accountNumber << endl;
    cout << "Full name: " << name << endl;
    cout << "Address : " << address << endl;
    cout << "Balance : €" << setprecision(2) << fixed << balance << endl;
}

void Account::withdraw()
{
    double amount = 0;
    
    do
    {
        cout << "How much would you like to withdraw?: ";
        cin >> amount;
        if(amount > balance)
        {
            cout << "\nInsufficient funds\n";
            cout << "Balance : €" << setprecision(2) << fixed << balance << endl;
            if(balance == 0) break;
        }
        else
        {
            balance -= amount;
            break;
        }
    }while(amount > balance);
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

void displayChoices(int &choice)
{
    cout << "\n\n1) Create Account\n";
    cout << "2) Deposit Money\n";
    cout << "3) Withdraw Money\n";
    cout << "4) Display Account Information\n";
    cout << "5) Exit\n";
    cout << "Enter choice: ";
    cin >> choice;
    cout << "\n\n";
}


int main() {
    Account accOne;
    int choice = 0;
    
    do
    {
        displayChoices(choice);
        switch (choice) {
            case 1:
                accOne.createAccout();
                break;
            case 2:
                accOne.deposit();
                break;
            case 3:
                accOne.withdraw();
                break;
            case 4:
                accOne.displayInfo();
                break;
            case 5:
                cout << "Goodbye\n";
                break;
            default:
                cout << "Invalid option\n";
                break;
        }
    }while(choice != 5);
    
    return 0;
}
