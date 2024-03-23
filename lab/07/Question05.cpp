#include<iostream>
using namespace std;

class Vehicle{
        string make;
        string model;
        int year;
    public:
        Vehicle(string make, string modal,int year): make(make),model(modal),year(year){}

        void display(){
            cout << "\n\nMake: " << make << endl;
            cout << "Model: " << model << endl;
            cout << "Year: " << year << endl;
        }

};

class Car : public Vehicle{
        int Num_Of_Doors;
        double Fuel_Efficiency;
    public:
        Car(string make,string modal,int year,int NumOfDoor,double FuelEffiency)
        :Vehicle(make,modal,year), Num_Of_Doors(NumOfDoor),Fuel_Efficiency(FuelEffiency){}

        void dispaly(){
            Vehicle::display();
            cout << "Number of doors: " << Num_Of_Doors << endl;
            cout << "Fuel Efficiency: " << Fuel_Efficiency << " MPG" << endl;
        }

};

class ElectricCar : public Car{
        double Battery_Life;
    public:
        ElectricCar(string make,string modal,int year,int NumOfDoor,double FuelEffiency,double Battery) 
        : Car(make,modal,year,NumOfDoor,FuelEffiency),Battery_Life(Battery){}

        void Display(){
            Car::dispaly();
            cout << "Battery Life: " << Battery_Life << " kWh" << endl<<endl;
        }
        
};

int main(int argc, char const *argv[])
{
    ElectricCar My_Car("Tesla", "Model S", 2023, 4, 120.5, 300);
    My_Car.Display();
    
    return 0;
}
