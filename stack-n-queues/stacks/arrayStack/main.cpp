#include "arrayStack.hpp"

using namespace std;

int main()
{
    ArrayStack<int> stack;
    menu();
    stack.push(5);
    stack.display();
    return 0;
}

