class Solution {
public:
    int func(string&word1, string&word2, int ind1, int ind2, vector<vector<int>>&dp){
        if(ind1<0) return ind2+1;    // insert operation to ind2
        if(ind2<0) return ind1+1;    // delete operations from ind1

        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];

        if(word1[ind1]==word2[ind2]) return dp[ind1][ind2]=0+func(word1,word2,ind1-1,ind2-1,dp); //no steps required

        int erase = func(word1,word2,ind1-1,ind2,dp);
        int insert = func(word1,word2,ind1,ind2-1,dp);
        int replace = func(word1,word2,ind1-1,ind2-1,dp);
        return dp[ind1][ind2]=1+min(erase,min(insert,replace));
    }

    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        vector<vector<int>>dp(n1,vector<int>(n2,-1));
        return func(word1,word2,n1-1,n2-1,dp);
    }
};