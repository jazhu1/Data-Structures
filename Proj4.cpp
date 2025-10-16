// James Zhu
// 11-19-2024
// Testing functionality for LinkedNodeClass, SortedListClass,
// FIFOQueueClass and LIFOStackClass.

#include <iostream>
#include "LinkedNodeClass.h"
#include "FIFOQueueClass.h"
#include "LIFOStackClass.h"
#include "SortedListClass.h"

using namespace std;

//Do NOT remove any of the preprocessor directives in this file.
//They should not affect your ability to write test code in your
//main function below, and they must be in your submitted main
//file exactly as provided to you with the project.
#ifdef ANDREW_TEST
#include "andrewTest.h"
#else

int main() {
    cout << "Starting tests for all data structures \n" << endl;

    // Testing LinkedNodeClass
    cout << "Testing LinkedNodeClass" << endl;
    {
        LinkedNodeClass *node1 = new LinkedNodeClass(NULL, 10, NULL);
        LinkedNodeClass *node2 = new LinkedNodeClass(node1, 20, NULL);
        node1->setBeforeAndAfterPointers();

        cout << "Node 1 value: " << node1->getValue() << endl;
        cout << "Node 2 value: " << node2->getValue() << endl;

        node1->setNextPointerToNull();
        node2->setPreviousPointerToNull();
        delete node1;
        delete node2;
    }
    cout << "LinkedNodeClass tests complete.\n" << endl;

    // Testing SortedListClass
    cout << "Testing SortedListClass" << endl;
    {
        SortedListClass list;

        list.insertValue(30);
        list.insertValue(10);
        list.insertValue(20);
        list.insertValue(20); // Duplicate test

        cout << "List printed forward:" << endl;
        list.printForward();

        cout << "List printed backward:" << endl;
        list.printBackward();

        int removedVal;
        list.removeFront(removedVal);
        cout << "Removed front: " << removedVal << endl;

        list.removeLast(removedVal);
        cout << "Removed last: " << removedVal << endl;

        cout << "Number of elements: " << list.getNumElems() << endl;

        int valueAtIndex;
        if (list.getElemAtIndex(0, valueAtIndex)) {
            cout << "Value at index 0: " << valueAtIndex << endl;
        } else {
            cout << "Invalid index access." << endl;
        }

        list.clear();
        cout << "List cleared. Number of elements: " << 
        list.getNumElems() << endl;
    }
    cout << "SortedListClass tests complete.\n" << endl;

    // Testing FIFOQueueClass
    cout << "Testing FIFOQueueClass" << endl;
    {
        FIFOQueueClass queue;

        queue.enqueue(1);
        queue.enqueue(2);
        queue.enqueue(3);

        cout << "Queue contents:" << endl;
        queue.print();

        int dequeuedValue;
        queue.dequeue(dequeuedValue);
        cout << "Dequeued value: " << dequeuedValue << endl;

        queue.dequeue(dequeuedValue);
        queue.dequeue(dequeuedValue);
        cout << "Dequeued last value: " << dequeuedValue << endl;

        if (!queue.dequeue(dequeuedValue)) {
            cout << "Attempt to dequeue from empty queue failed." << endl;
        }
    }
    cout << "FIFOQueueClass tests complete.\n" << endl;

    // Testing LIFOStackClass
    cout << "Testing LIFOStackClass" << endl;
    {
        LIFOStackClass stack;

        stack.push(1);
        stack.push(2);
        stack.push(3);

        cout << "Stack contents:" << endl;
        stack.print();

        int poppedValue;
        stack.pop(poppedValue);
        cout << "Popped value: " << poppedValue << endl;

        stack.pop(poppedValue);
        stack.pop(poppedValue);
        cout << "Popped last value: " << poppedValue << endl;

        if (!stack.pop(poppedValue)) {
            cout << "Attempt to pop from empty stack failed." << endl;
        }
    }
    cout << "LIFOStackClass tests complete.\n" << endl;

    cout << "All tests completed successfully!" << endl;
    return 0;
}

#endif