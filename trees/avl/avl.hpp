#ifndef AVL_H
#define AVL_H

/*
 * AVL implementation is learned and somewhat ripped from
 * https://hiimkarl.github.io//Learning-AVL-Trees-1/
 */

#include "node.hpp"

template <typename T>
class AVL
{
    private:
        Node<T>* root;
        int size;

    public:
        AVL();
        Node<T>* insert(Node<T>* root, T value);
        void remove(T value);
        Node<T>* find(Node<T>*, T value);
        int getHeight(Node<T>* node);
        void checkRotations(Node<T>* node);
        int balanceFactor(Node<T>* node);
        void updateHeight(Node<T>* node);
        void leftRotation(Node<T>* node);
        void rightRotation(Node<T>* node);
        void leftRightRotation(Node<T>* node);
        void rightLeftRotation(Node<T>* node);
};

template <typename T>
AVL<T>::AVL()
{
    root = NULL;
    size = 0;
}

template <typename T>
int AVL<T>::getHeight(Node<T>* node)
{
    return node->height;
}

template <typename T>
Node<T>* find(Node<T>* node, T value)
{
    Node<T>* trav = node;
    
    while(trav != NULL)
    {
        if(trav->data == value)
        {
            return trav;
        }

        else if(trav->data > value)
        {
            trav = trav->left;
        }

        else
        {
            trav = trav->right;
        }
    }
}

template <typename T>
Node<T>* AVL<T>::insert(Node<T>* root,T value)
{
    Node<T>* node = new Node<T>(value);
    if(root == NULL)
        return node;

    Node<T>* trav = root;
    Node<T>* parents[root->height + 1];
    int index = 0;

    while(trav != NULL)
    {
        parents[index++] = trav;

        if(trav->data > value)
           trav = trav->left;
        
        else
           trav = trav->right; 
    }

    trav = node;

    // updates height of the tree and checks if rotation is needed
    for(int i = 0; i < index; i++)
    {
        checkRotations(parents[index - i - 1]);
    }

    return root;
}

template <typename T>
void AVL<T>::checkRotations(Node<T>* node)
{
	int bf = getBalanceFactor(node);

	if(bf >= 2)
	{
		int leftBf = getBalanceFactor(node->left);

		if(leftBf > 0)
				leftRotation(node);

		else
				rightLeftRotation(node);
	}

	else if(bf <= -2)
	{
	 	int right_bf = getBalanceFactor(node->right);

		if(bf > 0)
				rightRotation(node);

		else
				leftRightRotation(node);
	}

	else
	{
		updateHeight(node);
	}
}

template<typename T>
int getBalanceFactor(Node<T>* node)
{
	long leftHeight = 0;

	if(node->left != NULL)
		leftHeight = node->left->height + 1;

	long rightHeight = 0;

	if(node->right != NULL)
			rightHeight = node->right->height + 1;

	return rightHeight - leftHeight;
}

template <typename T>
void AVL<T>::updateHeight(Node<T>* node)
{
	int leftHeight = 0;

	if(node->left != NULL)
		leftHeight = node->left->height + 1

	int rightHeight = 0;

	if(node->right != NULL)
		rightHeight = node->right->height + 1;

	int nodeHeight = 0;

	if(leftHeight > rightHeight)
		node->height = leftHeight;
	
	else
		node->height = rightHeight;	
}
#endif
