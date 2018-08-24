#include "node.hpp"
#include <queue>
#include <limits.h>

class BST
{
    public:
        BST();
        bool search(int n);
        Node<int>* removeNode(Node<int>* root, int n);
        void insertNode(int n);
        Node<int>* min(Node<int>* node);
        Node<int>* max(Node<int>* node);
        int findHeight(Node<int>* node);
        void levelOrderDisplay();
        void preOrderDisplay(Node<int>* node);
        void inOrderDisplay(Node<int>* node);
        void postOrderDisplay(Node<int>* node);
        bool isBstUtil(Node<int>* root, int minValue, int maxValue);
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
        std::cout << "The tree is empty\n";
        return false;
    }
    
    else
    {
        Node<int>* temp = root;
        while(temp != NULL)
        {
            if(n == temp->data)
            {
                return true;
            }

            else if(n > temp->data)
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

Node<int>* BST::removeNode(Node<int>* node, int n)
{
    if(node == NULL)
        return node;
    
    else if(n < node->data)
        node->left = removeNode(node->left, n);

    else if(n > node->data)
        node->right = removeNode(node->right, n);

    else
    {
        //case for no child
        if(node->left == NULL && node->right == NULL)
        {
            free(node);
            node = NULL;
            return node;
        }

        //case for one child
        else if(node->left == NULL)
        {
            Node<int>* temp = node;
            node = node->right;
            free(temp);
            return node;
        }

        else if(node->right == NULL)
        {
            Node<int>* temp = node;
            node = node->left;
            free(temp);
            return node;
        }

        else
        {
            Node<int>* temp = min(node->right);
            node->data = temp->data;
            root->right = removeNode(node->right, temp->data);
        }
            
    }

    return node;
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
        Node<int>* trav = root;
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
                    Node<int>* temp = new Node<int>;
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
                    Node<int>* temp = new Node<int>;
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

Node<int>* BST::min(Node<int>* node)
{
    Node<int>* trav = node;
    while(trav->left != NULL)
    {
        trav = trav->left;
    }

    return trav;
}

Node<int>* BST::max(Node<int>* node)
{
    Node<int>* trav = node;
    
    while(trav->right != NULL)
    {
        trav = trav->right;
    }

    return trav;
}

int BST::findHeight(Node<int>* node)
{
    if(node == NULL)
    {
        return -1;
    }

    return std::max(findHeight(node->left), findHeight(node->right)) + 1;
}

void BST::levelOrderDisplay()
{
    std::queue<Node<int>*> q;
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
    std::cout << node->data << " \n";
    preOrderDisplay(node->left);
    preOrderDisplay(node->right);
}

void BST::inOrderDisplay(Node<int>* node)
{
    if(node == NULL)
        return;
    preOrderDisplay(node->left);
    std::cout << node->data << " \n";
    preOrderDisplay(node->right);
}

void BST::postOrderDisplay(Node<int>* node)
{
    if(node == NULL)
        return;
    postOrderDisplay(node->left);
    postOrderDisplay(node->right);
    std::cout << node->data << " \n";
}

bool BST::isBstUtil(Node<int>* root, int minValue, int maxValue)
{
    if(root == NULL)
        return true;

    if(root->data > minValue && root->data < maxValue && isBstUtil(root->left, minValue, root->data) && isBstUtil(root->right, root->data, maxValue))
        return true;

    else
        return false;
}

bool BST::checkBST(Node<int>* node)
{
    return isBstUtil(root, INT_MIN, INT_MAX);
}
