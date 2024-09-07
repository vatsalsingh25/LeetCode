class Solution {
public:
    bool func(vector<int>& nums, int sum, int ind, vector<vector<int>>&dp){
        if(sum==0) return true;
        if(ind==0) return nums[0]==sum;

        if(dp[ind][sum]!=-1) return dp[ind][sum];

        int notPick = func(nums,sum,ind-1,dp);
        int pick = false;
        if(sum-nums[ind]>=0) pick = func(nums,sum-nums[ind],ind-1,dp);

        return dp[ind][sum]=pick||notPick;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++){
            sum+=nums[i];
        }
        if(sum%2==1) return false;
        sum = sum/2;

        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return func(nums,sum,n-1,dp);
    }
};