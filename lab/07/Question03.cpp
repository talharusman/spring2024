#include<iostream>
using namespace std;

class Position{
        int X = 0;
        int Y = 0;
        int Z = 0;
    public:
        Position(int X,int Y, int Z){
            this->X += X;
            this->Y += Y;
            this->Z += Z;
        }

        void display(){
            cout<<"possiton: ("<<X<<","<<Y<<","<<Z<<")"<<endl;
        }
};

class health{
        int hel;
    public:
        health(int hp):hel(hp){}

        void display(){
            cout<<"Health: "<<hel<<endl;
        }
};

class Character:public Position,public health{
      public:

      Character(int x,int y,int z,int hel):Position(x,y,z),health(hel){}

      void display(){
         Position::display();
         health::display();
      }
};

int main(int argc, char const *argv[])
{
    Character obj(1,3,5,3);
    obj.display();
    return 0;
}
