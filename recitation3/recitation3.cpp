#include <iostream>

using namespace std;

/* Pseudocode */
// Create Function fertilize(double stock, double amount)
    // If (stock - amount ) is less than 0
        // print " you can't use more fertilizer than you have, invalid input"
        // return stock

    // else 
        // create variable stockLeftOver
        // stockLeftOver = stock - amount 


// Create function restock(double stock, double amount)
    // create variable restockAmount 
    // restockAmount = stock + amount 
    // return resstock amount

// main function 
    // create variables stock and amount and intialize vairable
    // call fertilize function
    // call restock function 
    // return 0

double fertilize(double stock, double amount) {
    double stockLeftOver = stock - amount; 

    if(stockLeftOver < 0) {
        cout << " You can't use more fertilizer than you have " << endl;
        return stock;

    } else {
        return stockLeftOver;
    }
}

double restock(double stock, double amount) {
    double restockAmount = stock + amount;
    return restockAmount;

}

int main() {
    // double stock = 100.0;
    // double amount = 20.5;
    // double stock = 51.0;
    // double amount = 50.0;
    double stock = 71.4;
    double amount = 20.0;

    double fertilizeResult = fertilize(stock, amount);
    double restockResult = restock(stock, amount);

    cout << fertilizeResult << endl;
    cout << restockResult << endl;
}


