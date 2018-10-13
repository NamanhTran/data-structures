#include <iostream>
#include "singleList.hpp"

template <typename E>
class Stack
{
    public:
        int getSize() const;
        bool empty() const;
        const E& top() const throw(StackEmpty);
        void push(const E& e);
        void pop() throw(StackEmpty);

    private:
        LinkedList<E> S;
        int size;
};

template <typename E>
int Stack<E>::getSize() const
{
    return size;
}

template <typename E>
bool Stack<E>::empty() const
{
    if(size == 0)
        return true;

    else
        return false;
}

template <typename E>
const E& Stack<E>::top() const throw(StackEmpty)
{
   return S.top();
}

template <typename E>
void Stack<E>::push(const E& e)
{
    S.addToList(e);    
}

template <typename E>
void Stack<E>::pop() throw(StackEmpty)
{
    S.deleteFront();
}


