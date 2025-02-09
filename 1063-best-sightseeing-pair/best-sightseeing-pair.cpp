class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();

        int max_i = values[0];

        int ans = 0;
        for(int j=1; j<n; j++){
            ans = max(ans,max_i+(values[j]-j));    
            max_i=max(max_i,values[j]+j);         //values[i]-i
        }
        return ans;
    }
};