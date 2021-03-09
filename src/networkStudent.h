#include <iostream>
#include <string>
#include "student.h"
#ifndef NETWORKSTUDENT_H
#define NETWORKSTUDENT_H
using namespace std;


class NetworkStudent : public Student {

public:
    NetworkStudent();
    NetworkStudent(
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

    ~NetworkStudent();
};

#endif /* NETWORKSTUDENT_H */
