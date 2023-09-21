#include <iostream>

using namespace std;

// function prototype - function definition without the implementation 
// structure 
double pyramidVolume(double height, double base_length); // prototype for pyramid volume
void printMessage(string str);


int main(){
    //this code is the starting point for today's lecture.
    //note: the file won't compile as it's currently written
    //you will submit the modified code at the end of lecture as your participation
    //topics include function prototypes, string examples, test cases
    
    cout<<pyramidVolume(10, 5)<<endl; //prints output to screen, but doesn't store in any variable
    double pv = pyramidVolume(10, 5); 
    cout<<"pyramid volume = "<<pv<<endl;

    printMessage("welcome to CSCI1300");

    //writing test cases
    // TEST CASES ARE INPUTS, checking if these inputs work/dont work in the program to see
        // if the program overall works
        /*black box testing - give input, compare output. This is what coderunner
    has done so far. Not checking how you write the solution, only that the
    output matches the expected output */
        /*white box testing - give input, look at code to determine correctness.
    We disallow global variables and will check if they're used in
    awarding points for solution.*/
    /*
    Two types of test cases we'll focus on
    
    check that inputs are valid
    check range of different inputs
    
    We'll look at Homework 2, #4,
    Test cases:
    4 correct logic, character input, and budget 
    4 seat is correct and budget is wrong 
    4 seat was lowercase, budget correct
    1 invalid budget (budget < 0)
    1 incorrect seat  
    
    and then Q3 and Q4
    from Homework 3 to write test cases.
    test case 1: Uses ints, good for testing that math is correct 
    program will pass the test case, even if written with integers

    test case 2: requires doubles to pass the case. checking that data types are correct

    remaining two cases check for positive input values
        only need one case two check for invalid input

    */


    /*FizzBuzz problem.
    Given an integer n, for every integer i <= n, 
    the task is to print “FizzBuzz” if i is divisible by 3 and 5, 
    “Fizz” if i is divisible by 3, 
    “Buzz” if i is divisible by 5, 
    or i if none of the conditions are true.

    What are the test cases?
    one where i is divisible by 3 (i % 3 = 0) : 9, 12, 18
    one where i is divisible by 5 (i % 5 = 0) : 10, 20
    one where i is divsible by 3 and 5 (i % 3 = 0 and i % 5 = 0): 15, 30, 45
    one where i is not divisible by either 3 or 5 (i % 3 != 0 and i % 5 = 0), 0, 22
    */
    // CODE
    int i = 5;
    if(i % 3 == 0 && i % 5 == 0) {
        cout << "fizzbuzz" << endl;
    } else if (i % 3 == 0) {
        cout << "fizz" << endl;
    } else if (i % 5 == 0) {
        cout << "buzz" << endl;
    } else {
        cout << i << endl;
    }
    string str1 = "Go";
    string str2 = "Buffs";

    cout << "String concatenation = " << str1 + str2 << endl;
    cout << "String concatenation (with spaces) = " << str1 + " " + str2 + "!" << endl;

    // Find and Replace Functions
    string larger_string = "Use the find function to find the occurence of a substring within a string";
    string word_to_find = "occurence";



}
double pyramidVolume(double height, double base_length){ //arguments put the variables in scope
//height and base_length are local to pyramidVolume function
    double base_area = base_length * base_length;
    double volume = 1.0/3.0 * height * base_area;
    return volume;
}
void printMessage(string msg){
    cout<<msg<<endl;
}

