#include "includes/botMethods.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>

using namespace std;

Bot::Bot() {
    cout << "Enter first name: ";
    getline(cin, firstName);

    cout << "Enter last name: ";
    getline(cin, lastName);

    cout << "Enter birth month: ";
    cin >> birthMonth;

    cout << "Enter birth day: ";
    cin >> birthDay;

    cout << "Enter birth year: ";
    cin >> birthYear;
}

void Bot::setPerson() {
    cout << "Enter first name: ";
    getline(cin, firstName);

    cout << "Enter last name: ";
    getline(cin, lastName);

    cout << "Enter birth month: ";
    cin >> birthMonth;

    cout << "Enter birth day: ";
    cin >> birthDay;

    cout << "Enter birth year: ";
    cin >> birthYear;
}

void Bot::printPerson() {
    cout << "Enter first name: " << firstName << endl;

    cout << "Enter last name: " << lastName << endl;

    cout << "Enter birth month: " << birthMonth << endl;

    cout << "Enter birth day: " << birthDay << endl;

    cout << "Enter birth year: " << birthYear << endl;
}

void Bot::writeToFile(string fileName) {
    // Open file for reading
    ifstream inFile(fileName);
    
    // Check if file exists
    bool fileExists = inFile.good();
    
    if (fileExists) {
        string rewrite;
        cout << "\nThe file you gave already exists, would you like to overwrite it? (y/n)" << endl;
        cin >> rewrite;

        if(rewrite == "y") {
            ofstream overFile(fileName, ofstream::trunc);

            overFile << firstName << endl;
            overFile << lastName << endl;
            overFile << birthMonth << endl;
            overFile << birthDay << endl;
            overFile << birthYear << "\n" << endl;

            overFile.close();
        } else {
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
        
        cout << "\nPersonal details saved to " << fileName << " file." << endl;
    }
}

void Bot::readFromFile(string fileName) {
    ifstream file(fileName);

    getline(file, firstName);
    getline(file, lastName);
    file >> birthMonth;
    file >> birthDay;
    file >> birthYear;

    file.close();

    cout << "\nPersonal details read from " << fileName << " file." << endl;
};