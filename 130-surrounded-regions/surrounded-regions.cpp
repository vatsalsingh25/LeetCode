class Solution {
private:
    void dfs(int row, int col, vector<vector<char>>& board, vector<vector<int>>&vis){
        int m = board.size();
        int n = board[0].size();

        if(row<0 || row>=m || col<0 || col>=n || vis[row][col] || board[row][col]!='O') return; 

        vis[row][col]=1;    

        dfs(row-1,col,board,vis);   
        dfs(row+1,col,board,vis); 
        dfs(row,col-1,board,vis); 
        dfs(row,col+1,board,vis); 
    }
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        
        //traverse top and bottom boundry
        for(int j=0; j<n; j++){
            if(board[0][j]=='O' && !vis[0][j]) dfs(0,j,board,vis);
            if(board[m-1][j]=='O' && !vis[m-1][j]) dfs(m-1,j,board,vis);
        }


        //traverse top and bottom boundry
        for(int i=0; i<m; i++){
            if(board[i][0]=='O' && !vis[i][0]) dfs(i,0,board,vis);
            if(board[i][n-1]=='O' && !vis[i][n-1]) dfs(i,n-1,board,vis);
        }


        // visited array is complete after above lines are executed
        // change all the elements to 'X' in board, 
        //except those marked as 1 in vis(ie boundry O and connectd)
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(vis[i][j]==1) continue;
                else board[i][j]='X'; 
            }
        }

        return;
    }
};