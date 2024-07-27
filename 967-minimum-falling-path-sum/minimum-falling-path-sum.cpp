class Solution {
public:
    int func(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        int n = matrix.size();
        if(i>=n || j>=n || j<0) return 1e9;
        if(i==n-1) return matrix[i][j];
        if(dp[i][j]!=1e9) return dp[i][j]; //...
        int down = matrix[i][j] + func(i+1,j,matrix,dp);
        int dleft = matrix[i][j] + func(i+1,j-1,matrix,dp);
        int dright = matrix[i][j] + func(i+1,j+1,matrix,dp); 

        return dp[i][j]=min(down,min(dleft,dright)); //...
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,1e9)); //...
        int mini = INT_MAX;
        for(int i=0; i<n; i++){
            mini=min(mini, func(0,i,matrix,dp));
        }
        return mini;
    }
    //addition after recurr...
};