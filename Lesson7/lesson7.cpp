
#include <iostream>
#include <cstdlib> // this is the library that includes the abolsute value function

using namespace std;

// Define a function 
    // this function will return a sum of two numbers
    // when you pass an arguement into this, there should be 2
    // function has two arguements, both integers called a and b
    // it returns an integer
int mySum(int a, int b) {
    return a + b;
}

int main() {
    
    // call mySum function in main function!
    int c;
    c = mySum(10, 15); // call the function and set c equal to the return value
        // the arguements are 25
    cout << "c = " << c << endl;
    
    // warm up exercise 
    /* 
    Write code that takes in inputs of mpg of a vehicle and miles per year
    If mpg is greater than 30 and miles per year is less than 10,000,
    print a message that says "Great job "
    Otherwise, print a message that says big polluter
    */

   int miles;
   int mpg;

   cout << "Enter mpg of vehicle " << endl;
   cin >> mpg;
   cout << "Enter miles per year " << endl;
   cin >> miles;

   if (mpg > 30 && miles < 10000) {
        cout << "Great job" << endl;

   } else {
        cout << "Big Polluter" << endl;
   }

   /* write a program that takes an integer and prints "zero" if the number is 0
    other wise print "positive" or "negative"
    Add "small" if the absolute value of the number if < 5 
    and large if > 1,000, 000. 
    Don't reapeat the absolute value calculation*/

    int integer = 4;
    if (integer == 0) {
        cout << "0" << endl;
    } else if (integer > 0){
        cout << "> 0" << endl;
    } else {
        cout << "< 0" << endl;
    }
    // aboslute value function is c++ 
    // abs(integer)
    if(abs(integer) < 5) {
        cout << "smaller" << endl;
    } else if (abs(integer) > 10000) {
        cout << "large" << endl;
    } else {
        cout << "nothing special" << endl;
    }


    /* 
    Given two corner points on a rectangle, determine if the rectangle has a portrait 
    or a landsapce oritenation or is square. You can assume that the points are the 
    bottom left and upper right corners of the rectangle. Also they are positive 
    */
    // STEPS: 
    // draw a few examples to idenitify a pattern, identify inputs
    // come up with simple theory and see where it fails 
    // change in x and change in x and the change in y to solve the problems
    // FOUR VARIABLES
    double x1 = 0.0;
    double x2 = 3.0;
    double y1 = 0.0;
    double y2 = 10.0;

    // find change in x and change in y
    double changeInX = x2 - x1;
    double changeInY = y2 - y1;

    // Create conditions
    // if chnage in x = change in y, then we have a square
    // if change in x > change in y, then we have landscape
    // if change in y > change in x, then we have a portrait 

    if (changeInX == changeInY) {
        cout << "sqaure" << endl;

    } else if (changeInX > changeInY) {
        cout << "landscape" << endl;
    } else {
        cout << "portrait" << endl;
    }


    // Functions!


    }

   