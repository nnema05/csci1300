/*WARM UP*/
/*Part a*/
#include <iostream>

using namespace std;

int main() 
{
    int matrix[3][3] = {{1, 2, 3},
                        {4, 5, 6},
                        {7, 8, 9}};

    int rows = 3;
    int cols = 3;

    cout << "Left Diagonal elements are: ";
    for (int i = 0; i < rows; i++) {
        for (int j =0; j <cols; j++)  // Fill in the blank with for loop  
        {
            if (i == j) 
            {
                cout << matrix[i][j] << " ";
            }
        }
    }

    cout << endl;

    return 0;
}

/*Part b */
#include <vector>
#include <string>

int main() {
    vector<string> animals = {"apple","cat", "banana",  "dog", "elephant", "fox"};
    int len = animals.size();

    cout << "Strings with size 3:" << endl;
    for (int i = 0; i < len; i++) {
        if (animals[i].length() == 3)   //Fill in the blank with appropriate condition.
        {
            cout << animals[i] << endl;
        }
    }

    return 0;
}

/*Part c*/
#include <iostream>
#include <vector>

using namespace std;

// Function to add multiples of 3 to a vector
void addMultiplesOf3(vector<int>&vec)  // Fill in the blank with appropriate function parameter
{ 
    for (int i = 1; i <= 5; i++) 
    {
        int multiple = 3 * i;
        vec.push_back(multiple);
    }
}

int main() 
{
    vector<int> myVector= {1, 2, 4, 5};

    // Call the function to add multiples of 3 to the vector
    addMultiplesOf3(myVector);
    int length = myVector.size();
    
    // Print the elements of the vector
    cout << "Updated vector: ";
    for (int i = 0; i <= length; i++) 
    {
        cout << myVector[i] << " ";
    }
    cout << endl;

    return 0;
}


/*QUESTION 1*/
// PSUEDOCODE
// Create a vector of float type 
// For i goes from 0 to 14
    // Input a float value
    // Push it back to the vector
// Initialize average to 0
// For every float value in the vector
    // Average = Average + Float vlaue
// divide Average by 15 and assign value to a average 
// For every value in vector
    // if value is less than average 
        // for goes from index of value to size of vector -1
        // vector [i] = vector [i+1] 
    // pop back last element of vector
void userInput(vector<double> &vec) {
    double input;

    // asking user for input 
    for(int i = 0; i < 14; i++) {
        cout << "What is input" << endl;
        cin >> input;
        vec.push_back(input);
    }
    
}
void calculateAverage(vector<double> &vec) {
    double average = 0;
    for (int i = 0; i < vec.size(); i++) {
        average = average + vec[i];
    }
    average  = average/15.0;
};

void remove(vector<double> &vec, double average) {
    // asking user for input 
    for(int i = 0; i < vec.size(); i++) {
        if(vec[i] < average) {
            for(int j = i; j < vec.size() -1; j++) {
                vec.pop_back();
            }
        }
    }
}



int main() {
    vector<double> vec;
    // Ask user for input 
    userInput(vec);

    // Calculate average
    calculateAverage(vec);

    // 


    return 0;

}

/*QUESTION 3*/
// PSEUDOCODE
// Define two 2x3 arrays
// For i goes from 0 to 2 
    // input values for matrix i
    // one row at a time 
// For i goes from 0 to 2
    // input values for matrix 
    // 2 one row at a time 
// Call matrixSum 
// For i goes from 0 to 2
    // for j goes form 0 to 3
        // add corresponding elemnts from array
        // assign it to final matrix 
// output final matrix 

void matrixSum(int a[2][3], int b[2][3]) {
    int sum[3][3];
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 3; j++) {
            sum[i][j] = b[2][3] + a[i][j];
        }
    }

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << sum[i][j] << endl;
        }
    }

}

int main() {
    cout << "Enter values for matrix 1, one row at a time: ";
    int a[2][3];
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> a[i][j];
        }
    }


    cout << "Enter values for matrix 2, one row at a time: ";
    int b[2][3];
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> b[i][j];
        }
    }

    // call matrix sum!
    matrixSum(a, b);
   
}