#include "iostream"
using namespace std;
class printClass;
class perimeter{
    int length;
    int breadth;
    public:
    perimeter(int l, int b):length(l),breadth(b) { }
    
    friend class printClass;
};

class printClass{
    public:
    void Calculat(perimeter &obj){
        cout<<"perimeter is: "<<obj.breadth + obj.length<<endl;
    }
};


int main(int argc, char const *argv[])
{
    perimeter obj(3,5);
    printClass print;
    print.Calculat(obj);
    
    return 0;
}
