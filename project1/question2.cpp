

#include <iostream>
#include <cassert>
#include <string>

using namespace std;

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

int main() {
    cout << "Enter key 1: " << endl;
    string key1;
    getline(cin, key1);

    int shift_value = getMethod2ShiftAmount(key1);
    // assert statemets
    assert(getMethod2ShiftAmount("hello") == 7);
    assert(getMethod2ShiftAmount("elephant") == 11);
    assert(getMethod2ShiftAmount("abcabcabcabcabcabcabcabc") == 6);
    cout << "The Method 2 shift value is " << shift_value;
    return 0;
}