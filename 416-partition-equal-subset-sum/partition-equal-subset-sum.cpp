class Solution {
public:
    bool func(vector<int>& nums, int ind, int currSum, int total, vector<vector<int>>&dp){
        if(ind>=nums.size()) return false;
        if(currSum == total-currSum) return true;

        if(dp[ind][currSum]!=-1) return dp[ind][currSum];

        bool pick = func(nums,ind+1,currSum+nums[ind], total,dp);
        bool notPick = func(nums,ind+1,currSum, total,dp);

        return dp[ind][currSum] = (pick||notPick);
    }
    bool canPartition(vector<int>& nums) {
        
        int total = 0;
        for(int i=0; i<nums.size(); i++){
            total+=nums[i];
        }
        vector<vector<int>>dp(nums.size(),vector<int>(total+1,-1));
        return func(nums,0,0,total,dp);
    }
};