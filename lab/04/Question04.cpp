/*Programer: Talha Rusman
  Roll_N0: 23K0065
  */
#include<iostream>
#include<array>
using namespace std;

class Office{
   string Location;
   int SeatingCapacity;
   array<string, 3> Furniture = {"", "", ""};
   public:

   Office(string loca = "",int capacity = 0, array<string, 3> furniture = {"", "", ""}):
   Location(loca),
   SeatingCapacity(capacity),
   Furniture(furniture){}


};

int main(int argc, char const *argv[])
{
    Office O1("Islamabad",200,{"table","chair","sofa"});

    Office O2("Karachi",300);
    Office O3("Nawabshah");

    return 0;
}
