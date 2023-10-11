#include <iostream>
#include <cassert>
#include <string>

using namespace std;

// Shifting Character Function: Will shift a character based on the shift value passed in
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

// Method 4: will repeat using Method1, Method2, and Method3 for a given message. Lets walk through an example.
string getMethod4ShiftAmount(string message, string key1, string key2) {
    // create variable that will hold the shift value
    int shift_value = 0;
    char encrypted_character;
    string encrypted_message;
    
    // For the first character and every 3rd character after that 
    for(int i = 0; i < message.length(); i+=3) {
        // Do method 1 (shift char to right by 1)
        // for every 3rd character in string starting from first, shift the value by 1 (run shiftChar function)
        // then add that shifted character to encrypted message!
        encrypted_character = shiftChar(message[i], 1);
        encrypted_message = encrypted_message + encrypted_character;
    }

    // return encrypted_message;
    cout << encrypted_message << endl;
    return encrypted_message;
}

int main() {
    string message;
    string key1;
    string key2;
    int method_choice;
    cout << "Enter a message to encrypt: " << endl;
    getline(cin, message);

    cout << "Enter key 1: " << endl;
    getline(cin, key1);
    cout << "Enter key 2: " << endl;
    getline(cin, key2);

    // cout << "Select the Encryption Method to Use: " << endl;
    // cout << "Method 1: Shift Right by 1." << endl;
    // cout << "Method 2: Shift Right by Key Formula." << endl;
    // cout << "Method 3: Shift Right by Mixed Key Formula." << endl;
    // cout << endl;
    // cin >> method_choice;

    getMethod4ShiftAmount(message, key1, key2);
    // assert(encryptChar('a', 2, "hello", "world") == 'h');
    // assert(encryptChar('a', 3, "hello", "world") == 'd');
    // assert(encryptChar('y', 3, "rock", "road") == 'a');

    // cout << "The encrypted message is: " << encrypted_message;

}

