// Input and output data from a file
// FILE IO
// reading and writng to a file
// C++ uses streams 

#include <iostream> // cin, cout 
#include <fstream> // file stream, need this anytime we want to read and write files
#include <cctype>  // this is for isdigit
#include <sstream> // this is for stringstream
// we can treat a string like an input stream or a file stream
// for string processing! 

using namespace std;

int main() {
    // varaible name is fin, ifstream is the type of data
        // ifstream input file stream object 
        // reading in files
    ifstream fin;
    ofstream fout; // ofstream is creating an output variable fout which will hold an output file
    fin.open("testFile.txt"); // open the file, can only read the file
    fout.open("outputFile.txt");  // this will create the file if it doesn't alreayd exist
    // check if file opened correctly
    // fin.fail() if file doesn't exist, file is locked, file is not readable
    // fail is true if file couldnt be opened, for example, maybe it doesnt exist
    if (fin.fail()) { 
        cout << "file could not be opened";
        return -1; // error code, eturn -1 from to main to exit out of code when there is an error and things didn't go as expected
    }
    int value = 0;
    int sum = 0;
    // testFile.txt data was changed
    // name, integer 
    // first we want to skip
    // use get line
    // getline(cin, line) // reads from a stream and stores data as a string 
    string line;
    // find highest score 
    getline(fin, line);
    int max = 0; // initialize outside of loop
    while(getline(fin, line, ',')) { // we can use the last paramter of get line to control how much you are reading
        cout << line << endl;
        // fine the number and treat it as a number
        //int i = 0; // index into line
            /*
        while(!isdigit(line[i])) {
            i++;
        }
        // while will exit when we get to the number in line
        // substr(i) will get a string strating at i and go to the end
        // stori converts a string to an integer
        int number = stoi(line.substr(i)); // goes to ith position, gets the substr, and casts as int 
        if (number > max) {
            max = number;
        }
        cout << number << endl; // test that I can read the file, just print every line to the scrren
        */
    }
    // cout << "max value = " << max << endl;

    // CODE WHEN TEXT FILE WAS JUST NUMBERS
    /*while(fin >> value) { // here the while loop keeps going as long as there is data to read from the file
        // cin >> vlaue is same as fin>>value, but fin>>value is taking from file and putting it in value
            // both cin and fin read from a stream but they come from different sources!
        cout << value << endl;
        // sum all the numbers being read and write the sum to the output file
        sum = sum + value; 
    
    }*/

    // close the file!
    fin.close();
    fout << "last value = " << value << endl;
    fout << "sum = " << sum << endl;
    fout.close();

    string str = "this is string";
    stringstream s(str); // this creates a string stream from string str
    // count the number of words in the string 
    // default behavior or stringtream is to read up to space
    string word;
    int count = 0;
    while(s>> word) {
        cout << word << endl;
        count ++;
    }
    cout << "there are " << count << " words" << endl;
    // open the file
    // initialize count 
    // read each line 
    // for each line, count the number of words on the line, add to count 
    fin.open("words.txt");
    if (fin.fail()) {
        cout << "file didn't open";
        return -1; // error
    }

    count = 0; // this will be our word count

    while(getline(fin, line)) { // this reads the line in the file
        cout << line << endl; // test that the line looks like what we expect
        // loop over the words in the line
        // use string stream
        stringstream s(line); // make a stringstream out of the line
        
        if(s >> word) {
            count++;
        }

    }
    cout << "there were " << count << " words in the file " << endl;
    return 0;
}
