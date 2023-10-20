#include <iostream> 
#include <cmath>
#include <iomanip>

using namespace std;

void calculateDistanceMatrix(double distance[][3], double clue[][2], double region[][2], const int CLUE_ROWS, const int CLUE_COLS, const int REG_ROWS, const int REG_COLS) {
    // double distance[CLUE_ROWS][REG_ROWS];
    double x1;
    double x2;
    double y1;
    double y2;
    for (int i = 0; i < CLUE_ROWS; i++) {
        x1 = clue[i][0];
        // cout << "x1 " << x1 << endl;
        y1 = clue[i][1];
        // cout << "y1 " << y1 << endl;

        for(int j = 0; j < REG_ROWS; j++) {
            x2 = region[j][0];
            // cout << "x2 " << x2 << endl;
            y2 = region[j][1];
            // cout << "y2 " << y2 << endl;

            distance[i][j] = sqrt((pow((abs(x2 - x1)), 2)) + (pow((abs(y2 - y1)), 2)));
            // cout << distance[i][j] << " ";
        }
        //cout << endl;
    }
    
}

// arrays are passed by reference so distance is changing
void findClueRegion(double distance[][3], int clue_regions[], const int DISTANCE_ROWS, const int DISTANCE_COLS) {
   
    double minimum;
    int club_reigon_index = 0;
    // go through rows in distance matrix
    for(int i = 0; i < DISTANCE_ROWS; i++) {
        // cout << "i " << i;
        minimum = distance[i][0];
        club_reigon_index = 0;
        // go through each value in row
        for (int j = 0; j < DISTANCE_COLS; j++) {
            // find minimum value
            // cout << "j " << j << endl;
            if(distance[i][j] < minimum) {
                minimum = distance[i][j];
                // cout << "minimum in row "<< i << " is " <<minimum << endl;

                club_reigon_index = j;
               
            }
            // cout << "minimum in row "<< i << " is " <<minimum << endl;
            // cout << "club_reigon_index " << club_reigon_index << endl;
        }

        if(club_reigon_index == 0) {
            // cout << "reigon 1" << endl;
            clue_regions[i] = 1;
            // cout << "clue_regions[i] " << clue_regions[i] << endl;
        } else if (club_reigon_index == 1) {
            // cout << "reigon 2"<< endl;;
            clue_regions[i] = 2;
            // cout << "clue_regions[i] " << clue_regions[i] << endl;
        } else if(club_reigon_index == 2) {
            // cout << "reigon 3" << endl;
            clue_regions[i] = 3;
            // cout << "clue_regions[i] " << clue_regions[i] << endl;
        }    

    }

    // for(int i = 0; i < DISTANCE_ROWS; i++) {
    //     cout << clue_regions[i] << endl;
    // }
}

void findTreasure(int clue_regions[], double region[][2], const int CLUE_REGIONS_SIZE, const int REG_ROWS, const int REG_COLS) {
    int counter1 = 0;
    int counter2 = 0;
    int counter3 = 0;
    int reigon_index = 0;
    int counter[3];

    // for(int i = 0; i < CLUE_REGIONS_SIZE; i++){
    //     cout << clue_regions[i] << endl;
    // }
    // First cycle through clue_reigons
        // see if the variable in clue_reigons is 1, 2 or 3
        // then counter is increaseing accordingly 
    for(int i = 0; i < CLUE_REGIONS_SIZE; i++) {
        // reset counters
        // counter1 = 0;
        // counter2 = 0;
        // counter3 = 0;
        if(clue_regions[i] == 1) {
            counter1++;
            //cout << "counter 1 " << counter1 << endl;
        }
        if(clue_regions[i] == 2) {
            counter2++;
            //out << "counter 2 " << counter2 << endl;
        }
        if(clue_regions[i] == 3) {
            counter3++;
            //cout << "counter 3 " << counter3 << endl;
        } 
    }
    counter[0] = counter1;
    counter[1] = counter2;
    counter[2] = counter3;
    
    // cout << "counter 3 " << counter[2] << endl;
    // Getting the counter with the minimum value
    int min = 1000;
    for(int i = 0; i < 3; i++){
        if(counter[i] < min){
            // cout << "counter[i] " << counter[i] << endl;
            min = counter[i];
            // cout << "min " << min << endl;
            // cout << "i " << i << endl;
            reigon_index = i + 1;
            // cout << reigon_index << endl;
        }
    }
    
    cout << "Region " << reigon_index << " had the least number of clues : " << min << endl;
    // cout << "counter 1 " << counter1 << endl;
    // cout << "counter 2 " << counter2 << endl;
    // cout << "counter 3 " << counter3 << endl;

    // if counter1 or counter2 or counter3 
    // if(counter1 < counter2 && counter1 < counter3) {
    //     reigon_index = 1;
    //     cout << "Region " << reigon_index << " had the least number of clues : " << counter1 << endl;
    // }
    // else if(counter2 < counter1 && counter2 < counter3) {
    //     reigon_index = 2;
    //     cout << "Region " << reigon_index << " had the least number of clues : " << counter2 << endl;
    // }
    // else if(counter3 < counter1 && counter3 < counter2) {
    //     reigon_index = 3;
    //     cout << "Region " << reigon_index << " had the least number of clues : " << counter3 << endl;
    // }


    // } else if (counter1 == counter2 || counter1 == counter3) {
    //     reigon_index = 1;
    //     cout << "Region " << reigon_index << " had the least number of clues : " << counter1 << endl;
    // } else if(counter2 == counter1 || counter2 == counter3) {
    //     reigon_index = 2;
    //     cout << "Region " << reigon_index << " had the least number of clues : " << counter2 << endl;
    // } else if(counter3 == counter1 || counter3 == counter2) {
    //     reigon_index = 3;
    //     cout << "Region " << reigon_index << " had the least number of clues : " << counter3 << endl;
    // }

    

    // print treasure
    double x = region[reigon_index - 1][0];
    // x = static_cast<double>(x);
    // cout << "x " << x << endl;
    double y = region[reigon_index -1][1];
    // cout << "y " << y << endl;

    cout << "Treasure must be buried in the coordinates ( " << fixed << setprecision(2) << x << ", " << fixed << setprecision(2) << y << " )" << endl;
        
}       


int main() {
    /*CALCULATE DISATNCE*/
    // const int CLUE_ROWS = 3;
   //  const int CLUE_ROWS = 5;
    const int CLUE_COLS = 2;
    const int REG_ROWS = 3;
    const int REG_COLS = 2;
    const int CLUE_ROWS = 6;
    double clue[CLUE_ROWS][CLUE_COLS] = {{1, 0}, {-2, 2.4}, {-5, -8}, {10, -2}, {0,0.5}, {0, 7}};
    double region[REG_ROWS][REG_COLS] = {{-0.5, 1.8}, {3.75, -1.14}, {0, 0}};
    // double clue[CLUE_ROWS][CLUE_COLS] = {{2, 10}, {8, 4}, {5, 8}};
    // double region[REG_ROWS][REG_COLS] = {{2, 10}, {5, 8}, {1, 2}};
    
    // double clue[CLUE_ROWS][CLUE_COLS] = {{0, 0}, {0, 0}, {1, -4.5}, {-3.3, -0.8}, {1, 1}, {1, 0}};
    // double region[REG_ROWS][REG_COLS] = {{1, -1}, {-1, 1}, {-1, -1}};
    double distance[CLUE_ROWS][REG_ROWS];
    calculateDistanceMatrix(distance, clue, region, CLUE_ROWS, CLUE_COLS, REG_ROWS, REG_COLS);

    /*FIND CLUE REIGON*/
    const int DISTANCE_ROWS = CLUE_ROWS;
    const int DISTANCE_COLS = REG_ROWS;
    int clue_regions[DISTANCE_ROWS];
    findClueRegion(distance, clue_regions, DISTANCE_ROWS, DISTANCE_COLS);

    /*FIND TREASURE*/
    const int CLUE_REGIONS_SIZE = DISTANCE_ROWS;
    findTreasure(clue_regions, region, CLUE_REGIONS_SIZE, REG_ROWS, REG_COLS);

}