/*由于无敌的凡凡在2005年世界英俊帅气男总决选中胜出，Yali Company总经理Mr.Z心情好，决定给每位员工发奖金。公司决定以每个人本
年在公司的贡献为标准来计算他们得到奖金的多少。
于是Mr.Z下令召开m方会谈。每位参加会谈的代表提出了自己的意见：“我认为员工a的奖金应该比b高！”Mr.Z决定要找出一种奖金方案，
满足各位代表的意见，且同时使得总奖金数最少。每位员工奖金最少为100元。

【数据范围】
数据满足n<=10000，m<=20000。


输入格式
    第一行两个整数n,m，表示员工总数和代表数；
    以下m行，每行2个整数a,b，表示某个代表认为第a号员工奖金应该比第b号员工高。 

输出格式
    若无法找到合法方案，则输出“Poor Xed”；否则输出一个数表示最少总奖金。

样例输入
2 1
1 2
样例输出
201*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int outdegree[10010];
vector<int> father[10010];
int bonus[10010];

int max(int a, int b) {
    return a > b? a: b;
}

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
	    bonus[i] = 100;
    int a, b;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        outdegree[a]++;
        father[b].push_back(a);
    }
    queue<int> q;
    for(int i = 1; i <= n; i++)
        if(outdegree[i] == 0 && !father[i].empty())
            q.push(i);
    while(!q.empty()) {
        int k = q.front();
        q.pop();
        for(vector<int>::iterator it = father[k].begin(); it != father[k].end(); ++it)
        {
            outdegree[*it]--;
            bonus[*it] = max(bonus[*it], bonus[k] + 1);
            if(outdegree[*it] == 0)
                q.push(*it);
        }
    }
    
    bool flag = true;
    for(int i = 1; i <= n; i++)
        if(outdegree[i] != 0) {
            flag = false;
            cout << "Poor Xed\n";
            break;
        }
    if(flag) {
        int sum = 0;
        for(int i = 1; i <= n; i++)
            sum += bonus[i];
        cout << sum << "\n";
    }
    
    return 0;
}          
