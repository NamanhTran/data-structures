#include <stdio.h>
#include <iostream>

template <typename E>
struct Node
{
    struct Node* left;
    struct Node* right;
    E data;
};
