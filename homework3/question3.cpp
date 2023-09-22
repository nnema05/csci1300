
/* QUESTION 3
As a promising C++ programmer, you've been presented with an exciting opportunity by a reputable paint supplying company. 
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