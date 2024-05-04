#include <iostream>
using namespace std;

template<typename T, typename U>
class Convert {
protected:
    T Val1;
    U Val2;
public:
    Convert(T val1, U val2) : Val1(val1), Val2(val2) {}

    virtual void compute() {}
};

template<typename T>
class l_to_g : public Convert<T, double> {
public:
    l_to_g(T val1) : Convert<T, double>(val1, 0.0) {}

    void compute() override {
        this->Val2 = this->Val1 * 0.264172;
        cout << this->Val1 << " liter water is equal to: " << this->Val2;
    }
};

template<typename T>
class f_to_c : public Convert<T, double> {
public:
    f_to_c(T val1) : Convert<T, double>(val1, 0.0) {}

    void compute() override {
        this->Val2 = (this->Val1 - 32) * 5 / 9;
        cout << this->Val1 << " degree Fahrenheit is equal to: " << this->Val2 << " degree Celsius";
    }
};

int main() {
    l_to_g<int> ltog(4);
    ltog.compute();
    cout << endl;

    f_to_c<int> ftoc(70);
    ftoc.compute();
    cout << endl;

    return 0;
}
