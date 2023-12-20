
/*1a*/
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

// Define the struct for Person.
struct Person
{
    string name;
    int age;
    string occupation;
};

int main()
{
    // Create an instance of Person,
    Person person;

    // Assign values to person's attributes; see expected output below
    person.name = "Anna";
    person.age = 20;
    person.occupation = "Software Engineer";

    // Print out the person's information
    cout << "Name: " << person.name << endl;
    cout << "Age: " << person.age << endl;
    cout << "Occupation: " << person.occupation << endl;

    return 0;
}

/*1b*/
struct Person
{
    string name;
    int age;
    string occupation;
};

int main()
{
    // Create two instances of Person;
    Person person_one = {"Anna", 20, "Software Engineer"};
    Person person_two = {"Amy", 25, "Software Engineer"};

    // compares the two Person's occupation

    if(person_one.occupation == person_two.occupation)
    {
        cout << person_one.name << " and " << person_two.name << " have the same occupation: " << person_two.occupation << endl;
    }
}

/*1 FISH STRUCT*/
/* Psuedocode
Create struct called fish
Name its attributes
Create function that prints items in vectors
In main, create fish object
*/
struct Fish{
    string name;
    int gallons_required;
};

void displayFish(vector<Fish>fish_vector) {
    cout << fish_vector.name << endl;
}

int main() {
    vector<Fish> fish_vector;
    Fish minnow = {"Minnow", 1200};
    Fish.push_back(minnow);
    Fish fancy_guppy = {"Fancy Guppy", 1200};
    Fish.push_back(fancy_guppy);
    Fish blue_neon_guppy = {"Blue Neon Guppy", 1200};
    Fish.push_back(blue_neon_guppy);
    Fish elephant_ear_guppy = {"Elephant Ear Guppy", 1200};
    Fish.push_back(elephant_ear_guppy);
}

/*2 Aquarium class*/
/* PSUEDOCODE
Create class with definition
Create implementation
Write main to test!
*/

class Aquarium {
    public:
        Aquarium() {
            _aquarist_name = "";
            _gallons_used = 0;
        }
        Aquarium(string name) {
            _aquarist_name = name;
        }

        void setAquaristName(string name) {
             _aquarist_name = name;
        }
        string getAquaristName() {
            return _aquarist_name;
        }
        void setAquaristName(string name) {
             _aquarist_name = name;
        }
        double getGallonsUsed() {
            return _gallons_used;
        }
        bool loadFish(string file_name) {
            string line;
            if(getline(line, _fish)) {
                return true;
            } else {
                return false;
            }
        }

        bool removeFish(string name) {
            if(name == _fish) {
                _fish.push_back();
                return true;
            } else {
                return false;
            }
        }
    private:
        string _aquarist_name;
        int _gallons_used;
        vector<Fish> _fish;
};

int main() {
    ifstream file;
    file.open("fake_file.txt");
    //create an aquarium object
    Aquarium billys_aquarium("Billy");

    //test return value for a file that doesn't exit
    cout << billys_aquarium.loadFish("fake_file.txt") << endl;

    //test return value for a file that does exit
    cout << billys_aquarium.loadFish("fish_example.txt") << endl;

}