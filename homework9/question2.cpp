
// Calculating the sigmoid
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double x = 0;

    cout << "Enter a value for x: " << endl;
    cin >> x;

    double sigmoid = 1 / (1 + exp(-x));

    cout << "The sigmond for x=" << x << " is " << sigmoid;
}