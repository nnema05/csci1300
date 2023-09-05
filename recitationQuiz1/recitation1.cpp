
// Quiz 
// Find out number of days, hours, minutes, seconds
#include <iostream>
#include <cmath>

using namespace std;

int main () {
    int numberOfSeconds;
    cout << "Enter number of seconds: " << endl;
    cin >> numberOfSeconds;

    int secondsInADay = 86400; 

    // Get number of days
    int W = floor(numberOfSeconds/secondsInADay); // floor this integer
    cout << W << endl;

    // Find remaining number of seconds after getting days
    int remainderOfW = numberOfSeconds%secondsInADay;
    cout << remainderOfW << endl; 

    // Get number of hours 
    int X = floor(remainderOfW / 3600);
    cout << X << endl;

    // Find remaining number of seconds after getting hours
    int remainderOfX = remainderOfW % 3600;
    cout << remainderOfX << endl;

    // Get number of minutes 
    int Y = floor(remainderOfX / 60);
    cout << Y << endl;

    // Number of seconds is just remainder from finding number of minutes
    int Z = remainderOfX%60;

    cout << "The time is " << W <<  " days, " << X << " hours, " << Y << " minutes, and " << Z << " seconds";


}