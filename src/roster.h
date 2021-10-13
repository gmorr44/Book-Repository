#pragma once
#include <string>
#include<iostream>
#include "student.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"
using namespace std;


class Roster {
private:
    int lastIndex;
    int capacity;
    Student** students;
public:
    Roster();
    Roster(int capacity);

    Student* getStudentAt(int index);
    void parseThenAdd(string datarow);
    void add(string sId, string sFirst, string sLast, string sEmail, int sAge,
        int sD1, int sD2, int sD3, Degree sDt);
    void print_All();
    bool remove(string studentId);
    void printAverageDays(string studentId);
    void printInvalidEmail();
    void printByDegreeType(Degree d);

    ~Roster();

};
