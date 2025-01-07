#ifndef NODE_H //beginning of header guard
#define NODE_H
#include <iostream>
#include <cstring>
#include "Student.h"
using namespace std;

class Node{
 public:
  Node();
  ~Node();
  void setValue(Student* newvalue);
  Student* getValue();
  void setNext(Node* newnext);
  Node* getNext();
 private:
  Student* value;
  Node* next;
};
#endif
