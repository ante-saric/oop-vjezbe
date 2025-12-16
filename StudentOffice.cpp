#include "StudentOffice.h"
#include "UniversityConstants.h"

void StudentOffice::moveStudent(Student& s, std::string new_program) {
    s.study_program = std::move(new_program);
}

void StudentOffice::enroll_student(Student& s, const Course& c) {
    if (s.get_completed_ects() + c.get_ects() <=
        UniversityConstants::MAX_ETCS_PER_YEAR)
        s += c;
}

void StudentOffice::process_exam_results(Student& s, const Course& c) {
    Course* temp = new Course[s.completed_count + 1];

    for (size_t i = 0; i < s.completed_count; i++)
        temp[i] = s.completed_courses[i];

    temp[s.completed_count++] = c;

    delete[] s.completed_courses;
    s.completed_courses = temp;
}

void StudentOffice::update_student_years(Student* students, size_t count) {
    for (size_t i = 0; i < count; i++)
        ++students[i];
}
