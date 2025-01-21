class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        // Store the location of each element in the matrix
        unordered_map<int, pair<int, int>> location;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                location[mat[i][j]] = {i, j};
            }
        }
        
        // Row and column counters
        vector<int> rfreq(m, 0), cfreq(n, 0);
        
        // Iterate through the array and mark elements
        for (int i = 0; i < arr.size(); i++) {
            auto [r, c] = location[arr[i]]; // Get the row and column of the current number
            
            rfreq[r]++;
            cfreq[c]++;
            
            // Check if the current row or column is complete
            if (rfreq[r] == n || cfreq[c] == m) {
                return i;
            }
        }
        
        return -1; // This should not happen for valid inputs
    }
};
