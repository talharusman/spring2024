#include <iostream>
using namespace std;

inline float batting_average(int Total_Runs, int dismissed) {
    return static_cast<float>(Total_Runs) / dismissed;
}

inline float strike_rate(int total_runs, int total_balls) {
    return (static_cast<float>(total_runs) / total_balls) * 100;
}

int main(int argc, char const *argv[]) {
    int Total_Runs, Total_Ball, dismissed;

    cout << "Enter the total number of runs: " << endl;
    cin >> Total_Runs;

    cout << "\nEnter the total balls Player faced:" << endl;
    cin >> Total_Ball;

    cout << "\nEnter the number of times player dismissed:" << endl;
    cin >> dismissed;

    cout << "Batting average is: " << batting_average(Total_Runs, dismissed) << endl;
    cout << "Strike rate is: " << strike_rate(Total_Runs, Total_Ball) <<"%"<< endl;

    return 0;
}
