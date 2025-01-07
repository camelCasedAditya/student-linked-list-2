#ifndef STUDENT_HEADER
#define STUDENT_HEADER
#include <iostream>

using namespace std;

class Student {
 public:
  // initalize functions for student class
  Student();
  void setStudentID(int newStudentID);
  int getStudentID();

 private:
  // Student id attribute for Student object
  int studentID;
};

#endif
