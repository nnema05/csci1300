// FINAL WORKING

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

double calculateBudget(vector<string> cart, double budget) {
     double price = 0;
    if(cart.size() == 0) {
        // cout << "cart is empty" << endl;
        return budget; 
    } else {
        for (int i = 0; i < cart.size(); i++)  {
        if(cart[i] == "Cheetos") {
            price = 2.99*(1 +.09);
            budget = budget - price;
        } else if (cart[i] == "Oreos") {
            price = 3.39*(1 +.09);
            budget = budget - price;
        } else if (cart[i] == "Coffee") {
            price = 3.79*(1 +.09);
            budget = budget - price;
        } else if (cart[i] == "Slurpee") {
            price = 4.29*(1 +.09);
            budget = budget - price;
        }   
        break;
    }
    }
    

    return budget;
}

// create a function to add product 
vector<string> addProduct(char productChoice, double budget, vector<string> cart) {
    // have a varaible for price 
    double price; 

    // switch statement to check what the product is 
    switch(productChoice) {
        case 'A': 
            if (budget < 0) {
                cout << "Your budget is insufficient to add more products." << endl;
            } else {
                cart.push_back("Cheetos");
                cout << "Cheetos added to cart." << endl;
                // for (int i = 0; i < cart.size(); i++)  {
                //     cout << cart[i] << " "; 
                // }
            }
            break;
        case 'B': 
            if (budget < 0) {
                cout << "Your budget is insufficient to add more products." << endl;
            } else {
                cart.push_back("Oreos");
                cout << "Oreos added to cart." << endl;
                // for (int i = 0; i < cart.size(); i++)  {
                //     cout << cart[i] << " "; 
                // }

            }
            break;
        case 'C':
            if (budget < 0) {
                cout << "Your budget is insufficient to add more products." << endl;
            } else {
                cart.push_back("Coffee");
                cout << "Coffee added to cart." << endl;
                // for (int i = 0; i < cart.size(); i++)  {
                //     cout << cart[i] << " "; 
                // }
            }
            break;
        case 'D': 
            if (budget < 0) {
                cout << "Your budget is insufficient to add more products." << endl;
            } else {
                cart.push_back("Slurpee");
                cout << "Slurpee added to cart." << endl;
                // for (int i = 0; i < cart.size(); i++)  {
                //     cout << cart[i] << " "; 
                // }
            }
            break;
    }
    // cout << "bugdet in add product " << budget << endl;
    return cart;
    
}


// remove product function
vector<string> removeProduct(vector<string> cart, string remove, double budget) {
    string removedProduct;
    bool found = false;
    // cout << "Enter the product name to be removed from the cart: " << endl;
    // cin >> removeProduct;
    
    if(cart.size() == 0) {
        cout << "Cart is empty." << endl;

    } else {
        // go through entire cart
        for (int i = 0; i < cart.size(); i++)  {
            if(!found) {
                // if remove product vairable  is in cart, delete it
                if(remove == cart[i]) {
                    // say what will be removed from cart
                    cout << cart[i] << " removed from cart." << endl;
                    // save that to a variable
                    remove = cart[i];
                    // algorithim from textbook!
                    for(int j = i + 1; j < cart.size(); j++) {
                        cart[j - 1] = cart[j]; // move the elements down
                    } 
                    // delete the last position
                    cart.pop_back(); 
                    // set found to true!
                    found = true;
                }
            }
        }

        if(found == false) {
            cout << "Product Name not found." << endl;
        }  
    }
    // cout << budget << endl;
    return cart;
}

bool checkout(vector<string> cart, double budget) {
    bool cartNotEmpty = false;

    if(cart.size() == 0) {
        cout << "Cart is empty." << endl; 
        return cartNotEmpty;

    } else { // if not print what products your cart has
        cout << "Your cart has the following products: " << endl;
        for (int i = 0; i < cart.size(); i++)  {
            cout << cart[i] << endl; 
        }
    }

    // print the total amount of the cart 
    double totalAmount = 0;
    for (int i = 0; i < cart.size(); i++)  {
        if(cart[i] == "Cheetos") {
            totalAmount = totalAmount + (2.99*(1 +.09));
            // cout << totalAmount << endl;
        } else if(cart[i] == "Oreos") {
            totalAmount = totalAmount + (3.39*(1 +.09));
            // cout << totalAmount << endl;
        } else if(cart[i] == "Coffee") {
            totalAmount = totalAmount + (3.79*(1 +.09));
            // cout << totalAmount << endl;
        } else if(cart[i] == "Slurpee") {
            totalAmount = totalAmount + (4.29*(1 +.09));
            // cout << totalAmount << endl;
        }
    }

    cout << "Total amount: $" << fixed << setprecision(3) << totalAmount << endl;
    cout << "Thank you! Please visit again." << endl;
    cartNotEmpty = true;
    return cartNotEmpty;
}

int main() {
    // welcome the user 
    cout << "Welcome to Kroga Gas Station!" << endl;
    // ask user to enter a budget 
    double budget; 
    cout << "Enter your budget: " << endl;
    cin >> budget;
    // check if budget is valid. If not, exit the program
    if(budget <= 0) {
        cout << "Invalid input. Balance must be a non-negative value." << endl;
        return 0;
    }
    bool cartNotEmpty;
    // create a variable that will store the new budget as it changes
    double new_budget = budget;
    // create an vector for cart 
    vector<string> cart;
    
    // Display the four menu options
    // Your menu should run in a loop, offering the user every option until they choose to exit the program.
    int input = 0;
    while (input!=4) {
        // Menu options for user 
        cout << "Please input 1-4 followed by enter to navigate the menu: " << endl;
        cout << "1) Add Product" << endl;
        cout << "2) Remove Product" << endl;
        cout << "3) Checkout" << endl;
        cout << "4) Exit" << endl;

        // read in what user chooses as an input 
        cin >> input;
        // check if input is valid, if not prompt for their choice again
            // check for inputs that are not 1-4 or something that is outside of what is expected in cin
        while(cin.fail() || input < 1 || input > 4) { 
            
            cout << "Invalid input." << endl; 
    
            cin.clear(); // if this happens we have to cin.clear (reset cin.fail which is true right now to false)
            cin.ignore(10000,'\n'); // cin.ignore tells computer to ignore first 10000 characters in varaible or up until you hit a new line
                // ask cin to ignore the characters in the cin buffer: Ignore function is used to skip(discard/throw away) characters in the input stream.

            // Menu options for user 
            cout << "Please input 1-4 followed by enter to navigate the menu: " << endl;
            cout << "1) Add Product" << endl;
            cout << "2) Remove Product" << endl;
            cout << "3) Checkout" << endl;
            cout << "4) Exit" << endl; 
            /// Ask user again for choice 
            cin >> input; // read what user selects into the input 
            
        }

        // Below are conditionals based on what user inputs 
        // If input is 1, add product
        // create a variable to store the new bugdet as price increases
        if(input == 1) {
             // if the new budget is not enough to buy anything, then cout that
            if (budget < 4.29*(1 +.09)) {
                cout << "Your budget is insufficient to add more products." << endl;
            } else {
                // have an variable to track the product 
                char productChoice;
                // Display the following menu and prompt the user to choose a product:
                // Menu options for user 
                cout << "Add Product: " << endl;
                cout << "A) Cheetos" << endl;
                cout << "B) Oreos" << endl;
                cout << "C) Coffee" << endl;
                cout << "D) Slurpee" << endl;

                cin >> productChoice;

                // check if product input is valid
                if(cin.fail() || productChoice != 'A' && productChoice != 'B' && productChoice != 'C' && productChoice != 'D') { 
                        
                    cout << "Invalid input." << endl; 

                    cin.clear(); // if this happens we have to cin.clear (reset cin.fail which is true right now to false)
                    cin.ignore(10000,'\n'); // cin.ignore tells computer to ignore first 10000 characters in varaible or up until you hit a new line
                        // ask cin to ignore the characters in the cin buffer: Ignore function is used to skip(discard/throw away) characters in the input stream. 
                }
                // budget = calculateBudget(cart, budget);
                // cout << "bugdet before addding product " << budget << endl;
                cart = addProduct(productChoice, budget, cart);
                budget = calculateBudget(cart, budget);
               // cout << "bugdet after addding product " << budget << endl;
            }
        }
        
        if (input == 2) {
            // if input is 2, run remove product 
            string remove;
            cout << "Enter the product name to be removed from the cart: " << endl;
            cin >> remove;
            double price = 0;
            for (int i = 0; i < cart.size(); i++)  {
                // if remove product vairable  is in cart, delete it
                if(remove == cart[i]) {
                    if(remove == "Cheetos") {
                    price = 2.99*(1 +.09);
                    budget = budget + price;
                } else if (remove == "Oreos") {
                    price = 3.39*(1 +.09);
                    budget = budget + price;
                } else if (remove == "Coffee") {
                    price = 3.79*(1 +.09);
                    budget = budget + price;
                } else if (remove == "Slurpee") {
                    price = 2.99*(1 +.09);
                    budget = budget + price;
                } 
                }
            }
            cart = removeProduct(cart, remove, budget);
            // cout << "bugdet after removing product " << budget << endl;

        }

        if (input == 3) {
            // if input is 3, run checkout
            // set it equal to boolean
            cartNotEmpty = checkout(cart, budget);
            // if boolean is true, return 0
            if(cartNotEmpty) {
                return 0;
            }
            
        }

        if (input == 4) {
            // exit program
            cout << "Thank you! Please visit again." << endl;
            return 0;

        }
    }
}