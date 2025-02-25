class Solution {
private:
    void dfs(int row, int col, int orgColor, vector<vector<int>>& image, int color){
        int m = image.size();
        int n = image[0].size();  

        if(row<0 || row>=m || col<0 || col>=n || image[row][col]!=orgColor) return;

        image[row][col]=color;

        dfs(row-1,col,orgColor,image,color);
        dfs(row+1,col,orgColor,image,color);
        dfs(row,col-1,orgColor,image,color);
        dfs(row,col+1,orgColor,image,color);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();

        int orgColor = image[sr][sc];
        if(orgColor == color) return image; 
        
        dfs(sr,sc,orgColor,image,color);

        return image;
    }
};