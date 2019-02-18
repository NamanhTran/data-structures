#ifndef UNIONFIND_H_
#define UNIONFIND_H_
#include <vector>

class UF
{
    public:
        // Public methods for union-find
        UF(int n);

        // Union function
        void unionUF(int p, int q);

        // Checks if connected
        bool connected(int p, int q);

        // Sets id array to their corresponding index
        void quickFindUF(int n);
    private:
        // ID array for union find
        std::vector<int> id;

        // Private method for finding root of a number in the id array
        int root(int i);

        // Size vector (size of each tree)
        std::vector<int> sz;
};

// Initalizer for UF' array
UF::UF(int n)
{
    // Reserve n space in array
    id.reserve(n);
    sz.reserve(n);
    // 0 out size vector
    for (int i = 0; i < n; i++)
    {
        sz[i] = 0;
    }

    // Initialize id array
    quickFindUF(n);

    return;
}

// Sets id array to their corresponding index
void UF::quickFindUF(int n)
{
    for (int i = 0; i < n; i++)
    {
        id[i] = i;
    }

    return;
}

// Finds the root in the tree
int UF::root(int i)
{
    // Loops until we hit the root (when i = id[i])
    while (i != id[i])
    {
        // This line of code enable path compression which moves the current node to the grandparent
        // This allows for an almost flattened tree
        id[i] = id[id[i]];
        i = id[i];
    }

    return i;
}

// Checks if connected
bool UF::connected(int p, int q)
{
    return root(p) == root(q);
}

// Union method
void UF::unionUF(int p, int q)
{
    // Check if connected
    if (!connected(p, q))
    {
        // Get the root of each number
        int i = root(p);
        int j = root(q);
        
        // If already connected then return
        if (id[i] == j)
            return;

        // If the size of p's tree is smaller than q's tree then set the root of p to root of q
        if (sz[i] < sz[j])
        {
            id[i] = j;
            sz[j] += sz[i];
        }

        // If the size of q's tree is smaller than p's tree then set the root of q to root of p
        else
        {
            id[j] = i;
            sz[i] += sz[j];
        }

    }

    return;
}

#endif /* UNIONFIND_H_ */
