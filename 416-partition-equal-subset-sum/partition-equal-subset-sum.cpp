class Solution {
public:
    bool func(int ind, int target, vector<int>& nums,vector<vector<int>>& dp){
        if(target<0) return false;
        if(target==0) return true;
        if(ind==0) return nums[0]==target;

        if(dp[ind][target]!=-1) return dp[ind][target];

        bool notTake = func(ind-1,target,nums,dp);
        bool take = func(ind-1,target-nums[ind],nums,dp);

        return dp[ind][target]=take||notTake;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum=0;
        for(int i=0; i<n; i++){
            sum+=nums[i];
        }
        if(sum%2==1) return false;

        int target = sum/2;
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return func(n-1,target,nums,dp);
    }
};