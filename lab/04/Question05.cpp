/*Programer: Talha Rusman
  Roll_N0: 23K0065
  */
#include<iostream>
using namespace std;

class Office{
   string Location ="";
   int SeatingCapacity = 0;
   string *Furniture;
   public:

   Office(string loca = "",int capacity = 0,int size=0)
   {
      this-> Location = loca;
      this-> SeatingCapacity = capacity;
      Furniture =  new string[size];
   }

   ~Office(){
    cout<<"Destrucutor successfully "<<endl;
     delete[] Furniture;
   }


};

int main(int argc, char const *argv[])
{
    Office O1("Islamabad",200,3);
    Office O2("Karachi",300);
    Office O3("Nawabshah");

    return 0;
}
