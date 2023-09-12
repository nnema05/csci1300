
#include <iostream>

using namespace std;

int main() {
    // richter scale
/* value    destruction 
8   most structures fall 
7   many buildings destroyed
6   many buildings damaged
4.5     damage to poorly constructed buildings
less than 4.5   no damage
*/
// for given value on the richter scale, output the destruction expected

// define varaible
//double richter = 7.7; // arbitrary number
double richter = 8.0;

if(richter >= 8.0) {
    cout<< "most structures fall " <<endl;
} else if (richter >= 7.0) {
    cout<< "many buildings destroyed " <<endl;
} else if (richter >= 6.0) {
    cout<< "many buildings damaged " <<endl;
} else if (richter >= 4.5) {
    cout<< "damage to poorly constructed buildings " <<endl;
// if nothing is true else is what executues
} else {
    cout<< " no damage " <<endl;
}

// BELOW IS NOT THE CORRECT WAY TO FORMAT
    // the last condition will basically never be reached
    // If the last condition is true, the first condition will be as well
    // code won't execute correct logic
    // suntatically correct, logically not what we want 
if(richter >= 4.5) {
    cout<< "damage to poorly constructed buildings " <<endl;
} else if (richter >= 6.0) {
    cout<< "many buildings damaged " <<endl;
} else if (richter >= 7.0) {
    cout<< "many buildings destroyed " <<endl;
} else if (richter >= 8.0) {
    cout<< "most structures fall " <<endl;
} else {
    cout<< " no damage " <<endl;
}

if(richter >= 8.0) {
    cout<< "most structures fall " <<endl;
} 
if (richter >= 7.0) {
    cout<< "many buildings destroyed " <<endl;
} 
if (richter >= 6.0) {
    cout<< "many buildings damaged " <<endl;
} 
if (richter >= 4.5) {
    cout<< "damage to poorly constructed buildings " <<endl;
} else {
    cout<< " no damage " <<endl;
}
// multiple operators in my conditional 
// if two condition true, or one of two conditions are true
int a = 12;
if(a < 0 or a > 10) { // in an or statement, at least one condition needs to be true
    cout << "a is good" << endl;
} else {
    cout << "something not right " << endl;
}
// both conditions must be met 
int b = 5;
if ( a > 10 and b < 10) {
    cout << "both conditions true "<< endl;
} else {
    cout << "something false" << endl;
}

}