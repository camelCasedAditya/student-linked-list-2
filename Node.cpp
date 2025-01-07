#include <iostream>
#include <cstring>
#include "Node.h"
#include "Student.h"
using namespace std;

Node::Node(){
  value = new Student();
  next = NULL;
}

Node::~Node(){
  delete value;
  next = NULL;
}

void Node::setValue(Student* newvalue){
  value = newvalue;
}

Student* Node::getValue(){
  return value;
}

void Node::setNext(Node* newnext){
  next = newnext;
}

Node* Node::getNext(){
  return next;
}
