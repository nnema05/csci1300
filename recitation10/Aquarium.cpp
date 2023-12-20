
#include <iostream> 
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "Aquarium.h"

Aquarium::Aquarium() {
    _aquarist_name = "";
    _gallons_used = 0;
}

Aquarium::Aquarium(string aqurist_name) {
    _aquarist_name = aqurist_name;
    _gallons_used = 0;
}ma

void Aquarium::setAquariumName(string aquarist_name) {
    _aquarist_name = aquarist_name;
}
string Aquarium::getAquariumName() const {
    return _aquarist_name;
}

void Aquarium::setGallonsUsed(int gallons_used) {
    _gallons_used = gallons_used;
}

int Aquarium::getGallonUsed() const
{
    return _gallons_used;

}

void Aquarium::setGallonsUsed(int gallons_used) {
    _gallons_used = gallons_used;
}

int Aquarium::getTankSizeGallons() const;
{
    return _tank_size_gallons;

}
void Aquarium::setTankSizeGallons(int tank_size_gallons);
{
    tank_size_gallons =  _tank_size_gallons;

}

bool Aquarium::addFish(string fish_name) {
    for(int i = 0; i < _fish.size(); i++) {
        if(_fish.at(i).name == fish_name) {
            if(_tank_size_gallons < fish.at(i).gallons_required) {
                return 0;
            }
            _selected_fish.push_back(fish.name);
            return 1;
        }
    }
    return -1;
}

bool Aquarium::removeFish(string fish_name) {
    for(int i = 0; i < _fish.size(); i++) {
        if(_fish.at(i).name == fish_name) {
            if(_tank_size_gallons < fish.at(i).gallons_required) {
                return 0;
            }
            fish.name = fish.at(fish.size() - 1);
            _selected_fish.push_back(fish.name);
            return 1;
        }
    }
    return -1;
}


void Aquarium::displayFish() {
    int len = _fish.size();
    for(int i = len; i++) {
        cout << fish.at(i) << endl;
    }
}

bool Aquarium::loadFish(string filename)
{
    ifstream reader(filename);
    string line = "";
    if (reader.is_open())
    {
        while (getline(reader, line))
        {
            string fish_name, gal_req;
            stringstream ss(line);
            Fish current_fish;
            string word;
            int member = 0;

            // use stringstream to split the name and the gallons_required
            ss(ss, fish_name, ',');
            ss(ss, gal_req);
            current_fish.name = fish_name;
            int gal = stoi(gal_req);
            current_fish.gallons_required = gal;
            _available_fish.push_back(current_fish);
        }
        return true;
    }
    return false;
}

int findFishAmongAquariums(Aquarium aquariums[], int length, string fish_name) {
    for(int i = 0; i < length; i++) {
        if(aquariums[i].getAquariumName() == fish_name) {
            return i;
        }
    }
}

int findAquariumWithMostFish(Aquarium aquariums[], int length) {
    for(int i = 0; i < length; i++) {
        if(aquariums[i].getAquariumName() == fish_name) {
            return i;
        }
    }
}

