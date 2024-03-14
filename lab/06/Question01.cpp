#include<iostream>
using namespace std;

 class BankAccount{
     int accountId;
     double balance;
     int* transactionHistory;
     int numTransactions;
   public:
   BankAccount(){};
   BankAccount(int accountId,double balance,int numTransactions)
   {
        this->accountId = accountId;
        this->balance = balance;
        this->numTransactions = numTransactions;
        transactionHistory = new int[numTransactions];
        cout<<"enter the transection history:";
          for (size_t i = 0; i < numTransactions; i++)
          {
           cout<<"Enter Transactions noumber "<< i + 1;
                cin>>this->transactionHistory[i];
          }
   }
   BankAccount(BankAccount &account){
          this->accountId = account.accountId;
          this->balance = account.balance;
          this->numTransactions = account.numTransactions;
          for (size_t i = 0; i < numTransactions; i++)
          {
            this->transactionHistory[i] = account.transactionHistory[i];
          }
          
   }
   
    
    void dispaly(){
          cout<<"account Id: "<<accountId<<endl
              <<"balance: "<<balance<<endl;

              for (size_t i = 0; i < numTransactions; i++)
              {
                cout<<"Transactions noumber "<< i + 1<< " is: "<<transactionHistory[i];
              }   
              cout<<endl<<endl; 

    }
     ~BankAccount(){
        delete[] transactionHistory;
    }

    void update(){
         delete[]  transactionHistory;
         cout<<"Enter the number of transactions:";
         cin>>numTransactions;
          transactionHistory = new int[numTransactions];
           for (size_t i = 0; i < numTransactions; i++)
              {
                cout<<"Enter Transactions noumber "<< i + 1;
                cin>>this->transactionHistory[i];
              }   
    }

    
 };
int main(){
     
     BankAccount obj1(1,23.34,3);
     BankAccount copy(obj1);

     cout<<"-------------main object ----------"<<endl<<endl;
     obj1.dispaly();
     cout<<"-------------copy object----------"<<endl<<endl;
     copy.dispaly();
    
    return 0;
}