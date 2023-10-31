
#include <iostream>
#include <vector>
/* MIDTERM 2
Loops
Arrays and vectors
Conditinonals
file streams
*/

using namespace std;
// create a struct that has global scope! --> anywhere in the program
    // naming convention: upperCamelCase (ex. StreetAdress)
    // end struct with semi colon
    // how you define: struct NameOfStruct { // var }; 
struct Product 
{ 
    // the below name, category, price are data members or attributes of struct 
    string name; 
    string category;
    double price;
}phone, pear; // can create objects called phone and pear from struct within struct
    // phone and pear have global scope 
    // DONT DEFFINE 

// function to print the attributes in the Product struct 
    // can pass object from struct as 
void printProduct(Product p) {
    cout << "======= PRODUCT =========" << endl;
    cout << "Name: " << p.name << endl;
    cout << "Category: " << p.category << endl;
    cout << "Price $: " << p.price << endl;
    cout << "=========================" << endl;
    p.price = 20; // any changes you make in struct in function is only limited to function
        // BC STRUCT IS PASS BY VALUE 
}

// can return a struct data type! 
Product inflationpriceUpdate(Product p)
{
    p.price = 10;
    return p;
}
int main() {
    // structures - struct 
    // a structure is a collectino of related dtaa items, possibly different types
    // a structure type in C++ is called a struct 
    // a struct is heregeneous in that it can be composed of data of different types
    // in contrast array is homogenous, same data type

    // structure is a user defined data type 

    // phones, apples, clothes, pencils -> products 
    // price --> double, name --> string, category --> string (produce, tech, stationary)
    // price will be an array, name as an array, category as an array 

    // int x; // defining a vairable , x is a variable of type int
    // cout << x; // 0 or garbage value 
    // x = 10; initialzing 
    int y = 20; // defining + initialzing 

    Product apple; // defining a variable: apple is a variable/object of type Product 
    // apple has no initial values 
        // but apple attributes: has a name, category and price

    // Approach 1 -initialize a struct variable/object
    apple.name = "apple";
    apple.category = "produce";
    apple.price = 2.65; // get the attribute price from product struct 
    
    // approach -2 {} 
        // make sure everything is right order!
    Product pencil = {"pencil", "stationary", 10};
    
    // to print 
        // name of struct notation, dot notation then the get the attribute
    // cout << apple.name << endl;
    // cout << apple.category << endl;
    // cout << apple.price << endl;

    // or print using function
    printProduct(apple);
    printProduct(pencil);

    // updating price
    apple = inflationpriceUpdate(apple);
    cout << apple.price << endl;

    // cant compare two structs as is, need to compare inidivual attributes
    if(apple.category == pencil.category);

    // array of structs
    int arr[0];
    // First way to initizalize
        // initaizlie the first value of produce to be the apple struct 
    Product produce[2] = {apple};
    // Second way to initizlie
        // initialzing second value of produce with new attributes in a struct 
    produce[1] = {"pear", "produce", 3.25};
    // Third way to initialize
    Product potato = {"potato", "produce", 0.99};
    produce[2] = potato;

    // update the price for produce at index 1
    produce[1].price = 4.25;
        // can print this using produce 
    printProduct(produce[1]);

    // making a vector of product struct
    vector<Product> tech;
    Product phone = {"iphone", "phones", 1200};
    tech.push_back(phone);


    return 0;
}