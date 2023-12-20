
/* 
RECURSIVE FUNCTION
    - function that calls itslef
    - Recursive call: call with the smallest input 
    - Base case : smallest case. no additional calls 


EXAMPLE 1
countDown(n) {
     cout << n << "" << endl;
    if (n==0) {
        return;
    }
    else {
        countDown(n-1) // function calls itslef with a value of n - 1
            // going to continue printing n and decremiting n until n = 0
    }
}
// WILL PRINT 5, 4, 3, 2, 1, 0 
main() {
    countDown(5)
}

EXAMPLE 2
countDown(n) {
    if (n==0) {
        return; // return to the previous function call and continues through (doesnt call the function again)
            // then it couts!!
    }
    else {
        countDown(n-1) // function calls itslef with a value of n - 1
            // going to continue printing n and decremiting n until n = 0
    }
    cout << n << "" << endl;
}
// WILL PRINT 1, 2, 3, 4, 5

main() {
    countDown(5)
}

EXAMPLE 3
void PrintTriagnle(side_length) {
    // should print 
    *
    **
    ***
    ****
    if(side_length < 1) {
        return;
    } else {
        printTriangle(side_length - 1) 
    }
    for(int i = 0; i < side_length; i++) { 
        cout << "*" << endl;
    }
}

main() {
    printTriangle(4)
    // the last call will be where side length is going to equal 0
        // so we will return to the call where side_length = 1
            // so will print *
            // then exit and return to the print triangle side_length = 2
            // then will print **
            // then exit and return to the print triangle side_length = 3
            // then will print ***
            // then exit and return to the print triangle side_length = 4
            // then will print ****
        
} */


#include <iostream>
using namespace std;

void PrintTriangle(int side_length) {
    if(side_length < 1) { // base case
        cout << "base case " << endl;
        return;
    } else {
         cout << "side_length - 1" << side_length - 1 << endl;
        PrintTriangle(side_length - 1);
    }
    // print here
    for(int i =0; i < side_length; i++) {
        cout << "*";
    }
    cout << endl;
}
void countDown(int n) {
    // cout << n << " "; // prints 10-0
    if(n == 0) {
        return;
    } else {
        cout << " calling countDown " << n-1 << endl;
        countDown(n-1);
    }
    cout << n << " "; // prints 1-10, no printing happens until all of the recursive calls hv been made 
}

int main() {
    countDown(10);
    cout << endl;
    PrintTriangle(10);
}