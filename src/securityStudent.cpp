#include <iostream>
#include<string>
#include "securityStudent.h"

using namespace std;

SecurityStudent::SecurityStudent()
    :Student() {
    degreeType = SECURITY;
}
SecurityStudent::SecurityStudent(string studentId, string firstName,
    string lastName, string email, int age, int numDaysInCourse[],
    Degree degreeType)
    : Student(studentId, firstName, lastName, email, age, numDaysInCourse) {

    degreeType = SECURITY;
}

Degree SecurityStudent::getDegreeType() {
    return SECURITY;
}

void SecurityStudent::print() {
    this->Student::print();
    cout << "SECURITY" << "\n";
}
SecurityStudent::~SecurityStudent() {
    Student::~Student();
}