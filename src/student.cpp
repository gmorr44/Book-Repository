#include <iostream>
#include <iomanip>
#include <string>
#include "student.h"
using namespace std;

Student::Student() {
    this->studentId = "";
    this->firstName = "";
    this->lastName = "";
    this->email = "";
    this->age = 0;
    for (int i = 0; i < daysInCourse; i++) this->numDaysInCourse[i] = 0;
}
Student::Student(string studentId, string firstName, string lastName,
    string email, int age, int numDaysInCourse[]) {
    this->studentId = studentId;
    this->firstName = firstName;
    this->lastName = lastName;
    this->email = email;
    this->age = age;
    for (int i = 0; i < daysInCourse; i++) {
        this->numDaysInCourse[i] = numDaysInCourse[i];
    }
}
//Accessors-Setters
void Student::setStudentId(string studentId) {
    this->studentId = studentId;
}
void Student::setFirstName(string firstName) {
    this->firstName = firstName;
}
void Student::setLastName(string lastName) {
    this->lastName = lastName;
}
void Student::setEmail(string email) {
    this->email = email;
}
void Student::setAge(int age) {
    this->age = age;
}
void Student::setNumDaysInCourse(int numDaysInCourse[]) {
    for (int i = 0; i < daysInCourse; i++) {
        this->numDaysInCourse[i] = numDaysInCourse[i];
    }
}
//Mutators-Getters
string Student::getStudentId() {
    return studentId;
}
string Student::getFirstName() {
    return firstName;
}
string Student::getLastName() {
    return lastName;
}
string Student::getEmail() {
    return email;
}
int Student::getAge() {
    return age;
}
int* Student::getNumDaysInCourse() {
    return numDaysInCourse;
}

// This will display-print all fields except degree 
void Student::print() {
    cout << "ID: " << left << setw(4) << getStudentId();
    cout << "First Name: " << left << setw(7) << getFirstName();
    cout << "Last Name: " << left << setw(10) << getLastName();
    cout << "Email: " << left << setw(24) << getEmail();
    cout << "Age: " << left << setw(4) << getAge();
    cout << "Days In Course:"<< " {" << *getNumDaysInCourse();
    cout << "," << *(getNumDaysInCourse() + 1);
    cout << "," << *(getNumDaysInCourse() + 2) << "}  ";
}
Student::~Student() {

}