/*贝爷的人生乐趣之一就是约战马会长. 他知道马会长喜欢和怪兽对决，于是他训练了N只怪兽，并对怪兽用0到N-1的整数进行编号.
 贝爷训练怪兽的方式是让它们一对一互殴. 两只怪兽互殴会发生以下三种可能的结果：
1） 什么事也没发生
2） 第一只怪兽永远消失
3） 第二只怪兽永远消失
怪兽们经过了旷日持久的互殴. 贝爷不知道哪些怪兽进行了互殴也不知道它们互殴的顺序，但他确信无论经过多少次互殴，总有一些怪兽能存活下来，
他将要派这些怪兽去和马会长对决. 现在他想知道至少有多少只怪兽能存活下来，你能帮他算出来吗？
 
请实现下面Solution类中的minLeftMonsters函数，完成上述功能.
参数G: N*N（1 <= N <= 50）字符矩阵，G[i][j]表示怪兽i和怪兽j互殴会发生的结果. 字符‘+’代表怪兽i会消失，’-’代表怪兽j会消失，
数字’0’则代表什么都没发生. 输入保证G[i][i]一定是’0’，而且G[i][j]和G[j][i]一定相反（’-’和’+’互为相反，’0’和自身相反）.
返回值：怪兽存活的最少数目.
 
class Solution {
public:
       int minLeftMonsters(vector<vector<char>> G) {
      
  }
};
 
例1：
G =
0+-
-0+
+-0
返回1.
 
例2：
000
000
000
返回3.
*/
# include <iostream>
# include <vector>
# include <string>
# include <cstring>
# include <list>

using namespace std;

class Solution {
public:
  vector< list<int> > adja_list, adja_list_r; // graph and re_graph
  vector<int> post_time, pre_time;
  vector<int> visited;
  int cur_time;
  
  int minLeftMonsters(vector<vector<char> > G) {
    int size = G.size();
    if(size <= 1) return 1;
    if(size == 2) return G[0][1] == '0' ? 2 : 1;

    // initital
    adja_list = vector< list<int> >(size, list<int>());
    adja_list_r = vector< list<int> >(size, list<int>());
    cur_time = 0;
    post_time = vector<int>(size, -1);
    pre_time = vector<int>(size, -1);
    visited = vector<int>(size, -1);
    for(int i = 0; i < size; i++)
      for(int j = 0; j < size; j++) {
        if(G[i][j] == '+') {
          this->adja_list[i].push_back(j);
          this->adja_list_r[j].push_back(i);
        } else if(G[i][j] == '-') {
          this->adja_list[j].push_back(i);
          this->adja_list_r[i].push_back(j);
        }
      }
    
    // dfs graph_r
    bool update = true;
    while(update) {
      update = false;
      for(int i = 0; i < size; i++) {
        if(this->pre_time[i] == -1) dfs_reverse(i);
      }
    }

    update = true;
    int s_n, max_post = 0;
    int ret = 0, scc_index = 1;

    while(update) {
      update = false;
      s_n = -1;
      max_post = -1;
      
      for(int i = 0; i < size; i++) {
        if(this->visited[i] == -1 && max_post <= this->post_time[i]) {
          update = true;
          max_post = this->post_time[i];
          s_n = i;
        }
      }
      if(update) {
        scc_index++;
        ret += this->dfs(s_n, scc_index);
      }
    }

    return ret;
    
  }

  // dfs on graph_r
  void dfs_reverse(int n) {
    this->cur_time++;
    this->pre_time[n] = this->cur_time;
    list<int>::iterator it;
    for(it = adja_list_r[n].begin(); it != adja_list_r[n].end(); it++) {
      if(this->pre_time[*it] == -1) this->dfs_reverse(*it);
    }
    this->cur_time++;
    this->post_time[n] = this->cur_time;
  }

  // belong to k-th strong-connective-component
  // return 1 if it is a sink component; else return 0
  int dfs(int n, int k) {
    int ret = 1;
    this->visited[n] = k;
    list<int>::iterator it;
    for(it = adja_list[n].begin(); it != adja_list[n].end(); it++) {
      if(this->visited[*it] == -1) {
        if(this->dfs(*it, k) == 0)
          ret = 0;
      } else if(this->visited[*it] < k) ret = 0; // has edge point to the front scc
    }
    return ret;
  }
};


int main() {
  char a[3][3] = {
    '0', '+', '-',
    '-', '0', '+',
    '+', '-', '0'
  };

  vector< vector<char> > g;
  for(int i = 0; i < 3; i++) {
    vector<char> gg;
    for(int j = 0; j < 3; j++) gg.push_back(a[i][j]);
    g.push_back(gg);
  }

  Solution so;
  cout << so.minLeftMonsters(g) << endl;
  return 0;
}
