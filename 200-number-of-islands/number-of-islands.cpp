class Solution {
private:
    void dfs(int row, int col,vector<vector<char>>& grid, vector<vector<int>>&vis ){
        int n = grid.size();
        int m = grid[0].size();

        if(row<0 || row>=n || col<0 || col>=m 
        || grid[row][col]=='0'|| vis[row][col]) return;

        vis[row][col]=1;

        dfs(row,col-1,grid,vis);
        dfs(row,col+1,grid,vis);
        dfs(row-1,col,grid,vis);
        dfs(row+1,col,grid,vis);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));

        //traversing through the grid matrix to trigger dfs search as soon an a non visited "1" is found
        int count = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    count++;
                    dfs(i,j,grid,vis);
                }
            }
        }
        return count;
    }
};