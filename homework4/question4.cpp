/*STILL NEED TO WORK*/

// As a manager of a plowing company getting ready for winter, you decide to purchase several new work trucks. 
// You have a budget of $81,350 and need to purchase at least two trucks in order to meet your target capacity.
// You want to write a program to help you manage your purchases.

#include <iostream>

using namespace std;

int purchaseTruck(int budget) {
    int truck_choice1;
    int truck_choice2;
    int truck_choice3;
    int price;
    int new_budget = budget;

    cout << "Please enter a number from 1 to 5: " << endl;
    cin >> truck_choice1;
    switch (truck_choice1) {
        case 1:
            price = 26900;
            new_budget = budget - price;
            cout << "Congratulations! You have purchased a Ford F-150" << endl;
            break;
        case 2:
            price = 21400;
            new_budget = budget - price;
            cout << "Congratulations! You have purchased a Dodge RAM 1500" << endl;
            break;
        case 3:
            price = 24700;
            new_budget = budget - price;
            cout << "Congratulations! You have purchased a Chevy Silverado" << endl;
            break;
        case 4:
            price = 31200;
            new_budget = budget - price;
            cout << "Congratulations! You have purchased a Toyota Tundra" << endl;
            break;
        case 5:
            price = 28300;
            new_budget = budget - price;  
            cout << "Congratulations! You have purchased a GMC Sierra 1500" << endl;
            break;
        default: 
            cout << "Invalid input!" << endl;
            break;
    }

    cout << "Please enter a number from 1 to 5: " << endl;
    cin >> truck_choice2;
    switch (truck_choice2) {
        case 1:
            price = 26900;
            new_budget = new_budget - price;
            cout << "Congratulations! You have purchased a Ford F-150" << endl;
            break;
        case 2:
            price = 21400;
            new_budget = new_budget - price;
            cout << "Congratulations! You have purchased a Dodge RAM 1500" << endl;
            break;
        case 3:
            price = 24700;
            new_budget = new_budget - price;
            cout << "Congratulations! You have purchased a Chevy Silverado" << endl;
            break;
        case 4:
            price = 31200;
            new_budget = new_budget - price;
            cout << "Congratulations! You have purchased a Toyota Tundra" << endl;
            break;
        case 5:
            price = 28300;
            new_budget = new_budget - price;  
            cout << "Congratulations! You have purchased a GMC Sierra 1500" << endl;
            break;
        default: 
            cout << "Invalid input!" << endl;
            break;
    }
    
    if(new_budget > 31200) {
        cout << "Please enter a number from 1 to 5: " << endl;
        cin >> truck_choice3;
        switch (truck_choice3) {
            case 1:
                price = 26900;
                new_budget = new_budget - price;
                cout << "Congratulations! You have purchased a Ford F-150" << endl;
                break;
            case 2:
                price = 21400;
                new_budget = new_budget - price;
                cout << "Congratulations! You have purchased a Dodge RAM 1500" << endl;
                break;
            case 3:
                price = 24700;
                new_budget = new_budget - price;
                cout << "Congratulations! You have purchased a Chevy Silverado" << endl;
                break;
            case 4:
                price = 31200;
                new_budget = new_budget - price;
                cout << "Congratulations! You have purchased a Toyota Tundra" << endl;
                break;
            case 5:
                price = 28300;
                new_budget = new_budget - price;  
                cout << "Congratulations! You have purchased a GMC Sierra 1500" << endl;
                break;
            default: 
                cout << "Invalid input!" << endl;
                break;
        }

    } else {
        return new_budget;
    }
    

    return new_budget;
    
}

int main() {

    int budget = 81350;
    int new_buget;

    // display the truck models avaiable for purhcase
    cout << "These are the trucks available for purchase: " << endl;
    cout << "Truck model 1: Ford F-150. Price: $26,900" << endl;
    cout << "Truck model 2: Dodge RAM 1500. Price: $21,400" << endl;
    cout << "Truck model 3: Chevy Silverado. Price: $24,700" << endl;
    cout << "Truck model 4: Toyota Tundra. Price: $31,200" << endl; 
    cout << "Truck model 5: GMC Sierra 1500. Price: $28,300" << endl;

    new_buget = purchaseTruck(budget);


}

