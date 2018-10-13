#include <iostream>

template <typename E>
class ArrayStack
{
    public:
        ArrayStack();
        void push(E n);
        void pop();
        bool isEmpty();
        E returnTop();
        void display();

    private:
        E* stackPointer;
        int top;
        
};

template <typename E>
ArrayStack<E>::ArrayStack()
{
   stackPointer = new E[10];
   top = -1;
}

template <typename E>
void ArrayStack<E>::push(E n)
{
    if(top > sizeof(stackPointer))
    {
        //make array bigger
        E* temp = stackPointer;
        int arraySize = sizeof(*stackPointer);
        stackPointer = new E[arraySize * 2];

        //copy old array to new array
        for(int i = 0; i < top + 1; i++)
        {
            stackPointer[i] = temp[i];
        }

        free(temp);
    }

    top++;
    stackPointer[top] = n;
}

template <typename E>
void ArrayStack<E>::pop()
{
    if(!isEmpty())
        top--;
    else
        std::cout << "Stack is empty, failed to pop from stack\n";
}

template <typename E>
bool ArrayStack<E>::isEmpty()
{
    if(top == -1)
        return true;

    else
        return false;
}

template <typename E>
E ArrayStack<E>::returnTop()
{
    return stackPointer[top];
}

template <typename E>
void ArrayStack<E>::display()
{
    for(int i = 0; i < top + 1; i++)
    {
        std::cout << stackPointer[i] << " ";
    }

    std::cout << std::endl;
}
