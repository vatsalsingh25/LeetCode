class Solution {
public:
    int func(vector<int>&dp, int ind){
        if(ind==0) return 1;
        if(ind==1) return 1;

        if(dp[ind]!=-1) return dp[ind];

        int singleStep = func(dp,ind-1);
        
        int doubleStep = func(dp,ind-2);

        return dp[ind] = singleStep+doubleStep;
    }
    int climbStairs(int ind) {
        vector<int> dp(ind+1,-1);
        return func(dp, ind);
    }
};