#include <iostream>
#include <cstdlib>
using namespace std;
enum Error_code{overFlow, underFlow, success};

template<typename T>
class List
{
public:
	List();//default constructor
	List(int size);//constructor with initial size
	~List();//destructor
	int size() const;//get the max size
	bool isFull() const;//judge the list condition
	bool isEmpty() const;//the as the above
	void clear();//delete all the array
	void traverse(void(*visit)(T& x));
	Error_code retrieve(const int position, T& x) const;
	Error_code replace(const int position, const T& x);
	Error_code remove(const int position, T& x);
	Error_code insert(const int position, const T& x);
private:
	T *list;
	int length;
	int maxSize;
};

template<typename T>
List<T>::List()
{
	length = 0;
	list = new T[maxSize = 10];
}

template<typename T>
List<T>::List(const int size)
{
	maxSize = size;
	list = new T[maxSize];
	length = 0;
}

template<typename T>
List<T>::~List()
{
	delete [] list;
	length = 0;
}

template<typename T>
int List<T>::size() const
{
	return length;
}

template<typename T>
bool List<T>::isFull() const
{
	return length == maxSize;
}

template<typename T>
bool List<T>::isEmpty() const
{
	return length == 0;
}

template<typename T>
void List<T>::clear()
{
	delete [] list;
	length = 0;
}

template<typename T>
void List<T>::traverse(void (*visit)(T & x))
{
	for(int i = 0; i < length; i++)
		(*visit)(list[i]);
}

void add(int& x)
{x++;}

template<typename T>
Error_code List<T>::retrieve(const int position, T& x) const
{
	if(isEmpty()) return underFlow;
	else if(position < 0 || position >= maxSize ) return overFlow;
	else 
	{
		x = list[position - 1];
		return success;
	}
}

template<typename T>
Error_code List<T>::replace(const int position, const T &x)
{
	if(isEmpty()) return underFlow;
	else if(position < 0 || position >= maxSize ) return overFlow;
	else 
	{
		list[position - 1] = x;
		return success;
	}
}

template<typename T>
Error_code List<T>::remove(const int position, T &x)
{
	if(isEmpty()) return underFlow;
	else if(position < 0 || position >= maxSize ) return overFlow;
	else
	{
		x = list[position - 1];
		for(int i = position; i <= length; i++)
			list[i - 1] = list[i];
		length--;
		return success;
	}
}

template<typename T>
Error_code List<T>::insert(const int position, const T &x)
{
	if(isFull()) return overFlow;
	else if(position < 0 || position >= maxSize ) return overFlow;
	else
	{
		for(int i = length - 1; i >= position; i--)
			list[i + 1] = list[i];
		list[position] = x;
		length++;
		return success;
	}
}

void main()
{
	void add(int& x);
	List<int> l(10);
	for(int i = 0; i < 10; i++)
	{
		l.insert(i, i);
		//cout << l.size() << endl;//actually the 20th time loop, the array is full, 19 cannot be push in
	}
	int tmp = l.size() - 1;
	for(int i = tmp; i >= 0; i--)
	{
		l.retrieve(i + 1, tmp);
		cout << tmp << endl;
	}
	void (*visit)(int& x);
	visit = add;
	l.traverse(visit);
	tmp = l.size() - 1;
	for(int i = tmp; i >= 0; i--)
	{
		l.retrieve(i + 1, tmp);
		cout << tmp << endl;
	}
	system("pause");
}