
/* QUESTION 1
You are a tax expert and your friends have come to you for help in calculating their taxes. 
They are interested in knowing how much tax they owe to the government based on their age and income. 
Write a C++ program to help them calculate their taxes using the rubric below.
*/

// CSCI 1300 Fall 2023
// Author: Nandini Nema
// TA: Srikrishna Bangalore Raghu
// Question 1

#include <iostream>

using namespace std;

int main()
{
    // declare all the variables
    int age, income;

    // prompt the user & get their input
    cout << "What is your age?" << endl;
    cin >> age;
    cout << "What is your income?" << endl;
    cin >> income;

    if (age <= 0 || income <= 0) // EDIT THIS LINE
    {
        cout << "Neither age nor income can be zero" << endl;
        return 0;
    }

    // Check for age criteria
    if (age < 60) // EDIT THIS LINE
    {
        // Check for income criteria
        if (income < 50000) // EDIT THIS LINE
        {
            cout << "You are required to pay $" << 0.1*income << " in taxes" << endl;
        }
        else
        {
            cout << "You are required to pay $" << 0.2*income << " in taxes" << endl;
        }
    }
    else
    {
        // Check for income criteria
        if (income < 20000) // EDIT THIS LINE
        {
            cout << "You are not required to pay taxes" << endl;
        }
        else
        {
            cout << "You are required to pay $" << 0.05*income << " in taxes" << endl;
        }
    }

    return 0;
}