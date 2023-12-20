#include <iostream>
using namespace std;

void print(int height) { // function that takes in the height of an inverted triangle
    char character = 'a'; // create a char that starts at a

    for (int i = height; i >= 1; i--) { // for the height
        // Print characters from a, b, c ... etc 
        for (int j = 0; j < i; j++) { 
            // prints 4 characters, 
            // then print decreases height to 3, prints 3 characters
            // then keeps going as long as i = 1 
            cout << character;
            character++; // increment current character to b 

            // make sure to wrap around from z to a
                // if the character reaches z, reset it as a
            if (character > 'z') {
                character = 'a'; // Reset to 'a' if 'z' is reached
            }
        }

        cout << endl;
    }
}

int main() {
    int height;

    // Get user input for the height of the triangle
    cout << "Enter the height of the inverted alphabetical triangle: " << endl;
    cin >> height;
    if (height <= 0) {
        // Validate input
        cout << "Invalid input." << endl;
        return -1;
    }

    // Print the inverted alphabetical triangle
    print(height);

    return 0;
}
