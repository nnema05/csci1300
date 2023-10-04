#include <iostream>
#include <iomanip>

using namespace std;

/*QUESTION 1*/
// int main() {
//     int bagels = 75;
//     int months = 12;
//     int bonus_bagels = 2;
//     cout << bagels/months + bonus_bagels << endl;
//     return 0;
// } // PRINTS OUT: 8

/*QUESTION 2*/
// int main() {
//     cout << (((10 == 10.0) && (5 > 3)) && ((8!=6) || (4 > 7))) << endl;
// } // PRINTS: 1 which means true

/*QUESTION 3*/
// int main() {
//     cout << !(!(3 > 2) && (10 < 0) || (12 * 2 > 25 - 1)) << endl;
// } // PRINTS: 1 which means true

/*QUESTION 4*/ 
// int main() {
//     int x = 0;
//     int y = x + 2;
//     x++;

//     int answer = x + y;

//     cout << answer << endl;

//     return 0;
// } // PRINTS: 3

/* QUESTION 5*/ 
// int main() {
//     string x = "5";
//     int y = 5;

//     int answer = x + y;

//     cout << answer << endl;

//     return 0;
// } PRINTS : compile time error, cannot add string and int 

/*QUESTION 6*/
// int main() {
//     int x = 5/0;
//     cout << x << endl;
//     return 0;
// } // Prints : Inifity, warning!

/* QUESTION 7 */
// int main() {
//     double x;
//     x = 2 / 5;
//     cout << x << endl;
//     return 0;
// } // PRINTS: 0 because the two numbers being divided are integers! and round down to 0

/*QUESTION 8*/
// int main() {
//     float x = 5.0 / 2;
//     cout >> x >> endl;
//     return 0;
// } // PRINTS: compile time error 

/*QUESTION 9*/
// int main() {
//     int x = 5;
//     cout << "x" << endl;
//     return 0;
// } // PRINTS: x

/*QUESTION 10*/
// int main () {
//     string phrase = "The quick brown fox jumps over the lazy dog";
//     cout << phrase[11] << phrase[19] << phrase[4] << endl;
//     return 0;
// } // PRINTS r q

/*QUESTION 11*/
// int main () {
//     string phrase = "The quick brown fox jumps over the lazy dog";
//     int x = 2;
//     cout << phrase[3 + x] << phrase[7 * 2] << endl;
//     return 0;
// } // PRINTS un

/*QUESTION 12*/
// int main() {
//     string x = "hello " + "world";
//     cout << x << endl;
//     return 0;
// } PRINTS: Compile time error, cannot add string literals!

/* QUESTION 13*/
// int main() {
//     int x = 5;
//     int y = 2;
//     double z = x/y;
//     double answer = (static_cast<double>(x) / y) +z;
//     cout << answer << endl; // PRINTS 2, integers being divided even if set to double
//     return 0;
// }

/*QUESTION 1*/
// int main() {
//     int a = 1, b;
//     cout << "Please enter b: ";
//     cin >> b;

//     if (b > 300) {
//         a = b;

//     } else {
//         a = 1;
//     }

//     cout << "a: " << a << endl;
//     return 0;
// }

/*QUESTION 2*/
// int main() {
//     int x = 10;
//     int y = 4;
//     cout << !(x<15 && y>=3) << endl;
//     cout << (x>=15 || y < 3) << endl;

// }

/*QUESTION 3*/
// int main() {
//     int x = 0;
//     cout << (!x==0)<< endl;
// }

/*QUESTION 6*/
// int main() {
//     int x;
//     cout << x << endl;
//     x = x + 30;
//     cout << x<< endl;
// }

/*QUESTION 6*/
// int main() {
//     int x = 13;
//     x = x % 4;
//     cout << x<< endl;
// }

// int main() {
//     string x = "1300!";
//     int answer = x.substr(1,3).length() + x.length();
//     cout << answer << endl;
//     return 0;
// }

int main() {
    float x = 6.626068;
    cout << fixed << setprecision(4) << x << endl;
    return 0;
}