/* 给定一个数列，用选择排序进行从小到大的排序, 并输出在排序过程中的比较次数。

输入格式
 多组数据。对于每组数据： 第一行为整数 N， 0 < N <= 1000 。

第二行为N个无序整数。

输出格式
 对于每组数据输出一行，每行一个整数，为对该序列进行选择排序的比较次数。


样例输入
 将样例输入复制到剪贴板 
5
5 2 1 3 4
4
5 6 1 2
8
1 5 4 7 2 6 3 8

样例输出
10
6
28
*/
#include <iostream>
#include <cstdio>
using namespace std;

int a[1005];
int main(int argc, char const *argv[])
{
    int N, min, index, flag, sum = 0;
    while (scanf("%d", &N) != EOF) {
        sum = 0;
        for (int i = 0; i < N; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < N; ++i) {
            min = a[i];
            for (int j = i + 1; j < N; ++j) {
                if (a[j] < min) {
                    min = a[j];
                    index = j;
                }
            }
            sum += (N - i - 1);
            flag = a[i];
            a[i] = a[index];
            a[index] = flag;
        }
        cout << sum << endl;
    }
    return 0;
}                               

