#ifndef SINGLELIST_H_
#define SINGLELIST_H_

#include "node.hpp"

class LinkedList
{
    private:
        Node* head;
       	int size;

    public:
    	LinkedList();

    	// operation for list
        ~LinkedList();
        void addToList(const std::string n);
        void deleteFront();
    	bool find(const std::string n);
    	void display();
        void addAfter(Node* v, const std::string n);
};

LinkedList::LinkedList()
{
	// creates the list
    head = NULL;
    size = 0;
}

void LinkedList::addToList(const std::string n)
{
    Node* newList = new Node(n);

	// if no node exists in the list
    if(head == NULL)
    {
        head = newList;
    }

	// if node exists in the list already
    else
    {
        newList->next = head;
	    head->prev = newList;
        head = newList;
    }

	// increment the list size
    size++;
}

void LinkedList::addAfter(Node* v, const std::string n)
{
    // create a new node
    Node* newNode = new Node(n);

    // create temp that is the node after the new node
    Node* temp = v->next;

    // set the new node next to temp
    newNode->next = temp;

    // set the new node prev to node passed through argument
    newNode->prev = v;

    // set node given's next to the new node
    v->next = newNode;

    // set the node after the new node's prev to the new node
    temp->prev = newNode;

    // increase the size of the list
    size++;
}
void LinkedList::display()
{
	Node* temp = head;

	std::cout << "Data in the Double Linked-List:\n";

	// displays data in the list
	while(temp != NULL)
	{
		std::cout << temp->data << "\n";
		temp = temp->next;
	}
}

bool LinkedList::find(const std::string n)
{
	Node* temp = head;

	// find if data exists in the list
	while(temp != NULL)
	{
		// if data exist
		if(temp->data == n)
		{
			return true;
		}

		else
		{
			temp = temp->next;
		}
	}

	// if data does not exist
	return false;
}

void LinkedList::deleteFront()
{
	// deletes the front node
	Node* temp = head;
	head = temp->next;
	free(temp);
}

LinkedList::~LinkedList()
{
	// deletes the entire list
	while(head != NULL)
	{
		deleteFront();
	}
}

#endif /* SINGLELIST_H_ */
