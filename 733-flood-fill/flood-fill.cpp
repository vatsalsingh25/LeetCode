class Solution {
private:
    void dfs(int row, int col, int orgColor,vector<vector<int>>vis, vector<vector<int>>& image, int color){
        int m = image.size();
        int n = image[0].size();  

        if(row<0 || row>=m || col<0 || col>=n || image[row][col]!=orgColor || vis[row][col]) return;

        vis[row][col]=1;
        image[row][col]=color;

        dfs(row-1,col,orgColor,vis,image,color);
        dfs(row+1,col,orgColor,vis,image,color);
        dfs(row,col-1,orgColor,vis,image,color);
        dfs(row,col+1,orgColor,vis,image,color);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();

        vector<vector<int>>vis(m,vector<int>(n,0));

        int orgColor = image[sr][sc];
        dfs(sr,sc,orgColor,vis,image,color);

        return image;
    }
};