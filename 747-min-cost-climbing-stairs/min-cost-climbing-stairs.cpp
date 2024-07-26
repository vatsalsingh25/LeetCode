class Solution {
public:
    int func(vector<int>& cost, int ind, vector<int>&dp){
        if(ind==0) return 0;
        if(ind==1) return 0;
        
        if(dp[ind]!=-1) return dp[ind];
        
        int oneStep = func(cost,ind-1,dp)+cost[ind-1];
        int twoStep = func(cost,ind-2,dp)+cost[ind-2];
        
        return dp[ind]=min(oneStep,twoStep);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int N = cost.size();
        vector<int>dp(N+1,-1);
        return func(cost,N,dp);       
    }
};