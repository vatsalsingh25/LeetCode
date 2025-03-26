class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size();
        int n = grid[0].size();

        unordered_set<int>st;
        vector<int>nums;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                st.insert(grid[i][j]%x);
                nums.push_back(grid[i][j]);
                if(st.size()>1) return -1;        
            }
        }

        sort(nums.begin(), nums.end());

        int targetInd = nums.size()/2;
        int operations = 0;
        for(int i=0; i<nums.size(); i++){
            operations += abs(nums[targetInd]-nums[i])/x;   
        }

        return operations;
    }
};