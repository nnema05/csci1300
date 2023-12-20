
// Cosmic Element Conversion Program
#include <iostream>
using namespace std;

void elementCore() {
    cout << "Enter the number of Element Core particles: ";
    int element_core = 0;
    cin >> element_core;
    if(element_core < 0) {
        cout << "Invalid input. Please enter a non-negative integer." << endl;
        return;
    }

    int quantum_shard = element_core / 5760;
    if (quantum_shard > 50) {
        quantum_shard = 50;
    }
    element_core = element_core - (quantum_shard * 5760);  
    // cout << element_core;
    // cout << " quantum_shard " << quantum_shard << endl;

    int celestial_fragments = element_core / 180;
    if (celestial_fragments > 100) {
        celestial_fragments = 100;
    }
    element_core = element_core - (celestial_fragments * 180);  
    // cout << element_core;
    // cout << " celestial_fragments " << celestial_fragments << endl;

    int astral_essence = element_core / 10;
    if (astral_essence > 200) {
        astral_essence = 200;
    }
    element_core = element_core - (astral_essence * 10);  
    // cout << element_core;
    // cout << "astral_essence " << astral_essence << endl;

    int cosmic_dust = element_core / 2;
    if (cosmic_dust > 500) {
        cosmic_dust = 500;
    }
    element_core = element_core - (cosmic_dust * 2);  
    // cout << element_core;
    // cout << "cosmic_dust " << cosmic_dust << endl;

    // cout << " final elemenet core" << element_core << endl;
    cout << "Result:" << endl;
    cout << "Quantum Shards: " << quantum_shard << endl;
    cout << "Celestial Fragments: " << celestial_fragments << endl;
    cout << "Astral Essence: " << astral_essence << endl;
    cout << "Cosmic Dust: " << cosmic_dust << endl;
    cout << "Element Core: " << element_core << endl;
}

int main() {
    elementCore();

}