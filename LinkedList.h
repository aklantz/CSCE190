#pragma once

#include "Node.h"
#include "Patient.h"
#include <iostream>


using namespace std; 


class LinkedList {
private:
    //Node* head;

public:

    Node* head;
    LinkedList(); 

    // Destructor 
    ~LinkedList(); 

    // insert a Patient into the linked list
    void insert(Patient pat);

    // retrieve the value from the list
    Patient get(Patient toFind) const; 


    // is the value in the list?
    bool contains(Patient toFind) const;


    void remove(Patient value);
   

    // display elements of the linked list
    int displayList() const; 
};




//======================implementation========================

/**
    Constructor that sets the head of the linked list equal to the null pointer
*/
LinkedList::LinkedList() {
    head = nullptr;
};


/**
    Destructor
*/
LinkedList::~LinkedList() {
    Node* current = head;
    while (current) {
        Node* next = current->getNext();
        delete current;
        current = next;
    }
};


/**
    Inserts a new Patient object into the Linked List.

    @param pat the Patient object to insert into the list.
*/
void LinkedList::insert(Patient pat) {
    Node* newNode = new Node(pat);
    newNode->setNext(head);
    head = newNode;
};


/**
    Retrieves a Patient object from the linked list.
    @param toFind the Patient object to get from the list.

    @return the found patient object or a null object if it doesn't exist.
*/
Patient LinkedList::get(Patient toFind) const {
    Node* current = head;
    while (current) {
        if (current->getValue() == toFind)
            return current->getValue();
        current = current->getNext();
    }
    Patient patNull;
    return patNull; // Return -1 if toFind not found -- this may need to be a different value for different hash tables
};


/**
    Returns true if the specified Patient object is in the list and false otherwise.

    @param toFind the Patient object to find in the list.
    @return true if the object is found and false otherwise
*/
bool LinkedList::contains(Patient toFind) const{
    Node* current = head;
    bool found = false;


    while (current) {
        if (current->getValue() == toFind)
            found = true;
        current = current->getNext();
    }
    return found;
};



/**
    Displays the list of nodes in the linked list. Each node will call the 
    << operator for the Patient object. Returns the number of objects above 1 in the list.

    @return if there is more than one node in the list, returns the number of nodes after the head (count - 1). Returns 0 if there 
    are 1 or 0 nodes in the list.
*/
int LinkedList::displayList() const {
    int counter = 0;
    if (head != nullptr){
        Node* current = head;

        while (current) {
            counter++;
            Patient pat = current->getValue();
            pat << pat;
            current = current->getNext();
        }
    }
    if (counter > 0)
        return counter - 1;     //no collision if only one node
    else
        return counter;     //return 0 if no nodes in list
  
};


/**
    Removes the specified Patient object from the list.

    @param value the Patient object to remove from the list.
*/
void LinkedList::remove(Patient value){
    if (head == nullptr)
        return;
    if (head->getValue() == value) {
        Node* temp = head;
        head = head->getNext();
        delete temp;
        return;
    }


    Node* prev = head;
    Node* current = head->getNext(); // the first valid node
    while (current != nullptr && current->getValue() != value) {
        
        cout << "on node containing: ";
        Patient pat = current->getValue();
        pat << pat;
        prev = current;
        current = current->getNext(); // go to next value
    }//end while


    if (current == nullptr) { // if we reached end of list or the list is empty
        cout << "Reached end of list in bucket[.\n";
    }
    else {
        cout << "Deleting: ";
        Patient pat = current->getValue();
        pat << pat;
        prev->setNext(current->getNext()); // unlink the node you remove
        delete current; // delete the node
    }
};



