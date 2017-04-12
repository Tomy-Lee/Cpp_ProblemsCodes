#include <iostream>
#define maxq 10
#define f(x) (x+1)%(maxq-1)
using namespace std;

typedef int Queue_entry;

enum Error_code { success, overflow, underflow };

class Queue {
	public:
		Queue();
		bool empty() const;
		Error_code serve();
		Error_code append(const Queue_entry &item);
		Error_code retrieve(Queue_entry &item) const;
	protected:
		int count;
		int front,rear;
		Queue_entry entry[maxq];	
};
Queue::Queue() {
	count = 0;
	front = 0;
	rear = maxq-1;
}
bool Queue::empty() const {
	return (count == 0);
}
Error_code Queue::serve() {
	if(count <= 0) return underflow;
	count--;
	front = f(front);
	return success;
}
Error_code Queue::append(const Queue_entry &item) {
	if(count >= maxq) return overflow;
	count++;
	rear = f(rear);
	entry[rear] = item;
	return success;
}
Error_code Queue::retrieve(Queue_entry &item) const{
	if(count <= 0) return underflow;
	item = entry[front];
	return success;
}
int main(){
	cout<<"this is the queque"<<endl;
	return 0;
}
