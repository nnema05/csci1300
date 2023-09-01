
#include <iostream>

using namespace std;

int main() {

    // varaibles - integers and doubles
    // what is a variable?
    // location in memory where value can be stored
    // type name = value. All variables have a type!
    int a = 5; // type is int, name is a, value is 5 
    // this is illegal: int 5 = a (order matters when defining variables)
    cout << a << endl;

    double b = 4.5;
    cout << "b = " << b << endl;
    // int is integer or a whole  number
    // double is a decimal 

    // addition 
    double c = 5.1;
    double e = b + c; // add two doubles, result will be a double 
    cout << "e = " << e << endl;

    int x = a + 5;
    cout << "x = " << x << endl; // will print integer

    // division 
    double f2 = 5.0;
    double f3 = 6.0;
    cout << f2/f3<< endl; // will print double

    // integer division 
    a = 5;
    x = 6;
    cout << a/x << endl; // will round down the actual value to the nearest integer
        // print 0

    a = 15;
    cout << a/x << endl; // will round down the actual value to the nearest integer
        // print 2

   // multiplication
   double z = 45 * b;
   cout << z << endl; // will print double because multiplication on double

   // multiplication on integers
   cout << a * x << endl;
   cout << a * x * z << endl; // should print a double because you are multiplying by double


   // Question: Given a circle with a radius equal to 10
    // Calulate the are and circumference of the circle
    // area = pi * r^2
    // circumference = 2 * pi * r
    double pi = 3.14;
    int radius = 10;
    int area = pi * pow(radius, 2);
    int circumference = 2 * pi * radius;

    cout << "Area is " << area << endl;
    cout << "Circumference is " << circumference << endl;
    

    // how to get user input 
    cout << "Enter a radius " << endl;
    cin >> radius; // this will get user input and store in r
    area = pi * pow(radius, 2);
    cout << "The area is " << area << endl;

}