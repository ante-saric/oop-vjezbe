
#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>

class Course;

class Student {
private:
    int id;
    std::string name;
    std::string study_program;
    int year;

    Course* enrolled_courses;
    size_t enrolled_count;

    Course* completed_courses;
    size_t completed_count;

    static int total_students;

public:
    Student(int id = 0,
        const std::string& name = "",
        const std::string& program = "",
        int year = 1);

    Student(const Student& other);
    Student(Student&& other) noexcept;
    Student& operator=(const Student& other);
    Student& operator=(Student&& other) noexcept;
    ~Student();

    friend std::ostream& operator<<(std::ostream& os, const Student& s);
    friend std::istream& operator>>(std::istream& is, Student& s);

    Student& operator+=(const Course& c);
    Student& operator++();
    Student operator++(int);

    static int get_total_students();

    int get_completed_ects() const;

    friend class StudentOffice;
};

#endif
