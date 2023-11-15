
#include "Planet.h"
#include <iostream>

using namespace std;

int maxRadius(Planet planet_array[], const int PLANET_ARRAY_SIZE) {

    // if array is empty return -1
    if(PLANET_ARRAY_SIZE == 0) {
        return -1;
    }

    // set original max radius
    double max_radius = planet_array[0].getRadius();
    int max_radius_index = 0;
    for(int i = 0; i < PLANET_ARRAY_SIZE; i++) {
        // if bigger radius is found, set it to max radius
        if(planet_array[i].getRadius() > max_radius) {
            max_radius = planet_array[i].getRadius();
            max_radius_index = i;
        }
    }

    return max_radius_index;
}

int main() {
    Planet planets[3];
    planets[0] = Planet("Nebraska",20);
    planets[1] = Planet("Delphi 6",10);
    planets[2] = Planet("p3",20);
    int idx = maxRadius(planets, 3);
    cout << planets[idx].getName() << endl;
    cout << planets[idx].getRadius() << endl;
    cout << planets[idx].getVolume() << endl;
}

// to run : g++ question3.cpp Planet.cpp -o question3