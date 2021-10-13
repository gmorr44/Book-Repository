#pragma once
#include <string>
#include "student.h"
#ifndef SECURITYSTUDENT_H
#define SECURITYSTUDENT_H
using namespace std;

class SecurityStudent : public Student {


public:
    SecurityStudent();
    SecurityStudent(
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

    ~SecurityStudent();
};

#endif /* SECURITYSTUDENT_H */