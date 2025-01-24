class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // int count=0;
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<m; j++){
        //         bool flag = false;
        //         if(grid[i][j]==1){
        //             if(i>0){
        //                 if(grid[i-1][j]==1) flag = true;
        //             }
        //             if(i<n-1){
        //                 if(grid[i+1][j]==1) flag = true;
        //             }
        //             if(j>0){
        //                 if(grid[i][j-1]==1) flag = true;
        //             }
        //             if(j<m-1){
        //                 if(grid[i][j+1]==1) flag = true;
        //             }                   
        //         }
        //         if(flag) count++;
        //     }
        // }
        // return count;
        vector<int>row(n,0);
        vector<int>col(m,0);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1){
                    row[i]++;
                    col[j]++;
                }
            }
        }
        int count = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1){
                    if(col[j]>1 || row[i]>1) count++;
                }
            }
        }
        return count;
    }
};