#include <iostream> 
#include <iomanip>
using namespace std;

int main() {
    cout << fixed << setprecision(2);
    cout << "How many ducks would you like to order?" << endl;
    int ducks = 0;
    cin >> ducks;
    if(ducks < 0) {
        cout << "Please enter a valid input." << endl;
        return 0;
    }

    double price = 0;
    price = ducks * .5;

    if(ducks > 20 && ducks <= 100) {
        price = price * .9;
    } else if(ducks > 100 && ducks <= 500) {
        price = price * .8;
    } else if(ducks > 500) {
        price = price * .5;
    }

    cout << "Your total is $" << price;

}