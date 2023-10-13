#include <iostream>
#include <cassert>
#include <string>

using namespace std;

int absoluetValue(int a) {
    if(a < 0) {
        return -a;
    }

}

int main(){
    int i;
    string s = "54321";
    for(i = 0; i< 6; i++){
        cout << s[i]<<endl;
    }
}