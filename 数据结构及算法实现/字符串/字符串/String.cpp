#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

class String
{
public:
	String();
	~String();
	String(const String& copy);
	String(const char *copy);
	void operator =(const String& copy);
	const char *c_str() const;
private:
	char *string;
	int length;
};

String::String()
{
	string = new char[100];
	length = 0;
}

String::~String()
{
	delete [] string;
}

String::String(const String &copy)
{
	length = strlen(copy.c_str());
	string = new char[length + 1];
	char *tmp = string;
	for(int i = 0; i <= length; i++, tmp++)
	{
		char c = copy.c_str()[i];
		*tmp = c;
	}
}

String::String(const char *copy)
{
	length = strlen(copy);
	string = new char[length + 1];
	strcpy(string, copy);
}

void String::operator =(const String &copy)
{
	length = strlen(copy.c_str());
	string = new char[length + 1];
	char *tmp = string;
	for(int i = 0; i <= length; i++, tmp++)
	{
		char c = copy.c_str()[i];
		*tmp = c;
	}
}

const char *String::c_str() const
{
	return (const char*) string;
}

int main()
{
	String s("hello world");
	String s2;
	s2 = s;
	cout << s2.c_str() << endl;

	char *p = "helloworld";
	String s3(p);

	cout << s3.c_str() << endl;
	system("pause");
	return 0;
}