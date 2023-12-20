
// WARM UP 
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main() 
{
    // Fill the line below to make the generated random number different for each run.
    srand((unsigned)time(NULL));
    int random_number = rand();  
    cout << random_number << endl;
    return 0;
}


int main() 
{
    // Fill the line below to make the generated random number different for each run.
    srand((unsigned)time(NULL)); // plants a seed which will generate a number starting from a seed
    int random_number = 0;
    // Fill the line below to generate a random number between 1 to 32 inclusively.
    random_number = rand() % 32 + 1;
    cout << "Number generated is " << random_number << endl;
    return 0;
}

/* QUESTION 1*/
/* PSEUDOCODE 
-Pass in a number into a function that is up to the Fibonacci Sequence will go to 
-If number passed in 0, return 0;
-If number passed in 1, return 1;
-If its anything else, return the recuvrsive call like fib(n-1) + fib(n-2)
*/

/* SAMPLE RUN
-num = 8, fibonacci(num) = 21
-num = 9, fibonacci(num) = 34
*/

int fibonacci(int num) {
    if(num == 0) {
        return 0;
    } else if(num == 1) {
        return 1;
    }
    return fibonacci(num-1) + fibonacci(num-2);
}

int main() {
    int num;
    // num = 9;
    // num = 0;
    // num = 1;
    cout << fibonacci(num);
}

/* QUESTION 2 */
/* Psuedocode
-Function pass in first number of disks, rod from, rod to go to, middle rod 
-If number of rods you put in 0, return 0 
-First call is first rod , third rod, second rod, move the first rod to the third rod 
-Second call is second rod ,  rod, third rod, move the first rod to the third rod 
call of towerOfHanoi(number of disks - 1, first rod , third rod, first rod)
- call of towerOfHanoi(number of disks - 1, second rod , third rod, first rod)
*/

/* SAMPLE RUN
-If n = 3, moves = 7

*/

int towerOfHanoi(int num, char rod_from, char rod_to_go, char middle_rod, int &count) {
    if(num == 0) {
        return 0; 
    }
    towerOfHanoi(num - 1, rod_from, middle_rod, rod_to_go, count);
    cout << "Move from" << rod_from << " to " << rod_to_go << endl;
    towerOfHanoi(num - 1, middle_rod, rod_to_go, rod_from, count);
    count = 1+ num *2;
    return count;
    
}

int main() {
    int num = 3;
    int count = 0;
    cout << towerOfHanoi(num, 'A', 'C', 'B', count) << endl;
    return 0;
}