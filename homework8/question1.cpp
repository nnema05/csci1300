
#include <iostream>
using namespace std;

int predictRevenue(int current_revenue, int years) {
    
    // base case, if years are 0, the predicted revenue is what is originally passed in  
    if(years == 0) {
        return current_revenue;
    } else {
        // if its not 0, get the new predicted revenue
        int predicted_revenue = 2 * current_revenue + 5;
            // then pass that into predictRevenue and decremet the year by 1
        return predictRevenue(predicted_revenue, years - 1);

    }

}

int main() {
    int result = predictRevenue(100, 3);
    cout << result;
    return 0;
}