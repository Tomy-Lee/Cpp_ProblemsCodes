/*Sample Input:
3
CS301111 15:30:28 17:00:10
SC3021234 08:00:00 11:25:25
CS301133 21:45:00 21:58:40
Sample Output:
SC3021234 CS301133

��Ŀ���⣺����n���˵�id��sign inʱ�䡢sign outʱ�䣬������������˺������ȥ���˵�ID��

��������ʱ�䶼ת��Ϊ���������������ٵ�ʱ�䱣���ڱ���minn��maxn�У���ͬʱ���浱ǰ�������ٵ��˵�ID����������*/ 
#include <iostream>
#include <cstdio>
#include <limits.h>
using namespace std;
int main() {
    int n, minn = INT_MAX, maxn = INT_MIN;
    scanf("%d", &n);
    string unlocked, locked;
    for(int i = 0; i < n; i++) {
        string t;
        cin >> t;
        int h1, m1, s1, h2, m2, s2;
        scanf("%d:%d:%d %d:%d:%d", &h1, &m1, &s1, &h2, &m2, &s2);
        int tempIn = h1 * 3600 + m1 * 60 + s1;
        int tempOut = h2 * 3600 + m2 * 60 + s2;
        if (tempIn < minn) {
            minn = tempIn;
            unlocked = t;
        }
        if (tempOut > maxn) {
            maxn = tempOut;
            locked = t;
        }
    }
    cout << unlocked << " " << locked;
    return 0;
}
