

#include <iostream> 
using namespace std;

int main() {
    cout << "Enter the desired pass type (S for Student, P for Professional, V for VIP, K for Speaker): ";
    char pass_type;
    cin >> pass_type;
    cout << endl;
    // check valid input 
    if(pass_type != 'S' && pass_type != 'P' && pass_type != 'V' && pass_type != 'K') {
        cout << "Please enter valid input." << endl;
        return 0;
    }

    cout << "Enter the number of workshop add-ons: ";
    int add_ons;
    cin >> add_ons;
    cout << endl;
    // check valid input 
    if(add_ons < 0) {
        cout << "Please enter a non-negative number of workshops." << endl;
        return 0;
    }

    cout << "Enter your budget: $";
    double budget;
    cin >> budget;
    cout << endl;
    // check valid input 
    if(budget < 0) {
        cout << "Please enter a non-negative budget." << endl;
        return 0;
    }

    string pass;
    double total_cost = 0;
    // Check puchase of pass type
    if (pass_type == 'S') {
        budget = budget - 35.50;
        pass = "Student";
        total_cost+=35.50;
    } else if (pass_type == 'P') {
        budget = budget - 75.25;
        pass = "Professional";
        total_cost+=75.25;
    } else if (pass_type == 'V') {
        budget = budget - 150.75;
        pass = "VIP";
        total_cost+=150.75;
    } else if (pass_type == 'K') {
        budget = budget - 200.50;
        pass = "Speaker";
        total_cost+=200.50;
    }

    // ADD ONS, add 50 to each add one
    for(int i = 0; i < add_ons; i++) {
        budget = budget - 50;
        total_cost+=50;
    }

    // check if budget is less than 0, that means there are insuffienct funds 
    if(budget < 0) {
        cout << "Pass purchase failed. Insufficient funds." << endl;
    } else {
        cout << "Pass purchase successful! Pass type: " << pass << ", Workshops: " << add_ons << ", Total cost: $" << total_cost << ", Remaining budget: $" << budget << endl;
    }

}