#ifndef SINGLELIST_H_
#define SINGLELIST_H_

#include "node.hpp"
template <typename E>
class LinkedList
{
    private:
        Node<E>* head;       
       	int size;
        Node<E>* back;

    public:
		LinkedList();
		
		//operation for list
		~LinkedList();
    	void addToList(const E n);
    	void deleteFront();
		bool find(const E n);
        E top();
		void display();
};

template <typename E>
LinkedList<E>::LinkedList()
{
	//creates the list
    head = NULL;
    size = 0;
    back = NULL;
}

template <typename E>
void LinkedList<E>::addToList(const E n)
{
    Node<E>* newList = new Node<E>(n);

	//if no node exists in the list
    if(head == NULL)
    {
        head = newList;
        back = newList;
    }

	//adds a node to the end of the list for a queue
    else
    {
        newList->next = NULL;
        back->next = newList;
        back = newList;
    }

	//increment the list size
    size++;
}

template <typename E>
void LinkedList<E>::display()
{
	Node<E>* temp = head;

	std::cout << "Data in the Single Linked-List:\n";

	//displays data in the list
	while(temp != NULL)
	{
		std::cout << temp->data << "\n";
		temp = temp->next;
	}
}

template <typename E>
bool LinkedList<E>::find(const E n)
{
	Node<E>* temp = head;

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

template <typename E>
E LinkedList<E>::top()
{
    return head->data;
}

template <typename E>
void LinkedList<E>::deleteFront()
{
	//deletes the front node
	Node<E>* temp = head;
	head = temp->next;
	free(temp);
}

template <typename E>
LinkedList<E>::~LinkedList()
{
	//deletes the entire list
	while(head != NULL)
	{
		deleteFront();
	}
}

#endif /* SINGLELIST_H_ */
