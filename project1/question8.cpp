
// Now we will tie all of our functions together into a program that can be used by a person to do encryption and decryption of their own!
#include <iostream>
#include <cassert>
#include <string>

using namespace std;

/* INCLUDE ALL ENCRYPTION FUNCTIONS!!*/
// Shifting Character Function: Will shift a character based on the shift value passed in
char shiftCharEncrypt(char c, int shift) {
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

// Method 2 Function: right shift encryption with a shift value that you will calculate from a user provided key.
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

// Method 3: right shift encryption with a shift value that you will calculate from two keys that the user provides. 
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

// Method 4: will repeat using Method1, Method2, and Method3 for a given message. Lets walk through an example.
string getMethod4ShiftAmount(string message, string key1, string key2) {
    // create variable that will hold the shift value
    int shift_value = 0;
    int shift_value2 = 0;
    int shift_value3 = 0;
    char encrypted_character1;
    char encrypted_character2;
    char encrypted_character3;
    string encrypted_message;

    // For the first character and every 3rd character after that 
    for(int i = 0; i < message.length(); i+=3) {
        // Do method 1 (shift char to right by 1)
        // for every 3rd character in string starting from first, shift the value by 1 (run shiftCharEncrypt function)
        // then add that shifted character to encrypted message!
        message[i] = shiftCharEncrypt(message[i], 1);
        // encrypted_message = encrypted_message + encrypted_character1;
    }

    // run the getMethod2ShiftAmount function with key1 as argument 
        // set the value of it equal to integer called shift_value2
    shift_value2 = getMethod2ShiftAmount(key1);
    // For every 2nd character and every 3rd character after that 
    for(int j = 1; j < message.length(); j+=3) {
        // for every character in string, shift the value by result from the getMethod2ShiftAmount function
            // (run shiftCharEncrypt function)
        // then add that shifted character to encrypted message!
        message[j] = shiftCharEncrypt(message[j], shift_value2);
        // encrypted_character2 = shiftCharEncrypt(message[j], shift_value2);
            // cout << encrypted_character << endl;
        // encrypted_message = encrypted_message + encrypted_character2;
    }

    // run the getMethod3ShiftAmount function with key1 and key2 as argument 
        // set the value of it equal to integer called shift_value3
    shift_value3 = getMethod3ShiftAmount(key1, key2);
    // For every 3rd character and every 3rd character after that 
    for(int k = 2; k < message.length(); k+=3) {
        // for every character in string, shift the value by result from the getMethod3ShiftAmount function
            // (run shiftCharEncrypt function)
        // then add that shifted character to encrypted message!
        message[k] = shiftCharEncrypt(message[k], shift_value3);
        // cout << encrypted_character << endl;
        // encrypted_message = encrypted_message + encrypted_character3;
    }
    return message;
}

// Encrypt Char function: encrypts a character based on the user selected encryption method.
char encryptChar(int c, int method_choice, string key1, string key2) {
    int shift_value2;
    int shift_value3;
    char encrypted_letter;
    // if method choice is not valid (not 1,2 or 3), display that!
    if (method_choice != 1 && method_choice != 2 && method_choice != 3) {
        cout << "Invalid encryption method" << endl;
        return c;
    }
    // if method choice is equal to 1
        // This means shift to right by 1
    if(method_choice == 1) {
        // run the shiftCharEncrypt function where the shift value agruement is 1
        encrypted_letter = shiftCharEncrypt(c, 1);
    } else if (method_choice == 2) {// if method choice is equal to 1, encrypt with method 2
        // run the getMethod2ShiftAmount function with key1 as argument 
            // set the value of it equal to integer called shift_value
        shift_value2 = getMethod2ShiftAmount(key1);
        // then run the shiftCharEncrypt function where the shift value is result from the getMethod2ShiftAmount function
        encrypted_letter = shiftCharEncrypt(c, shift_value2); 
    } else if (method_choice == 3) {
        shift_value3 = getMethod3ShiftAmount(key1, key2);
        encrypted_letter = shiftCharEncrypt(c, shift_value3); 
    }
    return encrypted_letter;
}


// Encryption String function: that encrypts a string based on the user selected encryption method.
string encryptMessage(string message, int method_choice, string key1, string key2) {
    int shift_value2;
    int shift_value3;
    char encrypted_character;
    string encrypted_message;
    // if method choice is not valid (not 1,2 or 3), display that!
    if (method_choice != 1 && method_choice != 2 && method_choice != 3 && method_choice != 4) {
        cout << "Invalid encryption method" << endl;
        return message;
    }
    // if method choice is equal to 1
        // This means shift to right by 1
    if(method_choice == 1) {
        // for every character in string, shift the value by 1 (run shiftCharEncrypt function)
        // then add that shifted character to encrypted message!
        for(int i = 0; i < message.length(); i++) {
            encrypted_character = shiftCharEncrypt(message[i], 1);
            encrypted_message = encrypted_message + encrypted_character;
        }

    } else if (method_choice == 2) {// if method choice is equal to 1, encrypt with method 2
        // run the getMethod2ShiftAmount function with key1 as argument 
            // set the value of it equal to integer called shift_value2
        shift_value2 = getMethod2ShiftAmount(key1);
        // for every character in string, shift the value by result from the getMethod2ShiftAmount function
            // (run shiftCharEncrypt function)
        // then add that shifted character to encrypted message!
        for(int i = 0; i < message.length(); i++) {
            encrypted_character = shiftCharEncrypt(message[i], shift_value2);
            encrypted_message = encrypted_message + encrypted_character;
        }

    } else if (method_choice == 3) {
        // run the getMethod3ShiftAmount function with key1 and key2 as argument 
            // set the value of it equal to integer called shift_value3
        shift_value3 = getMethod3ShiftAmount(key1, key2);
        // for every character in string, shift the value by result from the getMethod3ShiftAmount function
            // (run shiftCharEncrypt function)
        // then add that shifted character to encrypted message!
        for(int i = 0; i < message.length(); i++) {
            encrypted_character = shiftCharEncrypt(message[i], shift_value3);
            encrypted_message = encrypted_message + encrypted_character;
        }
        
    } else if (method_choice == 4) {
            encrypted_message = getMethod4ShiftAmount(message, key1, key2);
    }
        
    return encrypted_message;

}


/* DECRYPT FUNCTIONS! */
// Shift Char for decryption! 
// Shifting Character Function: Will shift a character based on the shift value passed in
char shiftCharDecrypt(char c, int shift) {
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

// Method 4: will repeat using Method1, Method2, and Method3 for a given message. Lets walk through an example.
string getMethod4ShiftAmountDecrypt(string message, string key1, string key2) {
    // create variable that will hold the shift value
    int shift_value = 0;
    int shift_value2 = 0;
    int shift_value3 = 0;

    // For the first character and every 3rd character after that 
    for(int i = 0; i < message.length(); i+=3) {
        // Do method 1 (shift char to right by 1)
        // for every 3rd character in string starting from first, shift the value by 1 (run shiftCharDecrypt function)
        // then add that shifted character to decrypted message!
        message[i] = shiftCharDecrypt(message[i], 1);
    }

    // run the getMethod2ShiftAmount function with key1 as argument 
        // set the value of it equal to integer called shift_value2
    shift_value2 = getMethod2ShiftAmount(key1);
    // For every 2nd character and every 3rd character after that 
    for(int j = 1; j < message.length(); j+=3) {
        // for every character in string, shift the value by result from the getMethod2ShiftAmount function
            // (run shiftCharDecrypt function)
        // then add that shifted character to decrypted message!
        message[j] = shiftCharDecrypt(message[j], shift_value2);
    
    }

    // run the getMethod3ShiftAmount function with key1 and key2 as argument 
        // set the value of it equal to integer called shift_value3
    shift_value3 = getMethod3ShiftAmount(key1, key2);
    // For every 3rd character and every 3rd character after that 
    for(int k = 2; k < message.length(); k+=3) {
        // for every character in string, shift the value by result from the getMethod3ShiftAmount function
            // (run shiftCharDecrypt function)
        // then add that shifted character to decrypted message!
        message[k] = shiftCharDecrypt(message[k], shift_value3);
        
    }
    return message;
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
        // run the shiftCharDecrypt function where the shift value agruement is 1
        decrypted_letter = shiftCharDecrypt(c, 1);
    } else if (method_choice == 2) {// if method choice is equal to 1, decrypt with method 2
        // run the getMethod2ShiftAmount function with key1 as argument 
            // set the value of it equal to integer called shift_value
        shift_value2 = getMethod2ShiftAmount(key1);
        // then run the shiftCharDecrypt function where the shift value is result from the getMethod2ShiftAmount function
        decrypted_letter = shiftCharDecrypt(c, shift_value2); 
    } else if (method_choice == 3) {
        shift_value3 = getMethod3ShiftAmount(key1, key2);
        decrypted_letter = shiftCharDecrypt(c, shift_value3); 
    }
    return decrypted_letter;

}

// decryption String function: that decrypts a string based on the user selected decryption method.
string decryptMessage(string message, int method_choice, string key1, string key2) {
    int shift_value2;
    int shift_value3;
    char decrypted_character;
    string decrypted_message;
    // if method choice is not valid (not 1,2 or 3), display that!
    if (method_choice != 1 && method_choice != 2 && method_choice != 3 && method_choice != 4) {
        cout << "Invalid decryption method" << endl;
        return message;
    }
    // if method choice is equal to 1
        // This means shift to right by 1
    if(method_choice == 1) {
        // for every character in string, shift the value by 1 (run shiftCharDecrypt function)
        // then add that shifted character to decrypted message!
        for(int i = 0; i < message.length(); i++) {
            decrypted_character = shiftCharDecrypt(message[i], 1);
            decrypted_message = decrypted_message + decrypted_character;
        }

    } else if (method_choice == 2) {// if method choice is equal to 1, decrypt with method 2
        // run the getMethod2ShiftAmount function with key1 as argument 
            // set the value of it equal to integer called shift_value2
        shift_value2 = getMethod2ShiftAmount(key1);
        // for every character in string, shift the value by result from the getMethod2ShiftAmount function
            // (run shiftCharDecrypt function)
        // then add that shifted character to decrypted message!
        for(int i = 0; i < message.length(); i++) {
            decrypted_character = shiftCharDecrypt(message[i], shift_value2);
            decrypted_message = decrypted_message + decrypted_character;
        }

    } else if (method_choice == 3) {
        // run the getMethod3ShiftAmount function with key1 and key2 as argument 
            // set the value of it equal to integer called shift_value3
        shift_value3 = getMethod3ShiftAmount(key1, key2);
        // for every character in string, shift the value by result from the getMethod3ShiftAmount function
            // (run shiftCharDecrypt function)
        // then add that shifted character to decrypted message!
        for(int i = 0; i < message.length(); i++) {
            decrypted_character = shiftCharDecrypt(message[i], shift_value3);
            decrypted_message = decrypted_message + decrypted_character;
        }
        
    } else if (method_choice == 4) {
            decrypted_message = getMethod4ShiftAmountDecrypt(message, key1, key2);
    }
        
    return decrypted_message;

}


int main() {
    int input;
    // declare varaibles neeeded in loop
    string key1;
    string key2;
    int encyption_type;
    string message;
    string encrypted_message;
    string decrypted_message;

    // Starting loop. 
        // Offer the user every option to select until they chose to exit the program! (choose option 6)
    while (input!=6) {
        /// Menu options for user 
        cout << "Please input 1-6 followed by enter to navigate the menu: " << endl;
        cout << "1. Set Encryption Key 1" << endl;
        cout << "2. Set Encryption Key 2" << endl;
        cout << "3. Select Encryption Method" << endl;
        cout << "4. Encrypt Message" << endl;
        cout << "5. Decrypt Message" << endl;
        cout << "6. Exit Program" << endl;

        cin >> input; // read what user selects into the input 

        // if input is invalid (not 1-6), then tell the user its an invalid input and ask again 
            // will ask again ask long as the input is not 6 due to while loop!
        // or if cin.fails (an input we do not expect like a character instead of integer)
            // then cin
        while(cin.fail() || input < 1 || input > 6) { 
            
                cout << "Invalid input" << endl; 
        
                cin.clear(); // if this happens we have to cin.clear (reset cin.fail which is true right now to false)
                cin.ignore(10000,'\n'); // cin.ignore tells computer to ignore first 10000 characters in varaible or up until you hit a new line
                /// ASk user again for choice 
                cin >> input; // read what user selects into the input 

        }

        /* Below are conditional based on what user inputs! */
        /*OPTION 1 OR 2*/
        // If the option is 1 or 2 
            // If its 1, you are finiding encryption key 1
        if (input == 1) {

            // Get input for key1 from user
            cout << "Enter key: " << endl;
            cin.ignore(10000,'\n');
            getline(cin, key1);

            // check if key input is a valid input (keys should be at least 1 character long)
                // if invalid re ask user again and again until its valid 
            while(key1.length() < 1)  {
                cout << "Invalid key" << endl;
                cout << "Enter key: " << endl;
                getline(cin, key1);
            } 

            // When successfully set, display a successfully set message to user
            cout << "Successfully set encryption key1 to " << key1 << endl;
        } 

        if (input == 2) { // If option 2 is selected, ask user for key2!
            // Get input for key2 from user
            cout << "Enter key: " << endl;
            cin.ignore(10000,'\n');
            getline(cin, key2);

            // check if key input is a valid input (keys should be at least 1 character long)
                // if invalid re ask user again and again until its valid 
                // while loop because it needs to be repeated!
            while(key2.length() < 1)  {
                cout << "Invalid key" << endl;
                cout << "Enter key: " << endl;
                // cin.ignore(10000,'\n');
                getline(cin, key2);
            } 

            // When successfully set, display a successfully set message to user
            cout << "Successfully set encryption key2 to " << key2 << endl;
        }

        /*OPTION 3*/
            // Letting user select a encryption choice 
        if (input == 3) {
            cout << "Please input 1-4 to decide encryption technique." << endl;
            cout << "1. Method1 only (shift by 1)" << endl;
            cout << "2. Method2 only (shift by first key)" << endl;
            cout << "3. Method3 only (shift by both keys)" << endl;
            cout << "4. Mix of Method1, Method2, Method3" << endl;
            cin >> encyption_type;

            // check if input is invalid again until the input is valid
                // if invalid, say its in invalid input and reask 

            while(cin.fail() || encyption_type < 1 || encyption_type > 4) {
                cout << "Invalid encryption choice" << endl; 
            
                    // cin fail and clear are acounting for situations when the cin input is not what we expected
                    cin.clear();
                    cin.ignore(10000,'\n');
                    cin >> encyption_type; // read what user selects into the encryption type 
                
            }

            // When successfully set, display a successfully set message to user
            cout << "Successfully set encryption type to " << encyption_type << endl;
        }
        /*OPTION 4*/
            // Encrypt message 
        if (input == 4) {

            // If the user has not set both of the keys and chosen an encryption method, print that
            if (key1.length() < 1 || key2.length() < 1 || encyption_type < 1 || encyption_type > 4) {
                cout << "You cannot do this until you set both keys and choose an encryption method" << endl;

            } else { // keys and encryption method are set
                // Ask user for message to input 
                cout << "Enter your message to encrypt: " << endl;
                cin.ignore(10000,'\n');
                getline(cin, message);

                // run Encrypted Message function which will take in our message, encruption 
                encrypted_message = encryptMessage(message, encyption_type, key1, key2);
                cout << encrypted_message << endl; 
            }

        }

        /*OPTION 5*/
            // decrypt message 
        if (input == 5) {

            // If the user has not set both of the keys and chosen an encryption method, print that
            if (key1.length() < 1 || key2.length() < 1 || encyption_type < 1 || encyption_type > 4) {
                cout << "You cannot do this until you set both keys and choose an encryption method" << endl;

            } else { // keys and encryption method are set
                // Ask user for message to input 
                cout << "Enter your message to decrypt: " << endl;
                cin.ignore(10000,'\n');
                getline(cin, message);

                // run Encrypted Message function which will take in our message, encruption 
                decrypted_message = decryptMessage(message, encyption_type, key1, key2);
                cout << decrypted_message << endl; 
            }

        }

        if (input == 6) {
            cout << "Goodbye." << endl;
        }

    }
    
}

