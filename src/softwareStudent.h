#pragma once
#include <string>
#include "student.h"
#ifndef SOFTWARESTUDENT_H
#define SOFTWARESTUDENT_H
using namespace std;

class SoftwareStudent : public Student {


public:
    SoftwareStudent();
    SoftwareStudent(
        string studentId,
        string firstName,
        string lastName,
        string email,
        int age,
        int numDaysInCourse[],
        Degree degreeType
    );
    Degree getDegreeType();
    void print();

    ~SoftwareStudent();
};

#endif /* SOFTWARESTUDENT_H */
