#include "includes/learner.h"

using namespace std;

void learning::learn(string userInput) {
    string storePhrase = userInput;
    string learningResponse;

    //the phrase was not found in the brain and the proper response will be saved
    cout << "Not found! Tell me what to enter for \"" << storePhrase << "\": ";
    getline(cin, learningResponse);

    if(learningResponse == "ignore") {
        cout << "The input was ignored" << endl;
    } else {
        cout << learningResponse << endl;

        //open the brain file to write the learning response
        ofstream writeBrain;

        writeBrain.open("brain/brain.txt", ios::out | ios::app);

        if(writeBrain.is_open()) {
            writeBrain << endl << storePhrase << "|" << learningResponse;
        } else {
            cout << "Error: Couldn't open brain file" << endl;
        }

        writeBrain.close();
    }

    return;
}

int learning::getResponse(string userInput) {
    ifstream brain("brain/brain.txt");

    string phrase;
    string response;

    //quit if the user types Quit
    if(userInput == "Quit") {
        exit(0);
    } else if (userInput == "bye" || userInput == "Bye") {
        cout << "[Bot]: Bye" << endl;
        exit(0);
    } else if(userInput == "") {

    } else {
        while(getline(brain, phrase, '|')) {
            getline(brain, response);
            
            //bot response if existing phrase
            if(userInput == phrase) {
                cout << "[Bot]: " << response << endl;
                brain.close();
                return 1;
            }
        }
    }

    //we couldn't find the phrase, so we'll need to go to the other function
    brain.close();
    return 0;
}

void learning::showMessage() {
    cout << "*** Hi, I am Bot 3.0, how can I help you? ***" << endl;
}