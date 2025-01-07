#include "Student.h"
#include <iostream>
using namespace std;

// Constructor for student object
Student::Student() {
  studentID = 0;
}

// function to  set student id
void Student::setStudentID(int newStudentID) {
  studentID = newStudentID;
}

// function to get student id
int Student::getStudentID() {
  return studentID;
}
