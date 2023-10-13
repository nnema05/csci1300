
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int number = 0;
    cout << "Enter number" << endl;
    cin >> number; // im expecting an integer, what happens if i get a letter?
    if(cin.fail()==true) { // cin.fail is true if user doesnt enter a number
        cout << "cin failed state" << endl;
        // clear the cin buffer, gets you out of the fail state
        cin.clear(); // this clears the error, but the input 
        cin.ignore(1000, '\n'); // ignore the next 1000 characters up to the newline
    } else {
        cout << "you typed " << number << endl;
    }
    cout << "enter a real number" << endl;
    cin >> number;
    cout << "you type a " << number << endl; 

    /*ascii tables*/ 
    char a = 'a';
    // (int)a gives its ascii value, which is 97 for lowercase a
    cout << a << " " << (int)a << endl;
    a++;
    // add 1 to a, it now has an ascii value of 98, which is lowercase b 
    cout << a << " " << (int)a << endl;

    /* VECTORS */
    // interface on c++ that make array operations easier 
    // creating vectors, syntax looks different
    // adding and removing data from vectors
    // accessing elements using index 

    // creating an empty vector 
    // create a vector of integers, variable name is v, initially empty
    vector<int> v; // int v[5] 

    vector<int> v2(5); // variable name is v2, vector of int, size is 5
        // vector values are initialzied to 0
    cout << "size of vector v: " << v.size() << endl;
    for(unsigned int i = 0; i < v2.size(); i++) {
        cout << v2[i] << " ";
    }
    cout << "size of vector v2: " << v2.size() << endl;

    // how do I add stuff to a vector?
    // use push to dunamically add elements to a vector, dont need to know size ahead of time
    // push_back adds an element to end of vector
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);
    cout << "size of vector " << v.size() << endl; // should update to refelct 3 elemenst added to vector
    for(int i = 0; i < v.size(); i++) {
        // you can access vector elements with at command 
        v.at(i) = i; // this accesses the ith element using vector notation
        // this accesses the ith element ysing array notation
        cout << v.at(i) << " ";  // accesses vector elements at position i, same notation as array
    }
    cout << endl;

    // v.insert() - you can insert at any element using an iterator, dont need to shift
    int s = v.back(); // gets the last element and stores in s 
    // pop.back() will remove element at the last position
    v.pop_back(); // no arguements, not return value, removes element 
    cout << "s: " << s << endl;
    // print v now to show that last element removed
    for (unsigned int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";

    }
    cout << endl;

        
}