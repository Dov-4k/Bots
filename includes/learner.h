#ifndef LEARNER_H
#define LEARNER_H

#include <iostream>
#include <fstream>
#include <string>
#include "stdint.h"
#include <sstream>
#include <typeinfo>
#include <algorithm>

struct learning {
    public:
        void learn(std::string userInput);
        int getResponse(std::string userInput);
        void showMessage();
};

#endif // LEARNER_H