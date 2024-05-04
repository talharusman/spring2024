#include<iostream>
using namespace std;

class Account {
protected:
    int accountNumber;
    double Balance;

public:
    Account(int accountNumber, double balance) : accountNumber(accountNumber), Balance(balance) {}
    virtual double withdraw(double amount) = 0;
    virtual double deposit(double amount) = 0;
    virtual double calculateInterest() = 0;
    int getAccountNumber() { return accountNumber; }
    double getBalance() { return Balance; }
};

class SavingAccount : public Account {
protected:
    double interestRate;

public:
    SavingAccount(int accountNumber, double balance, double interestRate) : Account(accountNumber, balance), interestRate(interestRate) {}

    double deposit(double amount) {
        Balance += amount;
        return amount;
    }

    double withdraw(double amount) {
        if (amount < Balance) {
            Balance -= amount;
            return amount;
        }
        else {
            cout << "Sorry Insufficient Balance!" << endl;
            return 0;
        }
    }

    double calculateInterest() {
        double time, interest;
        cout << "Enter the number of years: ";
        cin >> time;
        
        interest = Balance * interestRate * time;
        return interest;
    }
};

class CurrentAccount : public Account {
protected:
    double overdraftLimit;

public:
    CurrentAccount(int accountNumber, double balance, double overdraftLimit) : Account(accountNumber, balance), overdraftLimit(overdraftLimit) {}

    double deposit(double amount) {
        Balance += amount;
        return amount;
    }

    double withdraw(double amount) {
        if ((Balance - amount) >= overdraftLimit) {
            Balance -= amount;
            return amount;
        }
        else {
            cout << "Withdrawal exceeds overdraft limit!" << endl;
            return 0;
        }
    }

    double calculateInterest() {
        return 0;
    }
};

int main(int argc, char const* argv[]) {
    SavingAccount sav(123, 100.0, 0.5);
    CurrentAccount cur(124, 500.0, 10.0);

    cout << "Savings account Number: " << sav.getAccountNumber() << endl;
    cout << "Current account Number: " << cur.getAccountNumber() << endl;

    cout << "\nInitial balances:" << endl;
    cout << "Savings account balance: " << sav.getBalance() << endl;
    cout << "Current account balance: " << cur.getBalance() << endl;

    sav.deposit(50.0);
    cur.withdraw(20.0);

    cout << "\nBalances after transactions:" << endl;
    cout << "Savings account balance: " << sav.getBalance() << endl;
    cout << "Current account balance: " << cur.getBalance() << endl;

    cout << "\nInterest earned by savings account: " << sav.calculateInterest() << endl;

    return 0;
}
