#include <iostream>
using namespace std;

void display(string **data, int n) {
    for (int i = 0; i < n; i++) {
        cout<< "\n\nThe details for event "<< i+1 <<":"<<endl;
        cout << "The event name is " << data[i][0] << endl;
        cout << "The event date is " << data[i][1] << endl;
        cout << "The event venue is " << data[i][2] << endl;
        cout << "The event organizer is " << data[i][3] << endl;
    }
    return;
}

void search(string **data, int n) {
    bool flag = false;
    string date;
    
    cout << "Enter the date (DD/MM/YY) you want to search for: ";
    cin >> date;

    for (int i = 0; i < n; i++) {
        if (data[i][1] == date) {
            cout << "The event name is " << data[i][0] << endl;
            cout << "The event date is " << data[i][1] << endl;
            cout << "The event venue is " << data[i][2] << endl;
            cout << "The event organizer is " << data[i][3] << endl;
            flag = true;
            break;  // exit the loop once a match is found
        }
    }

    if (!flag) {
        cout << "Event not found for the given date." << endl;
    }

    return;
}

int main() {
    int n;
    cout << "Enter the number of events you wish to manage: ";
    cin >> n;

    string **data = new string*[n];  // fix memory allocation

    for (int i = 0; i < n; i++) {
        data[i] = new string[4];
    }

    for (int i = 0; i < n; i++) {
        cout << "\n\nEnter the details for event " << i + 1 << ":" << endl;
        cout << "Enter the name of event: ";
        cin >> data[i][0];
        cout << "Enter the date (DD/MM/YY) of the event: ";
        cin >> data[i][1];
        cout << "Enter the venue for the event: ";
        cin >> data[i][2];
        cout << "Enter the name of the event organizer: ";
        cin >> data[i][3];
    }

    int choice;
    while (1) {
        cout << "\n\n1. Display data\n2. Event search\n3. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                display(data, n);
                break;
            case 2:
                search(data, n);
                break;
            case 3:
                return 0;
            default:
                cout << "Error! Choose the correct choice." << endl;
        }
    }

    // Free allocated memory before exiting
    for (int i = 0; i < n; i++) {
        delete[] data[i];
    }
    delete[] data;

    return 0;
}
