class Solution {
public:
    int countArrays(vector<int>& original, vector<vector<int>>& bounds) {
        int low = bounds[0][0], high = bounds[0][1], ans = 0;
        for(int i = 1; i < original.size(); ++i){
            int diff = original[i] - original[i-1];
            low = max(low + diff, bounds[i][0]);
            high = min(high + diff, bounds[i][1]);
            
        }
        return max(0,high-low+1);        
    }
};