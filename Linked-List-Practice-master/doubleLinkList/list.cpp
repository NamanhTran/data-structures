#include "doubleList.hpp"

using namespace std;

//function prototype for dataMenu, operationMenu, and operationExecute
void dataMenu(LinkedList* sll);
int operationMenu();
void operationExecute(int c, LinkedList* sll);

int main()
{
	//allocate new list
    LinkedList* list = new LinkedList;
	
	//call data menu function
    dataMenu(list);

	//choice declared to use in function in lower scopes
	//and used to check do while conditon
	int choice = 0;

	//loops until user quits
	do
	{
		//gets the choice from the user
		choice = operationMenu();

		//executes whatever choice the user made
		operationExecute(choice, list);
	}
	while(choice != 3);

	free(list);

    return 0;
}

void dataMenu(LinkedList* ssl)
{
	//declares data string
	string data = "";

	//ask user for input
	cout << "Type in EOF to mark you are done entering data.\n";
    do
	{
		getline(cin, data);
   
		//breaks if user enters end of file command
		if(data == "EOF")
		{
			break;
		}

        else
        {
            ssl->addToList(data);
        }
    }
    while(true);
}

int operationMenu()
{
	//declare choice
	int choice;
	
	//gets input from user ranging from 1-3
	do
    {
		cout << "Choose an operation:\n";
		cout << "1) Find something in the list\n";
		cout << "2) Show list content\n";
		cout << "3) Quit\n";
		cin >> choice;
    }
    while(choice != 1 && choice != 2 && choice != 3);
    
    return choice;
}

void operationExecute(int c, LinkedList* sll)
{
	//call find function 
	if(c == 1)
	{
		string data;
		cout << "Enter a string to find in the list: ";
        cin.ignore();
		getline(cin, data);
		bool found = sll->find(data);

		if(found)
		{
			cout << data << " exists in the list!\n";
		}
		
		else
		{
			cout << data << " does NOT exists in the list!\n";
		}

		cout << endl;
	}

	//displays list content
	else if(c == 2)
	{
		sll->display();
		cout << endl;
	}

	//quits if user chooses to quit
	else if(c == 3)
	{
		cout << "Goodbye!\n";
		sll->~LinkedList();
	}

	//in case something went wrong
	else
	{
		cout << "Looks like you tried to break this program!";
		sll->~LinkedList();
	}
}

