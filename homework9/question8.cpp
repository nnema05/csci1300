
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int num = 1;
    vector<int> numbers;

    while(num != -1) {
        cout << "Please enter a number: " << endl;
        cin >> num;
        
        if(num == -1) {
            break;
        }

        if(num < -1 || num == 0) {
            cout << "The number should be a positive integer or -1." << endl;
            cout << "Please enter a number: " << endl;
            cin >> num;
            // cout << "problem number " << endl;
        } else {

            if(numbers.size() == 0) {
                numbers.push_back(num);
                // cout << " hi 1 " << numbers.size() << endl;
            } else if(num % 5 == 0 && num % 3 == 0) {
                if(numbers.size() != 0) {
                    numbers.pop_back(); // removing from end 
                    for(int i = 0 + 1; i < numbers.size(); i++) {
                        numbers[i - 1] = numbers[i];
                    }
                    numbers.pop_back(); // removing from front 
                }
                // cout << " hi 2 " << numbers.size() << endl;
            } else if(num % 5 == 0) {
                if(numbers.size() != 0) {
                    for(int i = 1; i < numbers.size(); i++) {
                        numbers[i - 1] = numbers[i];
                    }
                    numbers.pop_back(); // removing from front 
                } 
                // cout << " hi 3 " << numbers.size() << endl;
                
            } else if(num % 3 == 0) {
                if(numbers.size() != 0) {
                    numbers.pop_back(); // removing from end 
                } 
                // cout << " hi 4 " << numbers.size() << endl;
               
            } else {
                // cout << " hellooo" << endl;
                numbers.push_back(num);
                // cout << " hi 5 " << numbers.size() << endl;
            }
        }

    }
    // cout << numbers.size() << endl;
    // when they enter -1  get max and min
    if( numbers.size() == 0 ) {
        cout << "The vector is empty" << endl;
    } else {
        int min = numbers[0];
        int max = numbers[0];
        // cout << "numbers[0] " << numbers[0];
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

        cout << "The elements in the vector are: ";
        for (int i = 0; i < numbers.size(); i++) {
            cout << numbers[i] << " ";
        }

        cout << "Min = " << min << endl;
        cout << "Max = " << max << endl;
    }
    
}


