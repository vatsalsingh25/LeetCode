class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        int start = 0;
        int end = 0;
        int i=0;
        while(i<n){
            start = intervals[i][0];
            end = intervals[i][1];
            while(i<n-1 && end>=intervals[i+1][0]){
                end = max(end, intervals[i+1][1]);
                i++;
            }
            ans.push_back({start,end});
            i++;
        }
        return ans;
    }

    

    

};