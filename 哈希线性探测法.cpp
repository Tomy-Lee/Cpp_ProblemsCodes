/* 使用线性探测法(Linear Probing)可以解决哈希中的冲突问题，其基本思想是：设哈希函数为h(key) = d, 并且假定哈希的存储结构是循环数组, 则当冲突发生时, 继续探测d+1, d+2…, 直到冲突得到解决. 
输入格式
 仅有一个测试用例, 第1行为整数n与m（1 <= n, m <= 10000）， n代表key的总数, m代表哈希表的长度, 并且令哈希函数为: Hash(key) = key mod m.

接下来n行，每行一个整数，代表一个key。Key与key两两不相同 ( 0 <= key <= 10, 000)。

输出格式
 输出建立好的hash表，比如下表

样例输入
 将样例输入复制到剪贴板 
3 5
1
5
6
样例输出
0#5
1#1
2#6
3#NULL
4#NULL
*/
#include <iostream>
using namespace std;

int a[10005];

void insert(int val, int m) {
    int pos = val % m;
    while (a[pos] != -1) {
        ++pos;
        pos %= m;
    }
    a[pos] = val;
}

int main(int argc, char const *argv[])
{
    int n, m, input;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) a[i] = -1;
    while (n--) {
        int input;
        cin >> input;
        insert(input, m);
    }
    for (int i = 0; i < m; ++i) {
        cout << i << "#";
        if (a[i] != -1) {
            cout << a[i] << endl;
        } else {
            cout << "NULL" << endl;
        }
    }
    return 0;
}                                 


