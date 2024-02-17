/*Programer: Talha Rusman
  Roll_N0: 23K0065
  */
#include<iostream>
using namespace std;

class WeekDays {
    string Days[7];
    int CurrentDay;

public:
    WeekDays() {
        Days[0] = "Sunday";
        Days[1] = "Monday";
        Days[2] = "Tuesday";
        Days[3] = "Wednesday";
        Days[4] = "Thursday";
        Days[5] = "Friday";
        Days[6] = "Saturday";
    }

    WeekDays(int Current) {
        if (Current > 6) {
            Current %= 7;
        }
        this->CurrentDay = Current;
    }

    string getCurrentDay() {
        return Days[CurrentDay];
    }

    string getNextDay() {
        if (CurrentDay + 1 > 6)
            return Days[0];
        else
            return Days[CurrentDay + 1];
    }

    string getPreviousDay() {
        if (CurrentDay - 1 < 0)
            return Days[6];
        else
            return Days[CurrentDay - 1];
    }

    string getNthDayFromToday(int nth) {
        int total = CurrentDay + nth;
        if (total > 6)
            total %= 7;
        return Days[total];
    }
};

int main() {
    WeekDays a;
    int nth = 0;
    a = WeekDays(4);
    cout << "current day: " << a.getCurrentDay() << endl;
    cout << "next day: " << a.getNextDay() << endl;
    cout << "previous day: " << a.getPreviousDay() << endl;

    cout << "Enter nth number to get nth day from current day: ";
    cin >> nth;
    cout << "Nth day from today is: " << a.getNthDayFromToday(nth) << endl;

    return 0;
}
