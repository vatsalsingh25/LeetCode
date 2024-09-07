class Solution {
public:
    int func(vector<int>&coins, int amount, int ind, vector<vector<int>>&dp){
        if(amount==0) return 1;
        if(ind==0){
            if(amount%coins[0]==0) return 1;
            else return 0;
        }

        if(dp[ind][amount]!=-1) return dp[ind][amount];

        int notPick = func(coins,amount,ind-1,dp);
        int pick = 0;
        if(amount-coins[ind]>=0) pick = func(coins,amount-coins[ind],ind,dp);

        return dp[ind][amount]=pick+notPick;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return func(coins,amount,n-1,dp);
    }
};