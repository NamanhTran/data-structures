#include "queue.hpp"

using namespace std;

int main()
{
    int temp;
    Queue<int> queue;
    for(int i = 0; i < 11; i++)
    {
        cin >> temp;
        queue.enqueue(temp);
    }

    for(int i = 0; i < 11; i++)
    {
        queue.display();
        queue.dequeue();
    }

    return 0;
}
