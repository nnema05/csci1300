
#include <iostream>
#include <string>

using namespace std;

int main() {
    // loops inside of loops
    // nested loops 
    // imagine, looping through every seat in the classroom 
        // every seat in a row - inner loop 
        // every row in the room - outer loop
    for (int row = 0; row < 10; row++) { // outer loop 
        for (int seat = 0; seat < 12; seat++) {
            cout << "row=" << row << " and seat= " << seat << endl;
        }

    }

    // how would I write the same logic using two nested while loops
    int row = 0;
    int seat = 0;
    while(row < 10) {
        int seat = 0;
        // row++;
        // moving row here produces a different output then incrementing after the inner while loop
        // being able to step through a while loop and identify the output would be good to know for your midterm
        while(seat < 12) {
            cout << "row=" << row << " and seat= " << seat << endl;
            seat++; 
        }
        row++;
        // have to reset seat to 0 everytime you go to a new row 
        seat = 0;
    }

    string str = "this is a string";
    // write code to change every letter to z
        // output of your code is new string 
        // outpit should be tziz zszazszrnz

        // remember index starts at 0, str[0] is the first letter in the string 
        // str[1] is second letter
    // for loop 
    for(int i = 1; i < str.length(); i+=2) {
        str[i] = 'z'; // letter z, put in single quotes
        // str[i] = z; // whats the error? this sees z as a variable, rather than a character
        cout << str << endl; // this will print partial solutions!
    }
    cout << str << endl;

    // how would i solve this with a while loop
    int character = 1;
    str = "this is a string";
    while (character < str.length()) {
        str[character] = 'z';
        character+=2;
    }
    cout << str << endl;
 
}
