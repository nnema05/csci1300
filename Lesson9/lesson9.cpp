
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
    int c = 45;
    int d = 12;
    int c = 45; // local to main
    int d = 12; // local to main
    scopeTest(c, d); // this will pass in the value stored in c, not the vairable

    if(c < 45) {
        int i = 10; // i is local to conditional 
        
    }
    // even if conditional is trye and variable is created, it is destroyed after conditional exits
    // cout << i << endl; // this does not work because variable not in scope outside of conditional 

}