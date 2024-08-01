class Solution {
public:
    int func(vector<int>& nums, int ind, int prev, vector<vector<int>>&dp){
        if(ind==nums.size()) return 0;

        if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];  //prev+1 cuz dp[][-1] would be invalid hence shift

        int notTake = 0+func(nums,ind+1,prev,dp);
        int take = INT_MIN;
        if(prev==-1 || nums[ind]>nums[prev]) 
            take = 1+func(nums,ind+1,ind,dp);
        
        return dp[ind][prev+1]=max(take,notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return func(nums,0,-1,dp);
    }
};