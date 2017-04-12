#include <iostream>
#include <cstdlib>
using namespace std;
enum Error_code{overflow, underflow, success};

template<typename T>
class Queue
{
public:
	Queue();
	Queue(int size);
	~Queue();
	bool isEmpty() const;
	bool isFull() const;
	int size() const;
	void clear();
	Error_code append(const T& x);
	Error_code serve();
	Error_code retrieve(T& x) const;
	Error_code serve_and_retrieve(T& x);
private:
	int maxSize;
	int front;
	int rear;
	T *queue;
};

template<typename T>
Queue<T>::Queue()
{
	maxSize = 1000;
	front = rear = 0;
	queue = new T[maxSize];
}

template<typename T>
Queue<T>::Queue(int size)
{
	maxSize = size;
	front = rear = 0;
	queue = new T[maxSize];
}

template<typename T>
Queue<T>::~Queue()
{
	front = rear = 0;
	delete []queue;
}

template<typename T>
bool Queue<T>::isEmpty() const
{
	return front == rear;
}

template<typename T>
bool Queue<T>::isFull() const
{
	return (rear + 1) % maxSize == front;

template<typename T>
int Queue<T>::size() const
{
	return (rear - front) % maxSize;
}

template<typename T>
void Queue<T>::clear()
{
	front = rear = 0;
	delete []queue;
}
template<typename T>
Error_code Queue<T>::append(const T &x)
{
	if(isFull()) return overflow;
	else
	{
		rear = (rear + 1) % maxSize;
		queue[rear] = x;
	}
	return success;
}

template<typename T>
Error_code Queue<T>::serve()
{
	if(isEmpty()) return underflow;
	else
	{
		front = (front + 1) % maxSize;
	}
	return success;
}
template<typename T>
Error_code Queue<T>::retrieve(T &x) const
{
	if(isEmpty()) return underflow;
	else
	{
		x = queue[(front + 1) % maxSize];
		return success;
	}
}

template<typename T>
Error_code Queue<T>::serve_and_retrieve(T& x)
{
	if(isEmpty()) return underflow;
	else
	{
		front = (front + 1) % maxSize;
		x = queue[front];
		return success;
	}
}

int main() {	
	Queue<char> cq2(10);
	for(int i = 97; i < 110; i++)
		cq2.append(i);
	for(int i = 0; i < 13; i++)
	{
		char c;
		if(cq2.serve_and_retrieve(c) == success)
			cout << c << "  ";
	}
	cout << endl;
	Queue<int> iq(10);
	for(int i = 1; i < 10; i++)
		iq.append(i);
	iq.clear();
	int tmp;
	iq.retrieve(tmp);
	cout << tmp << endl;
	cout << iq.isEmpty() << endl;
	system("pause");
	return 0;
}
