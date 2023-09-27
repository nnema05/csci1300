
#include <iostream>

using namespace std;

int manageFeeder(int feeder, int days_since_last_fill) {
    int days_till_fill_feeder;
    int remaining_feeder_1;
    int remaining_feeder_2;
    int remaining_feeder_3;

    switch(feeder) {
        case 1:
            remaining_feeder_1 = 21 - 3*days_since_last_fill;
            if (remaining_feeder_1 <= 0) {
                days_till_fill_feeder = 0;
            } else {
                days_till_fill_feeder = remaining_feeder_1/3;
            }
            break;
        case 2:
            remaining_feeder_2 = 37 - 2*days_since_last_fill;
            if (remaining_feeder_2 <= 0) {
                days_till_fill_feeder = 0;
            } else {
                days_till_fill_feeder = remaining_feeder_2/2;
            }
            break;
         case 3:
            remaining_feeder_3 = 17 - 4*days_since_last_fill;
            if (remaining_feeder_3 <= 0) {
                days_till_fill_feeder = 0;
            } else {
                days_till_fill_feeder = remaining_feeder_3/4;
            }
            break;
    }

    return days_till_fill_feeder;
}

int main () {
    int days_feeder_1;
    int feeder1 = 1;
    int days_feeder_2;
    int feeder2 = 2;
    int days_feeder_3;
    int feeder3 = 3;
    cout << manageFeeder(feeder1, days_feeder_1);

    cout << "How many days ago was feeder 1 filled? " << endl;
    cin >> days_feeder_1;
    if (days_feeder_1 < 0) {
        cout << "Invalid input!";
        return 0;
    }

    cout << "How many days ago was feeder 2 filled? " << endl;
    cin >> days_feeder_2;
    if (days_feeder_2 < 0) {
        cout << "Invalid input!";
        return 0;
    }

    cout << "How many days ago was feeder 3 filled? " << endl;
    cin >> days_feeder_3;
    if (days_feeder_3 < 0) {
        cout << "Invalid input!";
        return 0;
    }

    int days_till_fill_feeder1 = manageFeeder(feeder1, days_feeder_1);
    int days_till_fill_feeder2= manageFeeder(feeder2, days_feeder_2);
    int days_till_fill_feeder3 = manageFeeder(feeder3, days_feeder_3);

    cout << "Feeder 1 will need to be filled in " << days_till_fill_feeder1 << " days, feeder 2 will need to be filled in " << days_till_fill_feeder2 << " days, and feeder 3 will need to be filled in " << days_till_fill_feeder3 << " days.";

    return 0;


    
}