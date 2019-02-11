#ifndef NODE
#define NODE

#include <iostream>
#include <string.h>
#include "circularlyList.hpp"

template <typename E>
class Node
{
    friend class circluarlyList; 
    public:
        Node(E n);

    private:
        E data;
        Node* next;
};

template <typename E>
Node<E>::Node(E n)
{
   next = NULL;
   data = n; 
}

#endif
