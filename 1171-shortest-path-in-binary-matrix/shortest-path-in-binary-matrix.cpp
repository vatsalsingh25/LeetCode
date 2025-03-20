class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;

        vector<vector<int>>distance(n,vector<int>(n,INT_MAX));
        queue<pair<int,pair<int,int>>>q;
        // {distance, {row,col}}

        distance[0][0]=1;
        q.push({1,{0,0}});

        while(!q.empty()){
            int dis = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();

            for(int i=-1; i<=1; i++){
                for(int j=-1; j<=1; j++){
                    int nrow = row+i;
                    int ncol = col+j;
                    
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol]==0 && dis+1 < distance[nrow][ncol]){
                        distance[nrow][ncol] = dis + 1;
                        q.push({dis+1,{nrow,ncol}});
                    }
                }
            }

        }
        if(distance[n-1][n-1]==INT_MAX) return -1;
        return distance[n-1][n-1];
    }
};
// we dont essentially need to use priority queue since at every step we increase by 1, and hence it arranges in increasing order automatically