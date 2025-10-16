// James Zhu
// 11-19-2024
// Implementation of the SortedListClass, 
// that maintains elements in sorted order. 

#include <iostream>
#include "SortedListClass.h"

// Default Constructor
SortedListClass::SortedListClass() : head(NULL), tail(NULL) {}

// Copy constructor
SortedListClass::SortedListClass(const SortedListClass &rhs) : head(NULL), 
tail(NULL) {
    LinkedNodeClass *current = rhs.head;
    while (current != NULL) {
        insertValue(current->getValue());
        current = current->getNext();
    }
}

// Destructor
SortedListClass::~SortedListClass() {
    clear();
}

// Assignment operator
SortedListClass& SortedListClass::operator=(const SortedListClass &rhs) {
    if (this != &rhs) {
        clear();
        LinkedNodeClass *current = rhs.head;
        while (current != NULL) {
            insertValue(current->getValue());
            current = current->getNext();
        }
    }
    return *this;
}

// Clears the list completely
void SortedListClass::clear() {
    int temp;
    while (removeFront(temp));
}

void SortedListClass::insertValue(const int &valToInsert) {
    // Case 1: Empty list
    if (head == NULL) {
        LinkedNodeClass* insertNode = new LinkedNodeClass(NULL, valToInsert, 
        NULL);
        tail = head = insertNode;
    }
    else {
        LinkedNodeClass* current = head;

        // Traverse to find the correct insertion point
        while (current != NULL && current->getValue() <= valToInsert) {
            current = current->getNext();
        }

        // Case 2: Insert at the head
        if (current == head) {
            LinkedNodeClass* insertNode = new LinkedNodeClass(NULL, 
            valToInsert, head);
            insertNode->setBeforeAndAfterPointers();
            head = insertNode;
        }
        // Case 3: Insert at the tail
        else if (current == NULL) {
            LinkedNodeClass* insertNode = new LinkedNodeClass(tail, 
            valToInsert, NULL);
            insertNode->setBeforeAndAfterPointers();
            tail = insertNode;
        }
        // Case 4: Insert in the middle
        else {
            LinkedNodeClass* insertNode = 
            new LinkedNodeClass(current->getPrev(), valToInsert, current);
            insertNode->setBeforeAndAfterPointers();
        }
    }
}

// Prints the list from head to tail
void SortedListClass::printForward() const {
    LinkedNodeClass *current = head;
    std::cout << "Forward List Contents Follow:" << std::endl;
    while (current != NULL) {
        std::cout << "  " << current->getValue() << std::endl;
        current = current->getNext();
    }
    std::cout << "End Of List Contents" << std::endl;
}

// Prints the list from tail to head
void SortedListClass::printBackward() const {
    LinkedNodeClass *current = tail;
    std::cout << "Backward List Contents Follow:" << std::endl;
    while (current != NULL) {
        std::cout << "  " << current->getValue() << std::endl;
        current = current->getPrev();
    }
    std::cout << "End Of List Contents" << std::endl;
}

// Removes the front node and retrieves its value
bool SortedListClass::removeFront(int &theVal) {
    if (head == NULL) {
        return false;
    }
    LinkedNodeClass *temp = head;
    theVal = head->getValue();
    head = head->getNext();
    delete temp;

    if (head != NULL) {
        head->setPreviousPointerToNull();
    } else {
        tail = NULL; 
    }
    return true;
}


// Removes the last node and retrieves its value
bool SortedListClass::removeLast(int &theVal) {
    if (tail == NULL) {
        return false;
    }
    LinkedNodeClass *temp = tail;
    theVal = tail->getValue();
    tail = tail->getPrev();
    delete temp;

    if (tail != NULL) {
        tail->setNextPointerToNull();
    } else {
        head = NULL; 
    }
    return true;
}

// Gets the number of elements in the list
int SortedListClass::getNumElems() const {
    int count = 0;
    LinkedNodeClass *current = head;
    while (current != NULL) {
        count++;
        current = current->getNext();
    }
    return count;
}

// Retrieves the value at a specific index
bool SortedListClass::getElemAtIndex(const int index, int &outVal) const {
    if (index < 0) {
        return false;
    }
    int count = 0;
    LinkedNodeClass *current = head;
    while (current != NULL && count < index) {
        count++;
        current = current->getNext();
    }
    if (current == NULL) {
        return false;
    }
    outVal = current->getValue();
    return true;
}

