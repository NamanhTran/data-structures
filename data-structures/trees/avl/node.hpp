#ifndef NODE_H
#define NODE_H

template <typename T>
struct Node
{
    T data;
    Node<T>* left;
    Node<T>* right;
    int height;
    Node(T value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

#endif
