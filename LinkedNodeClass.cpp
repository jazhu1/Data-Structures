// James Zhu
// 11-19-2024
// This file contains the implementation of the LinkedNodeClass, 
// including functionality for accessing and modifying node pointers,
// and managing the relationships between nodes in a doubly-linked list.

#include<iostream>
#include "LinkedNodeClass.h"

LinkedNodeClass::LinkedNodeClass(LinkedNodeClass *inPrev, const int &inVal, 
LinkedNodeClass *inNext)
    : prevNode(inPrev), nodeVal(inVal), nextNode(inNext) {}

// Returns the value stored in this node
int LinkedNodeClass::getValue() const {
    return nodeVal;
}

LinkedNodeClass* LinkedNodeClass::getNext() const {
    return nextNode;
}

LinkedNodeClass* LinkedNodeClass::getPrev() const {
    return prevNode;
}

// Next node pointer to null
void LinkedNodeClass::setNextPointerToNull() {
    nextNode = NULL;
}

// Prvious node pointer to null
void LinkedNodeClass::setPreviousPointerToNull() {
    prevNode = NULL;
}

// Get correct nodes with correct pointer
void LinkedNodeClass::setBeforeAndAfterPointers() {
    if (prevNode) {
        prevNode->nextNode = this;
    }
    if (nextNode) {
        nextNode->prevNode = this;
    }
}
