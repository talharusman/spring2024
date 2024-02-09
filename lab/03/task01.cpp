#include <iostream>
#include <string>

using namespace std;

class BoardMarker {
private:
    string brand;
    string shade;
    bool refillable;
    bool inkStatus;

public:
    // Constructor
    BoardMarker(string brand, string shade, bool refillable, bool inkStatus) {
        this->brand = brand;
        this->shade = shade;
        this->refillable = refillable;
        this->inkStatus = inkStatus;
    }

    // Getter methods
    string getBrand() {
        return brand;
    }

    string getShade() {
        return shade;
    }

    bool isRefillable() {
        return refillable;
    }

    bool hasInk() {
        return inkStatus;
    }

    // Setter methods
    void setBrand(string brand) {
        this->brand = brand;
    }

    void setShade(string shade) {
        this->shade = shade;
    }

    void setRefillable(bool refillable) {
        this->refillable = refillable;
    }

    void setInkStatus(bool inkStatus) {
        this->inkStatus = inkStatus;
    }

    // Method to write
    void write() {
        if (inkStatus) {
            cout << "Writing..." << endl;
        } else {
            cout << "The ink has run out. Please refill the marker." << endl;
        }
    }

    // Method to refill the marker
    void refill() {
        if (refillable) {
            cout << "Refilling the marker..." << endl;
            inkStatus = true;
        } else {
            cout << "This marker is not refillable." << endl;
        }
    }
};

int main() {
    // Example usage
    BoardMarker marker("Dollar", "black", true, true);

    cout << "Brand: " << marker.getBrand() << endl;
    cout << "Shade: " << marker.getShade() << endl;
    cout << "Refillable: " << marker.isRefillable() << endl;
    cout << "Ink Status: " << marker.hasInk() << endl;

    marker.write();  // Writes because ink status is true

    marker.setInkStatus(false);
    marker.write();  // Prints a message indicating ink has run out

    marker.refill();  // Refills the marker
    marker.write();  // Writes again after refilling

    return 0;
}
