#include<iostream>
using namespace std;

class DarazPersonData {
private:
    string first_Name;
    string Last_Name;
    string Address;
    string City;
    string State;
    string Zip;
    string Phone;
public:
    // Mutators
    void setLastName(const string& lName) { Last_Name = lName; }
    void setFirstName(const string& fName) { first_Name = fName; }
    void setAddress(const string& addr) { Address = addr; }
    void setCity(const string& c) { City = c; }
    void setState(const string& s) { State = s; }
    void setZip(const string& z) { Zip = z; }
    void setPhone(const string& p) { Phone = p; }

    // Accessors
    string getFirst_name() const { return first_Name; }
    string getLast_name() const { return Last_Name; }
    string getAddress() const { return Address; }
    string getCity() const { return City; }
    string getState() const { return State; }
    string getZip() const { return Zip; }
    string getPhone() const { return Phone; }
};

class DarazCustomerData {
private:
    int Customer_Number;
    int Loyalty_Points;
public:
    DarazCustomerData(int customer_no, int Loyalty_Poi): Customer_Number(customer_no),Loyalty_Points(Loyalty_Poi){}
    // Mutators
    void setCustomer_Number(int no) { Customer_Number = no; }
    void setLoyalty_Points(int Points) { Loyalty_Points = Points; }

    // Accessors
    int getCustomer_Number() const {return Customer_Number;}
    int getLoyalty_Points() const {return Loyalty_Points;}
};

class DarazLoyaltyProgram {
public:
    static void addLoyaltyPoints(DarazCustomerData& customer, int points){
        if(points >  0)
            customer.setLoyalty_Points(customer.getLoyalty_Points() + points);
        else  cout << "Error: Cannot add negative loyalty points." << endl;
    }

    static void redeemLoyaltyPoints(DarazCustomerData& customer, int points){
        if(points > 0 && points <= customer.getLoyalty_Points()){
            customer.setLoyalty_Points(customer.getLoyalty_Points() - points);
        }else   cout << "Error: Invalid loyalty points for redemption." << endl;
    }

    static void displayTotalLoyaltyPoints(const DarazCustomerData& customer){
        cout<<"Total Loyalty Points for Customer "<<customer.getCustomer_Number()<< ": "<<customer.getLoyalty_Points()<<endl;
    }
};

int main(int argc, char const *argv[])
{
    DarazPersonData person;
    person.setLastName("Rusman");
    person.setFirstName("talha");
    person.setAddress("123 Main St");
    person.setCity("Karachi");
    person.setState("Sindh");
    person.setZip("12345");
    person.setPhone("0300-*******");

    DarazCustomerData customer(101,1000);
    cout<<"\n";

    DarazLoyaltyProgram::addLoyaltyPoints(customer, 100);
    DarazLoyaltyProgram::displayTotalLoyaltyPoints(customer);

    DarazLoyaltyProgram::redeemLoyaltyPoints(customer, 200);
    DarazLoyaltyProgram::displayTotalLoyaltyPoints(customer);
    cout<<"\n";
    
    return 0;
}
