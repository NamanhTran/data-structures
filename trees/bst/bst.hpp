#include "node.hpp"

class BST
{
    public:
        bool search(int n);
        void removeNode();
        void insertNode(int n);
        void display();

    private:
        int size;
        Node* root;
};

BST::BST()
{
    size = 0;
    Node* root = NULL;
}

bool BST::search(int n)
{
    if(size == 0)
    {
        cout << "The tree is empty\n";
        return false;
    }
    
    else
    {
        Node* temp = root;
        while(temp != NULL)
        {
            if(n == data)
            {
                return true;
            }

            else if(n > data)
            {
                temp = temp->right;
            }

            else
            {
                temp = temp->left;
            }
        }

        return false;
    }
}

void BST::removeNode(int n)
{
    Node* temp = root;
    Node* prev = root;
    while(temp != NULL)
    {
        if(temp->data == n && temp != root)
        {
            
        }
    }
}
