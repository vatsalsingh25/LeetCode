class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        int count = 0;
        int latestEnd = 0;

        for(auto it: meetings){
            int start = it[0];
            int end = it[1];

            if(start>latestEnd){
                count+=start-latestEnd-1;
            }
            latestEnd = max(end,latestEnd);
        }

        count+=days-latestEnd;
        return count;
    }
};