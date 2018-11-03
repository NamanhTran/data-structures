#include "node.hpp"
#include <queue>
#include <limits.h>

class BST
{
    public:
        // Default constructor
        BST();
        
        // Searches through the tree
        bool search(int n);

        // Removes a node from the tree
        Node<int>* removeNode(Node<int>* root, int n);

        // Insert a node to the tree
        void insertNode(int n);

        // Finds the min value of the tree from given node
        Node<int>* min(Node<int>* node);

        // Finds the max value of the tree from given node
        Node<int>* max(Node<int>* node);

        // Finds the height of the tree from the given node
        int findHeight(Node<int>* node);

        // Level order, preOrder, postOrder display function
        void levelOrderDisplay();
        void preOrderDisplay(Node<int>* node);
        void inOrderDisplay(Node<int>* node);
        void postOrderDisplay(Node<int>* node);

        // Utility function for the tree (only used in checkBST function)
        bool isBstUtil(Node<int>* root, int minValue, int maxValue);

        // Checks if the tree is a Binary Search Tree
        bool checkBST(Node<int>* node);
    private:
        // Size of the tree
        int size;

        // Root node of the tree
        Node<int>* root;
};

// Default constructor sets default values
BST::BST()
{
    size = 0;
    root = NULL;
}

// Searches through the tree for a certain value
bool BST::search(int n)
{
    // If the tree is empty return false
    if(size == 0)
    {
        std::cout << "The tree is empty\n";
        return false;
    }
    
    // If the tree is not empty 
    else
    {
        // Create a temp node (traversal node)
        Node<int>* temp = root;

        // Traverse through the tree
        while(temp != NULL)
        {
            // If the node is found return true
            if(n == temp->data)
            {
                return true;
            }

            // If the current node is less than the value, go right
            else if(n > temp->data)
            {
                temp = temp->right;
            }

            // If the current node is greater than the value, go left
            else
            {
                temp = temp->left;
            }
        }

        // If not found return false
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
        // Case for no child
        if(node->left == NULL && node->right == NULL)
        {
            // Delete current node
            free(node);

            // Set current node to NULL then return NULL
            node = NULL;
            return node;
        }

        // Case for one child on right
        else if(node->left == NULL)
        {
            // Set a temp node to current position
            Node<int>* temp = node;

            // Promote the only child to current position
            node = node->right;

            // Delete the node
            free(temp);

            // Return node
            return node;
        }
        
        // Case for one child on the left
        else if(node->right == NULL)
        {
            // Set a temp node to current position
            Node<int>* temp = node;

            // Promote the only child to parent's position
            node = node->left;

            // Delete the node
            free(temp);

            // Return node
            return node;
        }

        // Case for two childs
        else
        {
            // Set a temp node to the min node of the node's position in the tree
            Node<int>* temp = min(node->right);

            // Set the current node to the min value of the tree's current position
            node->data = temp->data;

            // Remove the duplicate node that is on the right side
            node->right = removeNode(node->right, temp->data);
        }
            
    }

    // If not found just return current node position
    return node;
}

// Insert node into tree
void BST::insertNode(int n)
{
    // If first node of the tree
    if(root == NULL)
    {
        // Create new node, set value, all assigned to root
        root = new Node<int>;
        root->data = n;
    }

    // If not the first node of the tree
    else
    {
        // Set a traversal node pointing to the root
        Node<int>* trav = root;

        // Traverse through the tree
        while(trav != NULL)
        {
            // If data is already in the tree exit out of the function
            if(trav->data == n)
            {
                std::cout << "The data already exists in the tree" << std::endl;
                return;
            }
            
            // If the key given is less than current node
            else if(trav->data > n)
            {
                // If the left node is NULL then insert new node there
                if(trav->left == NULL)
                {
                    // Create new node
                    Node<int>* temp = new Node<int>;

                    // Assign data to the node
                    temp->data = n;

                    // New node is inserted in the tree
                    trav->left = temp;

                    return;
                }

                else
                {
                    // Go left of the tree 
                    trav = trav->left;
                }
            }
            
            // If the key given is greater than the current node
            else
            {
                // If the right node is NULL then insert new node there
                if(trav->right == NULL)
                {
                    // Create new node
                    Node<int>* temp = new Node<int>;

                    // Assign data to the node
                    temp->data = n;

                    // New node is inserted in the tree
                    trav->right = temp;

                    return;
                }

                else
                {
                    // Go right of the tree
                    trav = trav->right;
                }
            }
        }
    }
}

// Find the min value of the tree
Node<int>* BST::min(Node<int>* node)
{
    // Create a traveral node
    Node<int>* trav = node;

    // Keep going left of the tree until we reach the end of the tree
    while(trav->left != NULL)
    {
        trav = trav->left;
    }
    
    // Return the node containing the min value
    return trav;
}

// Find the max value of the tree
Node<int>* BST::max(Node<int>* node)
{
    // Create a traversal node
    Node<int>* trav = node;
    
    // Keep going right of the tree until we reach the end of the tree 
    while(trav->right != NULL)
    {
        trav = trav->right;
    }
    
    // Return the node containing the max vale
    return trav;
}

// Find the height of the tree from the node given
int BST::findHeight(Node<int>* node)
{
    // If end of tree return -1 (because it's the end of the tree)
    if(node == NULL)
    {
        return -1;
    }
    
    // Return the max (height) of the two side + 1 (because we need to count the current node's height)
    return std::max(findHeight(node->left), findHeight(node->right)) + 1;
}

void BST::levelOrderDisplay()
{
    // Create a queue and push root to it
    std::queue<Node<int>*> q;
    q.push(root);
   
    // Loops until the the tree fully traversed 
    while(!q.empty())
    {
        // Set a current node to the front of the queue
        Node<int>* current = q.front();

        // Print current value 
        std::cout << current->data << " ";
        
        // If current still has a child node push to the queue
        if(current->left != NULL)
            q.push(current->left);

        if(current->right != NULL)
            q.push(current->right);

        // Pop the front because we already visited it
        q.pop();
    }
}

// PreOrder is when you vist the current node you are on then 
// visit the left side first, then the right side last
void BST::preOrderDisplay(Node<int>* node)
{
    if(node == NULL)
        return;
    std::cout << node->data << " \n";
    preOrderDisplay(node->left);
    preOrderDisplay(node->right);
}

// inOrder is when you visit the left most node first (all the way down until end of tree)
// then print out the current node you're at, then go through the right side 
void BST::inOrderDisplay(Node<int>* node)
{
    if(node == NULL)
        return;
    preOrderDisplay(node->left);
    std::cout << node->data << " \n";
    preOrderDisplay(node->right);
}

// postOrder is when you visit and print out left then right then finally print out the current node
void BST::postOrderDisplay(Node<int>* node)
{
    if(node == NULL)
        return;
    postOrderDisplay(node->left);
    postOrderDisplay(node->right);
    std::cout << node->data << " \n";
}

// Used in checkBST
bool BST::isBstUtil(Node<int>* root, int minValue, int maxValue)
{
    if(root == NULL)
        return true;

    if(root->data > minValue && root->data < maxValue && isBstUtil(root->left, minValue, root->data) && isBstUtil(root->right, root->data, maxValue))
        return true;

    else
        return false;
}

// Checks if the tree is a Binary Seach Tree
bool BST::checkBST(Node<int>* node)
{
    return isBstUtil(root, INT_MIN, INT_MAX);
}
