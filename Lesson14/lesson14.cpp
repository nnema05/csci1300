
#include <iostream>
using namespace std;

// function prototypes!
void printValue();
int printValue2();

// EXAMPLE OF NOT READABLE CODE!
int main() {
    int x = 0;
    // this creates an infinit loop and then breaks it in the loop
        // infinite loop because the condition true will always be true
    while(true) { // you may also see this as while(1)
        cout << "this is a loop" << endl;
        if (x > 5) {
            break; // break will exit out of loop
        }
        x++;
    }

    // how do we write this loop to be more readable?
        // this style is prefered!
    x = 0;
    while (x <= 5) {
        cout << "this is a loop" << endl;
        x++;
    }

    // EXAMPLE OF NOT READABLE CODE!
    // infinite loop, the conditional will break the loop 
    // prints "inputs"
    // asks for user input and store in x each time through loop
    // adds value of x to sum 
    // will break when sum > 29
    int sum = 0;
    x = 0;
    for(cout << "inputs"; cin >> x; sum = sum + x){
        cout << "sum=" << sum << endl;
        if(sum >20) {
            break;
        }
    }

    // how do I write this as a while loop
    sum = 0;
    x = 0;
    cout << "inputs" << endl; // we only want to print inputs once
    while(sum > 20) {
        cin >> x; // get input and store in x
        sum = sum + x;
        cout << "sum= " << sum << endl;
    }

    // translate for loop to while loop could be on midterm exam

    // MIDTERM 
    // 90 minutes 
    // paper
    // multiple choice
    // one page of hand written notes, front and back, 8.5 X 11
    // bring a pencil and maybe a backup pencil 
    // rooms are tbd. you will recieve an email next week with your room 
    // Thursday, 6:30pm 
    // WHat is on exam!
        // data type - int, double, char, string, bool
        // operators --> +, -, *, /, %
        // connditionals - if, else if, else, switch statements
        // functions - inputs, output, format, return types, function calls 
        // loops - while
        // pseudocode - what is it, translate to real code and vice versa
        // flow charts - focus on conditionals!

    // void function vs function that returns a value
    printValue(); // this calls a void function. No variable in main
    x = printValue2(); // this calls a function that returns an int.
    // needs to be stored as an int in main
}

// this function doesn't produce a value 
void printValue() {
    // do something
}

// this function produces a value
    // the return value has to be the same type as the function definition
int printValue2() {
    // do something 
    // return something 
    return 5;
}