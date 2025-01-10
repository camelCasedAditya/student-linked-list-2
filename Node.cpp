#include <iostream>
#include <cstring>
#include "Node.h"
#include "Student.h"
using namespace std;

// Node object constructor
Node::Node(){
  value = new Student();
  next = NULL;
}

// Node object destructor
Node::~Node(){
  delete value;
  next = NULL;
}

// function to set the value of a node
void Node::setValue(Student* newvalue){
  value = newvalue;
}

// Function to get the value of a node
Student* Node::getValue(){
  return value;
}

// Function to set the next node
void Node::setNext(Node* newnext){
  next = newnext;
}

// function to get the next node
Node* Node::getNext(){
  return next;
}
