#include <iostream>
#include <cstdlib>
using namespace std;
//definition of the Node
template<typename T>
class Node
{
	template<typename T> friend class List;
	Node();
	Node(const T& x, Node<T> *next = NULL);
	T data;
	Node *next;
};

template<typename T>
Node<T>::Node()
{
	next = NULL;
}
//constructor, initialize a node
template<typename T>
Node<T>::Node(const T &x, Node<T> *next = NULL)
{
	data = x;
}

//definition of the List
template<typename T>
class List
{
public:
	List();//defaut constructor
	~List();//destructor
	List(const List<T>& l);//copy constructor
	void clear();//erase all the nodes
	bool isEmpty() const;//judge if the list is empty
	bool isFull() const;//judge if the list is full
	int size() const;//get the length of the list
	bool find(int index, const T& x) const;//judge if a certain node is in the list
	int search(const T& x) const;//find the given value's position
	List<T>& _delete(const int index, const T& x);//delete the given node
	List<T>& insert(const int index, const T& x);//add a node to the list
	void output(ostream& os) const;//transport the list to the out stream
	ostream& operator <<(ostream& os, const List<T> l);//overload the operator <<
private:
	int length;
	Node *head;
	Node *set_position;
};

template<typename T>
List<T>::List()
{
	head = set_position = NULL;
	length = 0;
}

template<typename T>
List<T>::~List()
{
	while(head)
	{
		Node<T> *tmp = head -> next;
		delete head;
		head = tmp;
	}
	length = 0;
}

template<typename T>
List<T>::List(const List<T> &l)
{
	Node<T> *new_copy, *lorigin = l.head;
	head = new_copy = Node<T> *p(lorigin->data);
	length = 1;
	while(lorigin->next)
	{
		lorigin = lorigin->next;
		new_copy->next = Node<T> *p(lorigin->data);
		new_copy = new_copy->next;
		length++;
	}
}

template<typename T>
void List<T>::clear()
{
	while(head)
	{
		Node<T> *tmp = head -> next;
		delete head;
		head = tmp;
	}
}

template<typename T>
bool List<T>::isEmpty() const
{
	return length == 0;
}

template<typename T>
bool List<T>::isFull() const
{
	if(new Node<T> *p)
	{
		delete p;
		return false;
	}
	else
		return true;
}

template<typename T>
int List<T>::size() const
{
	return length;
}

template<typename T>
bool List<T>::find(int index, const T &x) const
{
	if(index > length || index < 0)
		return false;
	else
	{
		Node<T> *p = head;
		int len = 1;
		while(len < index)
		{
			p = p -> next;
			len++;
		}
		if(p -> data == x)
			return true;
		else 
			return false;
	}
}

template<typename T>
int List<T>::search(const T &x) const
{
		Node<T> *p = head;
		int position = 1;
		while(p -> data != x)
		{
			p = p -> next;
			position++;
		}
		return position;
}

template<typename T>
List<T>& List<T>::_delete(const int index, const T& x)
{
	if(isEmpty())
		return *this;
	else if(index > length || index < 0)
		return *this;
	else 
	{
		Node<T> *p = head;
		int position = 1;
		while(p -> next != NULL)
		{
			if(p -> data == x)
			{
				Node<T> *tmp = p -> next;
				p = tmp -> next;
				delete tmp;
			}
			else 
			{
				p = p -> next;
			}
		}
		return *this;
	}
}

template<typename T>
List<T>& List<T>::insert(const int index, const T& x)
{
	if(index > length || index < 0)
		return *this;
	else if(isFull())
		return *this;
	else 
	{
		Node<T> *p = head;
		int position = 1;
		while(position != index)
		{
			p = p -> next;
			position++;
		}
		Node<T> *tmp = new Node<T>;
		tmp -> data = x;
		tmp -> next = p -> next;
		p -> next = tmp;
		return *this;
	}
}

template<typename T>
void List<T>::output(ostream& os) const
{
	Node<T> *tmp;
	for(tmp = head; tmp; tmp = tmp -> next)
		os << tmp -> data << " ";
}

template<typename T>
ostream& List<T>::operator <<(ostream& os, const List<T> l)
{
	x.output(os);
	return os;
}