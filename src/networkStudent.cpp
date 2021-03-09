#include <iostream>
#include<string>
#include "networkStudent.h"

using namespace std;

NetworkStudent::NetworkStudent()
    :Student() {
    degreeType = NETWORK;
}
NetworkStudent::NetworkStudent(string studentId, string firstName,
    string lastName, string email, int age, int numDaysInCourse[],
    Degree degreeType)
    : Student(studentId, firstName, lastName, email, age, numDaysInCourse) {

    degreeType = NETWORK;
}

Degree NetworkStudent::getDegreeType() {
    return NETWORK;
}

void NetworkStudent::print() {
    this->Student::print();
    cout << "NETWORK" << "\n";
}
NetworkStudent::~NetworkStudent() {
    Student::~Student();
}