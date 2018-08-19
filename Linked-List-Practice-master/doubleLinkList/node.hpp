#ifndef NODE_H_
#define NODE_H_

#include <iostream>
#include <string>
#include "doubleList.hpp"

class Node
{
    friend class LinkedList;

    private:
        std::string data;
        Node* next;
		Node* prev;

    public:
        Node(std::string n);
};

Node::Node(std::string n)
{
    data = n;
    next = NULL;
	prev = NULL;
}

#endif /* NODE_H_ */
