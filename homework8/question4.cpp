
#include <iostream>
using namespace std;

int oneCount(int num) {
    // int steps = 0;
    if(num == 1) { // if number is 1, return 0
        return 0;
    } else if(num % 2 == 0) {
        // If num is even
        // steps++;
        return 1 + oneCount(num/2); // add one to returned number (to count number of steps)
    } else {
        // If num is not even
        // steps++;
        // cout << steps;
        return 1 + oneCount((num * 3) + 1); // add one to returned number (to count number of steps)
    }
}

int main() {
    int result = oneCount(3);
    cout << result;
}