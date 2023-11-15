#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

struct Candy {
    string name; // Name of candy
    string description; // Description of candy
    double price; // Price of candy
    string candy_type; // Type of candy
};

// Function read candy
vector<Candy> readCandy(string file_name, vector<Candy> candies) {
    cout << setprecision(2) << fixed;
    ifstream file;
    file.open(file_name); // opens a file
    // will hold each candy line from file
    string candy_line;
    // create object from candy class
    Candy candy;
    string price;

    if(file.is_open())
    {
        // while you read from each line
        while (!file.eof()) {
            
            // get whole candy line
            getline(file, candy_line);
            // put the candy line in the string stream
            stringstream ss(candy_line);
            // read each part into the right part of the struct using get line
                // delimeter by '|'
            // read into candy name
            getline(ss, candy.name, '|');
            // If there is no name, move on to next iteration - for empty lines text
            if(candy.name == "") {
                continue;
            }
            // cout << candy.name << endl;
            // read into candy description
            getline(ss, candy.description, '|');
            // cout << candy.description << endl;
            // read into candy price
            getline(ss, price, '|');
            candy.price = stod(price); // make string price to double and set it equal to candy price 
            cout << candy.price << endl;
            // read into candy type
            getline(ss, candy.candy_type);
            // cout << candy.candy_type << endl;

            // push back candy into the vector
            candies.push_back(candy);
        }
        
        return candies;
    }
    else
    {
        // if could not open file, return original vector
        cout << "Failed to open file" << endl;
        return candies;
    }
    file.close();

}

int main() {
    string file_name;
    cout << "Enter file to read: " << endl;
    cin >> file_name;
    vector<Candy> candies;

    candies = readCandy(file_name, candies);
    for(int i = 0; i < candies.size(); i++) {
        cout << "Name: " << candies[i].name << ". Description: " <<  candies[i].description << ". Price: " << candies[i].price << ". Type: " << candies[i].candy_type << endl;
    }

}