class Solution {
public:
    int func(vector<vector<int>>& triangle, int i, int j, vector<vector<int>>&dp){
        int n = triangle.size();
        if(i==n-1) return triangle[n-1][j];

        if(dp[i][j]!=-1) return dp[i][j];

        int down = triangle[i][j]+func(triangle, i+1, j, dp);
        int up = triangle[i][j]+func(triangle, i+1, j+1, dp);

        return dp[i][j]=min(down,up);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return func(triangle, 0, 0, dp);
    }
};