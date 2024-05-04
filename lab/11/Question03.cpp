#include<iostream>
using namespace std;

class Vehicle{
protected:
    string make, model;
    int speed;
public:
    Vehicle(const string& make, const string& model, int speed) : make(make), model(model), speed(speed) {}

    virtual void accelerate() = 0;
    virtual void brake() = 0;
    virtual void calculateFuelEfficiency() = 0;
    const string& getMake() const {
        return make;
    }
    const string& getModel() const {
        return model;
    }
    int getSpeed() const {
        return speed;
    }
};

class Car : public Vehicle{
protected:
    double fuelCapacity;
public:
    Car(const string& make, const string& model, int speed, double fuelCapacity) : Vehicle(make, model, speed), fuelCapacity(fuelCapacity) {}

    void accelerate() override {
        cout << "Car is accelerating." << endl;
    }
    void brake() override {
        cout << "Applying brake for car." << endl;
    }
    void calculateFuelEfficiency() override {
        cout << "Calculating fuel efficiency of car." << endl;
    }
};

class Truck : public Vehicle{
protected:
    double cargoCapacity;
public:
    Truck(const string& make, const string& model, int speed, double cargoCapacity) : Vehicle(make, model, speed), cargoCapacity(cargoCapacity) {}

    void accelerate() override {
        cout << "Truck is accelerating." << endl;
    }
    void brake() override {
        cout << "Applying brake for truck." << endl;
    }
    void calculateFuelEfficiency() override {
        cout << "Calculating fuel efficiency of truck." << endl;
    }
};

int main(){
    Car car("Tyota", "Grendy", 1800, 50.5);
    car.accelerate();
    car.brake();
    car.calculateFuelEfficiency();

    Truck truck("tyota", "Turk", 2500, 1000.0);
    truck.accelerate();
    truck.brake();
    truck.calculateFuelEfficiency();

    return 0;
}
