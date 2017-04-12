#include <iostream>
#include <cstdlib>
using namespace std;

class Node
{
	friend class LinkedStack;
	int data;
	Node *next;
};

class LinkedStack
{
public:
	LinkedStack();
	~LinkedStack();
	bool isEmpty() const;
	bool getTop(int& x) const;
	LinkedStack& push(const int& x);
	LinkedStack& pop();
	void operator =(const LinkedStack& x);
private:
	Node *top;
};

LinkedStack::LinkedStack()
{
	top = 0;
}

LinkedStack::~LinkedStack()
{
	Node *tmp = top;
	while(tmp)
	{
		tmp = top -> next;;
		delete top;
		top = tmp;
	}
}

bool LinkedStack::isEmpty() const
{
	return top == 0;
}

bool LinkedStack::getTop(int &x) const
{
	if(isEmpty()) return false;
	else 
	{
		x = top -> data;
		return true;
	}
}

LinkedStack& LinkedStack::push(const int &x)
{
	Node *p = new Node;
	p -> data = x;
	p -> next = NULL;
	top = p;
	return *this;
}

LinkedStack& LinkedStack::pop()
{
	Node *tmp = top;
	top = top -> next;
	delete tmp;
	return *this;
}

void LinkedStack::operator =(const LinkedStack& x)
{
	Node *new_top, *new_copy, *original_node = x.top;
	if(original_node == NULL) new_top = NULL;
	else
	{
		Node *p = new Node;
		p -> data = x.top -> data;
		new_top = new_copy = p;
		while(original_node -> next != NULL)
		{
			original_node = original_node -> next;
			new_copy -> next = original_node;
			new_copy = new_copy -> next;
		}
		while(!isEmpty()) pop();
		top = new_top;
	}
}