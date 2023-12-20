#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> numbers;

    bool whileLoop = false;

    while (!whileLoop) {
        int num;
        cout << "Please enter a number: " << endl;
        cin >> num;

        if (num == -1) {
            break; 
        } else if (num <= 0) {
            cout << "The number should be a positive integer or -1." << endl;
            continue; 
        }

        if (numbers.size() == 0) {
            numbers.push_back(num);
            // cout << numbers.size() << endl;
        } else if (num % 5 == 0 && num % 3 == 0) {
            for(int i = 0 + 1; i < numbers.size(); i++) {
                numbers[i - 1] = numbers[i];
            }
            numbers.pop_back(); // removing from front
            // cout << numbers.size() << endl;
            if(numbers.size() != 0) {
                numbers.pop_back();
            }

        } else if (num % 5 == 0) {
            for(int i = 0 + 1; i < numbers.size(); i++) {
                numbers[i - 1] = numbers[i];
            }
            numbers.pop_back(); // removing from front 
            // cout << numbers.size() << endl;

        } else if (num % 3 == 0) {
            numbers.pop_back();
            // cout << numbers.size() << endl;

        } else {
            numbers.push_back(num);
            // cout << numbers.size() << endl;
        }
    }

    // Display the elements in the vector
    if (numbers.size() == 0) {
        cout << "The vector is empty." << endl;
    } else {
        cout << "The elements in the vector are: ";
        for (int i = 0; i < numbers.size(); i++) {
            cout << numbers[i] << " ";
        }
        cout << endl;

        // Display the minimum and maximum values in the vector
        int min = numbers[0];
        int max = numbers[0];
        // cout << "numbers[0] " << numbers[0];
        // cout << numbers.size() << endl;
        for (int i = 0; i < numbers.size(); i++) {
            if(numbers[i] > max) {
                max = numbers[i];
            }
        }
        for (int i = 0; i < numbers.size(); i++) {
            if(numbers[i] < min) {
                min = numbers[i];
            }
        }
        cout << "Min = " << min << endl;
        cout << "Max = " << max << endl;
    }

    return 0;
}
