#include <iostream>
#include <fstream>

using namespace std;

int main() {
    string firstName, lastName;
    int birthYear, birthMonth, birthDay;

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

    // Open a file to write personal details
    ofstream file("personal_details.txt");

    // Write personal details to file
    file << "First Name: " << firstName << endl;
    file << "Last Name: " << lastName << endl;
    file << "Birth Month: " << birthMonth << endl;
    file << "Birth Day: " << birthDay << endl;
    file << "Birth Year: " << birthYear << "\n" << endl;

    // Close file
    file.close();

    cout << "Personal details saved to personal_details.txt file." << endl;

    return 0;
}