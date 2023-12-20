
#include <iostream>
using namespace std;

int findLadderLength(int height_one, int height_two) {
    // base case 
        // if height one == height two , then both are the largest multiple
    if (height_one == height_two) {
        return height_one;
    }
    // if one of them is 0, return 0
    else if (height_one == 0 || height_two == 0)
    {
        return 0;
    } 
    else {
        // create a smaller height 
        int small_height;
        if(height_one > height_two) { // if height one is greater than height two 
            // then we need a smaller height that will replace height one
            small_height = height_one - height_two;
            return findLadderLength(small_height, height_two);
        } else if(height_two > height_one) {
            small_height = height_two - height_one;
            return findLadderLength(height_one, small_height);
        }
    
    }
    return 0;
    
}

int main() {
    int result = findLadderLength(30, 45);
    cout << result;
}