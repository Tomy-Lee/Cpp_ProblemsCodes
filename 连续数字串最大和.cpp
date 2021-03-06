/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
For example, given the array [-2,1,-3,4,-1,2,1,-5,4],

the contiguous subarray [4,-1,2,1] has the largest sum = 6.*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() < 1) return 0;
        int i, sum = 0;
        int max = nums[0];
        for (i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (sum > max) max = sum;
            if (sum < 0) sum = 0;
        }
        return max;
    }
};



/*首先，题目需要两个变量记录和，一个叫做 sum，更像是一个中间变量，另一个是 max，用于记录已知出现的最大的子序列的和。

明确这一点：最大子序列首和尾必定不可能是和为负数的子序列，因为去掉首尾依然是子序列，且和一定比加上负数首尾的子序列的和要大。

算法主体：

一次遍历，sum 负责从 0 开始加每一个数字，一旦 sum < 0，因为上述原因，这个子序列必定会被淘汰，所以需要重置 sum 为 0。

max 从 0 开始不断和 sum 比较，一旦 sum > max，更新 max 的值。*/