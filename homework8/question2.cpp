#include <iostream>
using namespace std;

// Helper function: Finds the product of each of the digits by multiplying the last, then the second then the third numbers toegther
int product(int num) {
    if (num >= 0 && num < 10) { // base case: if its a single, return single digit
        return num;
    }
    return (num % 10) * product(num / 10);
    // ex. 999
    // First iteration: 999 --> 99 --> 9
        // 9 % 10 * 9 = 81
        // 99 % 10 * 81 = 729
    // Second iteration: result = 729 
}

// Recursive function to calculate the super product
int digitsSuperProductRecursive(int num) {
    if (num >= 0 && num < 10) { // base case: if its a single, return single digit
        return num;
    }

    // calulate the product of all of the numbers using the product function
    int result = product(num);
        // Ex. 236
            // result = 36 
            // result = 18
            // result = 8

    // Pass in the new result to this function to recheck the base case and then again get the product of the digit in the smaller number 
    return digitsSuperProductRecursive(result);
}

int main() {
    // Example usage
    int number = 57;
    int superProduct = digitsSuperProductRecursive(number);

    std::cout << "Super product of " << number << ": " << superProduct << std::endl;

    return 0;
}
