
// This is a  Pokemon header file
// It will define the pokemon class
// save your file with a .h extension, this is the convention for header files
//.hpp is also used sometimes for c++ header files

// header guards 
// if there is no definition for Pokemon
#indef POKEMON_H
#define POKEMON_H

class Pokemon{
    public:
    // need a public get and set method for each private variable
    // get is a public interface to access the private vairaible
    // set is a public interface
    void setHP(double); // arguement to this method is what we use to set the private _HP variable
    void setAttack(int);
    void setSpeed(int);
    void setDefense(int);
    void setMax(int);
    void setName(string);

    // get method 
    double getHP() const; // const keyword lets us know that method is read only 
    int getAttack() const;
    int getSpeed() const;
    int getDefense() const;
    int getMax() const;
    string getName() const;
    private: 
        // Define all Pokemon statistics
        double _HP; 
        int _attack;
        int _speed;
        int _defense;
        int _max;
        string _name;
    public:
        // get is public interface to access the private variable
        // set is public interface to update the private vairbale
        void setHP(double); // arguement to this method is what we use to set the Private _HP vairable
        void setAttack(int);
        void setSpeed(int);
        void setDefense(int);
        void setMax(int);
        void setName(string);

        // get methds, are called accessors
        double getHP() const; // const keyword lets us know that method is read only 
        int getAttack() const;
        int getSpeed() const;
        int getDefense() const;
        int getMax() const;
        int getName() const;

};

#endif
