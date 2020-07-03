/*
 * Node.h
 *
 * Class Definition: Node of a linked list for pqueue
 */

#pragma once
#include <cstdio>

template <class ElementType>
class Node{
public:
    ElementType client;
    Node<ElementType> *next;

    //Default Constructor
    Node();
    
    //Parametrized Constructor 1
    Node(ElementType theClient);
    
    //Parametrized Constructor 2
    Node(ElementType theClient, Node<ElementType>* NextNode);
};
template<class ElementType>
Node<ElementType>::Node()
{
    next = NULL;
}

template<class ElementType>
Node<ElementType>::Node(ElementType theClient)
{
    client = theClient;
    next = NULL;
}

template<class ElementType>
Node<ElementType>::Node(ElementType theClient, Node<ElementType>* nextNode)
{
    client = theClient;
    next = nextNode;
}
