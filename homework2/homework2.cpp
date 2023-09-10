
#include <iostream>
#include <iomanip>

using namespace std;

// PROBLEM 1 : Traffic Flow
int main() 
{
    // declare all the variables
    int traffic_flow_rate;

    // prompt the user & get their input
    cout << "What is the traffic flow rate on the highway?" << endl;
    cin >> traffic_flow_rate;

    // input validation: traffic flow rate on the highway must be positive
    if (traffic_flow_rate < 0) // EDIT THIS LINE
    {
        cout << "Invalid traffic flow rate." << endl;
        return 0;
    }

    // decide if it's possible to reach the concert on time based on traffic flow rate
    if (traffic_flow_rate >= 800) // EDIT THIS LINE
    {
        cout << "You're gonna make it to the concert on time." << endl;
    }
    else
    {
        cout << "You're gonna be late to the concert." << endl;
    }

    return 0;
}

// PROBLEM 2 : 
int main() {

    // declare variable
    double withdrawAmount;
    double balance = 1000.00;

    // prompt user and get input 
    cout << "Enter the amount to be withdrawn from your bank account: " << endl;
    cin >> withdrawAmount;

    balance = balance - withdrawAmount;

    // input validation: balance must be positive 
    if (withdrawAmount <= 0) // EDIT THIS LINE
    {
        cout << "Invalid input. Withdrawn amount must be a non-negative value." << endl;
        return 0;
    }
    if (balance < 100.00) // EDIT THIS LINE
    {
        cout << "Transaction Failed!" << endl;
        return 0;

    } else {
        // Fix decimal places printed to two
        cout << setprecision(2) << fixed;
        cout << "Transaction Successful! You're balance is $" << balance << endl;
    }

}

// PROBLEM 3:
int main() {
    
    // declare variables! 
    int temperature;
    int windSpeed;

    // Ask for user input
    cout << "What is tomorrow's temperature looking like? " << endl;
    cin >> temperature;
    cout << "What is tomorrow's wind speed looking like? " << endl;
    cin >> windSpeed;

    // Check user input 
    if (temperature < 0 || windSpeed < 0) {
        cout << "Please enter valid input." << endl;
    }
    if (temperature >= 20 && temperature <= 30 && windSpeed <= 50) {
       cout << "The weather conditions are ideal for skiing tomorrow." << endl;

    } else {
        cout << "The weather conditions are not ideal for skiing tomorrow." << endl;
    }
}

// PROBLEM 4: 
int main () {
    
    // Declare variable
    double budget; 
    char arenaSeats;

    // take in character input
    cout << "What is your budget? " << endl;
    cout << "Which of these seats would you like to take (G, B, P or O)? " << endl;
    cin >> budget;
    cin >> arenaSeats;
    
    // check user input is valid 
    if (budget < 0 || arenaSeats != 'G' && arenaSeats != 'B' && arenaSeats != 'P' && arenaSeats != 'O') {
        cout << "Input is invalid" << endl;
        return 0;
    }

    // if else statements
    if (budget >= 1950.33) {
        if(arenaSeats == 'G' || arenaSeats == 'B' || arenaSeats == 'P' ||arenaSeats == 'O') {
            cout << "Yes, this seat is within your budget!" << endl;
        }
    } else if (budget >= 1684.29) {
        if(arenaSeats == 'G' || arenaSeats == 'B' || arenaSeats == 'P') {
            cout << "Yes, this seat is within your budget!" << endl;
        } else {
            cout << "Sorry, this seat is outside your budget." << endl;
        }
    } else if (budget >= 1340.96) {
        if(arenaSeats == 'G' || arenaSeats == 'B') {
            cout << "Yes, this seat is within your budget!" << endl;
        } else {
            cout << "Sorry, this seat is outside your budget." << endl;
        }
    } else if (budget >= 1075.15) {
        if(arenaSeats == 'G') {
            cout << "Yes, this seat is within your budget!" << endl;
        } else {
            cout << "Sorry, this seat is outside your budget." << endl;
        }
    } else {
        cout << "Sorry, this seat is outside your budget." << endl;
    }

}

// PROBLEM 5:
int main () {

    // declare variables
    double billTotal;
    char carType;
    double numOfDays;

    // user input
    cout << "Which car type ( A, B, C, or D ) would you like to rent? " << endl;
    cin >> carType;
    cout << "How many days would you like to rent this car? " << endl;
    cin >> numOfDays;

    if (numOfDays < 0 || carType != 'A' && carType != 'B' && carType != 'C' && carType != 'D') {
        cout << "Please enter valid input." << endl;
        return 0;
    }

    if (carType == 'A') {
        billTotal = 1.09 * (100 + numOfDays * 15);
        cout << setprecision(2) << fixed;
        cout << "Your bill total is $" << billTotal << endl;
    }

    if (carType == 'B') {
        billTotal = 1.09 * (150 + numOfDays * 20);
        cout << setprecision(2) << fixed;
        cout << "Your bill total is $" << billTotal << endl;
    }

    if (carType == 'C') {
        billTotal = 1.09 * (200 + numOfDays * 25);
        cout << setprecision(2) << fixed;
        cout << "Your bill total is $" << billTotal << endl;
    }

    if (carType == 'D') {
        billTotal = 1.09 * (250 + numOfDays * 30);
        cout << setprecision(2) << fixed;
        cout << "Your bill total is $" << billTotal << endl;
    }

}

