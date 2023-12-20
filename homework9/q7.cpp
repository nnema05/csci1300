
#include <iostream>

void printInvertedAlphabeticalTriangle(int height) {
    char currentChar = 'a';

    for (int i = height; i >= 1; --i) {
        // Print characters in ascending order, handling 'z' to 'a' transition
        for (int j = 0; j < i; ++j) {
            std::cout << currentChar;
            ++currentChar;

            if (currentChar > 'z') {
                currentChar = 'a'; // Reset to 'a' if 'z' is reached
            }
        }

        std::cout << std::endl;
    }
}

int main() {
    int height;

    // Get user input for the height of the triangle
    std::cout << "Enter the height of the inverted alphabetical triangle: ";
    if (!(std::cin >> height) || height <= 0) {
        // Validate input
        std::cout << "Invalid input." << std::endl;
        return 1;
    }

    // Print the inverted alphabetical triangle
    printInvertedAlphabeticalTriangle(height);

    return 0;
}
