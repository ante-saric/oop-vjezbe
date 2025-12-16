#include "Course.h"

Course::Course(std::string n, std::string c, int e)
    : name(n), code(c), ects(e) {
}

int Course::get_ects() const {
    return ects;
}

std::ostream& operator<<(std::ostream& os, const Course& c) {
    os << c.name << " (" << c.code << ") [" << c.ects << " ECTS]";
    return os;
}

std::istream& operator>>(std::istream& is, Course& c) {
    is >> c.name >> c.code >> c.ects;
    return is;
}
