
#include <iostream> 

using namespace std;

void mostPopularWord(string word[],const int WORD_SIZE) {
    // create variables
    string mostPopularWord;
    string currentWord;
    int popularFreq = 0;
    int freq = 0;
    
    // for every string in string words 
    for(int i = 0; i < WORD_SIZE; i++) {

        // current 
        currentWord = word[i];
        // cout << "current word " << currentWord << endl;


        for (int j = 0; j < WORD_SIZE; j++) {
            if(currentWord == word[j]) {
                freq++;
                // cout <<  "freq " << freq << endl;
            }
        }

        if(freq >= popularFreq) {
            popularFreq = freq;
            // cout <<  "popular frequency " <<popularFreq << endl;
            mostPopularWord = currentWord;
            // cout <<  "most popular word " << mostPopularWord << endl;
        }
        freq = 0;
        // cout <<  "freq at end " << freq << endl;
    }

    // PRINT 
    cout << "The most popular word : " << mostPopularWord << " " << endl;
    cout << "Frequency : " << popularFreq << " " << endl;
    // Print position 
    cout << "Found at pos : " << endl;
    // Go through every word in array words
        // if its equal to mostPopularWord
        // print that position i
    for(int i = 0; i < WORD_SIZE; i++) {
        if(word[i] == mostPopularWord) {
            cout << i  << " " << endl;
        }
    }
    
}

int main() {

    // const int WORDS_SIZE = 4;
    // string words[WORDS_SIZE] = {"mail", "text", "spam", "spam"};

    // const int WORDS_SIZE = 6;
    // string words[WORDS_SIZE] = {"apple", "apple", "foo", "bar", "apple", "code"};

    const int WORDS_SIZE = 8;
    string words[WORDS_SIZE] = {"fishes", "whales", "dogs", "sharks", "bats", "cats", "ducks", "buffs"};

    mostPopularWord(words, WORDS_SIZE);

}