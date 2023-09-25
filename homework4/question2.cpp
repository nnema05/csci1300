
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

string composeMessage(string first_name, string last_name, char position);

int main()
{
    //Declare variables
    string first_name, last_name;
    char position;

    //Capture user input
    cout << "What is your first name?" << endl;
    cin >> first_name;
    cout << "What is your last name?" << endl;
    cin >> last_name;
    cout << "What is your position? Enter P for passenger, C for captain, E for engineer, and N for navigator:" << endl;
    cin >> position;

    //Validate input
    if (position != 'P' && position != 'C' && position != 'E' && position != 'N') {
        cout << "Invalid position!" << endl;
        return 0;
    }

    //Compose and display message
    string message = composeMessage(first_name, last_name, position);
    cout << message << endl;
    return 0;
}

string composeMessage(string first_name, string last_name, char position) {
    string rooms;
    if (position == 'P') {
        rooms = "The passenger rooms are thru the third door on the right";
    } else if (position == 'C') {
        rooms = "The captain's quarters are up the stairs on the left";
    } else if (position == 'E') {
        rooms = "The engine rooms are below deck down the second aft stairway";
    } else if (position == 'N') {
        rooms = "The cartography chamber is up the stairs on the bow";
        
    }
    string message = "Welcome Aboard " + first_name + " " + last_name + "! " + rooms;
    return message;

}