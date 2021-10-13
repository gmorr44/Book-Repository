#include <iostream>
#include <string>
#include "student.h"
#include "roster.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"
#include "degree.h"

using namespace std;

Roster::Roster() {
    this->capacity = 0;
    this->lastIndex = -1;
    this->students = nullptr;
}
Roster::Roster(int capacity) {
    this->capacity = capacity;
    this->lastIndex = -1;
    this->students = new Student*[capacity];
}
Student* Roster::getStudentAt(int index) {
    return students[index];
}

void Roster::parseThenAdd(string row) {
    if (lastIndex < capacity) {
        lastIndex++;
        Degree degreeType;

        
        if (row.find("SECURITY") < 100) degreeType = SECURITY;
        else if (row.find("NETWORK") < 100) degreeType = NETWORK;
        else if (row.find("SOFTWARE") < 100) degreeType = SOFTWARE;
        else {
            cerr << " INVALID DEGREE TYPE!";
                exit(-1);
        }

       //Student Id
        int rhs = row.find(",");
        string sId = row.substr(0, rhs);

        //Student first name
        int lhs = rhs + 1;
        rhs = row.find(",", lhs);
        string sFirst = row.substr(lhs, rhs - lhs);

        //Student last name
        lhs = rhs + 1;
        rhs = row.find(",", lhs);
        string sLast = row.substr(lhs, rhs - lhs);

        //Student email
        lhs = rhs + 1;
        rhs = row.find(",", lhs);
        string sEmail = row.substr(lhs, rhs - lhs);

        // Student age
        lhs = rhs + 1;
        rhs = row.find(",", lhs);
        int sAge = stoi(row.substr(lhs, rhs - lhs));

        //Day #1
        lhs = rhs + 1;
        rhs = row.find(",", lhs);
        int sD1 = stoi(row.substr(lhs, rhs - lhs));

        //Day #2
        lhs = rhs + 1;
        rhs = row.find(",", lhs);
        int sD2 = stoi(row.substr(lhs, rhs - lhs));

        //Day #3
        lhs = rhs + 1;
        rhs = row.find(",", lhs);
        int sD3 = stoi(row.substr(lhs, rhs - lhs));

        add(sId, sFirst, sLast, sEmail, sAge, sD1, sD2, sD3, degreeType);
    }
    else {
        cerr << "ERROR! LIST HAS REACHED MAX CAPACITY!\n";
        exit(-1);
    }
}

void Roster::add(string sId, string sFirst, string sLast, string sEmail, int sAge, int sD1, int sD2, int sD3, Degree dt) {

    int studentDays[Student::daysInCourse];
    studentDays[0] = sD1;
    studentDays[1] = sD2;
    studentDays[2] = sD3;
    if (dt == SECURITY)students[lastIndex] = new SecurityStudent(sId, sFirst, sLast, sEmail, sAge, studentDays, dt);
    else if (dt == NETWORK)students[lastIndex] = new NetworkStudent(sId, sFirst, sLast, sEmail, sAge, studentDays, dt);
    else students[lastIndex] = new SoftwareStudent(sId, sFirst, sLast, sEmail, sAge, studentDays, dt);
}

void Roster::print_All() {
    for (int i = 0; i <= this->lastIndex; i++) (this->students)[i]->print();
}

bool Roster::remove(string studentId) {
    bool found = false;
    for (int i = 0; i <= lastIndex; i++) {
        if (this->students[i]->getStudentId() == studentId) {
            found = true;
            delete this->students[i];
            this->students[i] = this->students[lastIndex];
            lastIndex--;
        }
    }
    return found;
}

void Roster::printAverageDays(string studentId) {
    bool found = false;
    for (int i = 0; i <= lastIndex; i++) {
        if (this->students[i]->getStudentId() == studentId) {
            found = true;
            int* b = students[i]->getNumDaysInCourse();
            cout << "The average days in all courses for student " << studentId << " is: " << (b[0] + b[1] + b[2]) / 3 <<endl;
        }
    }
}

void Roster::printInvalidEmail() {
    cout << "Printing invalid email addresses: " << endl;
    bool bad = false;
    for (int i = 0; i <= lastIndex; i++) {
        
        
        string p = students[i]->getEmail();
        if (p.find(" ") < 100) {
            bad = true;
            cout << "ID: " << students[i]->getStudentId() << "  Invalid Email Is: ";
            cout << p << endl;
        }
        else if ((p.find("@") > 100)  || (p.find(".") > 100)) {
            bad = true;
            cout << "ID: " << students[i]->getStudentId() << "  Invalid Email Is: ";
            cout << p << endl;
        }
        
    }
    if (!bad) cout << "NONE!" << endl << endl;
}

void Roster::printByDegreeType(Degree d) {
    cout << endl << "Printing students by degree type: " << DegreeStrings[d] << endl;
    for (int i = 0; i <= lastIndex; i++) {
        if (this->students[i]->getDegreeType() == d) this->students[i]->print();
    }
}

Roster::~Roster(){
    for(int i = 0; i <= lastIndex; i++) {
       delete this->students[i];
    }
    delete students;
}

int main() {

    int numStudents = 5;
    //imported data from old application
    string studentData[5] =
    { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmail.com,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,Fred,Moore,something@emailaddress.com,39,25,35,41,SOFTWARE"
    };


    Roster* classRoster = new Roster(numStudents);
    cout << "Parsing data and adding students..." << endl;
    for (int i = 0; i < numStudents; i++) {
        classRoster->parseThenAdd(studentData[i]);
    }
    cout << "Done..." << endl << endl;
    cout << "Printing all students:" << endl;
    classRoster->print_All(); //Displays all students on the roster
    cout << endl;

    classRoster->printInvalidEmail();
    cout << endl;

    cout << "Printing the average days in a course for all students:" << endl;
    for (int i = 0; i < numStudents; i++) {
        classRoster->printAverageDays(classRoster->getStudentAt(i)->getStudentId());
    }

    classRoster->printByDegreeType(SOFTWARE); // This will print only the software students.

    cout << endl << "Removing A3:" << endl;
    if (classRoster->remove("A3")) {
        classRoster->print_All();
        numStudents--;
    }
    else cout << " Student not found!" << endl;

    cout << endl << "Removing A3:";
    if (classRoster->remove("A3")) classRoster->print_All();
    else cout << endl << "Student not found!" << endl << endl;

    classRoster->~Roster();

    system("pause");
    return 0;
    
}

