#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>

using namespace std;

class manu {
public:
    vector<string> name;
    vector<float> price;

    void set_Add() {
        string foodName;
        float foodPrice;

        cout << "\n\nEnter the name of Food: ";
        cin.ignore();
        getline(cin, foodName);
        name.push_back(foodName);

        cout << "Enter the price of the Food: ";
        cin >> foodPrice;
        price.push_back(foodPrice);
    }

    void remove_iteam() {
        string Foodname;
        cout << "\n\nEnter name of Food you want to remove: ";
        cin >> Foodname;
        bool flag = false;
        for (int i = 0; i < name.size(); i++) {
            if (name[i] == Foodname) {
                name.erase(name.begin() + i);
                price.erase(price.begin() + i);
                flag = true;
                break;
            }
        }
        if (!flag) {
            cout << "Error! This item is not found." << endl;
        } else {
            cout << "---Item is removed successfully---" << endl;
        }
    }

    void display() {
        cout << "\n\n"<<left<<setw(25)<<"Food Name" << setw(20) << "Price" << endl;
        for (int i = 0; i < name.size(); i++) {
            cout << left << setw(25) << name[i] << setw(25) << price[i] << endl;
        }
    }
};

class Payment {
    manu obj;

public:
    void Bill(manu menu, string foodname[30][2], int count) {
        float total = 0;
        cout << "\n\n======= Bill =======\n";
        cout << "\n"<<left<< setw(25)<<"Food Name" << setw(20) << "Price" <<setw(10)<<"No"<<setw(20)<<"Total"<< endl;
        for (int i = 0; i < count; i++) {
            bool found = false;
            for (int j = 0; j < menu.name.size(); j++) {
                if (foodname[i][0] == menu.name[j]) {
                    cout << left << setw(25) << foodname[i][0] << setw(20) << menu.price[j] <<setw(10) << stoi(foodname[i][1])<<setw(20)<< menu.price[j] * stoi(foodname[i][1]) << endl;
                    total += menu.price[j] * stoi(foodname[i][1]);
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << left << setw(25) << foodname[i][0] << setw(25) << "Not Available" << endl;
            }
        }
        cout << "\nTotal: " << total << endl;
    }
};

class Restaurant_ordering_system {
    Payment payment;

public:
    void Ordering(manu menu) {
        string FoodNames[30][2];
        int count;
        cout << "\n\nEnter how many items you want to buy: ";
        cin >> count;
        for (int i = 0; i < count; i++) {
            cout << "Enter the name of product " << i + 1 << ": ";
            cin >> FoodNames[i][0];
            cout << "How many do you want to buy it: ";
            cin >> FoodNames[i][1];
        }
        system("cls");

        payment.Bill(menu, FoodNames, count);
    }
};

int main() {
    manu menu;
    Restaurant_ordering_system orderingSystem;

    while (true) {
        int choice;
        cout << "\n\nMenu" << endl
            << "1. Add Item" << endl
            << "2. Remove Item" << endl
            << "3. Display Menu" << endl
            << "4. Order something" << endl
            << "5. Exit" << endl
            << "   Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            menu.set_Add();
            system("cls");
            break;
        case 2:
            menu.remove_iteam();
            system("cls");
            break;
        case 3:
            system("cls");
            menu.display();
            break;
        case 4:
            orderingSystem.Ordering(menu);
            break;
        case 5:
            return 0;
        default:
            cout << "Error! Enter a valid choice." << endl;
            break;
        }
    }

    return 1;
}
