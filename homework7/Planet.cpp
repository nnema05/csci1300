
#include "Planet.h"
#include <iostream>
#include <cmath>
using namespace std;

// implenting each function

Planet::Planet()
{
    _planet_name = " ";
    _planet_radius = 0.0;
}    

Planet::Planet(string planet_name, double planet_radius)
{
    _planet_name = planet_name;
    _planet_radius = planet_radius;
}

string Planet::getName() const 
{
    return _planet_name;
}

void Planet::setName(string planet_name)
{
    _planet_name = planet_name;
}

double Planet::getRadius() const
{
    return _planet_radius;
}

void Planet::setRadius(double planet_radius)
{
    _planet_radius = planet_radius;
}

double Planet::getVolume() const 
{
    const double pi = 3.14159265359;
    double volume = (1.333333333333333333333)*pi*(_planet_radius * _planet_radius * _planet_radius);

    return volume;
}
