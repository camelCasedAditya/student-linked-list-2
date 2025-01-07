#include <iostream>
#include "Node.h"
#include "Student.h"

using namespace std;

// Intialize functions
void add(Student* newStudent);
void addR(Student* newStudent, Node*& head, Node* current);
void print(Node* next);
void deleteNode(Student* student);
void deleteR(int studentID, Node*& head, Node* current, Node* previous);

// Create start of linked list
Node* head = NULL;

int main() {
  // Add each student to linked list and print out the linked list
  Student* one = new Student();
  cout << "a" << endl;
  int oneID = 123;
  one->setStudentID(oneID);
  cout << "b" << endl;
  addR(one, head, head);
  cout << "c" << endl;
  print(head);
  cout << "1" << endl;

  Student* two = new Student();
  int twoID = 256;
  two->setStudentID(twoID);
  addR(two, head, head);
  print(head);
  cout << "2" << endl;

  Student* three = new Student();
  int threeID = 980;
  three->setStudentID(threeID);
  addR(three, head, head);
  print(head);
  cout << "3" << endl;

  // Delete one of the students from the linked list
  deleteR(two->getStudentID(), head, head, NULL);
  cout << "4" << endl;
  print(head);

  return 0;
}

// Function to add item to a linked list
void add(Student* newStudent) {
  Node* current = head;
  if (current == NULL) {
    head = new Node();
    head->setValue(newStudent);
  }
  else {
    while (current->getNext() != NULL) {
      current = current->getNext();
    }
    current->setNext(new Node());
    current->getNext()->setValue(newStudent);
  }
}

void addR(Student* newStudent, Node*& head, Node* current) {
  if (head == NULL) {
    head = new Node();
    head->setValue(newStudent);
  }
  else if (current->getNext() == NULL) {
    Node* node = new Node();
    node->setValue(newStudent);
    current->setNext(node);
  }
  else {
    addR(newStudent, head, current->getNext());
    return;
  }
}

void deleteR(int studentID, Node*& head, Node* current, Node* previous) {
  if (head == NULL) {
    return;
  }
  else if (current->getValue()->getStudentID() == studentID) {
    previous->setNext(current->getNext());
    cout << "Going to delete" << endl;
    delete current;
    cout << "deleted" << endl;
    return;
  }
  cout << current->getValue()->getStudentID() << endl;
  deleteR(studentID, head, current->getNext(), current);
  return;
}

// function to print items in the linked list
void print(Node* next) {
  if (next == head) {
    cout << "LIST: ";
  }
 if (next != NULL) {
    cout << next->getValue()->getStudentID() << " ";
    print(next->getNext());
  }
}

// function to delete a node in the linked list based on a student object
void deleteNode(Student* student) {
  Node* current = head->getNext();
  Node* previous = head;
  if (head->getValue() == student) {
    head = head->getNext();
    delete previous;
  }
  while (current != NULL) {
    if (current->getValue() == student) {
      previous->setNext(current->getNext());
      delete current;
      return;
    }
    previous = previous->getNext();
    current = current->getNext();
  }
}
