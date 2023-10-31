
// Question 3
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;
// FIARST FUNCTION
// Open keywork file
// when opening the keyword file, I need to put the string in the 2D [rows of the  array], 
// second colum is  the threshold value
// count number of keyword


int keywordThreshold(string keyword_file, string keyword_threshold[][2])
{
    // initialize variables
    ifstream keyword_open_file;
    keyword_open_file.open(keyword_file); // opens a file

    // need variables to count how many lines in each file
    int keyword_size = 0;

    if(keyword_open_file.is_open()) {

        while (!keyword_open_file.eof()) {
            getline(keyword_open_file, keyword_threshold[keyword_size][0], ' ');
            getline(keyword_open_file, keyword_threshold[keyword_size][1]);
            keyword_size++;
            
        }

    } else
    {
        cout << "Failed to open keyword file" << endl;
    }
    // cout << keyword_size<< endl;
    return keyword_size;
}

bool countFilter(string email_file, string keyword_threshold[][2], int keyword_count[], int keyword_size) {

    // initialize variables
    ifstream email_open_file;
    email_open_file.open(email_file); // opens a file

    // create email line and word
    string line;
    string word; 

    // initialize all values in keyword count as 0
    for(int i = 0; i < keyword_size; i++) {
        keyword_count[i] = 0;
        // cout << keyword_count[i];
    }
    

    if(email_open_file.is_open()) {

        while (!email_open_file.eof()) {
            getline(email_open_file, line);
            stringstream ssline(line);
            while(ssline >> word) {

                // check if word is equal on of the spam words (spam words are on keyword threshold)
                for(int i = 0; i < keyword_size; i++) {

                    if(keyword_threshold[i][0] == word) {

                        // increasing the count for each spam word in the array keyword_count
                        keyword_count[i]++;
                    }
                }
            }
        }
        
        // for(int i = 0; i < keyword_size; i++) {
        //     cout << keyword_count[i] << " " << endl;
        //     cout << keyword_threshold[i][0] << " ";
        //     cout << keyword_threshold[i][1] << endl;

        // }

    return true;
    } else
    {
        cout << "Failed to open email file" << endl;
        return false;
    }
    // cout << keyword_file_counter << endl;
}

bool checkSpam(int keyword_count[], string keyword_threshold[][2], int keyword_size) {
    // spam counter
    int spam_counter = 0;

    // for loop through keyword count
    for(int i = 0; i < keyword_size; i++) {
        if(keyword_count[i] >= stoi(keyword_threshold[i][1])) {
            spam_counter++;
        }
        
    }
    // if spam counter is equal to keyword size , return true
    if(spam_counter == keyword_size) {
        return true;
    } else {
        return false;
    }
}

int main() {
    string email_file = "email_not_spam.txt";
    string keyword_file = "keywords_1.txt";
    string keyword_threshold[10][2];
    int keyword_count[10] = {0,0,0,0,0,0,0,0,0,0};
    int keyword_size = 0;
    bool read_email_file, spam_email;
    keyword_size = keywordThreshold(keyword_file, keyword_threshold);
    if(!keyword_size) {
        return 0;
    }
    read_email_file = countFilter(email_file, keyword_threshold, keyword_count, keyword_size);
    if(!read_email_file) {
        return 0;
    }
    spam_email = checkSpam(keyword_count, keyword_threshold, keyword_size);
    if(spam_email) {
        cout << "It's a spam email!!" << endl;
    }
    else {
        cout << "It's not a spam email!!" << endl;
    }
}

