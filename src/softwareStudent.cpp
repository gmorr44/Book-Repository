#include <iostream>
#include<string>
#include "softwareStudent.h"

using namespace std;

SoftwareStudent::SoftwareStudent()
    :Student() {
    degreeType = SOFTWARE;
}
SoftwareStudent::SoftwareStudent(string studentId, string firstName,
    string lastName, string email, int age, int numDaysInCourse[],
    Degree degreeType)
    : Student(studentId, firstName, lastName, email, age, numDaysInCourse) {

    degreeType = SOFTWARE;
}

Degree SoftwareStudent::getDegreeType() {
    return SOFTWARE;
}

void SoftwareStudent::print() {
    this->Student::print();
    cout << "SOFTWARE" << "\n";
}
SoftwareStudent::~SoftwareStudent() {
    Student::~Student();
}

