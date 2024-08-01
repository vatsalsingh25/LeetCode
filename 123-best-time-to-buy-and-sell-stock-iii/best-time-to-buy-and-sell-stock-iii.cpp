class Solution {
public:
    int func(vector<int>& prices, int ind, int check, int limit, vector<vector<vector<int>>>&dp){
        if(limit==0) return 0;
        if(ind==prices.size()) return 0;

        if(dp[ind][check][limit]!=-1) return dp[ind][check][limit];

        int profit = 0;
        if(check==0){
            profit = max(-prices[ind]+func(prices,ind+1,1,limit,dp), 0+func(prices,ind+1,0,limit,dp));
        }
        else{
            profit = max(prices[ind]+func(prices,ind+1,0,limit-1,dp), 0+func(prices,ind+1,1,limit,dp));
        }
        return dp[ind][check][limit]=profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return func(prices,0,0,2,dp);
    }
};