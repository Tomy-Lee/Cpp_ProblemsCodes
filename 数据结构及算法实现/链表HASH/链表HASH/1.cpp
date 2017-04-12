// sicily1818为例子
#include <list>
#include <string>
#include <iostream>
using namespace std;

typedef string Key;
const int TableSize = 10007;

struct Record
{
    string name;
    int score;
    operator Key() const {return name;} //隐式类型转换
};

ostream &operator<<(ostream &out, const Record &item)
{
    if(item.score > 100 || item.score < 0)
        cout << "Score is error!";
    else if(item.score <= 59)
        cout << "E";
    else if(item.score <= 69)
        cout << "D";
    else if(item.score <= 79)
        cout << "C";
    else if(item.score <= 89)
        cout << "B";
    else 
        cout << "A";
    
    return out;
}

class HashTable
{
public:
    HashTable();
    int hash(const Key &item) const;
    void insert(const Record &item);
    void retrieve(const Key &target, Record &item) const;

private:
    list<Record> table[TableSize];          //使用分离链接法处理冲突
};

HashTable::HashTable()
{
}

//一个比较好的散列函数
int HashTable::hash(const Key &item) const
{
    unsigned int hashVal = 0;

    for(int i = 0; i < item.length(); i++)
        hashVal = (hashVal << 5) + (unsigned int)item[i];
    return hashVal % TableSize;
}

void HashTable::insert(const Record &item)
{
    int idx = hash(item);

    table[idx].push_front(item);
}

void HashTable::retrieve(const Key &target, Record &item) const
{
    int idx = hash(target);

    for(list<Record>::const_iterator it = table[idx].begin(); it != table[idx].end(); it++)
        if((Key)(*it) == target)
        {
            item = *it;
            return ;
        }
}
int main()
{
    int test;
    cin >> test;

    while(test--)
    {
        HashTable h;
        int n, m;
        Record tmp;
        Key name;
        cin >> n >> m;

        for(int i = 0; i < n; i++)
        {
            cin >> tmp.name >> tmp.score;
            h.insert(tmp);
        }

        for(int i = 0; i < m; i++)
        {
            cin >> name;
            h.retrieve(name, tmp);

            cout << tmp << endl;
        }
    }

    return 0;
}
