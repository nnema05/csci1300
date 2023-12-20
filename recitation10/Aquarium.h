

#ifndef AQUARIUM_H
#define AQUARIUM_H
#include <iostream> 
#include <string>
#include <vector>
using namespace std;
struct Fish{
    string name;
    int gallons_required;
};


class Aquarium {
    // data memebr
    private:
        string _aquarist_name;
        int _gallons_used;
        vector<Fish> _fish;  
        int _tank_size_gallons;
        vector<Fish> _available_fish;
        vector<Fish> _selected_fish;
    public :
        Aquarium();
        Aquarium(string);

        string getAquariumName() const;
        int getGallonUsed() const;  
        bool loadFish(string);
        bool removeFish(string);
        void setAquariumName(string);
        void setGallonsUsed(int);
        void displayFish();
        int getTankSizeGallons() const;
        void setTankSizeGallons(int);
        bool addFish(string);
        bool removeFish(string);
        int findFishAmongAquariums(Aquarium aquariums[], int length, string fish_name);
        int findAquariumWithMostFish(Aquarium aquariums[], int length);
        vector<Fish> getTankSizeGallons();
        vector<Fish> getSelectedFish() const;

};
#endif