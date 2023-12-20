#include <iostream> 
#include <string>
using namespace std;

string decimalToBinary(int num) {
    // int digit;
    // string digit_str = "";
    if(num == 0) {
        // return digit_str;
        return "0"; // return a 0 once we have hit num == 1 (which will happen when 1 / 2)
    } else {
        // digit = num % 2;
        // digit_str = to_string(digit);
        // cout << digit_str;
        // num = num / 2;
        return decimalToBinary(num / 2) + to_string(num % 2); // add the modulus answer to be returned as a string at the end
        /* Example: 13
        13 -> 6 -> 3 -> 1 -> 0
        "01101"      "0110"    "011"     "01"    "0"

        */ 
    }
}

int main() {
    string result = decimalToBinary(13);
    cout << result;
}