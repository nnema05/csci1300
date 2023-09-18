
#include <iostream>

using namespace std;

// created a vairable outside of main  
int g_var = 5; // global - can be seen everywhere in this file
    // any function that we now create in this file can be see and use this variable 

void printGVar() { // this function can see g_var because its global 
    cout << g_var << endl;
}

void scopeTest(int a, int b) {
    // a and b are local to scopeTest
    cout << a << endl;
    cout << b << endl; 
    // this will not work bc c is out of scope 
    // cout << c << endl;

}
int main() {
    // scope of variable is where a variable can be seen in a program 
    // Global - seen everywhere 

    printGVar();
    int g_var = 7; // local to main function 
        // you can have a local and global variable that can have the same name 
    cout << g_var << 7;
    g_var = 10;
    printGVar();
    // global variables are messy and they're hard to keep track of 
    // better practice is to use local variables that are passed as arguements!
    // local variable: only seen in the fucntion, or code block, where it is defined, 
        // or passed as an arguement 
    scopeTest(45, 12);
    int c = 45; // local to main
    int d = 12; // local to main
    scopeTest(c, d); // this will pass in the value stored in c, not the vairable

    if(c < 45) {
        int i = 10; // i is local to conditional 
        
    }
    // even if conditional is trye and variable is created, it is destroyed after conditional exits
    // cout << i << endl; // this does not work because variable not in scope outside of conditional 


    /* STRINGS */
    // Every character you type has an ASCII number associated with it 
    // Ex. A is a 65

    // a String is a sequence of individual alpha-numeric characters
    string strA; // string variable
    // Can do a lot of manipulation with a string  
        // if you strA., lots of methods come up of things you can do to a string
        // all are part of the string class (a class is a container of stuff)
    strA = "this is a string";
    // can get length of string
    int strALength = strA.length(); // call the length function of our string 
    cout << strALength << endl;
    strA = "Will the Rockies win the world series?";
    // get substring of string
    string str2 = strA.substr(9, 7);
        // will start at position 9 and print the 7 characters
    cout << str2 << endl; // prints "Rockies"

    // user input of string 
    cout << "type two words" << endl;
    // cin >> str2;
    // cout << str2 << endl; // this only stores the first word because cin stops after white space!
    // to fix this use function called getline
    getline(cin, str2); // reads the whole line plus spaces, not just first word
    cout << str2 << endl;


}