
#include <iostream>
#include <cstdlib> // this is for rand

using namespace std;

int main() {
    // loops - repeat lines of code while a condition is true
    // undefined number of times - repeats until condition is false, not known ahead of time 
    // defined number of times, fixed
    // unspecified: while loop 

    // while loop - do something while a condition is true
    int counter = 0;
    while (counter <= 5) {
        cout << "counter= " << counter << endl;
        counter++; // counter = counter + 1
    }
    cout << "counter after the loop = " << counter << endl;

    // write a while loop that takes an initial value and divides in half each time in loop. Loop 5 times
    counter = 0;
    double x = 10.0;
    while (counter < 5) {
        x = x / 2;
        cout << x << endl;
        counter ++;
    }

    // write some code that asks a user for sq. ft to paint 
    // if number is <=0, ask again. repreat until user enters valid number
    int sq_ft;
    cout << "Enter sq. ft to paint " << endl;
    cin >> sq_ft;
    while (sq_ft <=0) {
        cout << "Enter sq. ft to paint " << endl;
        cin >> sq_ft;
    }

    cout << "you entered " << sq_ft << endl;


    /* Imagine you're in a choose your own adventure game
    Your options are (f)ight the dragon, (s)torm the castle,
    (g)o gome. ask the user what they want to do,
    they have to select on these options
    Loop until they select a valid option, then print option they selcted
    */
    char option;
    cout << "Choose an option for chose your own adventure game "<< endl;
    cin >> option;
    while(option != 'f' && option != 's' && option != 'g') {
        cout << "Choose an option for chose your own adventure game "<< endl;
        cin >> option;
    }
    cout << "you entered " << option << endl;

    if(option == 'f') {
        cout << "you selected fight the dragon";

    } else if (option == 'g') {
        cout << "you selected go home";

    } else {
        cout << "you selected storm the castle";
    }

    /*
    write a program that asks the user to guess a number between 0 and 100
    the number should be randomly generated. Note you can use rand() % 100 + 1
    to generate the number. Include cstdlib

    pseudocode:
    generate a number and store it - variable
    ask user for a guess and store it - variable
    if user guess is not a number, then 
        if guess is higher than number, say lower
        if guess is lower than number, say higher
        ask for new guess 
    repeat until user guess == number 
    */

   // How do I change this to play the game until the user says to stop playing
    srand(time(nullptr));
    bool play = true; // make sure we play at least once 
    while(play) {
        int number = rand() % 100 + 1;
        // if you mod rand by 100, you get a range of 0 -99
        // we want 0 - 100 so you add 1
        int user_guess;
        cout << "guess number between 0 and 100" << endl;
        cin >> user_guess;

        while(number != user_guess) {
            if(user_guess > number) {
                cout << "go lower, please guess again " << endl;
            } else {
                cout << "go higher, please guess again" << endl;
            }
            cin >> user_guess;
        }
        cout << "correct: the number is " << number << endl;
        // ask user to play again 
        cout << "do you want to play again? 1 = yes, 0 = no " << endl;
        cin >> play;
    }


}