#include <iostream>
#include <string>
using namespace std;

class Stu
{
public:
	Stu(string s, int n);
	string name;
	int score;
	int key;
};

Stu::Stu(string s, int n)
{
	name = s;
	score = n;
	key = s[0] * 2 + s[1] * 3;
}

template<typename T>
class Hash
{
public:
	Hash(int divisor);
	~Hash();
	bool search(T &t, const int& k) const;
	bool insert(const T& t);
private:
	T *ht;//hash table
	bool *empty;//label
	int d;//divisor
	int hSearch(const T& t) const;
};

Hash::Hash(int divisor)
{
	d = divisor;
	ht = new T[d];
	empty = new bool[d];
}

Hash::~Hash()
{
	delete []ht;
	delete []empty;
}

int Hash::hSearch(const int& k) const
{
	int beg = k % d;
	int index = beg;
	while(index != beg)
	{
		if(empty[index] || ht[index].key == k)
			return index;
		index = (index + 1) % d;
	}
	return index;
}

bool Hash::search(T &t, const int& k) const
{
	int b = hSearch(k);
	if(ht[b].key != b || empty[b])
		return false;
	t = ht[b];
	return true;
}

bool Hash::insert(const T& t)
{
	int k = t.key;
	int pos = hSearch(k);
	if(empty[pos])
	{
		ht[pos] = t;
		empty[pos] = false;
		return true;
	}
	else
		return false;
}