class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> arr(n,vector<int>(n,0));

        
        for(int j=1; j<n; j++){
            int y=0;
            int x = j;
            vector<int>temp;
            while(y<n && x<n){
                temp.push_back(grid[y][x]);
                y++;
                x++;
            }
            sort(temp.begin(),temp.end());
            y=0;
            x=j;
            while(y<n && x<n){
                arr[y][x]=temp[y];
                y++;
                x++;
            }            
        }     

        for(int i=0; i<n; i++){
            int x = 0;
            int y=i;
            vector<int>temp;
            while(y<n && x<n){
                temp.push_back(grid[y][x]);
                y++;
                x++;
            }
            sort(temp.begin(),temp.end(), greater<int>());
            x=0;
            y=i;
            while(y<n && x<n){
                arr[y][x]=temp[x];
                y++;
                x++;
            }            
        }

        return arr;   
    }
};