#ifndef UNIVERSITYCONSTANTS_H
#define UNIVERSITYCONSTANTS_H

#include <iostream>

struct UniversityConstants {
    static const int MAX_ETCS_PER_YEAR = 60;
    static const int REQUIRED_ECTS_PER_YEAR = 45;

    static void print_university_rules() {
        std::cout << "Max ECTS/year: " << MAX_ETCS_PER_YEAR << "\n";
        std::cout << "Required ECTS/year: " << REQUIRED_ECTS_PER_YEAR << "\n";
    }
};

#endif
