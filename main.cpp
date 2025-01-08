#include <iostream>
#include "Node.h"
#include "Student.h"
#include <iomanip>

using namespace std;

// Intialize functions
void add(Student* newStudent);
void addR(Student* newStudent, Node*& head, Node* current);
void print(Node* next);
void deleteNode(Student* student);
void deleteR(int studentID, Node*& head, Node* current, Node* previous);
float averageGPA(Node* head, float total, float count);

// Create start of linked list
Node* head = NULL;

int main() {
  // deleteR(123, head, head, NULL);
  // // Add each student to linked list and print out the linked list
  // Student* one = new Student();
  // int oneID = 123;
  // one->setStudentID(oneID);
  // char name[100] = "Aditya";
  // one->setFirstName(strdup(name));
  // strcpy(name, "Chandran");
  // one->setLastName(strdup(name));
  // one->setGPA(3.45);
  // addR(one, head, head);
  // print(head);

  // Student* two = new Student();
  // int twoID = 256;
  // two->setStudentID(twoID);
  // char name1[100] = "Aditya";
  // two->setFirstName(strdup(name1));
  // strcpy(name1, "Chandran");
  // two->setLastName(strdup(name1));
  // two->setGPA(4.2);
  // addR(two, head, head);
  // print(head);

  // Student* three = new Student();
  // int threeID = 130;
  // three->setStudentID(threeID);
  // char name2[100] = "Aditya";
  // three->setFirstName(strdup(name2));
  // strcpy(name2, "Chandran");
  // three->setLastName(strdup(name2));
  // three->setGPA(2.75);
  // addR(three, head, head);
  // print(head);
  // cout << "" << endl;
  // float average = averageGPA(head, 0.0, 0.0);
  // cout << "Average: " << average << endl;

  // // Delete one of the students from the linked list
  // deleteR(two->getStudentID(), head, head, NULL);
  // print(head);
  bool running = true;

  while (running == true) {
    char input[100];
    cout << "Enter one of the following commands:" << endl;
    cout << "ADD (to add a student)" << endl; 
    cout << "DELETE (to delete a student)" << endl;
    cout << "PRINT (to print out all student in the list)" << endl;
    cout << "AVERAGE (to get the average of all students GPAs)" << endl;
    cout << "QUIT (to quit the program)" << endl << endl;
    cin >> input;
    cout << "" << endl;
    if (strcmp(input, "ADD") == 0) {
      Student* newStudent = new Student();
      char addInput[100];

      cout << "Enter the first name: " << endl;
      cin >> addInput;
      newStudent->setFirstName(strdup(addInput));

      cout << "Enter the last name: " << endl;
      cin >> addInput;
      newStudent->setLastName(strdup(addInput));

      int intInput = 0;
      cout << "Enter the student ID" << endl;
      cin >> intInput;
      newStudent->setStudentID(intInput);

      float floatInput = 0.0;
      cout << "Enter the GPA" << endl;
      cin >> floatInput;
      cout << "INPUT: " << fixed << std::setprecision(2) << floatInput << endl;
      // cout << type(floatInput) << endl;
      newStudent->setGPA(floatInput);

      addR(newStudent, head, head);
    }
    else if (strcmp(input, "DELETE") == 0) {
      int studentID = -1;
      cout << "Enter the id of the student who you want to delete: " << endl;
      cin >> studentID;
      deleteR(studentID, head, head, NULL);
    }
    else if (strcmp(input, "PRINT") == 0) {
      print(head);
    }
    else if (strcmp(input, "AVERAGE") == 0) {
      float average = averageGPA(head, 0.0, 0.0);
      cout << "Average GPA: " << average << endl;
    }
    else if (strcmp(input, "QUIT") == 0) {
      running = false;
    }
    cout << "" << endl;
  }

  return 0;
}

void addR(Student* newStudent, Node*& head, Node* current) {
  if (head == NULL) {
    head = new Node();
    head->setValue(newStudent);
    return;
  }
  else if (head->getValue()->getStudentID() > newStudent->getStudentID()) {
    Node* temp = head;
    head = new Node();
    head->setValue(newStudent);
    head->setNext(temp);
    return;
  }
  else if (current->getNext() != NULL && current->getNext()->getValue()->getStudentID() > newStudent->getStudentID()) {
    Node* node = new Node();
    node->setValue(newStudent);
    node->setNext(current->getNext());
    current->setNext(node);
    return;
  }
  else if (current->getNext() == NULL) {
    Node* node = new Node();
    node->setValue(newStudent);
    current->setNext(node);
    return;
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
  else if (current == NULL) {
    return;
  }
  else if (current->getValue()->getStudentID() == studentID) {
    previous->setNext(current->getNext());
    delete current;
    return;
  }
  deleteR(studentID, head, current->getNext(), current);
  return;
}

// function to print items in the linked list
void print(Node* next) {
  if (next == head) {
    cout << "STUDENT LIST: " << endl;
  }
 if (next != NULL) {
    cout << next->getValue()->getFirstName() << ", " << next->getValue()->getLastName() << ", " << next->getValue()->getStudentID() << ", " << setprecision(2) << next->getValue()->getGPA() << endl;
    print(next->getNext());
  }
}

float averageGPA(Node* head, float total, float counter) {
  if (head == NULL) {
    return 0;
  }
  else if (head->getNext() == NULL) {
    float average = (total+head->getValue()->getGPA())/(counter+1.0);
    return average;
  }
  else {
    counter = counter + 1;
    total = total + head->getValue()->getGPA();
    float output = averageGPA(head->getNext(), total, counter);
    return output;
  }
}
