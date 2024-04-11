#include <iostream>
using namespace std;
class Employe
{
    string name;
    int id;

public:
    Employe(string name, int id) : id(id), name(name) {}

    virtual double calculatePay() const
    {
    }
    virtual void display() const
    {
        cout << "name: " << name << endl;
        cout << "id: " << id << endl;
    }
};

class FullTimeEmploye : public Employe
{
    double MonthlySlary;

public:
    FullTimeEmploye(double salry, int id, string name) : Employe(name, id), MonthlySlary(salry) {}

    double calculatePay() const
    {
        return MonthlySlary;
    }
    void display() const
    {
        Employe::display();
        cout << "Monthly Salary: " << MonthlySlary << endl;
    }
};

class PartTimeEmploye : public Employe
{
    double HourlyRate;
    int HoursWork;

public:
    PartTimeEmploye(double HourlyRate, int HoursWork, int id, string name) : Employe(name, id), HourlyRate(HourlyRate), HoursWork(HoursWork) {}

    double calculatePay() const
    {
        return HourlyRate * HoursWork;
    }
    void display() const
    {
        Employe::display();
        cout << "Hourly Rate: " << HourlyRate << endl;
        cout << "Hours Work: " << HoursWork << endl;
    }
};

int main(int argc, char const *argv[])
{
    FullTimeEmploye full(500.0, 12, "Talha Rusman");
    PartTimeEmploye part(10, 5, 13, "Talha Rusman");

    cout << "\nFull Time Employee Details:" << endl;
    full.display();

    cout << "\nPart Time Employee Details:" << endl;
    part.display();

    // Demonstrating early or static binding
    Employe *emp1 = &full;
    Employe *emp2 = &part;

    cout << "\nUsing Base Class Pointer:" << endl;
    cout << "Full Time Employee - Calculated Pay: " << emp1->calculatePay() << endl;
    cout << "Part Time Employee - Calculated Pay: " << emp2->calculatePay() << endl;

    return 0;
}
