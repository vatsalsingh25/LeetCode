class Solution {
public:
    int func(vector<int>&coins, int amount, int ind, vector<vector<int>>&dp){
        if(ind==0){
            if(amount%coins[ind]==0) return amount/coins[ind];                 // remember this step
            else return 1e9;                                                //annd this (!=return 0)    
        }

        if(dp[ind][amount]!=-1) return dp[ind][amount];

        int notPick = 0+func(coins,amount,ind-1,dp);
        int pick = INT_MAX;
        if(amount-coins[ind]>=0) pick = 1+func(coins,amount-coins[ind],ind,dp);

        return dp[ind][amount]=min(pick,notPick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans = func(coins,amount,n-1,dp);
        if(ans>=1e9) return -1;                                                //and this step
        return ans;
    }   
};