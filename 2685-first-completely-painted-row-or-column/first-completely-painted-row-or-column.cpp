class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        unordered_map<int, pair<int, int>> location;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                location[mat[i][j]] = {i, j};
            }
        }
        vector<int> rfreq(m, 0), cfreq(n, 0);
        for (int i = 0; i < arr.size(); i++) {
            auto [r, c] = location[arr[i]]; 
            
            rfreq[r]++;
            cfreq[c]++;
            if (rfreq[r] == n || cfreq[c] == m) {
                return i;
            }
        }
        return -1; 
    }
};
