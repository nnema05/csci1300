

#include <iostream>

using namespace std;

int main() {
    // definite iteration, defined number of loop iterations
    // for loop 
         // int i = 0 --> initial condition, creating varaible i and setting to 0
         // i < 10 --> stopping condition, loop as long as i < 10
         // i++ --> incrementer on i. This is how i changes each time in loop
         // the last time through the loop, i = 9. 
         // i < 10 evaluated one last time and fails when i = 10
    for (int i = 0; i < 10; i++) {
        cout << i << endl;

    }
    // cout << i << endl; --> this will generate an error, i is local to for loop
    for (int i = 0; i < 20; i += 2) {
         cout << i << endl; // what prints? 0-18
    } 

    for (int i = 0; i < 20; i ++) {
         cout << i << endl; // what prints? 1 through 19
    } 

    // what if you want to count backwards from 20
    // i = i + 1 --> i++
    // i = i - 1 --> i--
    for (int i = 20; i > 0; i --) {
         cout << i << endl; 
    } 

    string str = "this is a string";
    cout << str[0] << endl; // prints the first character in str
    cout << str[1] << endl; // prints the second character in the str
    // can access any part of string using the index
        // index starts at 0
    
    // use a for loop to loop through a string and print the character at each position
        // index is the position, it starts at 0
        // count is the number of characters, it starts at 1
    for (int i = 0; i < str.length(); i++) {
        cout << str[i] << endl;
    }


    // Count all instances of the letter in a string using a for loop
        // count variable needs to be iniatilized outside of for loop
    int count = 0;
    for (unsigned int i = 0; i < str.length(); i++) {
        // int count = 0; // if count is created here, logic wont be correct
        if (str[i] == 'i') {
            count++;
        }
    }
    cout << "there are " << count << " i's in this string" << endl;
    
    // Extend to count all vowels
    count = 0;
    for (unsigned int i = 0; i < str.length(); i++) {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
            count++;
        }
    }



}