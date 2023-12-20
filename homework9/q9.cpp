#include <iostream>
#include <cassert>

bool insertAfter(char input_characters[], int num_elements, int ARR_SIZE, int index, char char_to_insert) {
    // Check if the array is full
    if (num_elements >= ARR_SIZE) {
        return false;
    }

    // Check if the index is within bounds
    if (index < 0 || index >= num_elements) {
        return false;
    }

    // Shift elements to make room for the new character
    for (int i = num_elements; i > index; --i) {
        input_characters[i] = input_characters[i - 1];
    }

    // Insert the new character
    input_characters[index + 1] = char_to_insert;

    // Increment the number of elements in the array
    ++num_elements;

    return true;
}

int main() {
    const int ARR_SIZE = 10;
    char input_characters[ARR_SIZE] = {'h', 'e', 'l', 'l', 'o', '\0'};
    int num_elements = 5;

    
    // Validate the updated array
    std::cout << "Updated array: ";
    for (int i = 0; i < num_elements; ++i) {
        std::cout << input_characters[i];
    }
    std::cout << std::endl;

    return 0;
}
