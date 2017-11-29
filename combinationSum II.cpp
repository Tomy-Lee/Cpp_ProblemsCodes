/*Given a set of candidate numbers (C) (without duplicates) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [2, 3, 6, 7] and target 7, 
A solution set is: 
[
  [7],
  [2, 2, 3]
]*/

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
   vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > result;
        vector<int> path;
        sort(candidates.begin(),candidates.end());
        helper(candidates,0,0,target,path,result);
        return result;
    }

    void helper(vector<int> &nums,int pos,int base,int target,vector<int>& path,vector<vector<int> > & result)
    {
        if(base==target)
        {
            result.push_back(path);
            return ;
        }
        if(base>target)
            return ;
        for(int i=pos;i<nums.size();i++)
        {
            path.push_back(nums[i]);
            helper(nums,i,base+nums[i],target,path,result);
            path.pop_back();
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
    vector<vector<int> > result=solution.combinationSum(nums, target);
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