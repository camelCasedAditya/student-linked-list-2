/*
Aditya Chandrashekaran
1/9/2025
Program to store students in a linked list.
Allows the user to create and delete students. 
Also the user can print out the list or get an average of all students gpa
*/

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
  // Boolean to keep program running
  bool running = true;

  while (running == true) {
    // Gets user input on what command they want to do
    char input[100];
    cout << "Enter one of the following commands:" << endl;
    cout << "ADD (to add a student)" << endl; 
    cout << "DELETE (to delete a student)" << endl;
    cout << "PRINT (to print out all student in the list)" << endl;
    cout << "AVERAGE (to get the average of all students GPAs)" << endl;
    cout << "QUIT (to quit the program)" << endl << endl;
    cin >> input;
    cout << "" << endl;

    // User wants to add a student
    if (strcmp(input, "ADD") == 0) {

      // Create student object
      Student* newStudent = new Student();
      char addInput[100];

      // Get user input for student attributes
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
      newStudent->setGPA(floatInput);

      // Add the new student object to the linked list
      addR(newStudent, head, head);
    }
    // User wants to delete a student
    else if (strcmp(input, "DELETE") == 0) {
      // Get user input on id of the student they want to delete and calls the delete function
      int studentID = -1;
      cout << "Enter the id of the student who you want to delete: " << endl;
      cin >> studentID;
      deleteR(studentID, head, head, NULL);
    }
    // User calls the print command
    else if (strcmp(input, "PRINT") == 0) {
      // Calls the print function and passes in head of the linked list
      print(head);
    }
    // User calls average command
    else if (strcmp(input, "AVERAGE") == 0) {
      // Calls the average function and prints it out
      float average = averageGPA(head, 0.0, 0.0);
      cout << "Average GPA: " << average << endl;
    }
    // User wants to quit
    else if (strcmp(input, "QUIT") == 0) {
      // Sets the running variable to false, ending the program
      running = false;
    }
    cout << "" << endl;
  }

  return 0;
}

// Function to add a node to the linked list
void addR(Student* newStudent, Node*& head, Node* current) {
  // If the head is null we create a new node with the student and make that node the head.
  if (head == NULL) {
    head = new Node();
    head->setValue(newStudent);
    return;
  }
  // If the id of the student stored in head is greater than the id of the new student we make a new node with the new student as head.
  // Then the next node of head is the original head node.
  else if (head->getValue()->getStudentID() > newStudent->getStudentID()) {
    Node* temp = head;
    head = new Node();
    head->setValue(newStudent);
    head->setNext(temp);
    return;
  }
  // If the next node's value in the linked list is greater than the student id of the new student then a new node is added inserted between the next node and the current node
  else if (current->getNext() != NULL && current->getNext()->getValue()->getStudentID() > newStudent->getStudentID()) {
    Node* node = new Node();
    node->setValue(newStudent);
    node->setNext(current->getNext());
    current->setNext(node);
    return;
  }
  // If we get to the end of the linked list we add the new node with the new student to the end of the list
  else if (current->getNext() == NULL) {
    Node* node = new Node();
    node->setValue(newStudent);
    current->setNext(node);
    return;
  }
  // If none of the conditions are met we call function again with the next node
  else {
    addR(newStudent, head, current->getNext());
    return;
  }
}

// function to delete a node from the linked list based on inputted student id.
void deleteR(int studentID, Node*& head, Node* current, Node* previous) {
  // If the head is null we exit the function since there is nothing to delete
  if (head == NULL) {
    return;
  }
  // If the current node is null this means we have gotten to the end of the linked list without finding a node that has a student with the inputted id
  else if (current == NULL) {
    return;
  }
  // If the inputted id and student id match on a node we delete the node and connect the previous node to the next node
  else if (current->getValue()->getStudentID() == studentID) {
    previous->setNext(current->getNext());
    delete current;
    return;
  }
  // If no conditions are met the function is called with the next node
  deleteR(studentID, head, current->getNext(), current);
  return;
}

// function to print items in the linked list
void print(Node* next) {
  // Heading of the list
  if (next == head) {
    cout << "STUDENT LIST: " << endl;
  }
  // for every node in the linked list we print out all the attribute of the student stored in it
  if (next != NULL) {
    cout << next->getValue()->getFirstName() << ", " << next->getValue()->getLastName() << ", " << next->getValue()->getStudentID() << ", " << setprecision(2) << next->getValue()->getGPA() << endl;
    // calls the print function on the next node
    print(next->getNext());
  }
}

// Function to calculate the average gpa in the linked list
float averageGPA(Node* head, float total, float counter) {
  // If the head is null this means the list is empty so a average of 0 is returned
  if (head == NULL) {
    return 0;
  }
  // If we get to the end of the list we calculate the average with the running total and count
  else if (head->getNext() == NULL) {
    float average = (total+head->getValue()->getGPA())/(counter+1.0);
    return average;
  }
  // Else we update the running total and count and call the function again with the updated total and count
  else {
    counter = counter + 1;
    total = total + head->getValue()->getGPA();
    float output = averageGPA(head->getNext(), total, counter);
    return output;
  }
}
