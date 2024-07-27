class Solution {
public:
    int func(int i, int j,vector<vector<int>>&triangle, vector<vector<int>>&dp){
        int n = triangle.size();
        if(i>=n) return 0;
        if(j>i) return 0;
        if(i==n-1) return triangle[i][j];

        if(dp[i][j]!=-1) return dp[i][j];

        int down = triangle[i][j]+func(i+1,j,triangle,dp);
        int diagonal = triangle[i][j]+func(i+1,j+1,triangle,dp);

        return dp[i][j]=min(down,diagonal);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[n-1].size();

        vector<vector<int>>dp(n,vector<int>(n,-1));

        return func(0,0,triangle,dp);
    }
};