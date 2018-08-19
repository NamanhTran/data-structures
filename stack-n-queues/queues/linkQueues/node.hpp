#ifndef NODE_H_
#define NODE_H_

#include <iostream>
#include <string>
#include "singleList.hpp"

template <typename E>
class Node
{
    friend class LinkedList;

    private:
        E data;
        Node<E>* next;

    public:
        Node(E n);
};

template <typename E>
Node<E>::Node(E n)
{
    data = n;
    next = NULL;
}

#endif /* NODE_H_ */
