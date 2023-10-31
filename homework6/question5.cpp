// Question 5

// int failed so size_t will work when int fails
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include<iomanip>

using namespace std;

int split(string input_string, char separator, string arr[], int arr_size) {
    int num_splits = 0; // every string will have at least one split
    string split = ""; // will hold the split string
    int input_string_length = input_string.length();
    
    // for loop through every character in input string 
    for(int i = 0; i < input_string_length; i++) { 
        char split_char = input_string[i]; // initiazling to first one
        
        // if the value is not equal to the seperator, add the character to the split string to build the split
        if(split_char != separator) {
            split = split + split_char;
        
        // if it is equal to the sepererator 
        } else if (split_char == separator) {
            // then add the whole split string to the array of split strings
            // increase num of splits by 1
            // reset split to an empty string 
            arr[num_splits] = split;
            num_splits++;
            split = "";
        }

        // check if number of splits is equal to array size each time a split is added to the array
            // if it is, you want to return -1 and the items in array still as 
        if (num_splits == arr_size)
        {
            return -1; 
        }
    }
    // after loop check if there is any characters left the split string!
        // if there are you need to add that to array and increase num of splits counter
     
    if(!split.length() == 0)
    {
        arr[num_splits] = split; 
        num_splits++; 
    }

    return num_splits;
    
}

int main () {
    // string testcase = "ABCDEFG";
    // char separator = ' ';
    // const int arr_size = 3;
    // string arr[arr_size];
    // // num_splits is the value returned by split
    // int num_splits = split(testcase, separator, arr, arr_size);
    // cout << "Function returned value: " << num_splits << endl;
    // if(num_splits != -1) {
    //     for (int i=0; i < num_splits; i++){
    //         cout << "arr["<< i << "]: " << arr[i] << endl;
    //     }   
    // }

    string testcase = "RST,UVW,XYZ";
    char separator = ',';
    const int arr_size = 3;
    string arr[arr_size];
    // num_splits is the value returned by split
    int num_splits = split(testcase, separator, arr, arr_size);
    cout << "Function returned value: " << num_splits << endl;
    if(num_splits != -1) {
        for (int i=0; i < num_splits; i++){
            cout << "arr["<< i << "]: " << arr[i] << endl;
        }   
    } else {
        cout << "Array is full, some elements may be truncated." << endl; // if the array is full, warns about potential truncation 
    }
}