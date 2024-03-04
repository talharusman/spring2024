#include<iostream>
using namespace std;

class LoanHelper{
   const float rate;
   float amount;
   int month;

   public:
   LoanHelper(float rate,float amount,int month):rate(rate),amount(amount),month(month){}

   void calculat(){
      float inter = (amount*rate)/month;
      float pay = inter +(amount/month);
      cout<<"You have to Pay ("<<pay<<") every month for "<<month<<" months to repay your loa"<<endl;
   }
};

int main(int argc, char const *argv[])
{
    LoanHelper o1(05,100,9);
    o1.calculat();
    
    return 0;
}
