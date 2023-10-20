
#include <iostream> 
#include <iomanip>

using namespace std;

// The function should compute the mean/average of all the values in the array.
double temperatureMean(double new_temperature[], const int TEMP_SIZE) {
    // initialize sum and average
    double sum = 0.0;
    double average = 0.0;

    // for every value in new temperature array
    for(int i = 0; i < TEMP_SIZE; i++) {
        // add the index from the array to sum
        sum = sum + new_temperature[i];
    }

    // compute average
    average = sum/TEMP_SIZE;
    return average;
}

// The function should compute the difference between the maximum and minimum values found in the array.
double temperatureRange(double new_temperature[], const int TEMP_SIZE) {
    /* FIND MAX VALUE*/
    // initialize max vale 
    double max = new_temperature[0];
    for(int i = 0; i < TEMP_SIZE; i++) {
        // if value in array is greater than max, set that equal to max
        if(new_temperature[i] > max) {
            max = new_temperature[i];
        }
    }

    /*FIND MIN VALUE*/
    // initialize min value
    double min = new_temperature[0];
    for(int i = 0; i < TEMP_SIZE; i++) {
        // if value in array is less than min, set that equal to min
        if(new_temperature[i] < min) {
            min = new_temperature[i];
        }
    }
    // get a difference between max and min
    double difference = max - min; 
    return difference;

}

// The function should compute the difference between the last and current year's temperature readings and store the results in the delta array.
void temperatureDelta(double new_temperature[], double old_temperature[], double delta[], const int TEMP_SIZE) {
    for(int i = 0; i < TEMP_SIZE; i++) {
        delta[i] = old_temperature[i] - new_temperature[i];
    }
}

int main() {
    const int TEMP_SIZE = 3;
    double old_temperature[TEMP_SIZE] = {55.5, 77.7, 88.8};
    double new_temperature[TEMP_SIZE] = {50.5, 67.2, 78.4};
    double delta[TEMP_SIZE];

    double average = temperatureMean(new_temperature, TEMP_SIZE);
    cout << "Temperature Mean : " << fixed << setprecision(3) << average << endl;

    double difference = temperatureRange(new_temperature, TEMP_SIZE);
    cout << "Temperature Range : " << fixed << setprecision(3) << difference << endl;

    temperatureDelta(new_temperature, old_temperature, delta, TEMP_SIZE);
}