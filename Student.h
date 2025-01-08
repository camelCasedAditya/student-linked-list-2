#ifndef STUDENT_HEADER
#define STUDENT_HEADER
#include <iostream>
#include <cstring>

using namespace std;

class Student {
 public:
  // initalize functions for student class
  Student();
  char* getFirstName();
  char* getLastName();
  void setFirstName(char* newFirstName);
  void setLastName(char* newLastName);
  void setStudentID(int newStudentID);
  int getStudentID();
  float getGPA();
  void setGPA(float newGPA);

 private:
  // Student id attribute for Student object
  char* firstName;
  char* lastName;
  int studentID;
  float GPA;

};

#endif
