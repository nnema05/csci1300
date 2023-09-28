
#include <iostream>
#include <iomanip>

using namespace std;

// There are several big football games coming up, and in preparation, you need to write a program to figure out how to keep Ralphie in good shape. 
// Ralphie needs at least 12.5 MCals (mega-calories) per day, at least 16.5 MCals on game days to fuel up for the run.
// Ralphie should never be fed more than 35 MCals over two consecutive days. Below is the schedule for the next week:
// Monday: No game
// Tuesday: No game
// Wednesday: Game day!
// Thursday: No game
// Friday: No game
// Saturday: Game day!
// Sunday: Game day!

void calculateAndDisplayDiet(int current_day, double previous_days_feed) {
    double food_left;

    if(current_day == 0 || current_day == 1 || current_day == 3 || current_day == 4) {
        if(previous_days_feed + 12.5 > 35) {
            cout << "Ralphie was fed too much yesterday!" << endl;

        } else {
            food_left = 35 - previous_days_feed;
            cout << "Ralphie should be fed at least 12.50 and at most " << fixed << setprecision(2) << food_left << " MCals of food today." << endl;

        }
    }

    if(current_day == 2 || current_day == 5 || current_day == 6) {
        if(previous_days_feed + 16.5 > 35) {
            cout << "Ralphie was fed too much yesterday!" << endl;

        } else {
            food_left = 35 - previous_days_feed;
            cout << "Ralphie should be fed at least 16.50 and at most " << fixed << setprecision(2) << food_left << " MCals of food today." << endl;

        }
    }
}

int main() {
    int current_day;
    double previous_days_feed;

    cout << "What day is it today? Enter a number from 0 to 6: " << endl;
    cin >> current_day;
    if (current_day != 0 && current_day != 1 && current_day != 2 && current_day != 3 && current_day != 5 && current_day != 6) {
        cout << "Invalid input!" << endl;
        return 0;
    }

    cout << "How much was Ralphie fed yesterday? Enter an amount in MCals: " << endl;
    cin >> previous_days_feed;
    if (previous_days_feed < 0) {
        cout << "Invalid input!" << endl;
        return 0;
    }

    calculateAndDisplayDiet(current_day, previous_days_feed);

}
