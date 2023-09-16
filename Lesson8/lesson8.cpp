
#include <iostream>

using namespace std;

/* Function syntax
<type> function name (<type> argurment name, ...) 
The type of my function needs to match the type of my return value
*/


// This function adds two integers and returns the sum 
// Function definition 
int mySum(int a, int b) {
    return a + b; // return value is an int
}

// Write a function that takes two doubles and returns the first double / second double
// Return the result 
double myDiv(double x, double y) {
    return x / y;
}

// Write a function for if statement
    // this would return nothing so void
void numberFun(int number) {
    if (number == 0) {
        cout << "number is 0" << endl;
    } else if (number > 0){
        cout << "positive " << endl;
    } else {
        cout << "negative " << endl;
    }

    // aboslute value function is c++ 
    // abs(integer)
    if(abs(number) < 5) {
        cout << "small" << endl;
    } else if (abs(number) > 10000) {
        cout << "large" << endl;
    }
}



// Write function that takes no arguement and doesn't return anything
// Prints "Welcome to CSCI 1300"
// Functino that doens't return a value is a void type 
void printMessage() {
    cout << "Welcome to CSCI 1300" << endl;
    // there's no return here
}

// Write a function called pyramid volume that calcultaes volume of a pyramid  
    // function takes two agruements, height and base_length, both doubles and returns the volume
    // volume calculated using 1/3 * height * base_area 
    // base_area = base_length * base length 
double pyramidVolume (double height, double base_length) { // agruements put the variables in scope
    // height and base_length are local to pyramidVolume function
    double base_area = base_length * base_length;
    double volume = 1.0/3.0 * height * base_area;
    return volume; 
}

void scopeTest() {
    int a = 5; // a is defined in this function. Local to the function
    cout << a << endl;
}

int main () {
    int a;
    // cout << a << endl; // a is out of scope INSTEAD
    // execute scope text. This creates vairable a, which is local to function
    scopeTest();
    cout << a << endl;


    /* function is a block of code 
    - attached to a lable, also called a name
    - run the code when the name is used in our prorgam 
    - function has a name, a type, arguements and an output  */ 

    // A FUNCTION PERFORMS A TASK!
        // We give it a name to reflect what that task is 

    // A main function is the function that runs first when your rporgam executes 
        // it returns 0 <- this is how cpu knows program runned succesfully 
    
    int c = mySum(10, 15); // function call
    cout << c << endl;

    double z = myDiv(100, 200);
    cout << z << endl;

    printMessage(); // function call. 
        // Notice that there is no variable being set to the value of this function because there is no returned value

    numberFun(5); // Function call 
    numberFun(100); 

    cout << pyramidVolume(10, 5) << endl; // prints output to screen, but doesn't store in any variable
    double pv = pyramidVolume(10, 5);
    cout << "pyramid volume = " << pv << endl;

    // variable scope 
    // Where variable matters 

    return 0;

}
