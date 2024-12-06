#pragma 
#include "Patient.h"


class Node {

private:
   // Patient value;
   // Node* next;
public:
    Patient value;
    Node* next;

    Node(Patient);
    Node* getNext();
    
    Patient getValue();
    void setNext(Node*);
};


/**
    Constructor that creates a node containing a Patient object
*/
Node::Node(Patient value) {
    this->value = value;
    next = nullptr;
};


/**
    Returns a pointer to the next node

    @return a pointer to the next node.
*/
Node* Node::getNext() {
    return next;
};


/**
    Returns the Patient object contained in the Node.

    @return the Patient object contained in the Node.
*/
Patient Node::getValue() {
    return value;
};


/**
    Sets the pointer to the next Node.

    @param the next node that this one should point to
*/
void Node::setNext(Node* n) {
    next = n;
};