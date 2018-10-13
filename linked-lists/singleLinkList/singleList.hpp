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

	//operation for list
	~LinkedList();
	void addToList(const std::string n);
	void deleteFront();
	bool find(const std::string n);
	void display();
	void reverse();
};

LinkedList::LinkedList()
{
	//creates the list
	head = NULL;
	size = 0;
}

void LinkedList::addToList(const std::string n)
{
	Node* newList = new Node(n);

	//if no node exists in the list
	if(head == NULL)
	{
		head = newList;
	}

	//if node exists in the list already
	else
	{
		newList->next = head;
		head = newList;
	}

	//increment the list size
	size++;
}

void LinkedList::display()
{
	Node* temp = head;

	std::cout << "Data in the Single Linked-List:\n";

	//displays data in the list
	while(temp != NULL)
	{
		std::cout << temp->data << "\n";
		temp = temp->next;
	}
}

bool LinkedList::find(const std::string n)
{
	Node* temp = head;

	//find if data exists in the list
	while(temp != NULL)
	{
		//if data exist
		if(temp->data == n)
		{
			return true;
		}

		else
		{
			temp = temp->next;
		}
	}

	//if data does not exist
	return false;
}

void LinkedList::deleteFront()
{
	//deletes the front node
	Node* temp = head;
	head = temp->next;
	free(temp);
}

void LinkedList::reverse()
{
	Node* current = head;
	Node* prev = NULL;
	Node* next = NULL;

	while(current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	head = prev;
}
LinkedList::~LinkedList()
{
	//deletes the entire list
	while(head != NULL)
	{
		deleteFront();
	}
}

#endif /* SINGLELIST_H_ */
