class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>>xAxis;
        vector<vector<int>>yAxis;
        for(auto it: rectangles){
            xAxis.push_back({it[0],it[2]});
            yAxis.push_back({it[1],it[3]});
        }
        
        sort(xAxis.begin(), xAxis.end());
        sort(yAxis.begin(), yAxis.end());\

        int latestEndy = yAxis[0][1];
        int yCount = 0;
        for(int i=1; i<yAxis.size(); i++){
            int start = yAxis[i][0];
            int end = yAxis[i][1];

            if(start>=latestEndy){
                yCount++;
            }
            latestEndy = max(end,latestEndy);
        }
        if(yCount>=2) return true;

        int latestEndx = xAxis[0][1];
        int xCount = 0;
        for(int i=1; i<xAxis.size(); i++){
            int start = xAxis[i][0];
            int end = xAxis[i][1];

            if(start>=latestEndx){
                xCount++;
            }
            latestEndx = max(end,latestEndx);
        }
        if(xCount>=2) return true;

        return false;
    }
};