class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        vector<vector<int>>dis(m,vector<int>(n,0));
        queue<pair<pair<int,int>,int>>q;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        vector<int>rdel = {-1,1,0,0};
        vector<int>cdel = {0,0,-1,1};
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dist = q.front().second;
            q.pop();
            for(int i=0; i<4; i++){
                int nrow = row+rdel[i];
                int ncol = col+cdel[i];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n 
                && mat[nrow][ncol]==1 && !vis[nrow][ncol]){
                    vis[nrow][ncol]=1;
                    dis[nrow][ncol]=dist+1;
                    q.push({{nrow,ncol},dist+1});
                }
            }
        }
        return dis;
    }
};