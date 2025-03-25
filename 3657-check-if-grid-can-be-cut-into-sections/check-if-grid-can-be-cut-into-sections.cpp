class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        //creating a (xStart,xEnd) array for allowing vertical lines
        //creating a (yStart,yEnd) array for allowing horizontal lines
        vector<vector<int>>xAxis;
        vector<vector<int>>yAxis;
        for(auto it: rectangles){
            xAxis.push_back({it[0],it[2]});
            yAxis.push_back({it[1],it[3]});
        }

        //sorting the array to get the axes together for furthur operation
        sort(xAxis.begin(), xAxis.end());
        sort(yAxis.begin(), yAxis.end());\

        //checking if horizontal seperation is possible

        // set the previous END of y = end point fo first rectangle 
        int perviousEndY = yAxis[0][1];
        int countY = 0;
        //start loop from index 1 as thats where we can start considering 
        //division as each part should have atleast one recangle
        for(int i=1; i<yAxis.size(); i++){
            int start = yAxis[i][0];
            int end = yAxis[i][1];
            //if current point is above or equal to the previous end point, we can divide the plane
            if(start>=perviousEndY){
                countY++;
            }
            perviousEndY = max(end,perviousEndY);
        }
        if(countY>=2) return true;

        //checking if vertical seperation is possible (exact approach as above)
        int previousEndX = xAxis[0][1];
        int countX = 0;
        for(int i=1; i<xAxis.size(); i++){
            int start = xAxis[i][0];
            int end = xAxis[i][1];

            if(start>=previousEndX){
                countX++;
            }
            previousEndX = max(end,previousEndX);
        }
        if(countX>=2) return true;

        return false;
    }
};