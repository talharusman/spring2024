#include<iostream>
#include<string>
using namespace std;

class Engine {
private:
    string type;

public:
    Engine(const string& engineType) : type(engineType) {}

    string getType() const {
        return type;
    }
};

class Wheel {
private:
    int size;
public:
    Wheel(int size) : size(size) {}

    int getSize() const {
        return size;
    }
};

class Headlights {
private:
    string type;
public:
    Headlights(const string& headlight_type) : type(headlight_type) {}

    string getType() const {
        return type;
    }
};

class Steering {
private:
    string type;
public:
    Steering(const string& type) : type(type) {}

    string getType() const {
        return type;
    }
};

class Car {
private:
    Engine* engine;
    Wheel* wheels[4];
    Headlights* headlights[2];
    Steering* steering;

public:
    Car(Engine& carEngine, Wheel carWheels[], Headlights carHeadlights[],  Steering& carSteering)
        : engine(&carEngine), steering(&carSteering) {
        for (int i = 0; i < 4; ++i) {
            wheels[i] = &carWheels[i];
        }
        for (int i = 0; i < 2; ++i) {
            headlights[i] = &carHeadlights[i];
        }
    }

    void displayDetails() {
        cout << "\n-------Details-------\n" << endl;
        cout << "Engine: " << engine->getType() << endl << endl;
        for (int i = 0; i < 4; ++i) {
            cout << "Wheel " << i + 1 << " Size: " << wheels[i]->getSize() << endl;
        }
        cout<<endl;
        for (int i = 0; i < 2; ++i) {
            cout << "Headlight " << i + 1 << " Type: " << headlights[i]->getType() << endl;
        }
        cout<<endl;
        cout << "Steering Type: " << steering->getType() << endl << endl;
    }

};

int main() {
    Engine carEngine("V8");
    Wheel carWheels[] = { Wheel(18), Wheel(18), Wheel(18), Wheel(18) };
    Headlights carHeadlights[] = { Headlights("LED"), Headlights("LED") };
    Steering carSteering("Power");

    Car myCar(carEngine, carWheels, carHeadlights, carSteering);
    myCar.displayDetails();

    return 0;
}
