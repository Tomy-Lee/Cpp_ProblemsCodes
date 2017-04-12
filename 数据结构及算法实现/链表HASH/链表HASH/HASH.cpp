#include <iostream>
#include <string>
#include <list>
using namespace std;

#define SIZE 10007
struct Stu
{
	string name;
	int sco;
};

class Hash
{
public:
	Hash();
	Hash& insert(const Stu& stu);
	Hash& erase(const string& key);
	Stu& search(const string& key, Stu& get) const;
private:
	list<Stu> stul[SIZE];
	int hash(const string& key) const;
};
Hash::Hash()
{
}

Hash& Hash::insert(const Stu &stu)
{
	int index = hash(stu.name);
	stul[index].push_back(stu);
	return *this;
}

Hash& Hash::erase(const string& key)
{
	int index = hash(key);
	for(list<Stu>::iterator iter = stul[index].begin(); iter != stul[index].end(); iter++)
		if(iter -> name == key)
			stul[index].erase(iter);
	return *this;
}

int Hash::hash(const std::string &key) const
{
	unsigned int hashVal = 0;
    for(int i = 0; i < key.length(); i++)
        hashVal = (hashVal << 5) + (unsigned int)key[i];
    return hashVal % SIZE;
}