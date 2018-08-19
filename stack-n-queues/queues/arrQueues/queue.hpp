#include <iostream>

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
        E* arrP;
        int size;
        int front;
        int back;
        int arraySize;
};

template <typename E>
Queue<E>::Queue()
{
    //initalize the variables in the class
    arraySize = 10;
    arrP = new E[arraySize];
    size = 0;
    front = 0;
    back = 0;

}

template <typename E>
void Queue<E>::enqueue(E n)
{
    //Double the size of the array if queue is full
    if(size == arraySize - 1)
    {
        std::cout << "Array Extended" << std::endl;
        E* temp = arrP;
        arraySize *= 2;
        arrP = new E[arraySize];

        for(int i = front; i < arraySize / 2; i++)
        {
            arrP[i] = temp[i];
        }

        free(temp);
    }

    arrP[back] = n;
    size++;
    back = (back + 1) % arraySize;
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
        front = (front + 1) % arraySize;
        size--;
    }
}

template <typename E>
E Queue<E>::getFront()
{
    //returns the front
    return arrP[front];
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
        //displays the entire queue
        for(int i = front; i < arraySize; i++)
        {
            std::cout << arrP[i] << " ";
        }   

        std::cout << std::endl;
    }
}
