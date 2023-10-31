#include<iostream>
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

/*QUESTION 0 - A*/
int main() 
{
    // Fill the line below to make an input file stream from the file name given above.
    ifstream infile;
    infile.open("input.txt");
    string text;  
    while(getline(infile, text))
    {      
        cout << text << endl;
    }
    return 0;
}

/*QUESTION 0 - B*/
int main() 
{
    // Fill the line below to make an input file stream from the file input.txt.
    ifstream infile;
    infile.open("input.txt");
    // Fill the line below to make an output file stream to the file output.txt.
    ofstream outfile;
    outfile.open("output.txt");
    string text;  
    while(getline(infile, text))
    {
        // Fill the line below to write the text to the output file stream.
        outfile << text << endl;
    }
    return 0;
}

/*QUESTION 1*/
/*Psuedo code
-Input the file name
-Define ifstream varaible infile
-Open up the file vistors.txt 
-Define and initialize integer variable num to 0
-Define and initialize an array of integers count[5] as {1,1,1, 1, 1} (becasue every day will hv at least one visitor)
-Define and initialize an array of strings days[5] as {Monday, Tuesday, Wednesday, Thursday, Friday}
-Define a string line 
-while getline of infile store the value in line
    -for int i goes from 0 to size of line
        -if line[i] is equal to ','
            -add 1 to count[num]
    -add 1 to num
-Define a string most_visited_day and initialize to ""
-Define an integer variable most integers and assign 0 to it
-For int i goes from 0 to 5
    - if count[i] is greater than most visitors
        -assign days[i] to most viisted day 
        -assign count[i] to most visitors
-print most visited day is the busiest day of the week at the motel
*/

int main() {
    // open file
    ifstream infile;
    infile.open("visiors.txt");

    int num = 0;
    int count[5] = {1, 1, 1, 1, 1};
    string days[5] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
    string line;
    string most_visited_day = "";
    int most_visitors = 0;
    while(getline(infile, line)) { // read each line with getfile 
        for(int i = 0; i < line.length(); i++) { // for each character line length
            if(line[i] == ',') {
                count[num]++;
            }
        }
        num++;

        for(int i = 0; i < 5; i++) {
            if(count[i] > most_visitors) {
                most_visited_day = days[i];
                most_visitors = count[i];
            }
        }
        
    }

    cout << most_visited_day << endl;
}


/*QUESTION 2*/
/*
-Define ifstream varaible infile1
-Define ifstream variable infiile2
-Define ofstream variable outfile
-Ask user to input the input and output file namess
-use infile 1 to open the first input file 
-use infile2 to open the second input file
-if either fails
    - print could not open files
    return 0
-define strings line1 and line 2
define and initizle string vairbale final string with ""
-while getline of infile1 using line1
    add line1 to final string 
-while getline of infile 2 using line 2
    -add line 2 to final string 
-use outfit to open the output file 
-write final_string to the output file
-close all files

*/
int main() {
    // open file 
    ifstream infile1;
    ifstream infile2;
    string file1;
    string file2;
    cout << "Enter the input file 1 that you want to concatenate:";
    cin >> file1;
    cout << "Enter the input file 2 that you want to concatenate:";
    cin >> file2;
    infile1.open(file1);
    infile2.open(file2);
    ofstream output;
    output.open("output.txt");
    string line1;
    string line2;
    string finalString = "";

    if(infile1.is_open() && infile2.is_open()) {
        while(getline(infile1, line1)) {
            finalString += line1;
        }
        while(getline(infile2, line2)) {
            finalString += line2;
        }
        cout << "Files concatenated successfully";

    } else {
        cout << "Could not open file/files." << endl;
        return 0;
    }
}