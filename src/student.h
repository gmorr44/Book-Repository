#pragma once
#include <string>
#include "degree.h"

using namespace std;

class Student {

public:
    const static int daysInCourse = 3;

    //Constructors
    Student(); // Empty constructor

    Student(string studentId, string firstName, string lastName,
        string email, int age, int numDaysInCourse[]);

    //Accessors-Setters
    void setStudentId(string studentId);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmail(string email);
    void setAge(int age);
    void setNumDaysInCourse(int numDaysInCourse[]);

    //Mutators-Getters
    string getStudentId();
    string getFirstName();
    string getLastName();
    string getEmail();
    int getAge();
    int* getNumDaysInCourse();
    virtual Degree getDegreeType() = 0;

    virtual void print() = 0;

protected:
    string studentId;
    string firstName;
    string lastName;
    string email;
    int age;
    int numDaysInCourse[daysInCourse];
    Degree degreeType;
public:

    //destructor
    ~Student();

};