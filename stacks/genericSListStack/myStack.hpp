#include <iostream>
#include <stdexcept>

#include "singleList.hpp"

template <typename E>
class Stack
{
    public:
        int getSize() const;
        bool empty() const;
        const E& top() const;
        void push(const E& e);
        void pop();

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
const E& Stack<E>::top() const
{
    if(empty())
        throw std::logic_error("Stack is empty");
    return S.top();
}

template <typename E>
void Stack<E>::push(const E& e)
{
    S.addToList(e);
}

template <typename E>
void Stack<E>::pop()
{
    if(empty())
        throw std::logic_error("Stack is empty");
    S.deleteFront();
}
