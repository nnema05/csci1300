
#include <iostream>

using namespace std;

struct Dog {
    string name;
    int age;
    string favorite_toy;
};

int main() {
    // make struct for dog spot
    Dog dog1 = {"spot", 5, "tennis ball"};
    Dog dog2 = {"lassie", 3, "frisbee"};
    
    // print! 
    cout << "Name: " << dog1.name << ". Age: " << dog1.age << ". Favorite Toy: "<< dog1.favorite_toy << "." << endl;
    cout << "Name: " << dog2.name << ". Age: " << dog2.age << ". Favorite Toy: "<< dog2.favorite_toy << "." << endl;
}