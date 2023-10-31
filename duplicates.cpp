#include <iostream> 
using namespace std; 

// Function that removes the array
    // pass array and array size by reference (so it can change)
void removeDup(int array[], int &array_size) {
    // This only works for a sorted array!
    // create a variable that holds the current number that you are on
    int currentNumber = 0;

    // go through each value in array
    for(int i = 0; i < array_size; i++) {
        // set current number to the value that we are on in array 
        currentNumber = array[i];
        // cout << "array[i] " << array[i] << endl;
        
        // iterate again through array 
        for(int j = i+1; j < array_size; j++) {
            // cout << "array[j] before if " << array[j] << endl;
            

            // check if current number is repeated anywhere in array 
            if(currentNumber == array[j]) {
                

                // if there are duplicates, remove that element by overwriting the duplicate value with the value before it
                    // then move all the following elements to a lower index
                for(int k = j + 1; k < array_size; k++) {
                    // cout << "currentNumber " << currentNumber << endl;
                    // cout << "array[k] " << array[k] << endl;
                    // cout << "array[j] " << array[j] << endl;
                    
                    array[k - 1] = array[k];
                }
                // reduce array size by 1 so we are making sure we are accounting for the fact that array size changes when values are getting removed
                array_size--; 
                // cout << "array size " << array_size << endl;
                // cout << "j " << j << endl;
                // cout << "i " << i << endl;
            
            }
        }
        

    }
}
int main() {
    int array[] = {1, 2, 2, 3, 4, 4, 5, 5}; 
    

    int array_size = sizeof(array) / sizeof(array[0]);

    removeDup(array, array_size);


    for(int i = 0; i < array_size; i++) {
        cout << array[i] << endl;
    }

    
}