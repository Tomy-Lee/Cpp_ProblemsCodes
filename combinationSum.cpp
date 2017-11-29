/*问题描述 
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T. 
Each number in C may only be used once in the combination. 
Note: 
All numbers (including target) will be positive integers. 
The solution set must not contain duplicate combinations. 
For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8, 
A solution set is:

[ 
[1, 7], 
[1, 2, 5], 
[2, 6], 
[1, 1, 6] 
]*/

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > ret;
        vector<int> cur;
        Helper(ret, cur, candidates, target, 0);
        return ret;
    }
    void Helper(vector<vector<int> > &ret, vector<int> cur, vector<int> &candidates, int target, int position){
        if(target == 0)
            ret.push_back(cur);
        else{
            for(int i = position; i < candidates.size() &&candidates[i] <= target; i ++){
                if(i != position && candidates[i] == candidates[i-1])
                    continue;
                cur.push_back(candidates[i]);
                Helper(ret, cur, candidates, target-candidates[i], i+1);
                cur.pop_back();
            }
        }
    }

};

int main(){
    int n; 
    cout<<"请输入向量长度："; 
    cin>>n;
    vector<int> nums;
    int a;
    for(int i=0;i<n;i++){
        cin>>a;
        nums.push_back(a);
    }
    int target;
    cout<<"请输入target:";
    cin>>target;
    Solution solution;
    vector<vector<int> > result=solution.combinationSum2(nums, target);
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
} 