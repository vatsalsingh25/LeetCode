class Solution {
public:
    int func(vector<int>&nums,int ind, int sum, vector<vector<int>>&dp){
        if(ind==0){
            if(sum==0 && nums[0]==0) return 2;
            if(sum==0) return 1;
            if(sum==nums[0]) return 1;
            return 0;
        }
        
        if(dp[ind][sum]!=-1) return dp[ind][sum];

        int notPick = func(nums,ind-1,sum,dp);
        int pick = 0;
        if(sum>=nums[ind]) pick = func(nums,ind-1,sum-nums[ind],dp);

        return dp[ind][sum] = pick+notPick;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
       int n = nums.size();
       int total=0;
       for(int i=0; i<n; i++){
            total+=nums[i];
       } 

        if((total-target)%2==1) return 0;
        if(total-target<0) return 0;
        int sum = (total-target)/2;
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return func(nums,n-1,sum,dp);
    }
    //s1-s2=k
    //s1=total-s2
    //total-s2-s2=k
    //s2=(total-k)/2
};