class Solution {
public:
    int func(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>&dp){
        int n = matrix.size();

        if(j<0 || j>=n) return 1e9;
        if(i==n-1) return matrix[i][j];
        // if(j<0 || j>=n) return 1e9;

        if(dp[i][j]!=1e9) return dp[i][j];

        int down = matrix[i][j]+func(matrix,i+1,j,dp);
        int dleft = matrix[i][j]+func(matrix,i+1,j-1,dp);
        int dright = matrix[i][j]+func(matrix,i+1,j+1,dp);

        return dp[i][j]=min(down,min(dleft,dright));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,1e9));
        int mini = INT_MAX;
        for(int j=0; j<n; j++){
            int sum = func(matrix,0,j,dp);
            mini=min(mini,sum);
        }
        return mini;
    }
};