/*Sample Input:
10
-10 1 2 3 4 -5 -23 3 7 -21
Sample Output:
10 1 4
��Ŀ���⣺��������������кͣ�������ĺ��Լ���������еĿ�ʼֵ�ͽ���ֵ�������������С��0����ô��Ϊ���ĺ�Ϊ0�����������βԪ�ء�
������sumΪҪ������ͣ�tempΪ��ʱ���ͣ�left��rightΪ����������е��±꣬tempindex���left����ʱ�±ꡣ
temp = temp + v[i]����temp��sum�󣬾͸���sum��ֵ��left��right��ֵ����temp < 0����ô���治����ʲôֵ����Ӧ������temp < 0ǰ������ݣ�
��Ϊ���������ܺ�ֻ���������ܺͣ������������ܺͣ�������������
������ֱ����temp = 0������ͬʱ����left����ʱֵtempindex����Ϊ�������е�ֵ��Ϊ���������Ҫ���0����һ��ֵ�����һ��ֵ��
�����������ʱ����flag�ж��ǲ������е����ֶ���С��0�ģ�����ǣ�Ҫ�������ʱ�����⴦��*/
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
