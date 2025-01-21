class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        // make matrix to store locations of elements;
        int m = mat.size();
        int n = mat[0].size();
        unordered_map<int,vector<int>>location;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                location[mat[i][j]] = {i,j};
            }
        }
        int ans;
        //mark numbers to 0 if traversed and also check if whole column/row is marked 0;
        vector<int>rfreq(m);
        vector<int>cfreq(n);
        for(int i=0; i<arr.size(); i++){
            vector<int>loc = location[arr[i]];
            int r = loc[0];
            int c = loc[1];
            rfreq[r]++;
            cfreq[c]++;
            if(rfreq[r]==n || cfreq[c]==m) return i;
        }
        return -1;
    }
};