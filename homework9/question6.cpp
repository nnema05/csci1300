#include <iostream>
#include <string>

using namespace std;

int count(string main_string, string substring) {
    int count = 0;

    // Iterate through every grouping of substring 
        // for example. mississippi and si
        // look if si equals first substring mi
            // look if si equals first substring is 
            // etc. 
        // only want to iterate for the amount of possible substrings of the length of the substring in the string which is equal ( main_string.length() - substring.length() )
    for (int i = 0; i <= main_string.length() - substring.length(); i++) {

        if (main_string.substr(i, substring.length()) == substring) {
            count++; // increment count if substring in main substring equals given substring 
        }
    }

    return count;
}

int main() {
    string main_string;
    string substring;

    // User input
    cout << "Enter the search string: " << endl;
    cin >> main_string;

    // Get user input for the substring
    cout << "Enter the substring to be searched: " << endl;
    cin >> substring;

    // Count occurrences and display the result
    int num_of_count = count(main_string, substring);

    cout << "Number of occurrences: " << num_of_count;

    return 0;
}
