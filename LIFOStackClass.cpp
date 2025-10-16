// James Zhu
// 11-19-2024
// Implementation of methods for a Last-In-First-Out 
// stack, including push, pop, traversal, and cleaning.

#include <iostream>
#include "LIFOStackClass.h"

// Constructor
LIFOStackClass::LIFOStackClass() : head(NULL) {}

// Destructor
LIFOStackClass::~LIFOStackClass() {
    clear();
}

// Push a new item onto the stack
void LIFOStackClass::push(const int &newItem) {
    LinkedNodeClass *newNode = new LinkedNodeClass(NULL, newItem, head);
    if (head) {
        head->setPreviousPointerToNull();
    }
    head = newNode;
}

// Pop an item from the stack
bool LIFOStackClass::pop(int &outItem) {
    if (!head) {
        return false; 
    }
    outItem = head->getValue();
    LinkedNodeClass *temp = head;
    head = head->getNext();
    if (head) {
        head->setPreviousPointerToNull();
    }
    delete temp;
    return true;
}

// Print the stack contents
void LIFOStackClass::print() const {
    LinkedNodeClass *current = head;
    while (current) {
        std::cout << current->getValue() << " ";
        current = current->getNext();
    }
    std::cout << std::endl;
}

// Get the number of elements
int LIFOStackClass::getNumElems() const {
    int count = 0;
    LinkedNodeClass *current = head;
    while (current) {
        count++;
        current = current->getNext();
    }
    return count;
}

// Clear the stack
void LIFOStackClass::clear() {
    int temp;
    while (pop(temp));
}

