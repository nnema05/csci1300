
/* QUESTION 6: Combine question 3, 4, 5
QUESTION 3: As a promising C++ programmer, you've been presented with an exciting opportunity by a reputable paint supplying company. 
They are seeking your expertise to develop a user-friendly C++ program that streamlines the process for their customers to estimate the cost of purchasing paint. 
This program will enable users to estimate the rough area of the four primary exterior walls of their house, 
QUESTION 4: which they can later use to calculate the required volume of paint and its cost. A
QUESTION 5: Additionally, the program offers users the option to hire painters, each with their own painting pace, to estimate the time needed to complete the painting project.
*/

#include <iostream>

using namespace std;

double calculateWallArea(double length, double width) {
    double areaOne = length * 10;
    double areaTwo = width * 10;
    double totalArea = (2 * areaOne) + (2 * areaTwo);
    return totalArea;

}


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

int main () {
    char option;
    cout << "Choose an option" << endl;
    cout << "1. Calculate Exterior Wall Area" << endl;
    cout << "2. Calculate Paint Cost" << endl;
    cout << "3. Estimate Painting Time" << endl;
    cout << "4. Exit " << endl;
    cin >> option;

    // create user input variables
    double length;
    double width;
    double totalArea;
    char paintGrade;
    char painter;

    if(option == '1') {
        // ask user for input
        cout << "Enter length of the base of the house (in ft) " << endl;
        cin >> length;
        cout << "Enter width of the base of the house (in ft) " << endl;
        cin >> width;

        if (length <= 0 || width <= 0) {
            cout << "Please enter a valid input" << endl;
        } else {
            double totalArea = calculateWallArea(length, width);
            cout << "The total area of all the four walls: " << totalArea << " sq ft" << endl; 
        }
    } else if (option == '2') {

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
    } else if (option == '3') {
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
    } else if (option == '4') {
        cout << "Thank you!" << endl;
        return 0;

    } else if (option != '1' || option != '2' || option != '3' || option != '4') {
        cout << "Please enter a valid input" << endl;
    }

    return 0;


}