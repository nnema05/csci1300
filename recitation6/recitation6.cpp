
/*WARM UP*/

#include <iostream>
#include <string>
using namespace std;
/*A*/
int main()
     {
        int num_rows;
         cout << "Enter the number of rows: ";
         cin >> num_rows;

        for (int i = 1; i <= num_rows; i++)
         {
             // Fill in the blank below to get the correct number of stars in the ith row.
             for (int j = 1; j <= i; j++)
            {
                 cout << "* ";
             }
             cout << endl;
         }

         return 0;
    }

    // /*B*/
     int main()
    {
         // Fill the blank below to create an integer array of size 5 and initialize it with the numbers 3, 4, 5, 6, 7
         int numbers[5] = {3, 4, 5, 6, 7};

         cout << "The contents of the array are: ";
         for(int i = 0; i < 5; i++)
        {
             cout << numbers[i] << " ";
         }
         return 0; 
    }

     #include <iostream>
     using namespace std;

     /*C*/
     // Fill the line below with the appropriate function header
     void addTwo(int numbers[], int numbers_length)
     {
         for(int i = 0; i < numbers_length; i++)
         {
             numbers[i] = numbers[i] + 2;
         }

         return;
     }

     int main() 
     {
         int numbers[5] = {10, 11, 12, 13, 14};

         addTwo(numbers, 5);

         cout << "The updated array is: ";
         for(int i = 0; i < 5; i++)
         {
             cout << numbers[i] << " ";
         }

         return 0;
     }

    // /*QUESTION 1*/
    // /*Swap function
    // -create temp vairable set it equal to first letter
    // -set first leftter equal to last letter 
    // -set last letter equal to temp
    // */
    // /*reverse array
    // -for loop
    // - for every letter in this array
    // -run the swap function
    // */
    // /*main
    // -prompt user to enter ten characters
    // -run reverseArray()
    // */

    // /*SPOT THE ERRORS*/
    // // need to be less than not <=
    // /*A*/
    int main() 
     {
         int x = 3, y = 4;

        for(int i = 0; i < x; i++)
         {
             for(int j = 0; j < y; i++)
             {
                 cout << "(" << i << ", " << j << ")  ";
         }
             cout << endl;
        }

     }

    // /*B*/
    // // need to be less than not <=
    // // #include <iostream>
    // // #include <string>
    // using namespace std;

     int main()
     {
         int numbers[5] = {10, 20, 30, 40, 50};
         int sum = 0;

         cout << "The contents of the array are: ";
         for (int i = 0; i < 5; i++)
         {
             cout << numbers[i] << " ";
         }
         cout << endl;
         // need a semi colon
         for (int i = 0; i < 5; i++)
         {
             sum += numbers[i];
         }

         cout << "Sum = " << sum << endl;
         return 0;
     }


    // // /*C*/
    // // #include <iostream>
     #include <string>
    // // using namespace std;
    // have to tp pass in a array length
     void flipSign(int numbers[], int numbers_length)
     {
        for (int i = 0; i < numbers_length; i++)
     {
        numbers[i] = -1 * numbers[i];
     }
     return;
 }

 int main(){
     int length = 4;
    int numbers[] = {1, 2, 3, 4};

     cout << "The contents of the array before changing: ";
     for (int i = 0; i < length; i++)
        {
         cout << numbers[i] << " ";
         }
     cout << endl;
    flipSign(numbers, length);

     cout << "The contents of the array after changing: ";
     for (int i = 0; i < length; i++)
     {
         cout << numbers[i] << " ";
     }

 return 0;
    }
