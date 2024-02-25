#include<iostream>
using namespace std;
class Roller_Coaster{
    private:
    string name;
    int height;
    int length;
    int speed;
    int capacity;
    int CurrentNumRiders;
    bool RideInProgress;
    
    public://defoult constructor
      Roller_Coaster() : name("Roller Coaster"), height(500), length(2000), speed(0), capacity(20), CurrentNumRiders(0), RideInProgress(false) {}
      Roller_Coaster(string name,int height,int length ,int speed,int capacity){
        this->name = name;
        this->height = height;
        this->length = length;
        this->CurrentNumRiders;

         if (capacity <= 3) {
            capacity = 4; // Set capacity to 4 by default
        } else {
           this-> capacity = capacity;
        }
        // Verify if capacity is in multiples of 2 or 3
        if (capacity % 2 != 0 && capacity % 3 != 0) {
            // Round up to the closest multiple of 2
            int closestMultipleOfTwo = ((capacity + 1) / 2) * 2;
            // Round up to the closest multiple of 3
            int closestMultipleOfThree = ((capacity + 2) / 3) * 3;
            // Choose the closest multiple of 2 or 3
            capacity = (closestMultipleOfTwo < closestMultipleOfThree) ? closestMultipleOfTwo : closestMultipleOfThree;
        }
        CurrentNumRiders = 0;
        RideInProgress = false;
      }
    //getter functions
    string getName() {
        return name;
    }
    int getHeight() {
        return height;
    }
    int getLength() {
        return length;
    }
    int getSpeed() {
        return speed;
    }
    int getCapacity() {
        return capacity;
    }
    int getCurrentNumRiders() {
        return CurrentNumRiders;
    }
    bool isRideInProgress() {
        return RideInProgress;
    }
    //set speed
    int setspeed(int speed){
         this->speed = speed;
    }
    //other operstion functions
    int LodRolar(int riderno){
        if(RideInProgress){
            return RideInProgress;//means ride is in process
        }
        int setAvelibal = capacity - CurrentNumRiders;
        if(riderno>setAvelibal){
            return riderno - setAvelibal;//seat are not avealibal
        }
        CurrentNumRiders +=riderno;
        return 0;//mean sets are avalibal
    }

     int startRide() {
        if (RideInProgress) {
            return -1; //means Ride is already in progress
        }
        if (CurrentNumRiders < capacity) {
            return capacity - CurrentNumRiders; //means Not all seats are occupied
        }
        RideInProgress = true;
        return 0; //means Ride started successfully
    }
    void stopRide() {
        RideInProgress = false;
    }

    void unloadRiders() {
        CurrentNumRiders = 0;
    }

    void accelerate() {
        int rollNumber = 0065; // Your roll number
        int lastDigit = rollNumber % 10;
        speed += lastDigit;
    }
    void deaccelerate(){
        int rollNumber = 0065;
         int fristDigit;
         for (int i = 0; i < 2; i++)
         {
            fristDigit = rollNumber%10;
            rollNumber =rollNumber/10;
         }
         speed -= fristDigit;  
    }



};
int main(int argc, char const *argv[])
{
    Roller_Coaster rc1; // Default constructor
    Roller_Coaster rc2("Thunder Bolt", 600, 2500, 80, 25); // Parameterized constructor

    // Demonstrate functionality
    cout << "Roller Coaster 1 Details:" << endl;
    cout << "Name: " << rc1.getName() << endl;
    cout << "Height: " << rc1.getHeight() << " meters" << endl;
    cout << "Length: " << rc1.getLength() << " meters" << endl;
    cout << "Speed: " << rc1.getSpeed() << " km/h" << endl;
    cout << "Capacity: " << rc1.getCapacity() << " people" << endl;
    cout << "Current Number of Riders: " << rc1.getCurrentNumRiders() << endl;
    cout << "Ride In Progress: " << (rc1.isRideInProgress() ? "Yes" : "No") << endl;
    
    cout << "\nRoller Coaster 2 Details:" << endl;
    cout << "Name: " << rc2.getName() << endl;
    cout << "Height: " << rc2.getHeight() << " meters" << endl;
    cout << "Length: " << rc2.getLength() << " meters" << endl;
    cout << "Speed: " << rc2.getSpeed() << " km/h" << endl;
    cout << "Capacity: " << rc2.getCapacity() << " people" << endl;
    cout << "Current Number of Riders: " << rc2.getCurrentNumRiders() << endl;
    cout << "Ride In Progress: " << (rc2.isRideInProgress() ? "Yes" : "No") << endl;
 
    int resuelt;
    cout<<"\nstarting Roller Coaster 1"<<endl;
     resuelt = rc1.startRide();
     if(resuelt==-1){
        cout<<"right is already in process:"<<endl;
     } else
     if(resuelt>0){
        cout << "Ride 1 cannot start, " << resuelt << " seats are empty!" << endl;
     }else cout << "Ride 1 started successfully!" << endl;

     cout<<"\nloding Roller Coster 2:"<<endl;
       int loadResult2 = rc2.LodRolar(10);
    if (loadResult2 > 0) {
        cout << loadResult2 << " riders were not seated due to insufficient space!" << endl;
    } else {
        cout << "All riders seated successfully!" << endl;
    }

    cout<<"\nAccelerating roller coster 1:"<<endl;
    rc1.accelerate();
     cout << "New speed of Ride 1: " << rc1.getSpeed() << " km/h" << endl;
    
    cout<<"\nDeacceleraltiong Roller Coster 2"<<endl;
    rc2.deaccelerate();
      cout << "New speed of Ride 1: " << rc1.getSpeed() << " km/h" << endl;

     cout<<"\n\nprogram is finished:"<<endl;
    return 0;
}
