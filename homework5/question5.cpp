
#include <iostream> 
#include <cmath>

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
            cout << distance[i][j] << " ";
        }
        cout << endl;
    }
    
}



int main() {
    // const int CLUE_ROWS = 3;
    const int CLUE_ROWS = 3;
    const int CLUE_COLS = 2;
    const int REG_ROWS = 3;
    const int REG_COLS = 2;
    double clue[CLUE_ROWS][CLUE_COLS] = {{2, 10}, {8, 4}, {5, 8}};
    double region[REG_ROWS][REG_COLS] = {{2, 10}, {5, 8}, {1, 2}};
    // double clue[CLUE_ROWS][CLUE_COLS] = {{2, 10}, {8, 4}, {5, 8}};
    // double region[REG_ROWS][REG_COLS] = {{2, 10}, {5, 8}, {1, 2}};
    double distance[CLUE_ROWS][REG_ROWS];
    // double clue[CLUE_ROWS][CLUE_COLS] = {{0, 0}, {0, 0}, {1, -4.5}, {-3.3, -0.8}, {1, 1}, {1, 0}};
    // double region[REG_ROWS][REG_COLS] = {{1, -1}, {-1, 1}, {-1, -1}};
    calculateDistanceMatrix(distance, clue, region, CLUE_ROWS, CLUE_COLS, REG_ROWS, REG_COLS);

}