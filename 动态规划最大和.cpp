/*Sample Input:
10
-10 1 2 3 4 -5 -23 3 7 -21
Sample Output:
10 1 4
题目大意：求最大连续子序列和，输出最大的和以及这个子序列的开始值和结束值。如果所有数都小于0，那么认为最大的和为0，并且输出首尾元素。
分析：sum为要求的最大和，temp为临时最大和，left和right为所求的子序列的下标，tempindex标记left的临时下标。
temp = temp + v[i]，当temp比sum大，就更新sum的值、left和right的值；当temp < 0，那么后面不管来什么值，都应该舍弃temp < 0前面的内容，
因为负数对于总和只可能拉低总和，不可能增加总和，还不如舍弃；
舍弃后，直接令temp = 0，并且同时更新left的临时值tempindex。因为对于所有的值都为负数的情况要输出0，第一个值，最后一个值，
所以在输入的时候用flag判断是不是所有的数字都是小于0的，如果是，要在输入的时候特殊处理。*/
#include <cstdio>
#include <vector>
using namespace std;
int main() {
    int n, flag = 0, sum = -1, temp = 0, left = 0, right = 0, tempindex = 0;
    scanf("%d", &n);
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
        if(v[i] >= 0)
            flag = 1;
        temp = temp + v[i];
        if(temp > sum) {
            sum = temp;
            left = tempindex;
            right = i;
        } else if(temp < 0) {
            temp = 0;
            tempindex = i + 1;
        }
    }
    if(flag == 0)
        printf("0 %d %d", v[0], v[n - 1]);
    else
        printf("%d %d %d", sum, v[left], v[right]);
    return 0;
}
