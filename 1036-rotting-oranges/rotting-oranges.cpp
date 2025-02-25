class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>>vis(m,vector<int>(n,0));
        queue<pair<pair<int,int>,int>>q;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        int time = 0;
        vector<int>delrow = {-1,1,0,0};
        vector<int>delcol = {0,0,-1,1};

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            q.pop();
            time = max(time,t);
            for(int i=0; i<4; i++){
                int nrow = row+delrow[i];
                int ncol = col+delcol[i];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && 
                !vis[nrow][ncol] && grid[nrow][ncol]==1){
                    q.push({{nrow,ncol},t+1});
                    vis[nrow][ncol]=1;
                }
            }
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!vis[i][j] && grid[i][j]==1) return -1;
            }
        }

        return time;
    }
};