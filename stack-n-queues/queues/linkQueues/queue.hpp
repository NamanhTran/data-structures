#include <iostream>
#include "singleList.hpp"

template <typename E>
class Queue
{
    public:
        Queue();
        void enqueue(E n);
        void dequeue();
        E getFront();
        int getSize();
        bool empty();
        void display();

    private:
        int size;
        LinkedList<E> list;
        
};

template <typename E>
Queue<E>::Queue()
{
    //initalize the variables in the class
    size = 0;
}

template <typename E>
void Queue<E>::enqueue(E n)
{
    list.addToList(n);
    size++;
}

template <typename E>
void Queue<E>::dequeue()
{
    //if the queue is empty throw error
    if(empty())
    {
        std::cout << "The queue is empty" << std::endl;
    }

    //add to the queue
    else
    {
        list.removeFront();
        size--;
    }
}

template <typename E>
E Queue<E>::getFront()
{
    //returns the front
    return list.top();
}

template <typename E>
int Queue<E>::getSize()
{
    //return the size of the queue
    return size;
}

template <typename E>
bool Queue<E>::empty()
{
    //if empty
    if(size == 0)
        return true;

    //if not empty
    else
        return false;
}

template <typename E>
void Queue<E>::display()
{
    if(empty())
    {
        std::cout << "The queue is empty\n";
    }

    else
    {
        list.display();
    }
}
