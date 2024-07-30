class Solution {
public:
    int func(string&s, string&t, int ind1, int ind2, vector<vector<int>>&dp){ 
        //bases cases cant be written in reverse order cuz it will return 0 before checking if ind2 also reached -1 or not
        if(ind2<0) return 1;   //t matched completly
        if(ind1<0) return 0;   //s iterated compeltly        

        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];

        if(s[ind1]==t[ind2]) return dp[ind1][ind2] = func(s,t,ind1-1,ind2-1,dp)+func(s,t,ind1-1,ind2,dp);   // (match this one) + (ignore this one)
        return dp[ind1][ind2] = func(s,t,ind1-1,ind2,dp); // when not a match...reduce the string to find a match;
    }
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return func(s,t,n-1,m-1,dp); 
    }
};