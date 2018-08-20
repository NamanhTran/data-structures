#include <iostream>

template <typename E>
typedef struct node
{
    struct node* left;
    struct node* right;
    E data;
}Node;
