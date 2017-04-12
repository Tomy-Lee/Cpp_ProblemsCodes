/*给定一个二叉查找树，要求计算其高度，每个二叉查找树将给出先序与中序的遍历。

例如：一个二叉查找树其先序遍历为：16, 10, 4, 15, 23 ; 中序遍历为 4, 10, 15, 16, 23，则其高度为2（假定空树高度为-1，只有根节点的数高度为0）

输入格式
第一行输入测试用例个数。

对于每个测试用例，

第一行是节点个数n，第二行是key值的先序遍历，第三行是key值的中序遍历
输出格式
对于每个测试用例，用一行输出树的高度

样例输入
 将样例输入复制到剪贴板 
2
3
4 5 6
4 5 6
5
6 4 8 9 10
4 6 8 9 10


样例输出
2
3*/ 
#include <iostream>
using namespace std;
int a[10000000];
int b[10000000];
bool c[10000000];

int FindPos(int start, int n, int val) {
    for (int i = start; i < n; ++i) {
        if (b[i] == val && c[i] == false) {
            c[i] = true;
            return i;
        }
    }
    return -1;
}

int Max(int a, int b) {
    return (a > b ? a : b);
}

int divided(int l, int r, int step, int pos, int n) {
    if (r - l == 1) return step;
    if (r - l == 0) return step - 1;
    int m = FindPos(l, r, a[pos]);
    while (m == -1) {
        ++pos;
        m = FindPos(l, r, a[pos]);
    }
    return Max(divided(l, m, step + 1, pos + 1, n), divided(m + 1, r, step + 1, pos + 1, n));
}

int main(int argc, char const *argv[])
{
    int total;
    cin >> total;
    while (total--) {
        int n, height = 0, pos;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            c[i] = false;
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        cout << divided(0, n, 0, 0, n) << endl;
    }
    return 0;
}                                 

