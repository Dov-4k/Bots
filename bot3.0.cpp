#include "includes/learner.h"

using namespace std;

int main() {
    learning learn;
    learn.showMessage();

    string userInput;

    do {
        cout << "[You]: ";
        getline(cin, userInput);

        //for closing the chat
        if(userInput != "x" && userInput != "X") {
            //continue with the program
            if(learn.getResponse(userInput)) {
                //keep going
            } else if(userInput == "Bye" || userInput == "bye") {
                exit(0);
            } else {
                //need to learn the phrase and response
                learn.learner(userInput);
            }
        }
    } while(userInput != "x" || userInput != "X");

    return 0;
};