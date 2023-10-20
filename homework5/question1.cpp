
#include <iostream> 
#include <cmath>
#include <iomanip>

using namespace std;

// sq root nums array 
void squareRoot(double square_root[], int size) {
    for(int i = 0; i < size; i++) { // for the size of sqaure root array
        square_root[i] = sqrt(i + 1); // add to the square root of 1-10 (using i + 1) to array
    }
   
}

// numbers array!
void createNumbersArray(int numbers[], int size) {
    // create index vairable
    for(int i = 0; i < size; i++) {
        for (int number = 50; number < 100; number++) {  // go through values 50-100
        
            if (number%7 == 0) { // check if the number 50-100 is divisble by 7
                numbers[i] = number; // if so add it to numbers array!
                // then increase i by 1!
                i++;
            }
        }
    }

}

// function for letters array 
void createLettersArray(char letters[], int size) {
    // create an index for upper case letters
    int indexForUpper = 0;
    // for every upper case letter from A - Z (65 to 90)
    for(int j = 65; j <= 90; j++) {
        // add that character to the i position in array letters!
        // switch from int to char using function static_cast<char> <- from textbook
        char c = static_cast<char>(j);
        // add that to the letters array
        letters[indexForUpper] = c;
        indexForUpper+=2; // increase indexForUpper by 2 to do every other
    } 

     // create an index for upper case letters
        // start at 1 for 
    int indexForLower = 1;
    // for every lower case letter from a - z (97 to 122)
    for(int j = 97; j <= 122; j++) {
        // add that character to the i position in array letters!
        // switch from int to char using function static_cast<char> <- from textbook
        char c = static_cast<char>(j);
        // add that to the letters array
        letters[indexForLower] = c;
        indexForLower+=2; // increase indexForLower by 2 to do every other
    }   
}

int main() {
    // card_names arrays
    string card_names[9] = {"Ace", "Clubs", "Diamonds", "Hearts", "Spades", "Jack", "Queen", "King", "Joker"};
    // print every value in array
    for (int i = 0; i < 9; i++) {
        cout << card_names[i] << endl;
    }

    // sq root nums array
    double square_root[10];
    // call function to fill this array with values
    squareRoot(square_root, 10);
     // print every value in array 
    for (int i = 0; i < 10; i++) {
        cout << fixed << setprecision(3) << square_root[i] << endl;
    }

    // numbers array 
    int numbers[8]; 
    // call function to fill this array with values
    createNumbersArray(numbers, 7);
    // print every value in array 
    for (int i = 0; i < 7; i++) {
        cout << numbers[i] << endl;
    }

    // letters array - will have 52
    char letters[52];
    createLettersArray(letters, 52);
    for (int i = 0; i < 52; i++) {
        cout << letters[i] << endl;
    }

    
}