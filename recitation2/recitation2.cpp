
#include <iostream>
using namespace std;

/* Warm Up  */ 
int main()
{
    int temperature = 50; 

    if (temperature >= 85) {
        cout << "It's a hot day!";
    }
    else if (temperature > 60 && temperature < 85) {
        cout << "It's a pleasant day.";
    }
    // Fill in the below line
    else if (temperature > 40 && temperature <= 60) {
        cout << "It's a cool day.";
    }
    else {
        cout << "It's a cold day.";
    }

    return 0;
}

/* PROBLEM 1 */
int main()
{
    int num = 5;

    if (num > 10) {
        cout << "The number is greater than 10." ;
    }
    else if (num == 10) {
        cout << "The number is equal to 10."; 
    }
    else {
        cout << "The number is less than 10.";
    }

    return 0; 
}

/* PROBLEM 2 */

int main()
{
    int angle = 40;
    if (angle<90) { 
        cout<<"It is an acute angle." ;
    }
    else if(angle == 90) {
        cout<<"It is a right angle.";
    }
    else{
        cout<<"It is an obtuse angle.";
    }
}

/* PROBLEM 3 */

int main()
{
    int num = 0;

    if (num == 0) {
        cout << "The number is zero.";
    }
    else {
        cout << "The number is not zero.";
    }

    return 0; 
}

/* PROBLEM 4 */
#include <iostream>
using namespace std;

int main()
{
    int num = 7;

    if (num==0) { 
        cout << "The number is zero.";
    }
    else {
        cout << "The number is not zero.";
    }

    return 0; 
}

/* HYDRATION APP */
int main() {
    int water;
    cout << "How much water have you drank? " << endl;
    cin >> water;

    int waterLeft = 64 - water;

    if (water < 32 ) {
        cout <<  "You’re very, very dehydrated! Get that water in! You have " << waterLeft << " fl oz left to drink." << endl;
    } else if (water > 32 && water < 64) {
        cout << "You’re doing great, but you’re still halfway to your goal! Get that water in! You have " << waterLeft << " fl oz left to drink" << endl;

    } else if (water >= 64) {
        cout << "You’ve hit your goal for the day! Great job getting hydrated!" << endl;
    }
}