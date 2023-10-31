// Question 1
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void compareAttendanceSheet(string first_attendance_file, string second_attendance_file)
{
    // initialize variables
    ifstream first_file;
    first_file.open(first_attendance_file); // opens a file
    ifstream second_file;
    second_file.open(second_attendance_file);

    // need variables to count how many lines in each file
    int first_file_counter = 0;
    string first_name;
    int second_file_counter = 0;
    string second_name;

    if(first_file.is_open() && second_file.is_open()) {

        // count number of lines in first file
        while (!first_file.eof()) {
            getline(first_file, first_name);
            first_file_counter++;
            
        }
        cout << first_file_counter << endl;

        while (!second_file.eof()) {
            getline(second_file, second_name);
            second_file_counter++;
           
        }
        cout << second_file_counter << endl;

        // make an array to store all names of first array that is size of first_file_counter
        string first_names[first_file_counter];
        // make an array to store all names of second array that is size of second_file_counter
        string second_names[second_file_counter];


        // while there is data in the string, add that data into each array from the corresponding file
        while (!first_file.eof()) {
            for(int i = 0; i < first_file_counter; i++) {
                getline(first_file, first_names[i]);
                cout << first_names[i] << endl;
            }
        
        }

        while (!second_file.eof()) {
            getline(second_file, second_names[second_file_counter]);
            for(int i = 0; i < second_file_counter; i++) {
                cout << second_names[i] << endl;
            }
        }

        // find which file has a bigger size 
        int max_counter;
        if(first_file_counter > second_file_counter) {
            max_counter = first_file_counter;
        } else {
            max_counter = second_file_counter;
        }


    } else
    {
        cout << "Failed to open attendance files" << endl;
    }
}
        // Fill in the blank below with code to read from file and store in the countries vector
//         string country;
//         while (!file.eof()) {
//             getline(file, country);
//             countries.push_back(country);
//         }
        

//         cout << "List of countries in the file are" << endl;    
//         for(int i = 0; i < int(countries.size()); i++)
//         {
//             cout << countries.at(i) << endl;
//         }
//     }
//     else
//     {
//         cout << "Failed to open file" << endl;
//     }
//     file.close();
// }

int main()
{
    string first_attendance_file = "attendance_sheet_1.txt"; 
    string second_attendance_file = "attendance_sheet_2.txt";
    compareAttendanceSheet(first_attendance_file, second_attendance_file);
}