#ifndef LIST_H
#define LIST_H

#include "node.h"

using namespace std;

class List
{
public:
	List();
	void remove(const int&);
	void add(const int&);
	void print() const;

private:
	unsigned sz;
	Node *frontPtr;
	Node *backPtr;

	void initialize();

}; //List class

/***************
**CONSTRUCTORS**
***************/

//defualt constructor
List::List()
{
	initialize();
} //List::List

/*******************
**MEMBER FUNCTIONS**
*******************/

//printing
void List::print() const
{
	Node *ptr = frontPtr;

	for (unsigned i = 0; i < sz; i++)
	{
		cout << ptr->getValue() << " ";
		ptr = ptr->getNextPtr();
	}

	//cout << frontPtr->getValue() << endl;
	//cout << backPtr->getValue() << endl;

	cout << endl;
} //List::print

//intializing
void List::initialize()
{
	sz = 0;
	frontPtr = 0;
}


//removing
void List::remove(const int& deletion)
{
	//cout << "remove" << endl;

	Node *ptr = frontPtr;
	Node *trail = frontPtr;

	//cout << "0" << endl;

	if (frontPtr->getValue() == deletion)
	{
		if (frontPtr == backPtr)
		{
			delete ptr;
		}
		else
		{
			//cout << "entered";
			ptr = ptr->getNextPtr();
			delete trail;
			trail = ptr;
			frontPtr = ptr;
		}
		sz--;
	}

	//cout << "1" << endl;

	while(ptr != backPtr)
	{
		//cout << "in loop" << endl;
		if (ptr->getNextPtr() == backPtr)
		{
			//cout << "checks back" << endl;
			if (backPtr->getValue() == deletion)
			{
				//cout << "if" << endl;
				delete backPtr;
				backPtr = ptr;
				sz--;
			}
			else
			{
				//cout << "else" << endl;
				ptr = backPtr;
			}
		}
		else if (ptr->getNextPtr()->getValue() == deletion)
		{
			//cout << "deleted" << endl;
			ptr = ptr->getNextPtr();
			trail->setNextPtr(ptr->getNextPtr());
			delete ptr;
			ptr = trail;
			sz--;
		}
		else
		{
			ptr = ptr->getNextPtr();
			trail = ptr;
		}

		//cout << "out" << endl;
	}

	//cout << "loop over" << endl;
} //List::remove

//adding
void List::add(const int& value)
{
	Node *newNode = new Node(value);

	if (sz == 0)
	{
		frontPtr = newNode;
	}
	else
	{
		backPtr->setNextPtr(newNode);
	}

	backPtr = newNode;
	sz++;
} //List::add

#endif // LIST_H



