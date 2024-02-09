#include <iostream>
#include <string>

using namespace std;

class WaterBottle {
private:
    string company;
    string color;
    int capacityLiters;
    int capacityMilliliters;

public:
    // Constructor
    WaterBottle(string company, string color, int capacityLiters, int capacityMilliliters) {
        this->company = company;
        this->color = color;
        this->capacityLiters = capacityLiters;
        this->capacityMilliliters = capacityMilliliters;
    }

    // Getter methods
    string getCompany() {
        return company;
    }

    string getColor() {
        return color;
    }

    int getCapacityLiters() {
        return capacityLiters;
    }

    int getCapacityMilliliters() {
        return capacityMilliliters;
    }

    //setter
    void setCompany(string company) {
        this->company = company;
    }

    void setColor(string color) {
        this->color = color;
    }

    void setCapacityLiters(int liters) {
        capacityLiters = liters;
    }

    void setCapacityMilliliters(int milliliters) {
        capacityMilliliters = milliliters;
    }

    
    void updateWaterConsumption(int millilitersConsumed) {

        int totalCapacity = capacityLiters * 1000 + capacityMilliliters;
        totalCapacity -= millilitersConsumed;

        if (totalCapacity < 0) {
            cout << "Water bottle is empty." << endl;
            capacityLiters = 0;
            capacityMilliliters = 0;
        } else {
            capacityLiters = totalCapacity / 1000;
            capacityMilliliters = totalCapacity % 1000;
        }
    }
};

int main() {

    WaterBottle bottle("Example Company", "Blue", 1, 500);


    cout << "Company is:"<< bottle.getCompany() << endl;
    cout << "Color is:"<< bottle.getColor() << endl;
    cout << "Capacity is : " << bottle.getCapacityLiters() << " liters and "
         << bottle.getCapacityMilliliters() << " milliliters" << endl;

    int millilitersConsumed;
    cout << "Enter milliliters of water consumed : ";
    cin >> millilitersConsumed;

    
    bottle.updateWaterConsumption(millilitersConsumed);


    cout << "Updated Capacity: " << bottle.getCapacityLiters() << " liters and "
         << bottle.getCapacityMilliliters() << " milliliters" << endl;

    return 0;
}