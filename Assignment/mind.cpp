#include<iostream>
using namespace std;

class Stairs{
  protected:
  int numSteps;
  float stepHeight;
  float stepWidth;
  string location;
  
  public:
    Stairs(int num,float hight,float width,string locat): numSteps(num),stepHeight(hight),stepWidth(width),location(locat){}
    
};
class ConveyorBelt{
    float lenght;
    float width;
protected:
    float speed;
    float capacity;
public:
    ConveyorBelt(float len,float wid,float sp,float cap):lenght(len),width(wid),speed(sp),capacity(cap){}
    ConveyorBelt(float speed,float capacity):speed(speed),width(speed){}
    
};


class Escalator :public Stairs,public ConveyorBelt{
   char direction;
   int currentLocation;
   public:
    Escalator(char dir,int current,int num,float hight,float width,string locat,float speed,float capacity) : direction(dir),currentLocation(current), Stairs(num,hight,width,locat),ConveyorBelt(speed,capacity){}
    
    void moveUp(int weight){
        
    }
    void moveDown(int weight){
        
    }
};

class industrialBelt : public ConveyorBelt{
   float minweight;
   bool operable;
   
   public:
   
   industrialBelt(float minweight,bool operabloe,float lenght,float width, float speed , float capacity):operable(operabloe),minweight(minweight),ConveyorBelt(lenght,width,speed,capacity){}
   
    bool chechEeight(int currWeight){
        
    }
    void operaterBelt(int currWeight){
        
    }
    void operateBelt(int currWeight,int speed){
        
    }
    
};



int main(){
    
    return 0;
}

