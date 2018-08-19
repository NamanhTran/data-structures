#ifndef CIRCULARLY_LINKED_LIST
#define CIRCULARLY_LINKED_LIST
#include "node.hpp"

template <typename E>
class circularlyList
{
    public:
        circularlyList();
        ~circularlyList();
        E front();
        E back();
        void advance();
        void add(E n);
        void removeFront();
    
    private:
        Node<E>* cursor;       
};

template <typename E>
circularlyList<E>::circularlyList()
{
    cursor = NULL;
}

template <typename E>
void circularlyList<E>::add(E n)
{
    Node<E>* temp = new Node<E>(n);
    temp->data = n;
    
    if(cursor == NULL)
    {
        temp->next = temp;
        cursor = temp; 
    }

    else
    {
        temp->next = cursor->next;
        cursor->next = temp;
    }
}

template <typename E>
E circularlyList<E>::front()
{
    return cursor->data->next;
}

template <typename E>
E circularlyList<E>::back()
{
    return cursor->data;
}

template <typename E>
void circularlyList<E>::advance()
{
    cursor = cursor->next;
}

template <typename E>
void circularlyList<E>::removeFront()
{
    Node<E>* temp = cursor->next;
    if(cursor == temp)
    {
        cursor = NULL;
    }

    else
    {
        cursor->next = temp->next;
    }

    delete temp;
}

template <typename E>
circularlyList<E>::~circularlyList()
{
    while(cursor != NULL)
    {
        removeFront();
    }
}

#endif
