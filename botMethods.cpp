#include "includes/botMethods.h"
#include <iostream>
#include <fstream>

using namespace std;

Bot::Bot() {
    cout << "Enter first name: ";
    cin >> firstName;

    cout << "Enter last name: ";
    cin >> lastName;

    cout << "Enter birth year: ";
    cin >> birthYear;

    cout << "Enter birth month: ";
    cin >> birthMonth;

    cout << "Enter birth day: ";
    cin >> birthDay;
}

void Bot::setPerson() {
    cout << "Enter first name: ";
    cin >> firstName;

    cout << "Enter last name: ";
    cin >> lastName;

    cout << "Enter birth year: ";
    cin >> birthYear;

    cout << "Enter birth month: ";
    cin >> birthMonth;

    cout << "Enter birth day: ";
    cin >> birthDay;
}

void Bot::printPerson() {
    cout << "Enter first name: " << firstName << endl;

    cout << "Enter last name: " << lastName << endl;

    cout << "Enter birth year: " << birthYear << endl;

    cout << "Enter birth month: " << birthMonth << endl;

    cout << "Enter birth day: " << birthDay << endl;
}

void Bot::writeToFile(string fileName) {
    // Open file for reading
    ifstream inFile(fileName);
    
    // Check if file exists
    bool fileExists = inFile.good();
    
    if (fileExists) {
        // Read data from file
        readFromFile(fileName);

        printPerson();
        
        // Calculate age
        time_t now = time(0);
        tm* local_time = localtime(&now);
        int currentYear = local_time->tm_year + 1900;
        int age = currentYear - birthYear;
        
        // Check if it's the user's birthday
        bool isBirthday = (local_time->tm_mon + 1 == birthMonth) && (local_time->tm_mday == birthDay);
        
        // Greet user
        cout << "Welcome back, " << firstName << " " << lastName << "!" << endl;
        cout << "You are " << age << " years old." << endl;
        if (isBirthday) {
            cout << "Happy birthday!" << endl;
        }
    } else {
        // Open file for writing
        ofstream outFile(fileName);
        
        // Write data to file
        outFile << firstName << endl;
        outFile << lastName << endl;
        outFile << birthMonth << endl;
        outFile << birthDay << endl;
        outFile << birthYear << "\n" << endl;

        // Close file
        outFile.close();
        
        cout << "Personal details saved to " << fileName << " file." << endl;
    }
}

void Bot::readFromFile(string fileName) {
    ifstream file(fileName);

    file >> firstName;
    file >> lastName;
    file >> birthMonth;
    file >> birthDay;
    file >> birthYear;

    file.close();

    cout << "Personal details read from " << fileName << " file." << endl;
};