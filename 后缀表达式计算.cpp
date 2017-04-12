#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

template<typename T>
class SqStack
{
public:
    SqStack();//constructor of SqStack
    ~SqStack();//destructor of SqStack
    bool isEmpty() const;//judge if the stack is empty
    T getTop();//return the top value
    SqStack<T>& push(const T& x);//add an element to the top of stack
    SqStack<T>& pop();//delete the top element of a stack
private:
    T *stack;//an array pointer of the stack, pointing to the top element
    int top;//the top element's index
};

template<typename T>
SqStack<T>::SqStack()
{
    top = 0;
    stack = new T[1001];
}

template<typename T>
SqStack<T>::~SqStack()
{
    delete []stack;
}

template<typename T>
bool SqStack<T>::isEmpty() const
{
    return top == 0;
}

template<typename T>
T SqStack<T>::getTop()
{
    return stack[top - 1];
}

template<typename T>
SqStack<T>& SqStack<T>::push(const T& x)
{
    if(top <= 1001)
        stack[top++] = x;
    return *this;
}

template<typename T>
SqStack<T>& SqStack<T>::pop()
{
    stack[top--];
    return *this;
}

class Operations
{
public:

};
int main()
{
    SqStack<double> dsta;
	char s[1000];
	while(cin.get(s, 1001, '\n'))
	{
		string str(s);
		double op1, op2;
		bool flag = true;
		for(string::size_type i = 0; i < str.length(); i++)
		{
			
			if(str[i] == '+')
			{
				op1 = dsta.getTop();
				dsta.pop();
				op2 = dsta.getTop();
				dsta.pop();
				dsta.push(op2 + op1);
			}
			else if(str[i] == '-')
			{
				op1 = dsta.getTop();
				dsta.pop();
				op2 = dsta.getTop();
				dsta.pop();
				dsta.push(op2 - op1);
			}
			else if(str[i] == '*')
			{
				op1 = dsta.getTop();
				dsta.pop();
				op2 = dsta.getTop();
				dsta.pop();
				dsta.push(op2 * op1);
			}
			else if(str[i] == '/')
			{
				op1 = dsta.getTop();
				dsta.pop();
				op2 = dsta.getTop();
				dsta.pop();
				if(op1 == 0.0) dsta.push(op2 / op1);
				else 
				{
					cout << "runtime error!" << endl;
					flag = false;
				}
			}
			else if(str[i] == ' ') 
				continue;
			else 
				dsta.push(str[i] - '0');
		}
		if(flag && !dsta.isEmpty())
			cout << dsta.getTop() << endl;
		system("pause");
	}
    return 0;
}