class Solution {
public:
    int func(vector<int>&coins, int ind, int amount,vector<vector<int>>&dp){
        if(amount==0) return 1;
        if(ind==0){
            return (amount%coins[0]==0);
        }

        if(dp[ind][amount]!=-1) return dp[ind][amount];
        
        int notPick = func(coins,ind-1,amount,dp);
        int pick=0;
        if(amount>=coins[ind]) pick = func(coins,ind,amount-coins[ind],dp);

        return dp[ind][amount]=pick+notPick;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return func(coins,n-1,amount,dp);
    }
};