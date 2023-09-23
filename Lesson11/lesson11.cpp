
#include <iostream>
#include <cassert> // need this for assert 

using namespace std;

int getSquare(int number) {
    return number * number;
    // return number * number + 1; // introduced an error to function
}

// function prototype
bool isEven(int);


int main () {
    // assert test cases
    // assert will abort the program on error, on unexpected results 
    // function called getNumber(int) - return sqaure of a number
    int number = 19;
    int square_of_number = getSquare(number);
    assert(square_of_number == 361); // 361 is expected output
    cout << "getSquare(19) passed " << endl;

    // write a few more tests
    assert(getSquare(4) == 16);
    assert(getSquare(10) == 100);

    // class exercise : write a function called isEven that takes
        // an int and returns true if input is even and false if input is odd
        // use assert to test your function 
    assert(isEven(4) == true);
    assert(isEven(5) == false);
    cout << "isEven test cases passed" << endl;

    /* STRINGS */
    // String concatenation
    string str1 = "Go";
    string str2 = "Buffs";
    string str3 = str1 + " " + str2;
    cout << "string concatenation example " << str3 << endl;
    // Find a string in another string
    string larger_string = "Use the find function to find the occurances of a string";
    string word_to_find = "occurance";
    int position = larger_string.find(word_to_find);
    // return value from find is the index in the string where a word is found
        // index of the first letter
        // IF STRING ISNT FOUND, returns -1 
    if (position != -1) {
        cout << word_to_find << " found at position " << position << endl;
    } else {
        cout << word_to_find << " not found" << endl;
    }

    /*REPLACE */
    string new_word = "usage";
    larger_string.replace(position, word_to_find.length(), new_word);
    // essentially removing word occurance and replacing it with word usage 
    // REPLACE FUNCTION TAKES THREE ARGUEMENTS: 
        // giving it a position (place to start)
        // then giving it a length (number of characters to take out)
        // then what new word to replace it to (this does not hv to be same number of characters that was removed)
    cout << larger_string << endl;
        

 
}

// class exercise : write a function called isEven that takes
    // an int and returns true if input is even and false if input is odd
    // use assert to test your function 
bool isEven(int input) {

    if (input % 2 == 0) {
        return true;
    } else {
        return false;
    }
}