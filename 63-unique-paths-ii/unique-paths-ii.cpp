class Solution {
public:
    int func(vector<vector<int>>& obstacleGrid, int x, int y, vector<vector<int>>&dp){
        if(x==0 && y==0) return 1;
        if(x<0 || y<0) return 0;
        if(obstacleGrid[x][y]==1) return 0;

        if(dp[x][y]!=-1) return dp[x][y];

        int up = func(obstacleGrid, x-1, y, dp);
        int left = func(obstacleGrid, x, y-1, dp);

        return dp[x][y]=up+left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1 || obstacleGrid[n-1][m-1]) return 0;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return func(obstacleGrid, n-1, m-1,dp);
    }
};