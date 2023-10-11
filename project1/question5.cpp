

// Combine all three methods! For decryption!!

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
        // Decryption. Going Backwards in character!
    for(int i = 0; i < shift; i++) { // we will change c one at a time and check what c is each time

        if (c == 'a') {
            // each time we will check if our c is at the boundry character 'a' (this is when to move c backwards you have to go back to z)
                // if it is we want to move backwards back to character value z
            c = 'z';
        } else {
            // if its not at a boundry case of 'a', move c back 1
            c--;
        }
    } 

    return c;
}

// Method 2 Function: right shift decryption with a shift value that you will calculate from a user provided key.
    // You will calculate the shift value based on the following formula: (number of vowels in key + number of characters in key) modulus 26
int getMethod2ShiftAmount(string key1) {

    // solve for number of vowels
    int vowels = 0; // declare and initialzie vowels
    for (int i = 0; i < key1.length(); i++) { // for each value in string key1
        // check if that index in string key1 is equal to a vowel 
        if((key1[i] == 'a') || (key1[i] == 'e') || (key1[i] == 'i') || (key1[i] == 'o') || (key1[i] == 'u') || (key1[i] == 'y')) 
        {
            // if so, increase vowel count by 1
            vowels++;
        }
    }
    // cout << vowels << endl;

    // solve for number of charcters in a key which is length of characters
    int length = key1.length();
    // cout << length << endl;

    // solve for the total shifted value
        // (number of vowels in key + number of characters in key) modulus 26
    int shift_value = (vowels + length) % 26;
    // cout << shiftValue;

    return shift_value;

}

// Method 3: right shift decryption with a shift value that you will calculate from two keys that the user provides. 
    // The shift value will be calculated based on the number of matching letters between the two keys modulo 26.
int getMethod3ShiftAmount(string key1, string key2) {
    
    // create varaible that will hold how many matching letters each string shares
        // this variable will be equal to shift_value
    int shift_value = 0;

    // check which string has the maxiumum length
        // This is to deal with case where key1 is a and key2 is aaa
                // since key2 is longer, we want to loop through the length of key 2 
                    // we want to account for all the times a appears
                    // if we just run through the length of key1, our shift value would only be 1 bc it will say a only appears once
                    // but we know a actually appears and matches 3 times so the shift_value would have to be 3
                        // this means we would have to run through the length of key2 not key1
    string max_string;
    string min_string;
    if (key1.length() > key2.length()) {  // if key1 has a greater length
        // set string with a max length as max string. This is the string that will be our outer for loop
        max_string = key1;
        // set the other as our min string
            // This is will be in our inner for loop
        min_string = key2;
        
    } else { // if key 2 has a greater length, or the lengths are the same
        // set string with a max length as max string. This is the string that will be our outer for loop
        max_string = key2;
        // set the other as our min string
            // This is will be in our inner for loop
        min_string = key1;
        
    }

    for (int i = 0; i < max_string.length(); i++) { // Outer loop goes for however long the max string is 
        // Inner loop goes through min string
        for (int j = 0; j < min_string.length(); j++) {
            // check if each value in max string is equal to each value in min string 
            if (max_string[i] == min_string[j]) {
                // if they are increase shift value by 1
                shift_value++;

            }

        }
    }

     // Method 3 states the shift value will be calculated based on the number of matching letters between the two keys modulo 26
    shift_value = shift_value%26;
    return shift_value;

}

// Decrypt Char function: decrypts a character based on the user selected decryption method.
char decryptChar(int c, int method_choice, string key1, string key2) {
    char decrypted_letter;
    int shift_value2;
    int shift_value3;
    // if method choice is not valid (not 1,2 or 3), display that!
    if (method_choice != 1 && method_choice != 2 && method_choice != 3) {
        cout << "Invalid decryption method" << endl;
        return c;
    }
    // if method choice is equal to 1
        // This means shift to right by 1
    if(method_choice == 1) {
        // run the shiftChar function where the shift value agruement is 1
        decrypted_letter = shiftChar(c, 1);
    } else if (method_choice == 2) {// if method choice is equal to 1, decrypt with method 2
        // run the getMethod2ShiftAmount function with key1 as argument 
            // set the value of it equal to integer called shift_value
        shift_value2 = getMethod2ShiftAmount(key1);
        // then run the shiftChar function where the shift value is result from the getMethod2ShiftAmount function
        decrypted_letter = shiftChar(c, shift_value2); 
    } else if (method_choice == 3) {
        shift_value3 = getMethod3ShiftAmount(key1, key2);
        decrypted_letter = shiftChar(c, shift_value3); 
    }
    return decrypted_letter;

}


int main() {
    char c;
    string key1;
    string key2;
    int method_choice;
    cout << "Enter a letter to decrypt: " << endl;
    cin >> c;

    cin.ignore(10000,'\n');

    cout << "Enter key 1: " << endl;
    getline(cin, key1);
    cout << "Enter key 2: " << endl;
    getline(cin, key2);

    cout << "Select the decryption Method to Use: " << endl;
    cout << "Method 1: Shift Right by 1." << endl;
    cout << "Method 2: Shift Right by Key Formula." << endl;
    cout << "Method 3: Shift Right by Mixed Key Formula." << endl;
    cout << endl;
    cin >> method_choice;

    char decrypted_letter = decryptChar(c, method_choice, key1, key2);
    assert(decryptChar('h', 2, "hello", "world") == 'a');
    assert(decryptChar('d', 3, "hello", "world") == 'a');
    assert(decryptChar('a', 3, "rock", "road") == 'y');
    cout << "The decrypted letter is: " << decrypted_letter;

}