/*
 * PriorityQueue.h
 *
 * Class Description: this class sorts clients
 */

#pragma once
#include <cstdio>
#include "EmptyDataCollectionException.h"
#include "Node.h"
#include "Client.h"

using namespace std;

template <class ElementType>
class PriorityQueue {
private:
    Node<ElementType>* head;
    int elementCount;
    bool empty;
    
public:
    
    //Default Constructor
    PriorityQueue();
    
    // Description: Returns the number of elements in the Priority Queue.
    // Time Efficiency: O(1)
    int getElementCount() const;
    
    // Description: Returns "true" is this Priority Queue is empty, otherwise "false".
    // Time Efficiency: O(1)
    bool isEmpty() const;
    
    // Description: Inserts newElement in sort order.
    //              It returns "true" if successful, otherwise "false".
    // Precondition: This Priority Queue is sorted.
    // Postcondition: Once newElement is inserted, this Priority Queue remains sorted.
    // Time Efficiency: O(n)
    bool enqueue(const ElementType& newElement);
    
    // Description: Removes the element with the "highest" priority.
    //              It returns "true" if successful, otherwise "false".
    // Precondition: This Priority Queue is not empty.
    // Time Efficiency: O(1)
    bool dequeue();
    // Description: Returns (a copy of) the element with the "highest" priority.
    // Precondition: This Priority Queue is not empty.
    // Postcondition: This Priority Queue is unchanged.
    // Exceptions: Throws EmptyDataCollectionException if this Priority Queue is empty.
    // Time Efficiency: O(1)
    ElementType peek() const throw(EmptyDataCollectionException);
    
}; // end PriorityQueue



//Default Constructor
template <class ElementType>
PriorityQueue<ElementType>::PriorityQueue()
{
    head=NULL;
    elementCount=0;
    empty=true;
}

// Description: Returns the number of elements in the Priority Queue.
// Time Efficiency: O(1)
template <class ElementType>
int PriorityQueue<ElementType>::getElementCount() const
{
    return elementCount;
}

// Description: Returns "true" is this Priority Queue is empty, otherwise "false".
// Time Efficiency: O(1)
template <class ElementType>
bool PriorityQueue<ElementType>::isEmpty() const
{
    return empty;
}

// Description: Inserts newElement in sort order.
//              It returns "true" if successful, otherwise "false".
// Precondition: This Priority Queue is sorted.
// Postcondition: Once newElement is inserted, this Priority Queue remains sorted.
// Time Efficiency: O(n)
template <class ElementType>
bool PriorityQueue<ElementType>::enqueue(const ElementType& newElement)
{
    
    Node<ElementType>* iteratorNode = head;
    
    if(head == NULL)
    {
        head = new Node<ElementType>(newElement);
        elementCount++;
        empty = false;
        return true;
    }
    
    Node<ElementType>* aNode;
    aNode = new Node<ElementType>(newElement);
    Node<ElementType>* nextNode;
    
    if(newElement.getTime() < head->client.getTime())
    {
        aNode->next = head;
        head = aNode;
        return true;
    }
    else if(newElement.getTime() == head->client.getTime() )
    {
        if (newElement.getType() == "A")
        {
            aNode->next = head->next;
            head->next = aNode;
            return true;
        }
    }
    
    nextNode = iteratorNode->next;
    
    while (iteratorNode != NULL)
    {
        if (iteratorNode->next == NULL)
        {
            aNode->next = iteratorNode->next;
            iteratorNode->next = aNode;
            break;
        }
        else if (newElement.getTime() < nextNode->client.getTime() )
        {
            aNode->next = iteratorNode->next;
            iteratorNode->next = aNode;
            break;
        }
        else if ((newElement.getTime() == nextNode->client.getTime() ) && (newElement.getType() == "A"))
        {
            aNode->next = iteratorNode->next;
            iteratorNode->next = aNode;
            break;
        }
        
        iteratorNode = iteratorNode->next;
        if (nextNode != NULL)
        {
            nextNode = nextNode->next;
        }
    }
    
    empty = false;
    elementCount++;
    return true;
    
}

// Description: Removes the element with the "highest" priority.
//              It returns "true" if successful, otherwise "false".
// Precondition: This Priority Queue is not empty.
// Time Efficiency: O(1)
template <class ElementType>
bool PriorityQueue<ElementType>::dequeue()
{
    if(empty)
    {
        return false;
    }
    
    Node<ElementType>* aNode;
    aNode = head;
    head = head->next;
    delete aNode;
    elementCount--;
    
    if(head == NULL)
    {
        elementCount=0;
        empty = true;
    }
    return true;
}

// Description: Returns (a copy of) the element with the "highest" priority.
// Precondition: This Priority Queue is not empty.
// Postcondition: This Priority Queue is unchanged.
// Exceptions: Throws EmptyDataCollectionException if this Priority Queue is empty.
// Time Efficiency: O(1)
template <class ElementType>
ElementType PriorityQueue<ElementType>::peek() const throw(EmptyDataCollectionException)
{
    if(empty)
    {
        throw EmptyDataCollectionException("peek() called with empty priority queue.");
    }
    return head->client;
}
