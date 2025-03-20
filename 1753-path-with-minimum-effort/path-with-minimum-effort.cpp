class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>>value(n,vector<int>(m,INT_MAX)); // array to store distances
        priority_queue< pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> >pq;

        pq.push({0,{0,0}});  //{diff,{row,col}}
        value[0][0]=0;

        vector<int>drow = {0,0,-1,1};
        vector<int>dcol = {-1,1,0,0};

        while(!pq.empty()){
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            int diff = pq.top().first;
            if(row == n-1 && col == m-1) return diff;
            pq.pop();

            for(int i=0; i<4; i++){
                int nrow = row+drow[i];
                int ncol = col+dcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                    int difference = abs(heights[row][col] - heights[nrow][ncol]);
                    int effort = max(difference,diff);
                    if( effort<value[nrow][ncol] ){
                        value[nrow][ncol] = effort;
                        pq.push({effort,{nrow,ncol}});
                    }
                }
            }
        }

        return 0;
    }
};