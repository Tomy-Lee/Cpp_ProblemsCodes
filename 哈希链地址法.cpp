/*请用HASH链式法来解决冲突，且规定链表在链表头插入新元素。

规定HASH函数为：h(x) = x % 11，即哈希数组下标为0～10.

给定两种操作：

I 操作，插入一个新的正整数K到哈希表中

F 操作，查询整数K是否在哈希表中，若不在，输出-1；若存在，输出目前K在所在链表中的顺序索引（假定链表头索引为0）。

输入格式
 一组数据。

第一行为整数N，0 < N <= 10000。

接下来N行为随机出现的I操作或F操作。(数据保证K不会重复，K为大于0的int类型)

输出格式
 对于每行F操作，按顺序输出结果。


样例输入
 将样例输入复制到剪贴板 
6
F 10
I 10
I 21
F 10
I 32
F 10

样例输出
-1
1
2
*/ 
#include <iostream>
#include <list>
using namespace std;
list<int> a[11];

void insert(int num) {
    int pos = num % 11;
    a[pos].push_front(num);
}

int find(int num) {
    int pos = num % 11;
    list<int>::iterator now = a[pos].begin();
    int i = 0;
    for (; now != a[pos].end(); ++now, ++i) {
        if (*now == num) return i;
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    while (n--) {
        char input;
        int nu;
        cin >> input >> nu;
        if (input == 'I') {
            insert(nu);
        } else if (input == 'F') {
            cout << find(nu) << endl;
        }
    }
    return 0;
}                                 

