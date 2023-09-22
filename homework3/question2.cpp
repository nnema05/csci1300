
/*
QUESTION 2
You have a collection of books available for lending. 
Write a C++ program helps users find and choose books based on their preferred genre, authors, and titles.
*/

#include <iostream>

using namespace std;


int main () {

    // declare variables
    int genreSelect;
    int authorSelect;
    int titleSelect; 
    int bookingCon;

    // prompt the user & get their input
    cout << "Select the genre: (1) Mystery (2) Science " << endl;
    cin >> genreSelect;

    switch(genreSelect) {
        case 1: 
            cout << "Select the Author: (1) Agatha Christie (2) Arthur Conan Doyle (3) Stephen King " << endl;
            cin >> authorSelect;

            switch(authorSelect) {
                case 1: 
                    cout << "Select the Book Title: (1) Hercule Poirot (2) Miss Marple Detective " << endl;
                    cin >> titleSelect;

                    switch(titleSelect) {
                        case 1: 
                            cout << "You have ordered Hercule Poirot" << endl;
                            break;

                        case 2:
                            cout << "You have ordered Miss Marple Detective" << endl;
                            break;

                        default:
                            cout << "Please enter a valid input" << endl;
                            break;
                    }
                    break;

                case 2: 
                    cout << "Select the Book Title: (1) The Memoirs of Sherlock Holmes (2) Tales of Terror and Mystery " << endl;
                    cin >> titleSelect;

                    switch(titleSelect) {
                        case 1: 
                            cout << "You have ordered The Memoirs of Sherlock Holmes" << endl;
                            break;

                        case 2: 
                            cout << "You have ordered Tales of Terror and Mystery" << endl;
                            break;
                        
                        default:
                            cout << "Please enter a valid input" << endl;
                            break;
                    }
                    break;

                case 3: 
                    cout << "Select the Book Title: (1) The Institute (2) Misery " << endl;
                    cin >> titleSelect;

                    switch(titleSelect) {
                        case 1: 
                            cout << "You have ordered The Institute" << endl;
                            break;

                        case 2: 
                            cout << "You have ordered Misery" << endl;
                            break;

                        default:
                            cout << "Please enter a valid input" << endl;
                            break;
                    }
                    break;

                default:
                    cout << "Please enter a valid input" << endl;
                    break;

            }

            break;
            

        case 2:
            cout << "Select the Author: (1) Stephen Hawking (2) Carl Sagan (3) Mary Roach " << endl;
            cin >> authorSelect;

            switch(authorSelect) {
                case 1: 
                    cout << "Select the Book Title: (1) A Brief History of Time (2) The Universe in a Nutshell " << endl;
                    cin >> titleSelect;

                    switch(titleSelect) {
                        case 1: 
                            cout << "You have ordered A Brief History of Time" << endl;
                            break;

                        case 2: 
                            cout << "You have ordered The Universe in a Nutshell" << endl;
                            break;
                        
                        default:
                            cout << "Please enter a valid input" << endl;
                            break;
                    }
                    break;


                case 2: 
                    cout << "Select the Book Title: (1) Cosmos (2) Pale Blue Dot " << endl;
                    cin >> titleSelect;

                    switch(titleSelect) {
                        case 1: 
                            cout << "You have ordered Cosmos" << endl;
                            break;

                        case 2: 
                            cout << "You have ordered Pale Blue Dot" << endl;
                            break;

                        default:
                            cout << "Please enter a valid input" << endl;
                            break;
                    }
                    break;


                case 3: 
                    cout << "Select the Book Title: (1) Stiff: The Curious Lives of Human Cadavers (2) Gulp: Adventures on the Alimentary Canal " << endl;
                    cin >> titleSelect;

                    switch(titleSelect) {
                        case 1: 
                            cout << "You have ordered Stiff: The Curious Lives of Human Cadavers" << endl;
                            break;

                        case 2: 
                            cout << "You have ordered Gulp: Adventures on the Alimentary Canal" << endl;
                            break;
                        
                        default:
                            cout << "Please enter a valid input" << endl;
                            break;
                    }
                    break;

                    
                default:
                    cout << "Please enter a valid input" << endl;
                    

            
            }
            break;

        default:
            cout << "Please enter a valid input" << endl;
            break;


    }


    return 0;

    
}

