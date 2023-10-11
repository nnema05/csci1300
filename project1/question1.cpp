
// CSCI 1300 Fall 2023
// Author: Nandini Nema
// TA: SriKrishna
// Question #1

/* Question 1
Write a function named shiftChar() that performs the right shift operation 
    based on the user provided shift value. 
*/

#include <iostream>
#include <cassert>

using namespace std;


char shiftChar(char c, int shift) {
    // First make sure that the user inputed character value is a lower case letter
        // If not, return the character as is
    if (int(c) < 97 || int(c) > 122) {
        return c;
    }

    // Check if shift is less than or greater than 0. 
        // This will tell us if we are moving c value backwards or forwards
    if (shift < 0) {
        // If less than 0, we are moving character value BACKWARDS!
            // we want to check do some checks EACH TIME our character value is changed by 1
                // This means we use for loop 
                // the for loop will keep moving the character backwards for the shift value amount 
        for(int i = shift; i < 0; i++) { // we will change c one at a time and check what c is each time
            // since shift is less than 0, our i value will start at shift and move up by 1 until it hits 0

            if (c == 'a') {
                // each time we will check if our c is at the boundry character 'a' (this is when to move c backwards you have to go back to z)
                    // if it is we want to move backwards back to character value z
                c = 'z';
            } else {
                // if its not at a boundry case of 'a', move c back 1
                c--;
            }
        } 

    } else {
        // if shift is greater than 0, we are moving character value FORWARDS!
        // we want to check do some checks EACH TIME our character value is changed by 1
                // This means we use for loop 
                // the for loop will keep moving the character forwards for the shift value amount 
        for(int i = 0; i < shift; i++) { // we will change c one at a time and check what c is each time
            // since shift is greater than 0, our i value will start at 0 and move up by 1 until it hits shift value

            if (c == 'z') {
                // each time we will check if our c is at the boundry character 'z' (this is when to move c forwards you have to go back to a)
                    // if it is we want to move forwards back to character value z
                c = 'a';
            } else { 
                // if its not at a boundry case of 'z', move c forwards by 1
                c++;
                // cout << c << endl;
            }
        }
    }

    return c;
}

int main() {
    char c;
    int shift;
    cout << "Enter a letter to encrypt: " << endl;
    cin >> c;
    cout << "Enter an integer to shift the letter by: " << endl;
    cin >> shift;

    char encrypted_letter = shiftChar(c, shift);
    assert(shiftChar('a', 1) == 'b');
    assert(shiftChar('a', -1) == 'z');
    assert(shiftChar('x', 4) == 'b');
    assert(shiftChar('h', 17) == 'y');
    assert(shiftChar('C', 1) == 'C');

    cout << "The encrypted letter is: " << encrypted_letter << endl;

    return 0;

}