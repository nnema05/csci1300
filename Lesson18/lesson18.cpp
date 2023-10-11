#include <iostream>

using namespace std;

// write a function that takes an array and a search value 
    // and returns the index where the value is found
int searchArray(int i_search[], int search_value, int i_length) {
    // search logic!
    bool found = false; // loop control
    int search_index = -1; // array index where search value found 
    int x = 0; // loop iterator
    while(x < i_length && !found) {
        if(i_search[x] == search_value) {
            search_index = x;
            found = true;
        }
        x++;
    }

    return 0;
}

int insertArray(int i_insert[], int index, int value, int i_used) {
    // we want to add a 5 to the array at i_insert[0] 
            // and shift other elements out of the way
        for(int x = i_used; x > 0; x--) {
            // x is at first used position
                // putting whats in the position before (x-1) into the the position next to it (z)
            i_insert[x] = i_insert[x-1];
        }
        i_insert[0] = value;
        i_used++; // reflects that we know have 3 elemnts in our array
        return i_used;

}

int main() {
    // array operations
    // search - given a value, does it exist in array and where
    // insert - add a value to an array and move other values out of the way
    // delete - remove a value and fill the sapce
    int i_search[6] = {4, 34, 23, 56, 67, 43}; // one way to initizalize an array
    int search_value = 56; // this is what we are looking for
    int i_length = 6; // size of the array

    // search logic starts here!
    bool found = false; // loop control
    int search_index = -1; // array index where search value found 
    int x = 0; // loop iterator
    while(x < i_length && !found) {
        if(i_search[x] == search_value) {
            search_index = x;
            found = true;
        }
        x++;
    }
    // call function
    search_index = searchArray(i_search, search_value, i_length);

    // what if the value of the search index if the search value is not found is array?
        // this happens after our function call 
    if(search_index == -1) {
        cout << "value not found" << endl;
    } else {
        cout << "value found at index: " << search_index << endl;
    }

    // insert a value into an array
        // need to move the data away from spot we want to inser 
        int i_insert[10]; // allocate 10 elemnt in array
        i_insert[0] = 10; // set the first element
        i_insert[1] = 20; // set the second element
        int i_used = 2; 
        /*
        // we want to add a 5 to the array at i_insert[0] 
            // and shift other elements out of the way
        for(int x = i_used; x > 0; x--) {
            // x is at first used position
                // putting whats in the position before (x-1) into the the position next to it (z)
            i_insert[x] = i_insert[x-1];
        }
        i_insert[0] = 5;
        i_used++; // reflects that we know have 3 elemnts in our array 
        */

        // write a function that takes an array, an index, a value and a number of elements
            // and adds the value to the array at the index
            // return the number of elements
            // call it insertArray
        // when we pass an array to a function, we can modify the array in the function and not return it
            // we pass a reference to the array 
        i_used = insertArray(i_insert, 0, 5, i_used);
        for(int x = 0; x < i_used; x++) {
            cout << i_insert[x] << endl;
        }


}