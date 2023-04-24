#ifndef BOTMETHODS_H
#define BOTMETHODS_H
#include <string>

using namespace std;

struct Bot {
    public:
        Bot();
        void setPerson();
        void printPerson();
        void writeToFile(string fileName);
        void readFromFile(string fileName);

    private:
        string firstName, lastName;
        int birthYear, birthMonth, birthDay;
};

#endif // BOTMETHODS_H