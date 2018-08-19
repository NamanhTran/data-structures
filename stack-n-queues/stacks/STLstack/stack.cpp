#include <stack>
#include <iostream>

using namespace std;

bool pairTest(char test, char top);

int main()
{
    stack<char> myStack;
    string symbol;
    cout << "Enter the a set of pairing symbol to test if it is valid: ";
    cin >> symbol;
    
    for (int i = 0; i < symbol.length(); i++)
    {
        if(symbol[i] == '{' || symbol[i] == '[' || symbol[i] == '(')
            myStack.push(symbol[i]);
        else
        {
            if(myStack.empty())
            {
                cout << "The pairing sequence is incorrect\n";
                return 1;
            }

            else if(pairTest(symbol[i], myStack.top()))
            {
                myStack.pop();
            }

            else
            {
                cout << "The pairing squence is incorrect\n";
                return 1;
            }
        }
    }

    if(!myStack.empty())
    {
        cout << "The pairing sequence is incorrect\n";
        return 1;
    }

    else
    {
        cout << "The pairing sequence is correct\n";
    }
    return 0;
}

bool pairTest(char test, char top)
{
    if(top == '(')
    {
        if(test == ')')
            return true;
    }

    else if(top == '{')
    {
        if(test == '}')
            return true;
    }
    
    else if(top == '[')
    {
        if(test == ']')
            return true;
    }

    return false;
}
