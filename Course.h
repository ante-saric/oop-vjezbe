#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <iostream>

class Course {
private:
    std::string name;
    std::string code;
    int ects;

public:
    Course(std::string n = "", std::string c = "", int e = 5);

    int get_ects() const;

    friend std::ostream& operator<<(std::ostream& os, const Course& c);
    friend std::istream& operator>>(std::istream& is, Course& c);
};

#endif
