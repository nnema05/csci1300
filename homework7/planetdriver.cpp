#include "Planet.h"

#include <iostream>
using namespace std;

int main() {

    string name = "Flarbellon-7";
    double radius = 500;
    Planet p6 = Planet(name, radius);
    cout << "Planet Name: " << p6.getName() << endl;
    cout << "Planet Radius: " << p6.getRadius() << endl;
    cout << "Planet Volume: " << p6.getVolume() << endl;;

}