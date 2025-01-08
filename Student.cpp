#include "Student.h"
#include <iostream>
#include <cstring>
using namespace std;

// Constructor for student object
Student::Student() {
  firstName = new char[100];
  lastName = new char[100];
  studentID = 0;
  GPA = 0.0;
}

void Student::setFirstName(char* newFirstName) {
  strcpy(firstName, newFirstName);
}
char* Student::getFirstName() {
  return firstName;
}
void Student::setLastName(char* newLastName) {
  strcpy(lastName, newLastName);
}
char* Student::getLastName() {
  return lastName;
}

// function to  set student id
void Student::setStudentID(int newStudentID) {
  studentID = newStudentID;
}

// function to get student id
int Student::getStudentID() {
  return studentID;
}

void Student::setGPA(float newGPA) {
  GPA = newGPA;
}
float Student::getGPA() {
  return GPA;
}
