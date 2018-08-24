#include "node.hpp"
#include <queue>

class BST
{
    public:
        bool search(int n);
        void removeNode();
        void insertNode(int n);
        int min();
        int max();
        int height();
        void levelOrderDisplay();
        void preOrderDisplay(Node<int>* node);
        void inOrderDisplay(Node<int>* node);
        void postOrderDisplay(Node<int>* node);
        bool checkBST(Node<int>* node);
    private:
        int size;
        Node<int>* root;
};

BST::BST()
{
    size = 0;
    root = NULL;
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
        Node<int>* temp = root;
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

//not finished
void BST::removeNode(int n)
{
    Node<int>* temp = root;
    Node<int>* prev = root;
    while(temp != NULL)
    {
        if(temp->data == n && temp != root)
        {
            
        }
    }
}

void BST::insertNode(int n)
{
    if(root == NULL)
    {
        root = new Node<int>;
        root->data = n;
    }

    else
    {
        Node<int> trav = root;
        while(trav != NULL)
        {
            if(trav->data == n)
            {
                std::cout << "The data already exists in the tree" << std::endl;
                return;
            }

            else if(trav->data > n)
            {
                if(trav->left == NULL)
                {
                    Node<int> temp = new Node;
                    temp->data = n;
                    trav->left = temp;
                }

                else
                {
                    trav = trav->left;
                }
            }

            else
            {
                if(trav->right == NULL)
                {
                    Node<int>* temp = new Node;
                    temp->data = n;
                    trav->right = temp;
                }

                else
                {
                    trav = trav->right;
                }
            }
        }
    }
}

int BST::min()
{
    Node<int> trav = root;
    while(trav->left != NULL)
    {
        trav = trav->left;
    }

    return trav->data;
}

int BST::max()
{
    Node<int> trav = root;
    
    while(trav->right != NULL)
    {
        trav = trav->right;
    }

    return trav->data;
}

int BST::findHeight(Node<int>* node)
{
    if(node == NULL)
    {
        return -1;
    }

    return max(findHeight(node->left), findHeight(node->right)) + 1;
}

void BST::levelOrderDisplay()
{
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty())
    {
        Node<int>* current = q.front();
        std::cout << current->data << " ";

        if(current->left != NULL)
            q.push(current->left);

        if(current->right != NULL)
            q.push(current->right);

        q.pop();
    }
}

void BST::preOrderDisplay(Node<int>* node)
{
    if(node == NULL)
        return;
    cout << node->data << " \n";
    preOrderDisplay(node->left);
    preOrderDisplay(node->right);
}

void BST::inOrderDisplay(Node<int>* node)
{
    if(node == NULL)
        return;
    preOrderDisplay(node->left);
    cout << node->data << " \n";
    preOrderDisplay(node->right);
}

void BST::postOrderDisplay(Node<int>* node)
{
    if(node == NULL)
        return;
    postOrderDisplay(node->left);
    postOrderDisplay(node->right);
    cout << node->data << " \n";
}

bool checkBST(Node<int>* node)
{

}
