// In mathematics, there are often many ways to decide how far two points are from each other. 
// Write a program to calculate the distance between two points in two different ways, 
    // depending on what the user asks for. All points are 2-dimensional, each has an x component and a y component

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>

using namespace std;

double calculateDistance(double distance_type, double x1, double y1, double x2, double y2) {
    double distance;
    double distancex = x2 - x1;
    double distancey = y2 - y1;
    if(distance_type == 1) {
        distance = abs(x2 - x1) + abs(y2 - y1);

    } else if (distance_type == 2) {
        distance = sqrt(pow(distancex, 2) + pow(distancey, 2));
    }

    return distance;
}

int main() {
    double distance_type;
    double x1;
    double y1;
    double x2;
    double y2;
    
    cout << "Enter distance type: " << endl;
    cin >> distance_type;
    if(distance_type != 1 && distance_type != 2) {
        cout << "Invalid distance type!" << endl;
        return 0;

    }
    cout << "Enter x1: " << endl;
    cin >> x1;
    cout << "Enter y1: " << endl;
    cin >> y1;
    cout << "Enter x2: " << endl;
    cin >> x2;
    cout << "Enter y2: " << endl;
    cin >> y2;

    double distance = calculateDistance(distance_type, x1, y1, x2, y2);
    cout << "The distance between the points is: " << fixed << setprecision(3) << distance << endl;



}