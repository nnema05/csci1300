
#include <iostream>
#include <random> // generate some random numbersS

using namespace std;

// passing an arguement by reference. x will change in the function. 
// pass y by value, that means you pass a copy of y (at a different location in memory)
    // so any changes we make doesnt get preserved
void passByReference(int &x, int y) {
    x++;
    y++;
}
// pass array by reference, using the & to say adress of 
void modifyArray(int arr[], const int &array_size) {
    for(int i = 0; i < array_size; i++) {
        arr[i]= i;
    }
    cout << "address of i_array " << arr << endl; // the name of an array without [] is adress
    cout << "address of i_used " << &array_size << endl; // & means of adress of 
}

int main() {
    // deleting an element for an array 
    const int array_size = 5; // use const for variables that won't change 
    int i_used = array_size;
    int i_array[array_size]; // 5 element array 
    srand(time(0));
    // generate 5 random numbers 
    for (int i = 0; i < array_size; i++) {
        i_array[i] = rand() % 100 + 1; // random numbers 0-100
        cout << i_array[i] << " ";
    }
    cout << endl;

    // delete an element by overwriting it, shifting every right of it by one position 
    // we use array_size-1 so that i_array[i+1] doesnt go beyond bounds of array
    for(int i = 0; i < array_size-1; i++) {
        i_array[i] = i_array[i + 1];
    }
    // change i_used to go down one 
    i_used--;
    // print array contents after delete operation
    for(int i = 0; i < i_used; i++) {
        cout << i_array[i] << " ";
    }
    cout << endl;
    // when you pass an array to a function, you pass the adress of the first element  in the array
    cout << "address of i_array " << i_array << endl; // the name of an array without [] is adress
    // CHANGING A DIFFERENT LOCATION!
    cout << "address of i_used " << &i_used << endl; // & means of adress of 
    modifyArray(i_array, i_used); // modify array is a void
    // print array contents after delete operation
    for(int i = 0; i < i_used; i++) {
        cout << i_array[i] << " ";
    }
    cout << endl;
    int x = 10;
    int y = 10;
    passByReference(x, y);
    // x is passed by reference and x is physcually is changed within the function
    cout << "x=" << x << endl;
    cout << "y = " << y;
    
    // more about 2D arrays 
    const int rows = 4;
    const int columns = 3;
    int medals[rows][columns];
    for(int x = 0; x < rows; x++) {
        for(int y = 0; y < columns; y++) {
            medals[x][y] = rand() % 10 + 1; // random numbers 0 to 10
        }
    }
    // find max value in each row and store in an array of maximum values
    // create an array that is same size as rows 

    int max_values[rows];
    // add to get sum_values of rows
    int sum_values[rows];
    for(int x = 0; x < rows; x++) {
        int max_value = 0; // minumum value possible
        int sum_val = 0; // inital sum 
        for(int y = 0; y < columns; y++) {
            sum_val += medals[x][y];
            if(medals[x][y] > max_value) { // if the current value we are on is greater then the max value
                max_value = medals[x][y]; // then set the max value equal to that current value
            }
        }
        max_values[x] = max_value; // store in max values array
        sum_values[x] = sum_val; // store sums in an array 
    }
    // print max values o
    for(int x = 0; x < rows; x++) {
        for(int y = 0; y < columns; y++) {
            cout << medals[x][y] << " ";
        }
        cout << endl;
        cout << max_values[x] << " " << sum_values[x] << endl;
    }
} 