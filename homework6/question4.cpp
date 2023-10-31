// Question 4
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

vector<string> teamsInTournament(string teamscores_file, int wins, int goals) {
    // initialize variables
    // vector for teams
    vector<string> teams;
    // line vairable
    string line;
    // vairbales from name, wins and goals from file
    string name_f;
    string wins_f;
    string goals_f;

    ifstream file;
    file.open(teamscores_file); // opens a file


    if(file.is_open()) {
        
        // while you get each line from 
        while (getline(file, line)) {

            // string stream to read in the name, wins and goal for each line
            stringstream ss(line);
            getline(ss, name_f, ',');
            getline(ss, wins_f, ',');
            getline(ss, goals_f);
            // cout << name_f << endl;
            // cout << wins_f << endl;
            // cout << goals_f << endl;

            if(stoi(wins_f) > wins) {
                // add to teams
                teams.push_back(name_f);
                // for(int i =0; i < teams.size(); i++) {
                //     cout << teams[i] << endl;
                // }
            
            // if wins are equal run tie breaker
                // teams qualify if their nunber of goals is >= the goals threshold
            } else if((stoi(wins_f) == wins) && (stoi(goals_f) >= goals)) {
                teams.push_back(name_f);
                // for(int i =0; i < teams.size(); i++) {
                //     cout << teams[i] << endl;
                // }
            }

        }
        // for(int i =0; i < teams.size(); i++) {
        //     cout << teams[i] << endl;
        // }

        // once all qualifying teams are added we have to print them to our user 
            // if vector teams is empty then no teams qualifiued
        if(teams.size() == 0) {
            cout << "No qualifying teams found" << endl;
        } else {
            cout << "Qualified teams are" << endl;
            int teamsLength = teams.size();
            for(int i =0; i < teamsLength; i++) {
                cout << teams[i] << endl;
            }
        }

    } else
    {
        cout << "Failed to open team scores file" << endl;
        cout << "No qualifying teams found" << endl;
    }
    
    return teams;
    
}

int main() {
    // get information from user
    cout << "Enter teamscores filename " << endl;
    string teamscores_file;
    cin >> teamscores_file;
    cout << "Enter number of wins required" << endl;
    int wins;
    cin >> wins;
    cout << "Enter number of goals scored for tie-breaker" << endl;
    int goals;
    cin >> goals;

    teamsInTournament(teamscores_file, wins, goals);
    return 0;
}