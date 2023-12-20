
#include <iostream> 
#include <cmath>
using namespace std;

int seq(long int num) { 
    cout << num << endl;
    if(num == 1) { // base case
        return 1; 
    } else if(num % 2 == 0) { // even
        // cout << floor(sqrt(num)) << endl;
        return seq(floor(sqrt(num))); // return the sqaure root of num
    } else if(num % 2 == 1) { // off
        return seq(floor(pow(sqrt(num), 3)));  // return the sqaure root of num power of 3
    }
}

int main() {

    cout << "Enter a positive integer: " << endl;
    long int num;
    cin >> num;
    
    // input validation
    if(num <= 0) {
        cout << "Invalid input." << endl;
        return 0;
    }

    seq(num);
    // cout << result;
    
}