#include <iostream>
using namespace std;

class ValidateString {
public:
    void check_string(const string &check) const {
        int size = check.size();
        bool flag = true;
        for (int i = 0; i < size; i++) {
            if ((check[i] >= 'a' && check[i] <= 'z') || (check[i] >= 'A' && check[i] <= 'Z') || check[i] == ' ') {
                continue;
            } else {
                flag = false;
                break;
            }
        }
        if (flag)
            cout << "This string is valid." << endl;
        else
            cout << "This string is invalid." << endl;
    }
};

int main() {
    ValidateString validator;
    while (true) {
        int choice;
        cout << "Menu" << endl
             << "1. Check new string"<< endl
             << "2. Exit" << endl;
        cin >> choice;
        switch (choice) {
            case 1: {
                string input;
                cout << "Enter the string: ";
                cin.ignore(); // Clear the buffer
                getline(cin, input);
                validator.check_string(input);
                break;
            }
            case 2:
                return 1;
                break;
            default:
                cout << "Error! Enter a valid choice." << endl;
                break;
        }
    }
    return 0;
}
