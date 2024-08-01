class Solution {
public:
    int func(vector<int>& prices, int ind, int check, int fee, vector<vector<int>>&dp){
        if(ind==prices.size()) return 0;

        if(dp[ind][check]!=-1) return dp[ind][check];

        int profit = 0;
        if(check==0){
            profit = max( -fee-prices[ind]+func(prices,ind+1,1,fee,dp) , 0+func(prices,ind+1,0,fee,dp));
        }
        else{
            profit = max( prices[ind]+func(prices,ind+1,0,fee,dp), 0+func(prices,ind+1,1,fee,dp));
        }
        return dp[ind][check]=profit;
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return func(prices,0,0,fee,dp);
    }
};