#include <iostream>
using namespace std;

class Pet
{
private:
    string Name;
    string healthStatus;
    int hungerLevel;
    int happinessLevel;
    string specialSkills;

public:
    // constructor
    Pet() {}
    Pet(string name, string health, int hunger, int happiness, string special) : Name(name),
                                                                                 healthStatus(health),
                                                                                 hungerLevel(hunger),
                                                                                 happinessLevel(happiness),
                                                                                 specialSkills(special) {}

    // getter functions
    string getname()
    {
        return this->Name;
    }
    string getHelthsta()
    {
        return this->healthStatus;
    }
    int gethungerlevel()
    {
        return this->hungerLevel;
    }
    int getHappiness()
    {
        return this->happinessLevel;
    }
    string getspecial()
    {
        return this->specialSkills;
    }

    // other member functions
    void updateHealth()
    {
        cout << "The health status of this pet was: " << this->healthStatus << endl;
        cout << "Enter the new health status: ";
        cin >> this->healthStatus;
    }
    void updateHappiness()
    {
        cout << "The happiness level of this pet was: " << this->happinessLevel << endl;
        int h;
        cout << "Enter the new happiness level(1-10): ";
        cin >> h;
        if (h <= 10)
        {
            this->happinessLevel = h;
        }
        else
        {
            cout << "Error! Happiness scale is within 10." << endl;
        }
    }
    void updateHunger()
    {
        cout << "The hunger level of this pet is: " << this->hungerLevel << endl;
        int H;
        cout << "Enter the new hunger level: ";
        cin >> H;
        if (H > this->hungerLevel && this->happinessLevel < 10)
            this->happinessLevel++;
        if (this->happinessLevel > 0 && H < this->hungerLevel)
            this->happinessLevel--;
    }
};

class Adopter
{
private:
    string adopterName;
    string adopterMobileNum;
    string adoptedPetRecords;

public:
    void adoptPet(Pet data[], Adopter adopt[], int &adopt_no)
    {
        Adopter temp;
        cout << "Enter the adopter's name: ";
        cin >> temp.adopterName;
        cout << "Enter the adopter's mobile number: ";
        cin >> temp.adopterMobileNum;
        cout << "Enter the name of the pet you want to adopt: ";
        cin >> temp.adoptedPetRecords;
        adopt[adopt_no] = temp;
        adopt_no++;
        return;
    }

    void returnPet(Pet data[], Adopter adopt[], int count, int &adopt_no)
    {
        string name;
        cout << "Enter name of adopter who wants to return pet: ";
        cin >> name;
        bool found = false;
        for (int i = 0; i < adopt_no; i++)
        {
            if (adopt[i].adopterName == name)
            {
                cout << "Your mobile number is: " << adopt[i].adopterMobileNum << endl;
                cout << "You adopted: " << adopt[i].adoptedPetRecords << endl;
                cout << "When you adopted " << adopt[i].adoptedPetRecords << ": " << endl;
                for (int j = 0; j < count; j++)
                {
                    if (adopt[i].adoptedPetRecords == data[j].getname())
                    {
                        data[j].updateHealth();
                        data[j].updateHappiness();
                        data[j].updateHunger();
                        found = true;
                    }
                }
                break;
            }
        }

        if (found)
        {
            // Remove the adopted pet
            for (int i = 0; i < adopt_no; i++)
            {
                if (adopt[i].adopterName == name)
                {
                    for (int j = i; j < adopt_no - 1; j++)
                    {
                        adopt[j] = adopt[j + 1];
                    }
                    adopt_no--;
                    break;
                }
            }
        }
        else
        {
            cout << "Error! Adopter not found or not adopted any pet." << endl;
        }
    }

    void displayAdoptedPets(Pet data[], Adopter adopt[], int count, int adopt_no)
    {
        for (int i = 0; i < adopt_no; i++)
        {
            cout << "\n----Details of Adopter " << i + 1 << "-----" << endl;
            cout << "Adopter name: " << adopt[i].adopterName << endl;
            cout << "Adopter Mobile Number: " << adopt[i].adopterMobileNum << endl;
            cout << "--Pet Detail Adopted--" << endl;
            for (int j = 0; j < count; j++)
            {
                if (adopt[i].adoptedPetRecords == data[j].getname())
                {
                    cout << "Pet name: " << data[j].getname() << endl;
                    cout << "Health status: " << data[j].getHelthsta() << endl;
                    cout << "Happiness level: " << data[j].getHappiness() << endl;
                    cout << "Hunger level: " << data[j].gethungerlevel() << endl;
                    cout << "Special skill: " << data[j].getspecial() << endl;
                }
            }
        }
    }
};

int main()
{
    Pet data[50];
    Adopter adopt[50];
    int count = 0, adopt_no = 0;
    int choice;
    while (true)
    {
        cout << "\n\n-------Menu------" << endl;
        cout << "1. Add detail of new pet" << endl
             << "2. Display details of all pets" << endl
             << "3. Adopt a pet" << endl
             << "4. Return a pet" << endl
             << "5. Display details of adopted pets" << endl
             << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string name, helth, special;
            int happiness, hunger;
            cout << "\n\nEnter name of pet: ";
            cin >> name;
            cout << "Enter health state of pet: ";
            cin >> helth;
            while (true)
            {
                cout << "Enter the new happiness level(1-10): ";
                cin >> happiness;
                if (happiness >= 1 && happiness <= 10)
                    break;
                else
                    cout << "Error! Happiness scale is within 1 to 10." << endl;
            }
            cout << "Enter the hunger level: ";
            cin >> hunger;
            cout << "Enter Special skill: ";
            cin >> special;
            data[count] = Pet(name, helth, hunger, happiness, special);
            count++;
            break;
        }
        case 2:
        {
            for (int i = 0; i < count; i++)
            {
                cout << "\n\nPet name: " << data[i].getname() << endl;
                cout << "Health status: " << data[i].getHelthsta() << endl;
                cout << "Happiness scale: " << data[i].getHappiness() << endl;
                cout << "Special skills: " << data[i].getspecial() << endl;
            }
            break;
        }
        case 3:
        {
            adopt[adopt_no].adoptPet(data, adopt, adopt_no);
            break;
        }
        case 4:
        {
            adopt[adopt_no].returnPet(data, adopt, count, adopt_no);
            break;
        }
        case 5:
        {
            adopt[adopt_no].displayAdoptedPets(data, adopt, count, adopt_no);
            break;
        }
        case 6:
        {
            cout << "Exiting..." << endl;
            return 0;
        }
        default:
        {
            cout << "Invalid choice! Please enter a valid option." << endl;
        }
        }
    }
    return 0;
}
