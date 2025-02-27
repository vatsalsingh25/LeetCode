class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>>vis(m,vector<int>(n,0));
        queue<pair<int,int>>q;

        // traverse all the boundries and push all '1' points into queue
        for(int j=0; j<n; j++){
            if(grid[0][j]==1){
                vis[0][j]=1; 
                q.push({0,j});
            } 
            if(grid[m-1][j]==1){
                vis[m-1][j]=1;
                q.push({m-1,j});
            } 
        }
        for(int i=0; i<m; i++){
            if(grid[i][0]==1){
                vis[i][0]=1; 
                q.push({i,0});
            } 
            if(grid[i][n-1]==1){
                vis[i][n-1]=1; 
                q.push({i,n-1});
            } 
        }

        //queue operations, pop front element and traverse all four direction 
        //and add new element if required node is found
        vector<int>delr = {-1,1,0,0};
        vector<int>delc = {0,0,-1,1};
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i=0; i<4; i++){
                int nrow = row+delr[i];
                int ncol = col+delc[i];

                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && 
                grid[nrow][ncol]==1 && !vis[nrow][ncol]){
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }

        int count = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1 && vis[i][j]==0) count++;
            }
        }

        return count;

    }
};