#include "node.hpp"

template <typename E>
class BST
{
    public:
        bool search();
        void display();
        void removeNode();
        void insertNode(E n);

    private:
        int size;
};

template <typename E>
BST<E>::BST
{
    size = 0;
}

template <typename E>
