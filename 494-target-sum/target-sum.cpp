class Solution {
public:
    int func(vector<int>nums, int ind, int target, vector<unordered_map<int,int>>&dp){
        if(ind==0){
            if(target==nums[0] && nums[0]==0) return 2;
            if(target==nums[0] || target == -nums[0]) return 1;
            else return 0;
        }
        if(dp[ind].find(target) != dp[ind].end()) return dp[ind][target]; //negetive values of target cant be stored
        int positive = func(nums,ind-1,target-nums[ind],dp);
        int negative = func(nums, ind-1, target+nums[ind],dp);

        return dp[ind][target]=positive + negative;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<unordered_map<int,int>>dp(n);
        return func(nums,n-1,target,dp);
    }
};