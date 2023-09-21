
#include <iostream>

using namespace std;

double estimatePaintingTime(double totalArea, char painter) {
    double timeMinutes = 0;
    double time = 0;

    switch (painter) {
        case 'W': 
            timeMinutes = (12.0 * (totalArea))/5.0;
            time = timeMinutes/60.0;
            break;
        case 'X': 
            timeMinutes = (10.0 * (totalArea))/3.0;
            time = timeMinutes/60.0;
            break;
        case 'Y': 
            timeMinutes = (5.0 * (totalArea))/2.0;
            time = timeMinutes/60.0;
            break;
        case 'Z': 
            timeMinutes = (15.0 * (totalArea))/7.0;
            time = timeMinutes/60.0;
            break;
        default:
            return -1;
    }

    return time;
}

int main() {
    double totalArea;
    char painter;

    // ask user for input
    cout << "Enter area of the four walls (in sq ft) " << endl;
    cin >> totalArea;
    cout << "Select a painter (W, X, Y or Z) " << endl;
    cin >> painter;

    double time = estimatePaintingTime(totalArea, painter);

    if (time == -1 || totalArea <= 0) {
        cout << "Please enter a valid input" << endl;
    } else {
        cout << "The time taken to paint all four walls by painter " << painter << ": " << time << " hours" << endl;
    }

    return 0;
}