
#include <iostream>

using namespace std;

int main() {
    // relational operator not, !=, !
    int b = 5;

    // be is not equal to 5
    if(b != 5) {
        cout << "b not equal 5" << endl;
    } else {
        cout << "b = 5" << endl;
    }

    // boolean variables and operators 
    // variable type called a bool 
        // holds true and false 
        // bool has only 2 values, same as 1 or 0
    bool flag = true; // true = 1, false = 0
    cout << flag << endl; // this will print a 1
    int a = 6;
    // flag is the true or false of a < 10
    flag = (a < 10); // (a < 10) will evaluate to true, 1 
    cout << flag << endl; // this will print a 1 because (a < 10) is true

    // code is just evaluating for a
        // if a = 0, it will be treated as a false boolean result
        // if a != 0, it will be treated as a true boolean result  
    if(a) { // please don't actually do this! set a condition on the varaible to evaluate
        cout << "conditional is true" << endl;
    } else {
         cout << "conditional is true" << endl;
    }

    a = -5;
    // truth tables 
    if(a < 0 || a > 10) {  // || this is an or statement 
        cout << "a is good" << endl;
    } else {
         cout << "something is wrong" << endl;
    }
    
    // OR truth table 
    /*
    T or T = T
    T or F = T 
    F or T = T
    F or F = F
    */

   // AND truth table 
   /*
    T and T = T
    T and F = F 
    F or T = F
    F or F = F
   */
    a = 5;
    b = 10;
    if (a < 10 && b > 0) {
        cout << "both are true" << endl;

    } else {
        cout << "something is false" << endl;
    }
    int x = 200;
    cout << (0<200<100) << endl; // THIS WILL NOT WORK 
        // this will evaluate 0 < 200, which is true. then will check 1 < 100 sso ends up being true 
    cout << (0<x && x<100) << endl;

    // nested comditions 
    if(a < 10) {
        // we know a < 10, lets check on b
        if (b < 6) {
            cout << "a < 10, b > 6" << endl;
        } else {
            // a < 10, b <= 6
            cout << "a < 10, b <= 6" << endl;
        }
    } else {
        // here? values of a and b? 
            // a >= 10 and know nothing about b that pushed us into this else 
        if (b > 6) {
            cout << "a > 10, b > 6" << endl;
        } else {
            cout << "a >= 10, b <= 6" << endl;
        }
    }
    /* write a program that takes an integer and prints "zero" if the number is 0
    other wise print "positive" or "negative"
    Add "small" if the absolute value of the number if < 5 
    and large if > 1,000, 000. 
    Don't reapeat the absolute value calculation*/

    int integer = 4;
    if (integer == 0) {
        cout << "0" << endl;
    } else {
        if (integer > 0) {
            cout << "positive" << endl;
        } else {
            cout << "negative" << endl;
        }

    }

}
