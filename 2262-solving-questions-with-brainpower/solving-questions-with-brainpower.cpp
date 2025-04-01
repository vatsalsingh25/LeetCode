class Solution {
public:
    long long func(vector<vector<int>>& questions, int ind, vector<long long>&dp){

        if(ind >= questions.size()) return 0; //base case
        if(dp[ind] != -1) return dp[ind];

        long long pick = questions[ind][0] + func(questions, ind+questions[ind][1]+1, dp);  //pick
        long long notpick = func(questions, ind+1, dp);  //not pick

        return dp[ind] = max(pick,notpick);
        
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long>dp(n,-1);
        return func(questions, 0, dp);
    }

};