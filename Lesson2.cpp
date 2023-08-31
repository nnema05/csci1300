
// Hello World 
// Coments: Words that will not executue

/* VARIABLES
-We need to represent data 
-USE VARIABLES
-Variables - represent the abstraction of the type of information 
-We can: 
    - Define a variable
    - Modify a variable 
    - Check if a statement is true or false 
    - Repeat a block of code 
    - get an input or produce an output 

    - Define a function (code that does something)
*/

// C++ has libraries (commonly used library)
    // One library is called iostream
#include <iostream>

// Name space 
using namespace std;

// Every program starts at a main function 
    // This is the first code that is executed when the function is run
int main() {

    // main function is everything between the {}

    // cout is print, << is an output stream indictaor
        // everything coming after these is whats written
        // endl ends a line
    cout << "hello world" << endl;
    cout << "this is csci 1300" << endl;

    // what is variable? 
        // Location is memory that can store a value and accessed with a label 
    int a = 5; // variable name is a, it is an integer type, it has a value of 5
        // If you say you have an integer, the computer will you 4 bytes of memory and in it is 5
        // The memory location is called the variable name (a) and inside of it is the value 5
    int b; // what is the value of b?
        // the value of b is unknown and undertermined
        // it will be a garabge value of stuff that is floating around in that memory place
    cout << " a = " << a <<endl; // this is print " a = " string and then the value in a 
    cout << " b = " << b <<endl; // this is print " b = " string and then the value in b 

    // Setting a equal to itself + 1  
        // get existing value of a, add 1 to it and then put it back 
    a = a + 1;
    cout << " a = " << a <<endl;

    // Double 
    double d = 4.5; // floating point, decimal values allowed
    string s = "this is a string"; // a string is alpha-numeric literal 
    double e = 3.4;
    double f = d + e; // addition operator
    string s2 = "another string";
    string s3 = s + s2;
    cout << s3 << endl;
}

// HOW TO RUN 
    // SAVE
    // g++ Lesson2.cpp -o Lesson2
    // this creates an executeable file called Lesson2
    // RUN executeable: ./Lesson2 