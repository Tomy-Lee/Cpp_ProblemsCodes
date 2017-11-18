# include <iostream>
# include <vector>
# include <list>
using namespace std;

class Solution {
public:

  vector<bool> visited;
  vector< list<int> > adja_list;
  int order;
  vector<int> ret;
  
  vector<int> topologicalSort(int n, vector<pair<int, int>>& edges) {
    ret = vector<int>(n, 0);
    this->visited = vector<bool>(n, false);
    this->adja_list = vector< list<int> >(n, list<int>());
    this->order = n - 1;
    
    int e = edges.size();
    for(int i = 0; i < e; i++)
      adja_list[edges[i].first].push_back(edges[i].second);

    bool update = true;
    while(update) {
      update = false;
      for(int i = 0; i < n; i++) if(visited[i] == false) {
          update = true;
          this->dfs(i);
        }
    }

    return ret;
  }

  void dfs(int n) {
    this->visited[n] = true;
    
    list<int>::iterator it;
    for(it = adja_list[n].begin(); it != this->adja_list[n].end(); it++)
      if(this->visited[*it] == false)
        dfs(*it);

    this->ret[this->order--] = n;
  }
};

int main() {
  
}
