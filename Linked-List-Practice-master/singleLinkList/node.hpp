#ifndef NODE_H_
#define NODE_H_

#include <iostream>
#include <string>
#include "singleList.hpp"

class Node
{
    friend class LinkedList;

    private:
        std::string data;
        Node* next;

    public:
        Node(std::string n);
};

Node::Node(std::string n)
{
    data = n;
    next = NULL;
}

#endif /* NODE_H_ */