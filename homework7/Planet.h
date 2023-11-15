#ifndef PLANET_H
#define PLANET_H
#include <iostream>
using namespace std;

class Planet
{
    public:
        Planet();  // Default constructor
        Planet(string planet_name, double planet_radius); // Parameterized constructor  
        // setters
        void setName(string input_planet_name);
        void setRadius(double input_planet_radius);
        // getters
        string getName() const;
        double getRadius() const;
        double getVolume() const;

    private:
        string _planet_name;
        double _planet_radius;
};
#endif