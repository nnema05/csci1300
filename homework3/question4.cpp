
#include <iostream>

using namespace std;

double calculatePaintCost(double totalArea, char paintGrade) {
    double cost = 0;
    switch (paintGrade) {
        case 'A': 
            cost = .75 * totalArea;
            break;
        case 'B': 
            cost = 1.25 * totalArea;
            break;
        case 'C': 
            cost = 2.75 * totalArea;
            break;
        default:
            return -1;
    }

    return cost;
}

int main() {
    double totalArea;
    char paintGrade;

    // ask user for input
    cout << "Enter area of the four walls (in sq ft) " << endl;
    cin >> totalArea;
    cout << "Select the paint grade (A, B, or C) " << endl;
    cin >> paintGrade;

    double cost = calculatePaintCost(totalArea, paintGrade);

    if (cost == -1 || totalArea <= 0) {
        cout << "Please enter a valid input" << endl;
    } else {
        cout << "The total cost to paint all four walls: $" << cost << endl;
    }

    return 0;
}