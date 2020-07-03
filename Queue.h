/*
 * Queue.h
 *
 * Description: queue class. contains the clients nodes in array
 */

#pragma once
#include "Client.h"
#include "EmptyDataCollectionException.h"

using namespace std;

template <class ElementType>
class Queue{
private:
    Client clientArray[100];
    int elementCount;
    bool empty;
    int front;
    int back;
public:
	// Default Constructor
	Queue();
    // Description: Returns the number of elements in the Queue.
    // Time Efficiency: O(1)
    int getElementCount() const;
    
    // Description: Returns "true" is this Queue is empty, otherwise "false".
    // Time Efficiency: O(1)
    bool isEmpty() const;
    
    // Description: Adds newElement to the "back" of this Queue
    //              (not necessarily the "back" of its data structure) and
    //              returns "true" if successful, otherwise "false".
    // Time Efficiency: O(1)
    bool enqueue(const ElementType& newElement);
    
    // Description: Removes the element at the "front" of this Queue
    //              (not necessarily the "front" of its data structure) and
    //              returns "true" if successful, otherwise "false".
    // Precondition: This Queue is not empty.
    // Time Efficiency: O(1)
    bool dequeue();
    
    // Description: Returns (a copy of) the element located at the "front" of this Queue.
    // Precondition: This Queue is not empty.
    // Postcondition: This Queue is unchanged.
    // Exceptions: Throws EmptyDataCollectionException if this Queue is empty.
    // Time Efficiency: O(1)
    ElementType peek() const throw(EmptyDataCollectionException);
};

// Default Constructor
template <class ElementType>
Queue<ElementType>::Queue()
{
    elementCount=0;
    empty=true;
    front=0;
    back=-1;
}

// Description: Returns the number of elements in the Queue.
// Time Efficiency: O(1)
template <class ElementType>
int Queue<ElementType>::getElementCount() const
{
    return elementCount;
}

// Description: Returns "true" is this Queue is empty, otherwise "false".
// Time Efficiency: O(1)
template <class ElementType>
bool Queue<ElementType>::isEmpty() const
{
    return empty;
}
template <class ElementType>
bool Queue<ElementType>::enqueue(const ElementType& newElement)
{
    if (back >= 99)
    {
        return false;
    }
    back++;
    clientArray[back] = newElement;
    empty = false;
    elementCount++;
    return true;
}
template <class ElementType>
bool Queue<ElementType>::dequeue()
{
    if(empty)
    {
        return false;
    }
    front++;
    elementCount++;
    if(front > back)
    {
        empty = true;
        elementCount=0;
        front = 0;
        back = -1;
    }
    return true;
}
template <class ElementType>
ElementType Queue<ElementType>::peek() const throw(EmptyDataCollectionException)
{
    if(empty)
    {
        throw EmptyDataCollectionException("peek() called with empty queue.");
    }
    return clientArray[front];
}
