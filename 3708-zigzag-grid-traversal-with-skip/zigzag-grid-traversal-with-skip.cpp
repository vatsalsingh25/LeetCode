class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        vector<int>ans;

        for(int i=0; i<grid.size(); i++){
            if(i%2==0){
                for(int j=0; j<grid[0].size(); j+=2){
                    ans.push_back(grid[i][j]);
                }
            }
            else{
                if(grid[0].size()%2==0){
                    for(int j=grid[0].size()-1; j>=0; j-=2){
                        ans.push_back(grid[i][j]);
                    }
                }
                else{
                    for(int j=grid[0].size()-2; j>=0; j-=2){
                        ans.push_back(grid[i][j]);
                    }                    
                }

            }
            
        }
        return ans;
    }
};