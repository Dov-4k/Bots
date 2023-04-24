#include <iostream>
#include <fstream>
#include "includes/botMethods.h"

using namespace std;

int main() {
    Bot bot;

    string fileName;
    cout << "\nWhat is the desired file name with extenstion: ";
    cin >> fileName;

    while(true) {
        cout << endl;
        bot.printPerson();
        string answer;
        cout << "Does the persons details look correct? (y/n)" << endl;
        cin >> answer;

        if(answer == "y") {
            bot.writeToFile("personalDetails.txt");
            break;
        } else if(answer == "n") {
            bot.setPerson();
            continue;
        }
    }

    return 0;
}