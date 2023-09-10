
# include <iostream>

using namespace std;

int main() {
    /* class exercise
    Burning one gallon of gas in your car produces 19.4 lbs of CO2 
    If the subaru outback gets 26 mpg, how much CO2 does this vehicle produce 
    ... if it travels 12,000 miles a year? Print the result 

     */
    double cO2PerGallon = 19.4;
    int subaruMPG = 26.00;
    int milesPerYear = 12000.00;

    double gallonsForSuburu = milesPerYear/subaruMPG;
    cout << gallonsForSuburu << endl;
    double cO2PerYear= gallonsForSuburu * cO2PerGallon;
    cout << "CO2 per year: " << cO2PerYear << endl;

    // modulus 
    int a = 75;
    int b = 50;
    int c = a % b; // a mod b
    cout << "mod: " << c << endl;

    // convert 200 seconds to minutes and seconds 
    /*
    pseudocode: 
    divide seconds by 60 to get whole number of minutes 
        // storing in an integer gets rid of fractional part 
    mod seconds by 60 to get remaining seconds 
    */
    int seconds = 200;
    int secondsInMin = 60;
    int minutes = seconds/secondsInMin; // number of minutes
    int secondsLeftOver = seconds % secondsInMin; // number of remaining seconds

    cout << "200 seconds is " << minutes << " minutes " << secondsLeftOver << " seconds." << endl;

    // branching 
        // a part of code thats only going to run if some line of code is true
    // if else. Block of code runs if a statement is true. Else something else happens
    int x = 10;

    // if is a C++ keyword. Built into the language 
    // statement between () is evaluated. If its true, code between {} will executed 
    // if its false, code is skipped
        // conditions 
        // <, >, <=, >=, ==
        // with two equal signs ==, checking to see if two things are equivalent 
            // = is an assignement operator
            // to evaluate a condition, use == always 
    if ( x < 4) {
        cout << " x is less than 4" << endl; 
    } else if(x==4) {
        cout << " x = 4"<< endl;
    } else {
        cout << " x is eqaul to or greater than 4" << endl;
    } 

    cout << "program done"<<endl;

    // concatenate strings!
    string str = "this is a string";
    string str2 = "another string";
    cout << str + str2 << endl;

    // Conditions :
    /*
     == equivalent
     >= greater or equal
     > greater than 
     < less than 
     <= less than or equal 
     != not equal 
    */

   // USE FLOW CHARTS!
   /* JUST IF
   If condition --> true --> code block 
        --> false (nothing happens)
    This is only an f, no else 
    if(a > 4) {
        cout << "a";
    }
    */
   /* IF ELSE
   If condition --> true --> code block 
        --> false --> code block
   */
    /* IF ELSE IF 
    If conition --> true --> code block
        false --> else if --> true --> code block 
        false --> else if --> true --> code block
        false --> else  --> code block
    
    */

}