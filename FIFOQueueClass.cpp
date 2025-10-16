// James Zhu
// 11/19/2024
// This file contains the implementation of a First-In-First-Out queue,
// including methods for enqueue, dequeue, traversal and cleaning.

#include <iostream>
#include "FIFOQueueClass.h"
#include "LinkedNodeClass.h"

// Constructor
FIFOQueueClass::FIFOQueueClass() : head(NULL), tail(NULL) {}

// Destructor
FIFOQueueClass::~FIFOQueueClass() {
    clear();
}

// Enqueue a new item
void FIFOQueueClass::enqueue(const int &newItem) {
    // Create a new node to hold the value
    LinkedNodeClass* newNode = new LinkedNodeClass(tail, newItem, NULL);

    // If the queue is empty, set head to the new node
    if (head == NULL) {
        head = newNode;
    } 
    // link the new node to the current tail
    else {
        newNode->setBeforeAndAfterPointers();
    }
    // Update the tail to point to the new node
    tail = newNode;
}

// Dequeue and item
bool FIFOQueueClass::dequeue(int &outItem) {
    if (!head) {
        return false; 
    }
    outItem = head->getValue();
    LinkedNodeClass *temp = head;
    head = head->getNext();
    if (head) {
        head->setPreviousPointerToNull();
    } else {
        tail = NULL; 
    }
    delete temp;
    return true;
}

// Print the queue contents
void FIFOQueueClass::print() const {
    LinkedNodeClass *current = head;
    while (current) {
        std::cout << current->getValue() << " ";
        current = current->getNext();
    }
    std::cout << std::endl;
}

// Get the number of elements
int FIFOQueueClass::getNumElems() const {
    int count = 0;
    LinkedNodeClass *current = head;
    while (current) {
        count++;
        current = current->getNext();
    }
    return count;
}

// Clear the queue
void FIFOQueueClass::clear() {
    int temp;
    while (dequeue(temp));
}

