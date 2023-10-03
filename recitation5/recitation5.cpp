
#include <iostream>
#include <string>

using namespace std;

int expsenseTracker() {
    int groceries;
    int entertainment;
    int education;
    string userInput;
    int totalAmount;
    while(userInput != "Exit") {
        cout << "Enter a category (Groceries, Entertainment, Education, or 'exit'): "<< endl;
        cin >> userInput;
        if (userInput != "Groceries" && userInput != "Entertainment" && userInput != "Education") {
            cout << "Invalid category. Please enter a valid caetgroy" << endl;
            cout << "Enter a category (Groceries, Entertainment, Education, or 'exit'): "<< endl;
            cin >> userInput;
        }
        if (userInput == "Groceries") {
            cout << "Enter the expense amount: " << endl;
            cin >> groceries;
        } else if (userInput == "Entertainment") {
            cout << "Enter the expense amount: " << endl;
            cin >> entertainment;
            
        } else if (userInput == "Education") {
            cout << "Enter the expense amount: " << endl;
            cin >> education;
        }
    
    }

    totalAmount = groceries + entertainment + education;
    cout << "Category-wise Expenses" << endl;
    cout << "Groceries: $" << groceries << endl;
    cout << "Entertainment: $" << entertainment << endl;
    cout << "Education: $" << education << endl;
    return totalAmount;
    
}

int main () {
    int totalAmount = expsenseTracker();
    cout << "Total Expenses for the Day: $" << totalAmount << endl;
}