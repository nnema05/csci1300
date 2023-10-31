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
    int second_file_counter = 0;
    // make an array to store all names of first array that is largest size
    string first_names[100];
    // make an array to store all names of second array that is largest size
    string second_names[100];

    if(first_file.is_open() && second_file.is_open()) {

        // count number of lines in first file
        // while there is data in the string, add that data into first array from first file
            // first file counter is the incrementer to get to each position in first names
        while (!first_file.eof()) {
            getline(first_file, first_names[first_file_counter]);
            first_file_counter++;
            
        }
        // cout << first_file_counter << endl;
        // for(int i = 0; i < first_file_counter; i++) {
        //     cout << first_names[i] << endl;
        // }

        // count number of lines in second file
        // while there is data in the string, add that data into second array from second file
             // second file counter is the incrementer to get to each position in second names
        while (!second_file.eof()) {
            getline(second_file, second_names[second_file_counter]);
            second_file_counter++;
        }
        // cout << second_file_counter << endl;
        // for(int i = 0; i < second_file_counter; i++) {
        //     cout << second_names[i] << endl;
        // }


        // for loop through first name counter
            // and check if the name first name exists anywhere in second name
            // boolean that says if name found  
        bool nameFound = false; 
        // missing students array!
        string missingStudents[100];
        int missingStudentsCounter = 0;
        for(int i = 0; i < first_file_counter; i++) {
            // reset to false before next iteration
            nameFound = false;
            for (int j = 0; j < second_file_counter; j++) {
                if (first_names[i] == second_names[j]) {
                    nameFound = true;
                    break;
                    // cout << " name found" << endl;
                }
            }

            if (!nameFound) {
                
                missingStudents[missingStudentsCounter] = first_names[i];
                missingStudentsCounter++;

            }
        }

        // for(int k = 0; k < first_file_counter; k++) {
        //     cout << k << missingStudents[k] << endl;
        // }

        
        // if nameFound is still false, then every student has baorded the bus!
        if(missingStudentsCounter == 0) {
            cout << "Every student has boarded the bus. It's time to leave." << endl;
        } else {
            // print missing stduents array , only if thing in array is not blank 
            cout << "Students yet to board the bus are" << endl;
            for(int i = 0; i < missingStudentsCounter; i++) {
                    cout << missingStudents[i] << endl;
            }
        }

    } else
    {
        cout << "Failed to open attendance files" << endl;
    }
}


int main()
{
    string first_attendance_file = "attendance_sheet_1.txt"; 
    string second_attendance_file = "attendance_sheet_2.txt";
    compareAttendanceSheet(first_attendance_file, second_attendance_file);
}