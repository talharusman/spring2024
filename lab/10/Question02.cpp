#include <iostream>
using namespace std;

class Base {
private:
    int a;

public:
    Base(int a) : a(a) {}

    Base& operator--() {
        a *= 4;
        return *this;
    }

    Base operator--(int) {
        Base temp(*this);
        a /= 4;
        return temp;
    }

    int getValue() const {
        return a;
    }
};

int main() {
    Base obj(2); 

    --obj;
    cout << "After preFix: " << obj.getValue() << endl;

    Base obj2 = obj--; 
    cout << "After postFix: " << obj.getValue() << endl;
    cout << "Value of obj2: " << obj2.getValue() << endl;

    return 0;
}
