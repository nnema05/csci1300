
/*

What is object oriented programming
Approach to programming that encapsulates functions and data into blocks of code - called classes

Classes to define objects. An obejct is an instantiation of a class.

Objects have data members (varaibles) and member functions (methods)

Methods act on the data members 

Methods can have a public or private interface. 
Public means that other code can call the method outside the object 
Private means that only other member functions can call the method 

Class is a template that has data and functions in in it

Member data is always private to the class. Can only be accessed through public methods
    Structs are set up so that all the data is public

Encapsulation - public interface available, details of the implementation are hidden

How would you represent an Automobile in code?
Make, model, price, color, drive train, mpg, cylinder, speed, acceleration, condition
Real world objects have complex feautures 
*/

#include <iostream>
using namespace std;

// define automobile outside of main
class Automobile {
    // private data and methods of class Automobile
    private:
        string make;
        string model;
        string condition;
        int year;
    
    public:
        // constructor - called when the object is created 
        // constructor overloading - multiple ways of creating an instance of the object 
        Automobile() {
            // constructor with no agruements
            // we will set the defult values for make, model, condition and year
            // every instance of Automobile with this constructor will have same values
            make = "Ford";
            model = "Ranger";
            condition = "new";
            year = 2023;
        }
        Automobile(string ma, string mo, int y) {
            // set object properties using arguements to constructor
            make = ma;
            model = mo;
            year = y;
            condition = "new";
            cout << "calling constructor" << endl;
        }
        // get and set methods to access private data
        // getMake is a public method in Automobile
        string getMake() {
            return make;
        }
        // setMake takes an arguememt and updates make to that value 
        void setMake(string ma) {
            make = ma;
        }

        // write a public method to set the condition of an autombile
            // the three possible conditions are new, used, wrecked
            // method needs to check that user entered valid condition
            // only update if condition is valid
            // call it set condition
        void setCondition(string c) {
            if(c == "new" || c == "used" || c == "wrecked") {
                condition = c;
            } else {
                cout << "not a valid condition" << endl;
            }
        }
              
};

int main() {
    Automobile subaru("Subaru", "Outback", 2023); // this creates an instance of automobile called subaru 
    // cout << subaru.make<< endl; // does not work since make is private
    // to get access to private data in Automobile, we need get and set methods that are public 
    cout << subaru.getMake() << endl;
    // how would I do setMake and what would it do 
    subaru.setCondition("new");

    Automobile ford; // this calls the constructor with no arguments
    cout << ford.getMake() << endl;

}