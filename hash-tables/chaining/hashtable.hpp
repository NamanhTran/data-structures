#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "node.hpp"

#define TABLE_SIZE 100

template <typename T>
class HashTable
{
    private:
        Node<T>* table[TABLE_SIZE];
        int hashGen(T value);

    public:
        void insert(T value);
        void remove(T value);
        bool search(T data);
};

template <typename T>
void HashTable<T>::insert(T value)
{
    int hash = hashGen(value);

    if(table[hash] == NULL)
    {
        Node<T>* temp = new Node<T>;
        temp->data = value;
        temp->next = NULL;
        table[hash] = temp;
    }

    else
    {
        Node<T>* temp = new Node<T>;
        temp->data = value;
        temp->next = table[hash];
        table[hash] = temp;
    }
}

template <typename T>
void HashTable<T>::remove(T value)
{
    int hash = hashGen(value);

    Node<T>* temp = table[hash];
    Node<T>* prev = table[hash];
    while(temp != NULL)
    {
        if(temp->data == value)
        {
            if(temp == prev)  
                table[hash] = temp->next;
            
            else
                prev->next = temp->next;

            free(temp);

            return;
        }

        else
        {
            prev = temp;
            temp = temp->next;
        }
    }

    std::cout << "\n\nNode was not found to remove\n\n";
}

template <typename T>
bool HashTable<T>::search(T value)
{
    int hash = hashGen(value);

    Node<T>* temp = table[hash];

    while(temp != NULL)
    {
        if(temp->data = value)
            return true;
        
        temp = temp->next;
    }

    return false;
}

template <typename T>
int HashTable<T>::hashGen(T value)
{
    /*
     CREATE HASH FUNCTION
     IDEA:
        TAKE BIT SIZE OF THE VALUE THEN HASH IT
    */

    return 0;
}
#endif
