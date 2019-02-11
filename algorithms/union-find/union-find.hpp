#ifndef UNIONFIND_H_
#define UNIONFIND_H_
#include <vector>

class UF
{
    public:
        UF(int n);
        void unionUF(int p, int q);
        bool connected(int p, int q);
        void quickFindUF(int n);
    private:
        std::vector<int> id;
        int root(int i);
        std::vector<int> sz;
};

UF::UF(int n)
{
    id.reserve(n);
    sz.reserve(n);
    // 0 out size vector
    for (int i = 0; i < n; i++)
    {
        sz[i] = 0;
    }

    quickFindUF(n);

    return;
}

void UF::quickFindUF(int n)
{
    for (int i = 0; i < n; i++)
    {
        id[i] = i;
    }

    return;
}

int UF::root(int i)
{
    while (i != id[i])
    {
        i = id[i];
    }

    return i;
}

bool UF::connected(int p, int q)
{
    return root(p) == root(q);
}

void UF::unionUF(int p, int q)
{
    if (!connected(p, q))
    {
        int i = root(p);
        int j = root(q);
        id[i] = j;

    }

    return;
}

#endif /* UNIONFIND_H_ */
