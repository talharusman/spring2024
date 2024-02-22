/* programer: Talha Rusman
   Roll-Number: 23k-0065
   Date: 22/2/2024
*/

#include <iostream>
using namespace std;

class BankAccount
{
    string AccoutNumber;
    string accountHolderName;
    double balance;

public:
    BankAccount() {}
    BankAccount(string AccoutNumber, string accountHolderName, double balance)
    {
        this->AccoutNumber = AccoutNumber;
        this->accountHolderName = accountHolderName;
        this->balance = balance;
    }

    void deposit(double amount)
    {
        balance += amount;
    }
    void withdraw(double amount)
    {
        if (balance >= amount)
        {
            balance -= amount;
        }
        else
            cout << "you cant withdrow" << endl;
    }

    void display()
    {
        cout << "account number" << AccoutNumber << endl;
        cout << "Name is " << accountHolderName << endl;
        cout << "balance " << balance << endl;
    }
};

int main(int argc, char const *argv[])
{
    BankAccount bank[10];
    bank[0] = BankAccount("23k0065", "talha", 200);
    bank[0].deposit(100);
    bank[0].withdraw(100);
    bank[0].display();
    return 0;
}
