//��������n�������ֽܷ�ɵ����е���k����ͬ���ֵ���ϴ�ӡ����������k=2, n=6: [1, 5][2,4] 
//������Ҫ�ǱȽ�һ�ַǵݹ鷽������Solotion1�У���ѭ���ݹ鷽������Solution�У������ܲ��졣 
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<time.h>

using namespace std; 

class Solution {
public:
    vector<vector<int> > combinationSum3(int k, int n) {
        vector<vector<int> > result;
        vector<int> num;
        help(k, n, 1, num, result);
        return result;
    }
    void help(int k, int n, int level, vector<int> &num, vector<vector<int> > &result){
        if(n < 0) return;
        if(n == 0 && num.size() == k) result.push_back(num);
        for(int i=level;i<=30;++i){
            num.push_back(i);
            help(k, n-i, i+1, num, result);
            num.pop_back();
        }
    }
};


class Solution1 {
public:
    vector<vector<int> > combinationSum3(int k, int n) {
        vector<vector<int> > ret;
        vector<int> path(k);
        int i = 0;
        int curSum = 0;
        
        while(i!=-1){
            path[i]++;
            curSum++;
            if(path[i]>30 || curSum > n || (i!=k-1 && curSum+path[i] >= n) ){
                curSum -= path[i];
                i--;
            }else if(i == k-1){
                if(curSum == n) ret.push_back(path);
            }else if(curSum+path[i] < n){
                path[i+1] = path[i];
                curSum += path[i];
                i++;
            }
        }
        return ret;
    }
};


int main(){
    int k, n;
    cout<<"������ k �� n ��";
    cin>>k>>n;
    clock_t start_time=clock();
    Solution1 solution;
    vector<vector<int> > result = solution.combinationSum3(k, n);
    clock_t end_time=clock();
    int size = result.size();
    for(int i=0;i<size;i++){
        int size1=result[i].size();
        cout<<"[";
        int j;
        for(j=0;j<size1-1;j++){
            cout<<result[i][j]<<", ";
        }
        cout<<result[i][j]<<"]"<<endl;
    } 
    
    cout<< "Running time is: "<<static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000<<"ms"<<endl;
    return 0;
}
