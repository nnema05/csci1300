#include <iostream>

using namespace std;

int main() {
    // boolean logic 
    int a = 5;
    int b = b; 
    cout << (a < b) << endl; // evaluates to a false statement, print as 0
    int c = 6;
    cout << ((a < b) || (c > a)) << endl; // what prints? evaluates to true or 1
    int d = 4;
    cout << ((a < b) && (d == b)) << endl; // evaluates to false 
    cout << (!(a < b) && (d == b)) << endl; // evaluates to true
        // the not operator --> inverses the result makes it not the result
        // ex.
        cout << (!(a<b)) << endl; // make this not false so makes it true
            // because (a < b) is false, it makes it !false which is true
        // (a < b) = F, !F = T
        // !F && (d == b) !F && T = T
    
    cout << (!(a < b) || ((d==b) && (c >10))) << endl; // evalutes to true because first evaluates to true 

    // arrays 
    // string and string indexes
    // str[0] - arrays of characters
    // can use [] notation to get any position in the string
    // array of ints 
    int intArray[10]; // declared an int array, memory allocated for 10 integers 
    for (int i = 0; i < 10; i++) {
        cout << intArray[i] << endl; // this will print garabage 
    }


    for (int i = 0; i < 10; i++) {
        intArray[i] = i; // set the value of each element of intArray to its index 
        cout << intArray[i] << endl; // this will print garabage 
    }

    // 2d arrays 
    int int2DArray[5][10]; // array of ints with 5 rows and 10 columns 
    // what would I do to set every value in int2DArray to row*column
    for (int x = 0; x < 5; x++) { // row for loop
        for (int y = 0; y < 10; y++) {
            // can I print without the comma at the end?
            if(y < 9) {
                int2DArray[x][y] = x*y;
                cout << int2DArray[x][y] << ", ";

            } else {
                cout << int2DArray[x][y];
            }
        }

        cout << endl;

    }

    // do same code as a nested while loop
    int x = 0;
    while (x < 5) {
        int y = 0;
        while(y < 10) {
            if(y < 9) {
                int2DArray[x][y] = x*y;
                cout << int2DArray[x][y] << ", ";

            } else {
                cout << int2DArray[x][y];
            }
            y++;
        }
        x++;

    }



}