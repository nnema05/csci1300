
// Question 3: function to calculate the area of the exterior walls of a house.

#include <iostream>

using namespace std;

double calculateWallArea(double length, double width) {
    double areaOne = length * 10;
    double areaTwo = width * 10;
    double totalArea = (2 * areaOne) + (2 * areaTwo);
    return totalArea;

}

int main () {

    // create user input variables
    double length;
    double width;
    double totalArea;

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
    return 0;

}