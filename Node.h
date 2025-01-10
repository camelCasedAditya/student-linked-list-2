#ifndef NODE_H //beginning of header guard
#define NODE_H
#include <iostream>
#include <cstring>
#include "Student.h"
using namespace std;

class Node{
  // initalize the functions for the node class
 public:
  Node();
  ~Node();
  void setValue(Student* newvalue);
  Student* getValue();
  void setNext(Node* newnext);
  Node* getNext();
  
  // Node object attributes
 private:
  Student* value;
  Node* next;
};
#endif
