/* programer: Talha Rusman
   Roll-Number: 23k-0065
   Date: 3/3/2024
*/
#include<iostream>
using namespace std;

class Square{
   float side_length;
   float sq_area;
   static float all_area;
   public:
   Square(){}
   Square(float side_length){
     this->side_length = side_length;
   }

   void calculateArea(){

     sq_area = side_length * side_length;
     all_area += sq_area;
     cout<<"Your area is calculated successfully:"<<endl;

   }
    void setter(float side_length){
        this->side_length = side_length;
    }
   void getarea(){
      cout<<"Area is: "<<sq_area<<endl
          <<"All area: "<<all_area<<endl;
   }

};

float Square::all_area = 0.0;
int main(int argc, char const *argv[])
{   
    Square square1, square2, square3;
    cout<<"Square 1"<<endl;
    square1.setter(12);
    square1.calculateArea();
    square1.getarea();
    
    cout<<"Square 2"<<endl;
    square2.setter(15);
    square2.calculateArea();
    square2.getarea();

    cout<<"Square 3"<<endl;
    square3.setter(20);
    square3.calculateArea();
    square3.getarea();

    return 0;
}
