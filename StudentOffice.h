#ifndef STUDENTOFFICE_H
#define STUDENTOFFICE_H

#include "Student.h"

class StudentOffice {
public:
    static void moveStudent(Student& s, std::string new_program);
    static void enroll_student(Student& s, const Course& c);
    static void process_exam_results(Student& s, const Course& c);
    static void update_student_years(Student* students, size_t count);
};

#endif
